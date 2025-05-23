#include "patch.h"

#include <gc/OSCache.h>

#include <cstdint>
#include <cstring>

namespace mod::patch
{
    void clear_DC_IC_Cache(void *ptr, uint32_t size)
    {
        gc::OSCache::DCFlushRange(ptr, size);
        gc::OSCache::ICInvalidateRange(ptr, size);
    }

    void writeStandardBranches(void *address, void *functionStart, void *functionBranchBack)
    {
        void *branchBackAddress = reinterpret_cast<void *>(reinterpret_cast<uint32_t>(address) + 0x4);

        writeBranch(address, functionStart);
        writeBranch(functionBranchBack, branchBackAddress);
    }

    void writeBranch(void *ptr, void *destination)
    {
        uint32_t branch = 0x48000000; // b
        writeBranchMain(ptr, destination, branch);
    }

    void replaceEvtInstr(int32_t *instr, uint16_t opc)
    {
        *(uint16_t *)((uintptr_t)instr + sizeof(uint16_t)) = opc;
    }

    void writeEvtBranch(int32_t *instr, const int32_t *destination, bool async)
    {
        replaceEvtInstr(instr, async ? 0x5C : 0x5E); // calls{a,s}
        instr[1] = (uintptr_t)destination;           // arg 1
    }

    void writeBranchBL(void *ptr, void *destination)
    {
        uint32_t branch = 0x48000001; // bl
        writeBranchMain(ptr, destination, branch);
    }

    void writeBranchMain(void *ptr, void *destination, uint32_t branch)
    {
        uint32_t delta = reinterpret_cast<uint32_t>(destination) - reinterpret_cast<uint32_t>(ptr);

        branch |= (delta & 0x03FFFFFC);

        uint32_t *p = reinterpret_cast<uint32_t *>(ptr);
        *p = branch;

        clear_DC_IC_Cache(ptr, sizeof(uint32_t));
    }

    void writePatch(void *destination, const void *patch_start, const void *patch_end)
    {
        uint32_t patch_len = reinterpret_cast<uintptr_t>(patch_end) - reinterpret_cast<uintptr_t>(patch_start);
        writePatch(destination, patch_start, patch_len);
    }

    void writePatch(void *destination, const void *patch_start, uint32_t patch_len)
    {
        clear_DC_IC_Cache(const_cast<void *>(patch_start), patch_len);
        memcpy(destination, patch_start, patch_len);
        clear_DC_IC_Cache(destination, patch_len);
    }

    void writePatch(void *destination, uint32_t patch_data)
    {
        writePatch(destination, &patch_data, sizeof(uint32_t));
    }

    void writeBranchPair(void *original_start, void *original_end, void *new_start, void *new_end)
    {
        writeBranch(original_start, new_start);
        writeBranch(new_end, original_end);
    }

    void writeBranchPair(void *original_start, void *new_start, void *new_end)
    {
        writeBranch(original_start, new_start);
        writeBranch(new_end, reinterpret_cast<void *>(reinterpret_cast<int32_t>(original_start) + 4));
    }

    void writeIntWithCache(void *ptr, uint32_t value)
    {
        uint32_t *p = reinterpret_cast<uint32_t *>(ptr);
        *p = value;
        clear_DC_IC_Cache(ptr, sizeof(uint32_t));
    }
} // namespace mod::patch
