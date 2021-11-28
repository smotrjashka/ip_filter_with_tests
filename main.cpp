#include <iostream>
#include "version.h"
#include <cassert>

int main() {
    assert(version::getVersion()>0);
    std::cout << "Version: " << version::getVersion() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
