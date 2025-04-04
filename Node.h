#pragma once
#include "String.h"

class Node {
private:
  String string; 
  Node* pNext; 

public: 
  Node();
  Node(const String& str);
  ~Node();
  void SetNext(Node* pNext);
  String GetData();
  Node* GetNext();
};