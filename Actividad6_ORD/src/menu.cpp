// Archivo de Implementacion de la clase Menu
#include "menu.hpp"

using namespace std;

//: state(1)
Menu::Menu() {
  this->Interface();
}

Menu::Menu(const Menu& m) : songs(m.songs) {}

void Menu::Interface() {
  int option(0);

  while (option != 6) {
    cout << "1. Agregar cancion." << endl;
    cout << "2. Mostrar Lista de Canciones." << endl;
    cout << "3. Buscar cancion." << endl;
    cout << "4. Eliminar cancion de la lista." << endl;
    cout << "5. Vaciar Lista." << endl;
    cout << "6. Salir" << endl;
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
        this->deleteSong();
        break;
      case 5:
        this->songs.deleteAll();
        break;
      case 6:
        cout << "Saliendo..." << endl;
        break;
      default:
        cout << "Opcion invalida." << endl;
        break;
    }
  }
  getchar();
}

void Menu::showList() {
  system("CLS");
  cout << "Lista de Canciones:" << endl;
  cout << "Nombre \tAutor \tInterprete \tArchivo \tRanking" << endl;
  if (this->songs.isEmpty()) {
    cout << "Aun no hay canciones en la lista." << endl;
  } else {
    cout << songs.toString() << endl;
  }
}

void Menu::addSong() {
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

void Menu::findSong() {
  string sName;
  int findMethod, findOption;

  cout << "Buscar por nombre o por interprete(1/2): ";
  cin >> findOption;

  cout << "Busqueda Lineal o Binaria?(1/2): ";
  cin >> findMethod;

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

void Menu::insertNewSong(const Song& s) {
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

void Menu::deleteSong() {
  cout << "Ingresa la posicion de la cancion de quieres eliminar: ";
  cin >> pos;

  try {
    songs.deleteData(pos);
  } catch (const List<Song>::Exception& e) {
    cout << e.what() << endl;
  }

  cout << "Cancion Eliminada." << endl;
}