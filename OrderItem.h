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
    Timestamp m_timestamp = 0;
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

    void processResp(const Response& _new_response, const Timestamp& _current_time, LogItem& newLog, ShmemManager* mShmemManager){
        if(_new_response.m_type == resp_type::NEWORDER_CONFIRM){
            m_state = order_state::CONFIRMED;

            if(_current_time - m_timestamp > 500000000){
            // std::cout << "Order Latency=" << _current_time - m_timestamp << 
            // "|CurrentTime=" << _current_time << "\n";
                // char buf[128];
                // int n = snprintf(buf, sizeof(buf), "Order Latency=%u|CurrentTime=%u", _current_time - m_timestamp, _current_time);
                // FastLogger::getInstance()->log(_tlog->tb, buf);

                newLog.clear();

                newLog.m_type = log_type::ORDERDELAY;
                newLog.m_current_time = _current_time;
                newLog.m_delay = _current_time - m_timestamp;

                mShmemManager->pushLog(newLog);
            }
        }
        else if(_new_response.m_type == resp_type::MODORDER_CONFIRM){
            m_order_price = _new_response.m_resp_price;
            m_order_quant = _new_response.m_resp_quant;
            m_state = order_state::CONFIRMED;
        }
        else if(_new_response.m_type == resp_type::CANCEL_CONFIRM){
            if(_current_time - m_timestamp > 500000000){
            // std::cout << "Order Latency=" << _current_time - m_timestamp << 
            // "|CurrentTime=" << _current_time << "\n";
                // char buf[128];
                // int n = snprintf(buf, sizeof(buf), "Order Latency=%u|CurrentTime=%u", _current_time - m_timestamp, _current_time);
                // FastLogger::getInstance()->log(_tlog->tb, buf);

                newLog.clear();

                newLog.m_type = log_type::ORDERDELAY;
                newLog.m_current_time = _current_time;
                newLog.m_delay = _current_time - m_timestamp;

                mShmemManager->pushLog(newLog);
            }

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