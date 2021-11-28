#ifndef OCTATE_H
#define OCTATE_H

#include <string>


class Octate {
public:
    Octate(unsigned short numberOctate);
    Octate(std::string stringOctate);

    unsigned short OctateNumber();
    std::string OctateName();
    bool operator<(const Octate& r) const;
    bool operator>(const Octate& r) const;
    bool operator==(const Octate& r) const;
    bool operator!=(const Octate& r) const;
private:
    bool isValidOctateNumber(unsigned short numberOctate);
    bool isValidOctateNumber(int numberOctate);
    unsigned short octate_number;
};


#endif //OCTATE_H
