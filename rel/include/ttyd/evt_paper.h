#pragma once

#include <cstdint>

#include "evtmgr.h"

namespace ttyd::evt_paper
{
    extern "C"
    {
        EVT_DECLARE_USER_FUNC(evt_paper_entry, 1)
    }
} // namespace ttyd::evt_paper
