#ifndef _TIME_
#define _TIME_

#include <iostream>
#include <stdint.h>
//#include <string>


class Time{
private:
    uint32_t hour;
    uint32_t min;
    uint32_t sec;
    uint32_t t_sec;
    
public:
    Time();
    Time(uint32_t hour,uint32_t min,uint32_t sec);
    uint32_t CalSeconed();
    uint32_t setHour(uint32_t hour);
    uint32_t getHour();
    uint32_t setMin(uint32_t min);
    uint32_t getMin();
    uint32_t setSec(uint32_t sec);
    uint32_t getSec();
    std::string getTimeStr();
    bool operator<=(Time timeObj);
    bool operator>=(Time timeObj);
};


#endif // _TIME_