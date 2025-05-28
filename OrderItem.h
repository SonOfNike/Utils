#pragma once

#include "enums_typedef.h"

enum class order_state {PENDING_NEW,PENDING_CANCEL,PENDING_MODIFY,CONFIRMED,NONE};

struct OrderItem{
    Price m_order_price = 0;
    Shares m_order_quant = 0;
    Shares m_total_fills = 0;
    OrderId m_id = 0;
    order_state m_state = order_state::NONE;
};