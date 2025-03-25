#ifndef __RECIPE_HPP__
#define __RECIPE_HPP__
#include <string>
#include "listTD.hpp"
#include "ingredient.hpp"
#include "time.hpp"
#include "name.hpp"


class Recipe {
    private:
        std::string recipeName;
        List<Ingredient> ingredients;
        Time prepTime;
        std::string process;
        Name author;
    public:
        Recipe();
        Recipe(const Recipe&);

        void setRecipeName(const std::string&);
        void setIngredients(const Ingredient&);
        void setPrepTime(const int&, const int&, const int&);
        void setProcess(const std::string&);
        void setAuthor(const Name&);

        void addProcessStep(const std::string&);

        std::string getRecipeName() const;
        std::string getIngredients();
        Ingredient getIngredient(const int&);
        std::string getPrepTime();
        std::string getProcess() const;
        Name getAuthor() const;

        std::string toString() const;

        bool operator==(const Recipe&);
        bool operator!=(const Recipe&);
        bool operator<(const Recipe&);
        bool operator<=(const Recipe&);
        bool operator>(const Recipe&);
        bool operator>=(const Recipe&);

        int comapreTo(const Recipe&);
        static int compare(const Recipe&, const Recipe&);
        static int compareByRecipeName(const Recipe&, const Recipe&);
        static int compareByIngredients(const Recipe&, const Recipe&);
        static int comapreByPrepTime(Recipe&, Recipe&);
        static int compareByAuthor(const Recipe&, const Recipe&);

};


#endif //__RECIPE_HPP__