// Archivo de Definicion de la clase Song
#ifndef __SONG_HPP__
#define __SONG_HPP__
#include <string>

class Song {
 private:
  std::string song_name;
  std::string author;
  std::string interpreter;
  int streams;

 public:
  Song();
  Song(const Song&);

  void setSong(const std::string&);
  void setAuthor(const std::string&);
  void setInterpreter(const std::string&);
  void setStreams(const int&);

  std::string toString() const;

  std::string getSongName() const;
  std::string getAuthor() const;
  std::string getInterpreter() const;
  int getStreams() const;
};

#endif  // __SONG_HPP__