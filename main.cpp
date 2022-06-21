#include "lib.h"

#include <iostream>

#include <cassert>
#include <cstdlib>
#include <iostream>

#include <string>
#include <vector>
#include <array>

#include <algorithm>



using IP = std::array<uint8_t, 4>;

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string>    result;
    std::string::size_type      start {0};
    std::string::size_type      stop  {str.find_first_of(d)};

    while (stop != std::string::npos)
    {
        result.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    result.push_back(str.substr(start));

    return result;
}

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


int main(int, char **)
{
    //std::cout << "Homework 02" << std::endl;
    //std::cout << "Version: " << version() << std::endl;
    //std::cout << "===================================\n";

    try
    {
        std::vector<IP> ip_pool;
        for (std::string line; std::getline(std::cin, line);) {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(stringToIp(split(v.at(0), '.')));
        }

        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(), ip_pool.end(), std::greater<IP>());
        printIpPool (ip_pool);

        // TODO filter by first byte and output
        // ip = filter(1)
        auto f_byte {1};
        for (const auto& ip : ip_pool) {
            if (ip.at(0) == f_byte)
                printIp(ip);
        }


        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
        f_byte = 46;
        auto s_byte {70};
        for (const auto& ip : ip_pool) {
            if (ip.at(0) == f_byte && ip.at(1) == s_byte)
                printIp(ip);
        }

        // TODO filter by any byte and output
        // ip = filter_any(46)
        auto num {46};
        for (const auto& ip : ip_pool) {
            for(const auto& ip_part : ip) {
                if (ip_part == num) {
                    printIp(ip);
                    break;
                }
            }
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
