#pragma once

#include "enums_typedef.h"

enum class md_type {PRINT, NYSEOPEN, NASDOPEN, IMBALANCE, SIGIMB, QUOTE, BID, ASK, NONE};

struct alignas(64) MDupdate{
    Price m_bid_price = 0;
    Price m_ask_price = 0;
    Timestamp m_timestamp = 0;
    Shares m_bid_quant = 0;
    Shares m_ask_quant = 0;
    SymbolId m_symbolId = 0;
    md_type m_type = md_type::NONE;

    // Tells the compiler: "Just move every member automatically"
    // MDupdate(MDupdate&&) = default; 
    // MDupdate& operator=(MDupdate&&) = default; // Move Assignment
};