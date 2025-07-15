#pragma once

#include "enums_typedef.h"

enum class resp_type {NEWORDER_CONFIRM, MODORDER_CONFIRM, CANCEL_CONFIRM, TRADE_CONFIRM, ORDER_REJECT, CANCEL_REJECT, MOD_REJECT, NONE};

struct Response{
    Price m_resp_price = 0;
    Shares m_resp_quant = 0;
    OrderId m_order_id = 0;
    SymbolId m_symbolId = 0;
    side m_side = side::NONE;
    resp_type m_type = resp_type::NONE;

    void clear(){
        m_resp_price = 0;
        m_resp_quant = 0;
        m_order_id = 0;
        m_symbolId = 0;
        m_side = side::NONE;
        m_type = resp_type::NONE;
    }
};