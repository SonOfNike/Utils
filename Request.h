#pragma once

#include "enums_typedef.h"

enum req_type {NEWORDER, MODORDER, CANCEL, NONE};

struct Request{
    OrderId m_order_id = 0;
    Price m_req_price = 0;
    Shares m_order_quant = 0;
    Shares m_total_fills = 0;
    req_type m_type = req_type::NONE;
};