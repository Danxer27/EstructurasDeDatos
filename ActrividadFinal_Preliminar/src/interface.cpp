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
    string temp_recipe_name, temp_author_name, temp_author_lname;
    int hours, minutes, seconds;
    char temp_char;
    

    fflush(stdin);
    cout << "Introduce la informacion de la Receta." << endl;
    cout << "Nombre de la Receta: ";
    getline(cin, temp_recipe_name);

    cout << "Tiempo de preparacion( HH MM SS ): ";
    cin >> hours >> minutes >> seconds;

    cout << "Escribe el proces de la receta, cuando termines de escribir ingresa '~' para conclurir: ";
    do{
        cin >> temp_char;
    }while(temp_char != '~');

    cout<< "Ingresa nombre del autor:";
    getline(cin, temp_author_name);
    cout<< "Ingresa apellido del autor:";
    getline(cin, temp_author_lname);

    


}