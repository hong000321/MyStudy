#include "6_uml_to_class.h"

Time::Time(){
    hour = 0;
    min = 0;
    sec = 0;
}

Time::Time(uint32_t hour,uint32_t min,uint32_t sec){
    this->hour = hour;
    this->min = min;
    this->sec = sec;
}

uint32_t Time::CalSeconed(){
    this->t_sec =  hour*60*60 + min*60 + sec;
    return this->t_sec;
}

uint32_t Time::setHour(uint32_t hour){
    this->hour = hour;
    return this->hour;
}

uint32_t Time::getHour(){
    return this->hour;
}

uint32_t Time::setMin(uint32_t min){
    this->min = min;
    return this->min;
}

uint32_t Time::getMin(){
    return this->min;
}

uint32_t Time::setSec(uint32_t sec){
    this->sec = sec;
    return this->sec;
}

uint32_t Time::getSec(){
    return this->sec;
}

std::string Time::getTimeStr(){
    std::string retStr =std::to_string(this->hour) + ":" + std::to_string(this->min) + ":" + std::to_string(this->sec);
    return retStr;
}

bool Time::operator<=(Time timeObj){
    this->CalSeconed();
    timeObj.CalSeconed();
    if(this->t_sec <= timeObj.t_sec){
        return true;
    }
    return false;
}
bool Time::operator>=(Time timeObj){
    this->CalSeconed();
    timeObj.CalSeconed();
    if(this->t_sec >= timeObj.t_sec){
        return true;
    }
    return false;   
}

int main(void){
    Time tt;
    std::cout << tt.getTimeStr() << std::endl;
    tt.setHour(5);
    tt.setMin(48);
    tt.setSec(23);
    std::cout << tt.getTimeStr() << std::endl;

    Time t2(4,50,23);
    
    std::cout << "초(sec)로 환산된 값은 : " << tt.CalSeconed() << std::endl;

    if(tt>=t2){
        std::cout << tt.getTimeStr() << "이 " << t2.getTimeStr() << "보다 크거나 같다!!" << std::endl;
    }else{
        std::cout << t2.getTimeStr() << "이 " << tt.getTimeStr() << "보다 크거나 같다!!" << std::endl;   
    }


    return 0;
}