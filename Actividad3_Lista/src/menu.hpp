// Arhivo de definicion de la clase Menu
#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include "list.hpp"
#include "song.hpp"

class Menu {
 private:
  List<Song> songs;

 public:
  Menu();
  Menu(const Menu&);

  void Interface();
  void showList();
  void addSong();
  void deleteSong();
  void insertNewSong(const Song&);
};

#endif  //__MENU_HPP__