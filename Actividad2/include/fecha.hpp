#include <string>

class Fecha{
    private:
        int day;
        int month;
        int year;
    public:
        Fecha();
        Fecha(const Fecha&);

        void setDay(const int&);
        void setMonth(const int&);
        void setYear(const int&);

        std::string toString() const;

        int getDay() const;
        int getMonth() const;
        int getYear() const;

};