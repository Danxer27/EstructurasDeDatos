// Arhivo de definicion de la clase Interface
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include <iostream>
#include "listTD.hpp"
#include "song.hpp"

class Interface {
 private:
  List<Song,5000>* songs;
  Song temp_song;
  int pos;
  bool isSorted;

 public:
  Interface(List<Song,5000>&);

  void Menu();
  void showList();
  void addSong();

  void sortList();
  void findSong();

  void deleteSong();
  void insertNewSong(const Song&);
};

#endif  //__INTERFACE_HPP__