// Arhivo de definicion de la clase Interface
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include <iostream>
#include "list.hpp"
#include "song.hpp"

class Interface {
 private:
  List<Song> songs;
  Song temp_song;
  int pos;
  bool isSorted;

 public:
  Interface();
  Interface(const Interface&);

  void Menu();
  void showList();
  void addSong();

  void sortList();
  void findSong();

  void deleteSong();
  void insertNewSong(const Song&);
};

#endif  //__INTERFACE_HPP__