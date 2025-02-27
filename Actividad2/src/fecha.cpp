#include "fecha.hpp"
using namespace std;

Fecha::Fecha() {}

Fecha::Fecha(const Fecha& f) : day(f.day), month(f.month), year(f.year) {}

void Fecha::setDay(const int& d){
    if(d < 31 && d > 1){
        this->day = d;
    }
}

void Fecha::setMonth(const int& m){
    if(m > 1 && m <= 12){
        this->month = m;
    }
}

void Fecha::setYear(const int& y){
    this->year = y;
}

string Fecha::toString() const {
    string date;
    if(this->day < 10){
        date+= "0" + to_string(this->day) + "/";
    }else{
        date+= this->day + "/";
    }
    if(this->month < 10){
        date+= "0" + to_string(this->month) + "/";
    }else{
        date+= to_string(this->month) + "/";
    }
    date+= to_string(this->year);
}

int Fecha::getDay() const {
    return this->day;
}

int Fecha::getMonth() const{
    return this->month;
}

int Fecha::getYear() const {
    return this->year;
}