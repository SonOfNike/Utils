#pragma once

#include "enums_typedef.h"

class Timeout{
public:
    Timeout(const Timestamp& time, const SymbolId& sym_id, const SymbolId& strat_id): m_time(time),
        m_sym_id(sym_id), m_strat_id(strat_id){;} 

    Timeout(): m_time(0),m_sym_id(0), m_strat_id(0){;} 

    Timestamp m_time = 0;
    SymbolId m_sym_id = 0;
    SymbolId m_strat_id = 0;
};

struct TimeoutComparator {
    bool operator()(const Timeout& a, const Timeout& b) const {
        // Example: Max-heap based on value1 (higher value1 means higher priority)
        return a.m_time > b.m_time; 
        
        // Example: Min-heap based on value2 (lower value2 means higher priority)
        // return a.value2 > b.value2; 
    }
};