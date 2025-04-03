#include "String.h"

String::String() : line{}, length{0} {}

String::~String() {

}

int String::GetLength() {
  return this->length;
}

void String::SetLength(int length) {
  this->length = length; 
}