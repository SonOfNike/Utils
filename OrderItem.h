#pragma once

#include "enums_typedef.h"

enum class order_state {PENDING_NEW,PENDING_CANCEL,PENDING_MODIFY,CONFIRMED,NONE};

class OrderItem{
public:
    Price m_order_price = 0;
    Shares m_order_quant = 0;
    Shares m_total_fills = 0;
    OrderId m_id = 0;
    side m_side = side::NONE;
    order_state m_state = order_state::NONE;

    void setPrice(Price _price){
        m_order_price = _price;
    }

    void setQuant(Shares _quant){
        m_order_quant = _quant;
    }

    void setSide(side _side){
        m_side = _side;
    }
};