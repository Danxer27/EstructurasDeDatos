#include "time.hpp"
using namespace std;


Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(const Time&) {}

void Time::setHours(const int& h){
    this->hours = h;
}

void Time::setMinutes(const int& m){
    if(this->exceeds(m)){
        this->minutes = m & 60;
        this->hours += m / 60;
    }
    this->minutes = m;
}

void Time::setSeconds(const int& s){
    if(this->exceeds(s)){
        this->seconds = s & 60;
        this->minutes += s / 60;
    }
    this->seconds = s;
}

int Time::getOnlyHours() const{
    return this->hours;
}

int Time::getOnlyMinutes() const {
    return this->minutes;
}

int Time::getOnlySeconds() const {
    return this->seconds; 
}

double Time::getHours() const {
    double hoursTime =  this->hours + (this->minutes / 60) + ((this->seconds / 60) / 10);
    return hoursTime;
}

double Time::getMinutes() const {
    double minTime = (this->hours * 60) + this->minutes + (this->seconds / 60);
    return minTime;
}

int Time::getSeconds() const {
    return (((this->hours * 60) + this->minutes) * 60) + this->seconds;
}

std::string Time::toString(){
    return to_string(this->getHours()) + ":" + to_string(this->getMinutes()) + ":" + to_string(this->getSeconds());
}

bool Time::exceeds(const int& e){
    if(e > 59) return true;
    else return false;
}

//### Operadores Logicos

bool Time::operator== (const Time& e) const{
    return this->getSeconds() == e.getSeconds();
}

bool Time::operator!= (const Time& e) const{
    return !(*this == e);
}

bool Time::operator> (const Time& e) const{
    return this->getSeconds() > e.getSeconds();
}

bool Time::operator>= (const Time& e) const {
    return *this == e || *this > e;
}

bool Time::operator<(const Time& e) const{
    return !(*this >= e);
}

bool Time::operator<=(const Time& e) const{
    return !(*this > e);
}

//### Operadores Aritmeticos


int Time::operator+ (const Time& t){
    return this->seconds + t.seconds;
}

void Time::operator+= (const Time& t){
    this->setSeconds(getSeconds() + t.getSeconds());
}

int Time::operator- (const Time& t){
    return this->getSeconds() - t.getSeconds();
}

void Time::operator-= (const Time& t){
    this->setSeconds(getSeconds() - t.getSeconds());
}

int Time::operator* (const Time& t){
    return this->getSeconds() * t.getSeconds();
}

void Time::operator*= (const Time& t){
    this->setSeconds(getSeconds() * t.getSeconds());
}

float Time::operator/ (const Time& t){
    return this->getSeconds() / t.getSeconds();
}

void Time::operator/= (const Time& t){
    this->setSeconds(getSeconds() / t.getSeconds());
}

//Comparadores

int Time::compareTo(const Time& e){
    this->getSeconds() - e.getSeconds();
}

int Time::compareBySeconds(const Time& a, const Time& b){
    return a.getOnlySeconds() - b.getOnlySeconds();
}

int Time::compareByMinutes(const Time& a, const Time& b){
    return a.getOnlyMinutes() - b.getOnlyMinutes();
}

int Time::compareByHours(const Time& a, const Time& b){
    return a.getOnlyHours() - b.getOnlyHours();
}

