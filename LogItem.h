#pragma once

#include "enums_typedef.h"

enum class log_type {ORDERDELAY, MDDELAY, NASDOPEN, NYSEOPEN, TRADE, TRIGGER, IMBALANCE, NONE};

struct LogItem{
    Price m_price = 0;
    Price m_price2 = 0;
    Timestamp m_current_time = 0;
    Timestamp m_delay = 0;
    Shares m_shares = 0;
    Shares m_shares2 = 0;
    SymbolId m_symbolId = 0;
    SymbolId m_stratID = 0;
    side m_side = side::NONE;
    log_type m_type = log_type::NONE;

    void clear(){
        m_price = 0;
        m_price2 = 0;
        m_current_time = 0;
        m_delay = 0;
        m_shares = 0;
        m_shares2 = 0;
        m_symbolId = 0;
        m_stratID = 0;
        m_side = side::NONE;
        m_type = log_type::NONE;
    }
};