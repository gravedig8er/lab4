#pragma once
#include "FormNode.h"

class List {
private:
  FormNode* head; 
  FormNode* cur; 
  FormNode* tail;

public: 
  List();
  List(const List& other);
  ~List();
  void push_back(FormNode& temp);
  FormNode* GetHead() const;
  void sort();
};