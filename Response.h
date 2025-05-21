#pragma once

#include "enums_typedef.h"

enum resp_type {NEWORDER_CONFIRM, MODORDER_CONFIRM, CANCEL_CONFIRM, TRADE_CONFIRM, ORDER_REJECT, CANCEL_REJECT, MOD_REJECT, NONE};

struct Response{
    Price m_resp_price = 0;
    Shares m_resp_quant = 0;
    resp_type m_type = resp_type::NONE;
};