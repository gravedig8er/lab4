#pragma once
#include "String.h"

class Node {
private:
  String string; 
  Node* pNext; 

public: 
  Node();
  Node(String str);
  ~Node();
  void SetNext(Node* pNext);
};