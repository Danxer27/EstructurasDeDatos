// Archivo de Implenentacion de la clase Song
#include "song.hpp"
using namespace std;

Song::Song() {}

Song::Song(const Song& s)
    : song_name(s.song_name),
      author(s.author),
      interpreter(s.interpreter),
      streams(s.streams) {}

void Song::setSong(const string& s) {
  this->song_name = s;
}

void Song::setAuthor(const string& s) {
  this->author = s;
}

void Song::setInterpreter(const string& s) {
  this->interpreter = s;
}

void Song::setStreams(const int& s) {
  this->streams = s;
}

string Song::toString() const {
  return "Song: " + this->song_name + "\nAuthor: " + this->author +
         "\nInterpreter: " + this->interpreter +
         "\nRanking: " + to_string(this->streams);
}

string Song::getSongName() const {
  return this->song_name;
}

string Song::getAuthor() const {
  return this->author;
}

string Song::getInterpreter() const {
  return this->interpreter;
}

int Song::getStreams() const {
  return this->streams;
}
