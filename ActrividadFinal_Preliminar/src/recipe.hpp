#ifndef __RECIPE_HPP__
#define __RECIPE_HPP__
#include <string>
#include "list.hpp"
#include "ingredient.hpp"
#include "time.hpp"


class Recipe {
    private:
        List<Ingredient> ingredients;
        Time prepTime;
        std::string process;
        std::string author;
    public:
        Recipe();
        Recipe(const Recipe&);

        void setIngredients(const Ingredient&);
        void setPrepTime(const int&, const int&, const int&);
        void setProcess(const std::string&);
        void setAuthor(const std::string&);

        void addProcessStep(const std::string&);

        std::string getIngredients();
        Ingredient getIngredient(const int&);
        std::string getPrepTime();
        std::string getProcess();
        std::string getAuthor();

        std::string toString();

        bool operator==(const Recipe&);
        bool operator!=(const Recipe&);
        bool operator<(const Recipe&);
        bool operator<=(const Recipe&);
        bool operator>(const Recipe&);
        bool operator>=(const Recipe&);

        int comapreTo(const Recipe&);
        static int compare(const Recipe&, const Recipe&);
        static int compareByIngredients(/*PENDING TO ADD*/);
        static int comapreByPrepTime(/*PENDING TO DECIDE*/);
        static int compareByAuthor(const std::string&, const std::string());

};


#endif //__RECIPE_HPP__