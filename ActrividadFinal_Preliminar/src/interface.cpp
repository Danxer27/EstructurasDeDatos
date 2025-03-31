//Archivo de Implementacion de la clase Interface
#include "interface.hpp"
using namespace std;

Interface::Interface(List<Recipe,3000>& l)  {
    this->recipes = &l;
    this->Menu();
}

void Interface::Menu(){
    int option(1);

  while (option != 0) {
    cout << "1. Agregar Receta." << endl;
    cout << "2. Modificar Receta." << endl;
    cout << "3. Eliminar Receta." << endl;
    cout << "4. Mostrar Recetas." << endl;
    cout << "5. Buscar Recetas." << endl;
    cout << "6. Ordenar Recetas." << endl;
    cout << "7. Eliminar todas las recetas." << endl;
    cout << "8. Guardar en Disco." << endl;
    cout << "9. Leer del Disco." << endl;
    cout << "0. Salir" << endl;
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
        this->showRecipes(false);
        break;
      case 5:
        this->findRecipe();
        break;
     case 6  :
        this->sortRecipes();
        break;
      case 7:
        this->deleteAllRecipes();
        break;
     case 8:
        this->saveToDiskRecipes();
        break;
     case 9:
        this->readFromDiskRecipes();
        break;
      case 0:
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
    int hours, minutes, seconds, cathegory;
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
      temp_process += temp_char;
        cin >> temp_char;
    }while(temp_char != '~');

    fflush(stdin);
    cout<< "Ingresa nombre del autor:";
    getline(cin, temp_author_name);
    cout<< "Ingresa apellido del autor:";
    getline(cin, temp_author_lname);

    temp_author_full_name.setFirst(temp_author_name);
    temp_author_full_name.setLast(temp_author_lname);

    cout << "Selecciona la categoria de la receta: " << endl
    << "1. Desayno." << endl
    << "2. Comida." << endl
    << "3. Cena." << endl
    << "4. Navidenia." << endl
    << "Opcion: ";
    cin >> cathegory;

      switch (cathegory){
      case 1:
        temp_recipe.setCathegory("Desayuno");
        break;
      case 2:
        temp_recipe.setCathegory("Comida");
        break;
      case 3:
        temp_recipe.setCathegory("Cena");
        break;
      case 4:
        temp_recipe.setCathegory("Navidenia");
        break;
      default:
        temp_recipe.setCathegory("None");
        break;
      }



    //Añadiendo todo a la receta
    temp_recipe.setRecipeName(temp_recipe_name);
    temp_recipe.setPrepTime(hours, minutes, seconds);
    temp_recipe.setProcess(temp_process);
    temp_recipe.setAuthor(temp_author_full_name);

    //Añadiendo Ingredientes
    List<Ingredient> temp_list_ingredients;
    Ingredient temp_ingredient;
    char option;
    
    do{
      temp_ingredient = this->addIngredient();

      try {
        temp_list_ingredients.insertData(temp_list_ingredients.getLastPos(), temp_ingredient);
      } catch (const List<Ingredient>::Exception& e) {
        cout << e.what() << endl;
      }
        cout << "Quieres añadir mas ingredientes(s/n): ";
        cin>>option;

    }while(option == 's');

    temp_list_ingredients.sortDataQuick(Ingredient::comapreByName);

    temp_recipe.setIngredients(temp_list_ingredients);
    
    try {
      recipes->insertData(recipes->getLastPos(), temp_recipe);
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

Ingredient& Interface::addIngredient(){
    Ingredient temp_ingredient;
    string temp_ingredient_name, temp_unit;
    double temp_amount;

    fflush(stdin);
    cout << "Ingresa el nombre del ingrediente: ";
    getline(cin, temp_ingredient_name);
    cout << "Ingresa la cantidad y su unidad( 00 kg ): ";
    cin >> temp_amount >> temp_unit;
    temp_ingredient.setName(temp_ingredient_name);
    temp_ingredient.setAmount(temp_amount);
    temp_ingredient.setMeasurementUnit(temp_unit);
    
    return temp_ingredient;
}



//Caso de que se quiera modificar desde el menu sin conocer una receta especifica
void Interface::modifyRecipe(){ 
  int recipe_pos;

  if(recipes->isEmpty()){
    cout << "Aun no hay recetas para modificar." << endl;
    
  }else {
 
    cout << "Ingresa el numero de receta que deseas moidificar: ";
    cin >> recipe_pos;
    
    this->modifyRecipe(recipes->retrieve(recipe_pos));
    
  }
}


//Modificar alguna receta y algun ingrediente
void Interface::modifyRecipe(Recipe& p){
  int option, h,m,s, ing_option, ing_pos, temp_num, ing_mod;
  string temp_st;
  Time temp_time;
  string temp_author_name, temp_author_lname;
  Name temp_name;
  char againOption, option_add, temp_char;
  Ingredient temp_ingredient;

  if(recipes->isEmpty()){
    cout << "Aun no hay recetas para modificar." << endl;
    return;
  }

    cout << "Que queires modificar de la receta: "<< endl 
    << "1. Nombre de la receta." << endl
    << "2. Ingredientes." << endl 
    << "3. Tiempo de preparacion." << endl 
    << "4. Proceso de preparacion." << endl 
    << "5. Nombre del autor." << endl
    << "6. Categoria." << endl
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

            do{
              p.addIngredient(this->addIngredient());
              cout << "Quieres añadir mas ingredientes(s/n): ";
              cin >> option_add;

          }while(option_add != 'n');

          break;
        case 2:
          int posIng;
          if(p.getIngredients().isEmpty()){
            cout << "Aun no hay ingredientes eliminar para buscar. "<<endl;
            break;
          }
        
          cout << "Ingresa la posicion del ingrediente de quieres eliminar: ";
          cin >> posIng;
          
          try {
            p.getIngredients().deleteData(posIng);
          } catch (const List<Recipe>::Exception& e) {
            cout << e.what() << endl;
          }
        
          cout << "Ingrediente Eliminado." << endl;
          break;

        case 3:
          p.getIngredients().deleteAll();
          cout << "Ingredientes Eliminados." << endl;

          break;
      
        case 4:
          if(p.getIngredients().isEmpty()){
            cout << "Esta receta aun no contiene ingredientes para modificar." << endl;
            break;
          }

          cout << "Que numero de ingrediente quieres modificar?: ";
          cin >> ing_pos;

          cout << "Que quieres modificar de este ingrediente?:" << endl
          << "1. Nombre." << endl
          << "2. Cantidad." << endl
          << "3. Unidad de Medida." << endl
          << "Opcion:";
          cin >> ing_option;
      
          switch (ing_option) {
            case 1:
              fflush(stdin);
              cout<< "Ingresa el nuevo nombre del ingrediente:";
              getline(cin, temp_st);

              p.getIngredients().retrieve(ing_pos).setName(temp_st);
              break;
            case 2:
              cout << "Ingrese la nueva cantidad:";
              cin >> temp_num;

              p.getIngredients().retrieve(ing_pos).setAmount(temp_num);
          
            case 3:
              fflush(stdin);
              cout<< "Ingresa la nueva unidad de medida:";
              getline(cin, temp_st);

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
    case 6:
      int cat;
      fflush(stdin);
      cout<< "Ingresa la nueva categoria:" << endl
      << "1. Desayno." << endl
      << "2. Comida." << endl
      << "3. Cena." << endl
      << "4. Navidenia." << endl
      << "Opcion: ";
      cin >> cat;

      
      switch (cat){
        case 1:
          p.setCathegory("Desayuno");
          break;
        case 2:
          p.setCathegory("Comida");
          break;
        case 3:
          p.setCathegory("Cena");
          break;
        case 4:
          p.setCathegory("Navidenia");
          break;
        default:
          p.setCathegory("None");
          break;
        }

      break;
    
    default:
        cout << "Opcion invalida." << endl;
        this->modifyRecipe(p);
        break;
    }

    cout << "Quieres modificar alguna otra cosa de la receta? (s/n): ";
    cin >> againOption;
    if(againOption == 's'){
      this->modifyRecipe(p);
    }
}

void Interface::deleteRecipe(){
  int pos;
  if(recipes->isEmpty()){
    cout << "Aun no hay canciones para buscar. "<<endl;
    this->Menu();
  }

  cout << "Ingresa la posicion de la receta de quieres eliminar: ";
  cin >> pos;
  
  try {
    recipes->deleteData(pos);
  } catch (const List<Recipe>::Exception& e) {
    cout << e.what() << endl;
  }

  cout << "Receta Eliminada." << endl;
}

void Interface::deleteAllRecipes(){
  recipes->deleteAll();
  cout << "Recetario vaciado." << endl;
  return;
}

void Interface::showRecipes(const bool& ask){
  system("cls");
  
  int i(0), j(0);
  string cat;
  if (recipes->isEmpty()) {
    cout << "Aun no hay recetas en la lista por mostrar." << endl;
  } else {
    cout << "Lista de Recetas:" << endl; 
    if(ask){
      cout << "Quieres buscar recetas por alguna categoria?(No: 'n', Si: #<Categoria>): ";
      cin.ignore();
      getline(cin, cat);

      if(cat[0] != 'n' && cat.length() < 3){
        while(i < recipes->getLastPos()){
          cout << recipes->retrieve(i).toString() << endl;
          j++;
        }
        if(j == 0){
          cout << "Ninguna receta encontrada con la categoria: " << cat << endl;
        }
      } else {
        cout << recipes->toString() << endl;
      }
    }else{
      cout << recipes->toString() << endl;
    }
    
  }
}

void Interface::findRecipe(){
  string sName;
  int findMethod, findOption, pos;
  char doSort;
  Recipe temp_recipe;
  
  if(recipes->isEmpty()){
    cout << "Aun no hay recetas para buscar. "<<endl;
    return;
  }

  cout << "Buscar por nombre de la receta o por categoria(1/2): ";
  cin >> findOption;
  
  if (findOption == 1) {
    cout << "Ingrese el nombre de la receta a buscar: ";
    fflush(stdin);
    getline(cin, sName);
    temp_recipe.setRecipeName(sName);
  } else {
    cout << "Ingrese la categoria de la receta a buscar: ";
    cin >> sName;
    temp_recipe.setCathegory(sName);
  }
  
  if (findOption == 1) {
    
      (recipes->isSorted(Recipe::compareByRecipeName)) ? pos = recipes->findDataBin(temp_recipe, Recipe::compareByRecipeName) :pos = recipes->findDataLin(temp_recipe, Recipe::compareByRecipeName);

  } else {

      pos = recipes->findDataBin(temp_recipe, Recipe::compareByCathergory);
      if(pos == -1){
        pos = recipes->findDataLin(temp_recipe, Recipe::compareByCathergory);
      }
  }
  if (pos == -1) {
    cout << "\nCancion no encontrada" << endl;
  } else {
    cout << "\nLa cancion en la posicion " << pos
    << " es: " << recipes->retrieve(pos).toString() << endl;
  }
}

void Interface::sortRecipes(){
  int option(0);

  if(recipes->isEmpty()){
    cout << "Aun no hay recetas para ordenar." << endl;
    return;
  }

  cout << "Deseas ordenar por Nombre o por tiempo de preparacion?(1/2):";
  cin >> option;

  if(option == 1) recipes->sortDataQuick(Recipe::compareByRecipeName);
  else recipes->sortDataQuick(Recipe::compareByPrepTime);

  this->showRecipes(false);
  
}


void Interface::saveToDiskRecipes(){

  if(recipes->isEmpty()){
    cout << "Aun no hay recetas para guardar." << endl;
    return;
  }

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