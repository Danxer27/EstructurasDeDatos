#ifndef __INGREDIENT_HPP__
#define __INGREDIENT_HPP__
#include <string>
#include "list.hpp"

class Ingredient {
    private:
        std::string name;
        float amount;
        std::string measureUnit;
    public:
        Ingredient();
        Ingredient(const Ingredient&);

        void setName(const std::string&);
        void setAmount(const float&);
        void setMeasurementUnit(const std::string&);

        std::string getName() const;
        float getAmount() const;
        std::string getUnit() const;

        std::string toString();

        Ingredient& operator=(const Ingredient&);

        bool operator==(const Ingredient&) const;
        bool operator!=(const Ingredient&) const;
        bool operator<=(const Ingredient&) const;
        bool operator>=(const Ingredient&) const;
        bool operator<(const Ingredient&) const;
        bool operator>(const Ingredient&) const;

        int compareTo(const Ingredient&);
        static int compare(const Ingredient&, const Ingredient&);
        static int comapreByName(const Ingredient&, const Ingredient&);
        static int compareByAmount(const Ingredient&, const Ingredient&);
};






#endif //__INGREDIENT_HPP__