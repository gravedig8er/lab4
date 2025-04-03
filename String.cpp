#include "String.h"

String::String() : line{}, length{0} {}

String::String(char* src) {
  int i = 0; 
  while (src[i] != '\0') {
    line[i] = str[i];
    i++; 
  }
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

