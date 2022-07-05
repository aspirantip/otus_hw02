#pragma once

#include <iostream>
#include <array>
#include <vector>

using IP = std::array<uint8_t, 4>;

IP stringToIp(const std::vector<std::string>& ip_str)
{
    IP ip;
    auto ip_part {ip.begin()};
    for (const auto& ip_part_str: ip_str) {
        *ip_part = std::stoi(ip_part_str);
        ip_part++;
    }

    return ip;
}

inline void printIp (const IP& ip)
{
    uint8_t cnt{0};
    for (const auto& ip_part: ip) {
        std::cout << int(ip_part);
        if (++cnt != ip.size()) {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

inline void printIpPool (const std::vector<IP>& ip_pool)
{
    for (const auto& ip: ip_pool) {
        printIp (ip);
    }
}
