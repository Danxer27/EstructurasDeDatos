// Archivo de Implenentacion de la clase Song
#include "song.hpp"
using namespace std;

Song::Song() {}

Song::Song(const Song& s)
    : song_name(s.song_name),
      author(s.author),
      interpreter(s.interpreter),
      mp3Name(s.mp3Name),
      ranking(s.ranking) {}

int Song::state = 1;

void Song::setSong(const string& s) {
  this->song_name = s;
}

void Song::setAuthor(const string& s) {
  this->author = s;
}

void Song::setInterpreter(const string& s) {
  this->interpreter = s;
}

void Song::setRanking(const int& s) {
  this->ranking = s;
}

void Song::generateMP3File() {
  int j = this->song_name.size(), i(0);
  int n = this->interpreter.size() + j;
  this->mp3Name = "";
  while (i < n) {
    if (i > j) {
      if (!(this->interpreter[i - j - 1] == ' ')) {
        this->mp3Name += tolower(this->interpreter[i - j - 1]);
      }
    } else if (i == j) {
      this->mp3Name += "-";
    } else {
      if (!(this->song_name[i] == ' ')) {
        this->mp3Name += tolower(this->song_name[i]);
      }
    }
    i++;
  }
  this->mp3Name += ".mp3";
}

string Song::toString() const {
  return this->song_name + "\t " + this->author + "\t " + this->interpreter +
         "\t " + this->mp3Name + "\t " + to_string(this->ranking);
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

int Song::getRanking() const {
  return this->ranking;
}

// Relacion de equidad
bool Song::operator==(const Song& s) const {
  if (state == 1) {
    return this->song_name == s.song_name;
  } else if (state == 2) {
    return this->interpreter == s.interpreter;
  } else if (state == 3) {
    return this->author == s.author;
  } else {
    return this->song_name == s.song_name;
  }
}

bool Song::operator!=(const Song& s) const {
  return !(*this == s);
}

// Relacion comparada por numero de reproducciones.
bool Song::operator<(const Song& s) const {
  if (state == 1) {
    return this->song_name < s.song_name;
  } else if (state == 2) {
    return this->interpreter < s.interpreter;
  } else if (state == 3) {
    return this->author < s.author;
  } else {
    return this->song_name == s.song_name;
  }
}

bool Song::operator<=(const Song& s) const {
  return *this < s || *this == s;
}

bool Song::operator>(const Song& s) const {
  return !(*this <= s);
}

bool Song::operator>=(const Song& s) const {
  return !(*this < s);
}

int Song::compareTo(const Song& s) {
  return this->song_name == s.song_name;
}

int Song::compareByName(const Song& a, const Song& b) {
  return a.song_name == b.song_name;
}

int Song::compareByAuthor(const Song& a, const Song& b) {
  return a.author == b.author;
}

int Song::compareByranking(const Song& a, const Song& b) {
  return a.ranking == b.ranking;
}

int Song::compareByInterpreter(const Song& a, const Song& b) {
  return a.interpreter == b.interpreter;
}

int Song::compareByMP3File(const Song& a, const Song& b) {
  return a.mp3Name == b.mp3Name;
}

void Song::setState(const int& n) {
  state = n;
}