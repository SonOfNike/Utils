#pragma once

#include "enums_typedef.h"

enum class req_type {NEWORDER, MODORDER, CANCEL, NONE};

struct Request{
    Price m_req_price = 0;
    Shares m_order_quant = 0;
    Shares m_total_fills = 0;
    OrderId m_order_id = 0;
    SymbolId m_symbolId = 0;
    req_type m_type = req_type::NONE;

    void clear(){
        m_req_price = 0;
        m_order_quant = 0;
        m_total_fills = 0;
        m_order_id = 0;
        m_symbolId = 0;
        m_type = req_type::NONE;
    }
};