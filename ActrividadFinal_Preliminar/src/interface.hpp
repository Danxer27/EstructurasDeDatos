//Archivo de definicion de la clase Interfaz
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include "list.hpp"
#include "recipe.hpp"
#include "time.hpp"


class Interface {
    private:
        List<Recipe>* recipes;
    public:
        Interface(List<Recipe>&);

        void Menu();
        
        void addRecipe();
        void modifyRecipe();
        void deleteRecipe();
        void showRecipes();
        void findRecipe();
        void sortRecipes();
        void saveRecipes();
        void readRecipes();

};


#endif //__INTERFACE_HPP__