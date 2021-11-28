#include "iPv4.h"
#include <vector>
#include <set>
#include <iostream>

int main(int argc, char const *argv[]){
  //  std::vector<IPv4> ip_pool;
  std::cout << "start enter values" << std::endl;
    std::set<IPv4, std::greater<IPv4>> ipv4_pool;

    for(std::string line; std::getline(std::cin, line);){
        std::vector<std::string> v = (Utils::split(line, '\t'));
        ipv4_pool.insert(IPv4(v.at(0)));
    }

    std::cout << "finished!" << std::endl;

    IPv4 defaultIPv4 = IPv4("0.0.0.0");
    ipv4_pool.erase(defaultIPv4);

    for (IPv4 iPv4 : ipv4_pool) {
        std::cout << iPv4.IPv4address() << std::endl;
    }

}