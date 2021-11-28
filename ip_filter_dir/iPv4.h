//
// Created by Nastia on 20.11.2021.
//

#ifndef IPV4_H
#define IPV4_H

#include "octate.h"
#include <vector>
#include "utils.h"


class IPv4 {
public:
    IPv4(std::string iPv4candidate);
    std::string IPv4address();
    bool isValidIpv4address(const IPv4& ipv4Suspect);

   const bool operator<(const IPv4& l) const;
   const bool operator>(const IPv4& l) const;
   const bool operator==(const IPv4& l) const;

private:
    std::vector<Octate> octates;
    void changeForDefault();
    bool isValidIpv4address();

};


#endif //IPV4_H
