// Archivo de Implementacion de la clase Interface
#include "interface.hpp"
#include <cstdlib>
#include <iomanip>
using namespace std;

Interface::Interface(List<Song>& l) {
  this->songs = &l;
  this->Menu();
}

void Interface::Menu() {
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
        songs->deleteAll();
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

void Interface::addSong() {
  Song temp_song;
  string song_name, author, interpreter;
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

  cin.ignore();
  if (opcion == 's') {
    this->addSong();
  }
}

void Interface::insertNewSong(const Song& s) {
  char opcion = 'n';
  string sName;
  Song temp_song;

  if (!songs->isEmpty()) {
    cout << "Quieres Agregarlo en una posicion especifica?(s/n): ";
    cin >> opcion;
    if (opcion == 's') {
      cout << "Para insertar en una posicion especifica ingrese el nombre de "
              "la cancion contigua a la que quiere insertar la cancion: ";
      cin.ignore();
      getline(cin, sName);

      temp_song.setSong(sName);

      try {
        songs->insertData(songs->getNextPos(songs->findData(temp_song)), s);
      } catch (const List<Song>::Exception& e) {
        cout << e.what() << endl;
      }
      return;
    }
  }
  try {
    songs->insertData(songs->getLastPos(), s);
  } catch (const List<Song>::Exception& e) {
    cout << e.what() << endl;
  }
}

// Menu para buscar una cancion.
void Interface::findSong() {
  Song temp_song, temp_song_found;
  string sName;
  int findOption;
  bool nameFind(true);

  if (songs->isEmpty()) {
    cout << "Aun no hay canciones para buscar. " << endl;
    this->Menu();
  }

  cout << "Buscar por nombre o por interprete(1/2): ";
  cin >> findOption;

  if (findOption == 1) {
    cout << "Ingrese el nombre de la cancion a buscar: ";
  } else {
    cout << "Ingrese el nombre del interprete de la cancion a buscar: ";
    nameFind = false;
  }

  cin.ignore();
  getline(cin, sName);

  if (nameFind)
    temp_song.setSong(sName);
  else
    temp_song.setInterpreter(sName);

  if ((nameFind ? songs->findData(temp_song, Song::compareByName)
                : songs->findData(temp_song, Song::compareByInterpreter)) ==
      nullptr) {
    cout << "\nCancion no encontrada" << endl;
  } else {
    nameFind ? songs->findData(temp_song, Song::compareByName)
             : songs->findData(temp_song, Song::compareByInterpreter);

    cout << "\nLa cancion en la posicion "
         << songs
                ->getPreviousPos(
                    nameFind ? songs->findData(temp_song, Song::compareByName)
                             : songs->findData(temp_song,
                                               Song::compareByInterpreter))
                ->getNext()
         << " es: "
         << songs
                ->retrieve(nameFind
                               ? songs->findData(temp_song, Song::compareByName)
                               : songs->findData(temp_song,
                                                 Song::compareByInterpreter))
                .toString()
         << endl;
  }
}

void Interface::showList() {
  system("cls");
  cout << "Lista de Canciones:" << endl;

  if (songs->isEmpty()) {
    cout << "Aun no hay canciones en la lista." << endl;
  } else {
    cout << "Nombre              "
         << "Autor               "
         << "Interprete          "
         << "Archivo.MP3                    "
         << "Ranking" << endl;

    cout << songs->toString() << endl;
  }
}

void Interface::deleteSong() {
  Song temp_song;
  string sName;
  if (songs->isEmpty()) {
    cout << "Aun no hay canciones para eliminar. " << endl;
    return;
  }

  cout << "Ingresa el nombre de la cancion de quieres eliminar: ";
  cin.ignore();
  getline(cin, sName);

  temp_song.setSong(sName);

  try {
    songs->deleteData(songs->findData(temp_song));
  } catch (const List<Song>::Exception& e) {
    cout << e.what() << endl;
  }

  cout << "Cancion Eliminada." << endl;
}