#pragma once

#include "enums_typedef.h"

enum md_type {PRINT, IMBALANCE, QUOTE, BID, ASK, NONE};

struct MDupdate{
    Price m_bid_price = 0;
    Price m_ask_price = 0;
    Shares m_bid_quant = 0;
    Shares m_ask_quant = 0;
    Timestamp m_timestamp = 0;
    md_type m_type = md_type::NONE;
};