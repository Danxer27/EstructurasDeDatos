//Archivo de definicion de la clase Interfaz
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include <fstream>
#include <iostream>
#include "listTD.hpp"
#include "recipe.hpp"
#include "time.hpp"



class Interface {
    private:
        List<Recipe,3000>* recipes;
        bool is_Sorted;
    public:
        Interface(List<Recipe,3000>&);

        void Menu();
        
        void addRecipe();
        Ingredient& addIngredient();
        void modifyRecipe();
        void modifyRecipe(Recipe&);
        void deleteRecipe();
        void deleteAllRecipes();
        void showRecipes(const bool&);
        void findRecipe();
        void sortRecipes();
        void saveToDiskRecipes();
        void readFromDiskRecipes();

};


#endif //__INTERFACE_HPP__