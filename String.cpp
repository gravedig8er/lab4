#include "String.h"
#include "MyFunctions.h"

String::String() : line{}, length{0} {}

String::String(char* src) {
  length = 0; 
  if (src == nullptr) return;

  int i = 0; 
  while (src[i] != '\0' && i < N) {
    line[i] = src[i];
    i++; 
  }

  line[i] = '\0';
  length = i;
}

String::~String() {

}

int String::GetLength() {
  return this->length;
}

void String::SetLength(int length) {
  this->length = length; 
}

String::String(const String& other) {
  memset(line, N+1);
  this->length = other.length;
  line[length] = '\0';

  for (int i = 0; i < other.length; i++) {
    this->line[i] = other.line[i];
  }
}

void String::operator = (const String& other) {
  if (this == &other) return;
  memset(line, N+1);
  if (this == &other) return;
  this->length = other.length; 
  line[length] = '\0';

  for (int i = 0; i < other.length; i++) {
    this->line[i] = other.line[i];
  }
}

void String::reset() {
  memset(line, N+1);
  this->length = 0;
}