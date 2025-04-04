#pragma once
#include "Node.h"
#include "String.h"

class FormNode {
private: 
  Node* head; 
  Node* cur; 
  Node* tail; 

  FormNode* pNext; 
public: 
  FormNode();
  ~FormNode();
  void push_back(String str);
};