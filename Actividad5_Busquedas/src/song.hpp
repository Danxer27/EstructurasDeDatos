// Archivo de Definicion de la clase Song
#ifndef __SONG_HPP__
#define __SONG_HPP__
#include <string>

class Song {
 private:
  std::string song_name;
  std::string author;
  std::string interpreter;
  std::string mp3Name;
  int ranking;
  static int state;

 public:
  Song();
  Song(const Song&);

  void setSong(const std::string&);
  void setAuthor(const std::string&);
  void setInterpreter(const std::string&);
  void setRanking(const int&);
  void generateMP3File();

  std::string toString() const;

  std::string getSongName() const;
  std::string getAuthor() const;
  std::string getInterpreter() const;
  std::string getMP3File() const;
  int getRanking() const;

  bool operator==(const Song&) const;
  bool operator!=(const Song&) const;
  bool operator>(const Song&) const;
  bool operator>=(const Song&) const;
  bool operator<(const Song&) const;
  bool operator<=(const Song&) const;

  int compareTo(const Song&);
  int compareByName(const Song&, const Song&);
  int compareByAuthor(const Song&, const Song&);
  int compareByInterpreter(const Song&, const Song&);
  int compareByranking(const Song&, const Song&);
  int compareByMP3File(const Song&, const Song&);

  static void setState(const int&);
};

#endif  // __SONG_HPP__