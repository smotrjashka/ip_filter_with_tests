//
// Created by Nastia on 20.11.2021.
//

#include "octate.h"
#include <stdexcept>

///even we can have octet number from 0 to 255
Octate::Octate(unsigned short numberOctate) {
    if(isValidOctateNumber(numberOctate)){
        octate_number = numberOctate;
    } else
        octate_number = 256;
}

Octate::Octate(std::string stringOctate) {
    try {

        int octateValue = std::stoi(stringOctate);
        if (isValidOctateNumber(octateValue)){
            octate_number = (unsigned short) octateValue;
        } else
            octate_number = 256;
    } catch (const std::out_of_range& oor){
        octate_number = 256;
    } catch (const std::invalid_argument& ia) {
        octate_number = 256;
    }
}

bool Octate::isValidOctateNumber(unsigned short numberOctate) {
    if (numberOctate > 255){
        return false;
    }
    return true;
}

bool Octate::isValidOctateNumber(int numberOctate) {
    if (numberOctate > 0 && numberOctate < 256){
        return true;
    }
    return false;
}

bool Octate::operator<(const Octate& r) const{
    return (this->octate_number)<r.octate_number;
}

bool Octate::operator>(const Octate &r) const {
    return (this->octate_number)>r.octate_number;
}

bool Octate::operator==(const Octate &r) const{
    return (this->octate_number)==r.octate_number;
}

bool Octate::operator!=(const Octate &r) const {
    return (this->octate_number)!=r.octate_number;
}

unsigned short Octate::OctateNumber() {
    return octate_number;
}

std::string Octate::OctateName() {
    return std::to_string(octate_number);
}