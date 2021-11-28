//
// Created by Nastia on 20.11.2021.
//

#include "iPv4.h"
#include <iostream>

IPv4::IPv4(std::string iPv4candidate) {
    std::vector<std::string> candidatesVector = Utils::split(iPv4candidate, '.');
   for(std::string ocatateCandidate : candidatesVector){
       Octate oct(ocatateCandidate);
       octates.emplace_back(oct);
   }

    if (!isValidIpv4address()){
        changeForDefault();
    }

}

bool IPv4::isValidIpv4address() {
    if (octates.empty()){
        return false;
    } else if (octates.size() != 4){
        return false;
    } else {
        for (Octate o : octates) {
            if (o.OctateNumber()==256) {
                return false;
            }
        }
    }
    return true;
}


bool IPv4::isValidIpv4address(const IPv4 &ipv4Suspect) {
    if (ipv4Suspect.octates.empty()){
        return false;
    } else if (ipv4Suspect.octates.size() != 4){
        return false;
    } else {
        for (Octate o : ipv4Suspect.octates) {
            if (o.OctateNumber()==256) {
                return false;
            }
        }
    }
    return true;
}

void IPv4::changeForDefault() {
    octates = {Octate(0), Octate(0), Octate(0), Octate(0)};
}

std::string IPv4::IPv4address() {
    std::string ipv4address;
    for (int i = 0; i < 4; ++i) {
        ipv4address.append(octates[i].OctateName() + ".");
    }

    ipv4address.erase(ipv4address.at(ipv4address.size()-1));
    return ipv4address;
}

const bool IPv4::operator==(const IPv4 &l) const{
    for (int i = 0; i < 4; ++i) {
        if(this->octates[i] != l.octates[i])
            return false;
    }
    return true;
}

const bool IPv4::operator<(const IPv4 &l) const{
    if (this->operator==(l)){
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        if (this->octates[i]<l.octates[i]){
            return true;
        } else if (this->octates[i]!=l.octates[i]){
            return false;
        }
    }
    /// we may never reach this point, but just in case
    return false;
}

const bool IPv4::operator>(const IPv4 &l) const{
    if (this->operator==(l)){
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        if (this->octates[i]>l.octates[i]){
            return true;
        } else if (this->octates[i]!=l.octates[i]){
            return false;
        }
    }
    /// we may never reach this point, but just in case
    return false;
}