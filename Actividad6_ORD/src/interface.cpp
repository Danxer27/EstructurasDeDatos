// Archivo de Implementacion de la clase Interface
#include "interface.hpp"

using namespace std;

Interface::Interface() : isSorted(false) {
  this->Menu();
}

Interface::Interface(const Interface& m) : songs(m.songs) {}

void Interface::Menu() {
  int option(0);

  while (option != 7) {
    cout << "1. Agregar cancion." << endl;
    cout << "2. Mostrar Lista de Canciones." << endl;
    cout << "3. Buscar cancion." << endl;
    cout << "4. Ordenar Lista. " << endl;
    cout << "5. Eliminar cancion de la lista." << endl;
    cout << "6. Vaciar Lista." << endl;
    cout << "7. Salir" << endl;
    cout << "Opcion: ";
    cin >> option;
    cout << endl;

    switch (option) {
      case 1:
        this->addSong();
        break;
      case 2:
        this->showList();
        break;
      case 3:
        this->findSong();
        break;
      case 4:
        this->sortList();
        break;
      case 5:
        this->deleteSong();
        break;
      case 6:
        this->songs.deleteAll();
        break;
      case 7:
        cout << "Saliendo..." << endl;
        break;
      default:
        cout << "Opcion invalida." << endl;
        break;
    }
  }
  getchar();
}


void Interface::addSong() {
  string song_name;
  string author;
  string interpreter;
  int ranking;
  
  fflush(stdin);
  cout << "Introduce los datos de la cancion." << endl;
  cout << "Nombre de la cancion: ";
  getline(cin, song_name);
  cout << "Autor de la cancion: ";
  getline(cin, author);
  cout << "Interprete de la cancion: ";
  getline(cin, interpreter);
  cout << "Ranking de la cancion: ";
  cin >> ranking;
  cout << endl;
  
  temp_song.setSong(song_name);
  temp_song.setAuthor(author);
  temp_song.setInterpreter(interpreter);
  temp_song.setRanking(ranking);
  temp_song.generateMP3File();
  
  this->insertNewSong(temp_song);
  
  this->showList();
  
  char opcion;
  cout << endl << "Quieres agregar otra cancion?(s/n): " << endl;
  cin >> opcion;
  if (opcion == 's') {
    this->addSong();
  }
}

void Interface::insertNewSong(const Song& s) {
  char opcion;
  cout << "Quieres Agregarlo en una posicion especifica?(s/n): ";
  cin >> opcion;
  if (opcion == 's') {
    int pos;
    cout << "Introduce la posicion: ";
    cin >> pos;
    
    try {
      this->songs.insertData(pos - 1, s);
    } catch (const List<Song>::Exception& e) {
      cout << e.what() << endl;
    }
  } else {
    try {
      this->songs.insertData(this->songs.getLastPos(), s);
    } catch (const List<Song>::Exception& e) {
      cout << e.what() << endl;
    }
  }
}

  //Menu para ordenar Lista
void Interface::sortList(){
  short int sortMethod, sortOption;
  
  cout << "Quieres ordenar por Nombre de la cancion o por Nombre del interprete?(1/2):";
  cin >> sortOption;
  
  cout << "Con que metodo quieres ordenar la lista?: \n1. Burbuja \n2. Insercion \n3. Seleccion \n4. Shell by Factor\n5. Shell by Ciura\n :";
  cin >> sortMethod;
  
  switch (sortMethod) {
    case 1: //Bubble Sort
    sortOption ==  1 ? this->songs.sortDataBubble(Song::compareByName) : this->songs.sortDataBubble(Song::compareByInterpreter);
    break;
    case 2: //Insertion Sort
    sortOption ==  1 ? this->songs.sortDataInsert(Song::compareByName) : this->songs.sortDataInsert(Song::compareByInterpreter);
    break;
    case 3: //Selec Sort
    sortOption ==  1 ? this->songs.sortDataSelect(Song::compareByName) : this->songs.sortDataSelect(Song::compareByInterpreter);
    break;
    case 4: //Shell sort by factor
    sortOption ==  1 ? this->songs.sortDataShellFactor(Song::compareByName) : this->songs.sortDataShellFactor(Song::compareByInterpreter);
    break;
    case 5: //Shell sort by Ciura
    sortOption ==  1 ? this->songs.sortDataShellCiura(Song::compareByName) : this->songs.sortDataShellCiura(Song::compareByInterpreter);
    break;;
    default:
    cout << "Opcion invalida."<<endl;
    this->sortList();
    break;
  }
  this->isSorted = true;
  this->showList();
  
}


  //Menu para buscar una cancion.
void Interface::findSong() {
  string sName;
  int findMethod, findOption;
  char doSort;
  
  if(this->songs.isEmpty()){
    cout << "Aun no hay canciones para buscar. "<<endl;
    this->Menu();
  }

  cout << "Buscar por nombre o por interprete(1/2): ";
  cin >> findOption;
  
  cout << "Busqueda Lineal o Binaria?(1/2): ";
  cin >> findMethod;

  if(findMethod == 2){
    if(!this->isSorted){
      cout << "La lista no esta ordenada para trabajar con busqueda binaria, quieres ordenarla o continuar de todas maneras?:(1.Ordenar / 2. Continuar): ";
      cin >> doSort;
      if(doSort == 1){
        this->sortList();
      }
    }
  }
  
  if (findOption == 1) {
    Song::setState(1);  // Busca por nombre
    cout << "Ingrese el nombre de la cancion a buscar: ";
  } else {
    Song::setState(2);  // Busca por interprete
    cout << "Ingrese el nombre del interprete de la cancion a buscar: ";
  }
  
  cin.ignore();
  getline(cin, sName);
  
  temp_song.setSong(sName);
  
  if (findMethod == 1) {
    pos = this->songs.findDataLin(temp_song);
  } else {
    pos = this->songs.findDataBin(temp_song);
  }
  
  if (pos == -1) {
    cout << "\nCancion no encontrada" << endl;
  } else {
    cout << "\nLa cancion en la posicion " << pos
    << " es: " << this->songs.retrieve(pos).toString() << endl;
  }
}


void Interface::showList() {
  system("CLS");
  cout << "Lista de Canciones:" << endl;
  cout << "Nombre \tAutor \tInterprete \tArchivo \tRanking" << endl;
  if (this->songs.isEmpty()) {
    cout << "Aun no hay canciones en la lista." << endl;
  } else {
    cout << songs.toString() << endl;
  }
}


void Interface::deleteSong() {

  if(this->songs.isEmpty()){
    cout << "Aun no hay canciones para buscar. "<<endl;
    this->Menu();
  }

  cout << "Ingresa la posicion de la cancion de quieres eliminar: ";
  cin >> pos;
  
  try {
    songs.deleteData(pos);
  } catch (const List<Song>::Exception& e) {
    cout << e.what() << endl;
  }

  cout << "Cancion Eliminada." << endl;
}