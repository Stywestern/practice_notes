#include <iostream>
#include <fstream>
#include <string>

bool is_leap_year(int num) {
    if (num % 4 == 0) {
        if (num % 100 == 0 && !(num % 400 == 0)) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int main()
{  
    std::cout << is_leap_year(1996) << std::endl;
    std::cout << is_leap_year(1997) << std::endl;
    std::cout << is_leap_year(1900) << std::endl;
    std::cout << is_leap_year(2000) << std::endl;

}
