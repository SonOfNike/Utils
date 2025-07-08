#pragma once

#include "enums_typedef.h"
#include "Response.h"

enum class order_state {PENDING_NEW,PENDING_CANCEL,PENDING_MODIFY,CONFIRMED,NONE};

class OrderItem{
public:
    Price m_order_price = 0;
    Shares m_order_quant = 0;
    Shares m_total_fills = 0;
    OrderId m_id = 0;
    side m_side = side::NONE;
    order_state m_state = order_state::NONE;

    void clear(){
        m_order_price = 0;
        m_order_quant = 0;
        m_total_fills = 0;
        m_id = 0;
        m_side = side::NONE;
        m_state = order_state::NONE;
    }

    void processResp(const Response& _new_response){
        if(_new_response.m_type == resp_type::NEWORDER_CONFIRM){
            m_state = order_state::CONFIRMED;
        }
        else if(_new_response.m_type == resp_type::MODORDER_CONFIRM){
            m_order_price = _new_response.m_resp_price;
            m_order_quant = _new_response.m_resp_quant;
            m_state = order_state::CONFIRMED;
        }
        else if(_new_response.m_type == resp_type::CANCEL_CONFIRM){
            clear();
        }
        else if(_new_response.m_type == resp_type::TRADE_CONFIRM){
            m_order_quant -= _new_response.m_resp_quant;
            m_total_fills += _new_response.m_resp_quant;
            if(m_order_quant == 0) clear();
        }
        else if(_new_response.m_type == resp_type::ORDER_REJECT){
            clear();
        }
        else if(_new_response.m_type == resp_type::CANCEL_REJECT){
            ;
        }
        else if(_new_response.m_type == resp_type::MOD_REJECT){
            ;
        }
    }
};