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
  void push_back(FormNode& temp);
};