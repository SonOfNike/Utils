#pragma once

#include "enums_typedef.h"
#include "globals.h"
#include <string>
#include <charconv>
#include <string_view>
#include <optional>

std::optional<int> stringViewToInt(std::string_view str) {
    int result;
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);
    if (ec == std::errc()) {
        return result;
    } else {
        return std::nullopt; // Indicates conversion failure
    }
}

Timestamp parse_timestring(std::string_view time_string){
    Timestamp result = 0;
    uint string_size = time_string.length();

    result += stringViewToInt(time_string.substr(11,2)).value() * HOURS;
    result += stringViewToInt(time_string.substr(14,2)).value() * MINUTES;
    result += stringViewToInt(time_string.substr(17,2)).value() * SECONDS;

    if(string_size > 29){
        result += stringViewToInt(time_string.substr(20,3)).value() * MILLI_SECONDS;
        result += stringViewToInt(time_string.substr(23,3)).value() * MICRO_SECONDS;
        result += stringViewToInt(time_string.substr(26,3)).value();
    }
    else if(string_size > 26){
        result += stringViewToInt(time_string.substr(20,3)).value() * MILLI_SECONDS;
        result += stringViewToInt(time_string.substr(23,3)).value() * MICRO_SECONDS;
        // result += stringViewToInt(time_string.substr(26,string_size - 26)).value();
    }
    else if(string_size > 23){
        result += stringViewToInt(time_string.substr(20,3)).value() * MILLI_SECONDS;
        // result += stringViewToInt(time_string.substr(23,string_size - 23)).value() * MICRO_SECONDS;
    }

    return result;
}