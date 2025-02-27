// Archivo de Implementacion de la clase Menu
#include "menu.hpp"

using namespace std;

Menu::Menu() {
  this->Interface();
}

Menu::Menu(const Menu& m) : songs(m.songs) {}

void Menu::Interface() {
  int option(0);

  while (option != 5) {
    this->showList();

    cout << "1. Agregar cancion." << endl;
    cout << "2. Mostrar Lista de Canciones." << endl;
    cout << "3. Eliminar cancion de la lista." << endl;
    cout << "4. Vaciar Lista." << endl;
    cout << "5. Salir" << endl;
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
        this->deleteSong();
        break;
      case 4:
        this->songs.deleteAll();
        break;
      case 5:
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
  // system("cls");
  cout << "Lista de Canciones:" << endl;
  if (this->songs.isEmpty()) {
    cout << "Aun hay canciones en la lista." << endl;
  } else {
    cout << songs.toString() << endl;
  }
}

void Menu::addSong() {
  Song temp_song;
  string song_name = "Skyline";
  string author = "Daft Punk";
  string interpreter = "Daft Punk";
  int streams = 1000;

  fflush(stdin);
  cout << "Introduce los datos de la cancion." << endl;
  cout << "Nombre de la cancion: ";
  getline(cin, song_name);
  cout << "Autor de la cancion: ";
  getline(cin, author);
  cout << "Interprete de la cancion: ";
  getline(cin, interpreter);
  cout << "Ranking de la cancion: ";
  cin >> streams;
  cout << endl;

  temp_song.setSong(song_name);
  temp_song.setAuthor(author);
  temp_song.setInterpreter(interpreter);
  temp_song.setStreams(streams);

  this->insertNewSong(temp_song);

  system("cls");
  this->showList();

  char opcion;
  cout << endl << "Quieres agregar otra cancion?(s/n): " << endl;
  cin >> opcion;
  if (opcion == 's') {
    this->addSong();
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
  int pos;
  cout << "Ingresa la posicion de la cancion de quieres eliminar: ";
  cin >> pos;
  songs.deleteData(pos);
  cout << "Cancion Eliminada." << endl;
}