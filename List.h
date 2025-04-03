#pragma once
#include "FormNode.h"

class List {
private:
  FormNode* head; 
  FormNode* cur; 
  FormNode* tail;

public: 
  List();
  ~List();
  // тут должно быть взаимодействие с остальными элементами
};