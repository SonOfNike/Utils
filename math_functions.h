#pragma once

#include "enums_typedef.h"
#include "globals.h"

Price roundToNearestCent(Price _num){
    Price rem = _num % CENTS;
    return rem >= 50 ? (_num - rem + CENTS) : (_num - rem);
}