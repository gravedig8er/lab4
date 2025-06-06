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
  FormNode(const FormNode& other);
  ~FormNode();
  void push_back(String str);
  void reset();
  void SetNext(FormNode* pNext);
  FormNode* GetNext();
  bool empty() const;
  bool lessThan(const FormNode& other) const;
  int getTotalLength() const;
  void operator=(const FormNode& other);
  Node* GetHead() const;
};