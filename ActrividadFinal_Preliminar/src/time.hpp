#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <string>

class Time {
    private:
        int hours;
        int minutes;
        int seconds;

        bool exceeds(const int&);

    public:
        Time();
        Time(const Time&); 

        void setHours(const int&);
        void setMinutes(const int&);
        void setSeconds(const int&);

        int getOnlyHours() const;
        int getOnlyMinutes() const;
        int getOnlySeconds() const;
        double getHours() const;
        double getMinutes() const;
        int getSeconds() const;

        std::string toString();

        bool operator==(const Time&) const;
        bool operator!=(const Time&) const;
        bool operator>(const Time&) const;
        bool operator>=(const Time&) const;
        bool operator<(const Time&) const;
        bool operator<=(const Time&) const;

        void operator+ (const int&);
        void operator- (const int&);

        int compareTo(const Time&);
        static int compareBySeconds(const Time&, const Time&);
        static int compareByMinutes(const Time&, const Time&);
        static int compareByHours(const Time&, const Time&);


};



#endif //__TIME_HPP__