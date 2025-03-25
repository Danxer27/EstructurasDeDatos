//Archivo de Implementacion de la clase Interface
#include "interface.hpp";
using namespace std;

Interface::Interface(List<Recipe>& l){
    this->recipes = &l;
    this->Menu();
}

void Interface::Menu(){
    int option(0);

  while (option != 9) {
    cout << "1. Agregar Receta." << endl;
    cout << "2. Modificar Receta." << endl;
    cout << "3. Eliminar Receta." << endl;
    cout << "4. Mostrar Recetas." << endl;
    cout << "5. Buscar Recetas." << endl;
    cout << "6. Ordenar Recetas." << endl;
    cout << "7. Guardar en Disco." << endl;
    cout << "8. Leer del Disco." << endl;
    cout << "9. Salir" << endl;
    cout << "Opcion: ";
    cin >> option;
    cout << endl;

    switch (option) {
      case 1:
        this->addRecipe();
        break;
      case 2:
        this->modifyRecipe();
        break;
      case 3:
        this->deleteRecipe();
        break;
      case 4:
        this->showRecipes();
        break;
      case 5:
        this->findRecipe();
        break;
     case 6  :
        this->sortRecipes();
        break;
     case 7:
        this->saveRecipes();
        break;
     case 8:
        this->readRecipes();
        break;
      case 9:
        cout << "Saliendo..." << endl;
        break;
      default:
        cout << "Opcion invalida." << endl;
        break;
    }
  }
  getchar();
}

void Interface::addRecipe(){
    string temp_recipe_name, temp_author_name, temp_author_lname, temp_process("");
    int hours, minutes, seconds;
    char temp_char;
    Name temp_author_full_name;
    Time temp_prepTime;
    Recipe temp_recipe;

    fflush(stdin);
    cout << "Introduce la informacion de la Receta." << endl;
    cout << "Nombre de la Receta: ";
    getline(cin, temp_recipe_name);

    cout << "Tiempo de preparacion( HH MM SS ): ";
    cin >> hours >> minutes >> seconds;


    cout << "Escribe el proces de la receta, cuando termines de escribir ingresa '~' para conclurir: ";
    do{
        cin >> temp_char;
        temp_process += temp_char;
    }while(temp_char != '~');

    cout<< "Ingresa nombre del autor:";
    getline(cin, temp_author_name);
    cout<< "Ingresa apellido del autor:";
    getline(cin, temp_author_lname);

    temp_author_full_name.setFirst(temp_author_name);
    temp_author_full_name.setLast(temp_author_lname);

    //Añadiendo todo a la receta
    temp_recipe.setRecipeName(temp_recipe_name);
    temp_recipe.setPrepTime(hours, minutes, seconds);
    temp_recipe.setProcess(temp_process);
    temp_recipe.setAuthor(temp_author_full_name);

    //Añadiendo Ingredientes
    List<Ingredient> temp_list_ingredients;
    Ingredient temp_ingredient;
    string temp_ingredient_name, temp_unit;
    double temp_amount;
    char option;
    fflush(stdin);

    do{
        cout << "Ingresa el nombre del ingrediente: ";
        getline(cin, temp_ingredient_name);
        cout << "Ingresa la cantidad y su unidad( 00 kg ): ";
        cin >> temp_amount >> temp_unit;

        temp_ingredient.setName(temp_ingredient_name);
        temp_ingredient.setAmount(temp_amount);
        temp_ingredient.setMeasurementUnit(temp_unit);

        temp_list_ingredients.insertData(temp_list_ingredients.getLastPos(), temp_ingredient);

        cout << "Quieres añadir mas ingredientes(s/n): ";
        cin>>option;
    }while(option != 'n');

    temp_recipe.setIngredients(temp_list_ingredients);
    
    char recipe_option;
    cout << "Quieres añadir mas recetas(s/n): ";
    cin>>recipe_option;

    if(recipe_option != 'n'){
        this->addRecipe();
    }
}