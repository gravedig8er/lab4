#pragma once
#include "Node.h"

class FormNode {
private: 
  Node* head; 
  Node* cur; 
  Node* tail; 

  FormNode* pNext; 
public: 
  FormNode();
  ~FormNode();
};