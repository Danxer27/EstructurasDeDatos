//Archivo de Implementacion de la clase Interface
#include "interface.hpp"
using namespace std;

Interface::Interface(List<Recipe,3000>& l){
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
        this->saveToDiskRecipes();
        break;
     case 8:
        this->readFromDiskRecipes();
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

    fflush(stdin);
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

        try {
          temp_list_ingredients.insertData(temp_list_ingredients.getLastPos(), temp_ingredient);
        } catch (const List<Ingredient>::Exception& e) {
          cout << e.what() << endl;
        }

        return;
        cout << "Quieres añadir mas ingredientes(s/n): ";
        cin>>option;
    }while(option != 'n');

    temp_list_ingredients.sortDataQuick(Ingredient::comapreByName);

    try {
      temp_recipe.setIngredients(temp_list_ingredients);
    } catch (const List<Recipe>::Exception& e) {
      cout << e.what() << endl;
    }
    
    char recipe_option;
    cout << "Quieres añadir mas recetas(s/n): ";
    cin>>recipe_option;

    if(recipe_option != 'n'){
        this->addRecipe();
    }
}

//Caso de que se quiera modificar desde el menu sin conocer una receta especifica
void Interface::modifyRecipe(){ 
  int recipe_pos;

  //AÑADIR VERIFICACION SI YA HAY RECETAS

  cout << "Ingresa el numero de receta que deseas moidificar: ";
  cin >> recipe_pos;

  this->modifyRecipe(recipes->retrieve(recipe_pos));

}

void Interface::modifyRecipe(Recipe& p){
  int option, h,m,s, ing_option, ing_pos, temp_num, ing_mod;
  string temp_st;
  Time temp_time;
  string temp_author_name, temp_author_lname;
  Name temp_name;
  char againOption, option_add, temp_char;

    cout << "Que queires modificar de la receta: "<< endl 
    << "1. Nombre de la receta." << endl
    << "2. Ingredientes." << endl 
    << "3. Tiempo de preparacion." << endl 
    << "4. Proceso de preparacion." << endl 
    << "5. Nombre del autor." << endl
    << "Opcion: ";
    cin >> option;
    
    switch (option) {
    case 1:
      fflush(stdin);
      cout<< "Ingresa el nuevo nombre de la receta:";
      getline(cin, temp_st);
      p.setRecipeName(temp_st);
        break;
    case 2:
      cout << "Tiempo de preparacion( HH MM SS ): ";
      cin >> h >> m >> s;

      p.setPrepTime(h,m,s);

      break;
    case 3:
      cout << "Que te gustaria cambiar en los ingredientes?:" << endl
      << "1. Agregar un ingrediente. " << endl
      << "2. Eliminar un ingrediente." << endl
      << "3. Eliminar todos los ingredientes." << endl
      << "4. Modificar un ingrediente." << endl
      << "Opcion:";
      cin >> ing_mod;

      switch (ing_mod) {
        case 1:
        //ANADIR PARA agregar ingredientes
            do{
              cout << "Quieres añadir mas ingredientes(s/n): ";
              cin >> option_add;
          }while(option_add != 'n');

          break;
        case 2:
        //añadir codigo para eliminar
          break;

        case 3:
        //añadir codigo para vaciar
          break;
      
        case 4:

          cout << "Que numero de ingrediente quieres modificar?: ";
          cin >> ing_pos;

          cout << "Que quieres modificar de este ingrediente?:" << endl
          << "1. Nombre." << endl
          << "2. Cantidad." << endl
          << "3. Unidad de Medida." << endl
          << "Opcion:";
          cin >> ing_option;
          // ANADIR VERIFICACION
          switch (ing_option) {
            case 1:
              fflush(stdin);
              cout<< "Ingresa el nuevo nombre del ingrediente:";
              getline(cin, temp_st);

              // p.getIngredient(ing_option).setName(temp_st);
              p.getIngredients().retrieve(ing_pos).setName(temp_st);
              break;
            case 2:
              cout << "Ingrese la nueva cantidad:";
              cin >> temp_num;

              p.getIngredients().retrieve(ing_pos).setAmount(temp_num);
              // p.getIngredient(ing_option).setAmount(temp_num);
            case 3:
              fflush(stdin);
              cout<< "Ingresa la nueva unidad de medida:";
              getline(cin, temp_st);

              // p.getIngredient(ing_option).setName(temp_st);
              p.getIngredients().retrieve(ing_pos).setMeasurementUnit(temp_st);
            default:
              cout << "Opcion no valida." << endl;
              break;
          }
          break;
      default:
        break;
      }
    case 4:
        cout << "Escribe el proces de la receta, cuando termines de escribir ingresa '~' para conclurir: ";
        do{
            cin >> temp_char;
            temp_st += temp_char;
        }while(temp_char != '~');

        p.setProcess(temp_st); 
        
        break;
    case 5:

        fflush(stdin);
        cout<< "Ingresa nuevo nombre del autor:";
        getline(cin, temp_author_name);
        cout<< "Ingresa nuevo apellido del autor:";
        getline(cin, temp_author_lname);

        temp_name.setFirst(temp_author_name);
        temp_name.setLast(temp_author_lname);

        p.setAuthor(temp_name);

        break;
    
    default:
        cout << "Opcion invalida." << endl;
        this->modifyRecipe(p);
        break;
    }

    cout << "Quieres modificar alguna otra cosa de la receta? (s/n): ";
    cin >> againOption;
    if(againOption != 'n'){
      this->modifyRecipe(p);
    }
}

void Interface::deleteRecipe(){
  
}

void Interface::showRecipes(){
  system("cls");
  cout << "Lista de Recetas:" << endl;
  // stringstream ss;
  // ss << left << setw(20) << "Nombre" << left << setw(20) << "Autor" << left
  //    << setw(20) << "Interprete" << left << setw(30) << "Archivo.MP3" << left
  //    << setw(10) << "Ranking";
  // cout << ss.str() << endl;

  if (recipes->isEmpty()) {
    cout << "Aun no hay recetas en la lista." << endl;
  } else {
    cout << recipes->toString() << endl;
  }
}

void Interface::findRecipe(){
}

void Interface::sortRecipes(){
  int option;
  cout << "Deseas ordenar por Nombre o por tiempo de preparacion?(1/2):";
  
  option == 1 ? recipes->sortDataQuick(Recipe::compareByRecipeName) : recipes->sortDataQuick(Recipe::compareByPrepTime);

  this->showRecipes();
  
}


void Interface::saveToDiskRecipes(){
  string fileName;
  cout << "Nombre del archivo: ";
  cin >> fileName;

  ofstream myFile;

  myFile.open(fileName, ios_base::trunc);

  if(!myFile.is_open()){
    cout << "No se pudo abrir el archivo para escritura";
    return;
  }

  int i(0);

  while(i <= recipes->getLastPos()){
    myFile << recipes->retrieve(i) << '#';

    i++;
  }

  myFile.close();

}

void Interface::readFromDiskRecipes(){

}