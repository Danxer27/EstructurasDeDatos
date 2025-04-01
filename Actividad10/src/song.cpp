// Archivo de Implenentacion de la clase Song
#include "song.hpp"
#include <iomanip>
#include <sstream>
using namespace std;

Song::Song() : mp3Name("") {}

Song::Song(const Song& s) {
  this->copyAll(s);
}

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
  int j(this->song_name.size()), i(0);
  int n(this->interpreter.size() + j);
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
  stringstream ss;
  ss << left << setw(20) << this->song_name << left << setw(20) << this->author
     << left << setw(20) << this->interpreter << left << setw(30)
     << this->mp3Name << left << setw(10) << to_string(this->ranking);
  return ss.str();
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

Song& Song::operator= (const Song& s){
  this->copyAll(s);
}

bool Song::operator==(const Song& s) const {
    return this->song_name == s.song_name;
}

bool Song::operator!=(const Song& s) const {
  return !(*this == s);
}

bool Song::operator<(const Song& s) const {
    return this->interpreter < s.interpreter;
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

// Comparadores

int Song::compareTo(const Song& s) {
  return this->song_name.compare(s.song_name);
}

int Song::compareByName(const Song& a, const Song& b) {
  return a.song_name.compare(b.song_name);
}

int Song::compareByAuthor(const Song& a, const Song& b) {
  return a.author.compare(b.author);
}

int Song::compareByInterpreter(const Song& a, const Song& b) {
  return a.interpreter.compare(b.interpreter);
}

int Song::compareByranking(const Song& a, const Song& b) {
  return abs(a.ranking - b.ranking);
}

int Song::compareByMP3File(const Song& a, const Song& b) {
  return a.mp3Name.compare(b.mp3Name);
}

int Song::compareByNamePtr(const Song* a, const Song* b) {
  return a->song_name.compare(b->song_name);
}

int Song::compareByAuthorPtr(const Song* a, const Song* b) {
  return a->author.compare(b->author);
}

int Song::compareByInterpreterPtr(const Song* a, const Song* b) {
  return a->interpreter.compare(b->interpreter);
}

int Song::compareByrankingPtr(const Song* a, const Song* b) {
  return abs(a->ranking - b->ranking);
}

int Song::compareByMP3FilePtr(const Song* a, const Song* b) {
  return a->mp3Name.compare(b->mp3Name);
}

void Song::copyAll(const Song& s){
  this->song_name = s.song_name;
  this->author = s.author;
  this->interpreter = s.interpreter;
  this->mp3Name = s.mp3Name;
  this->ranking = s.ranking;
}
