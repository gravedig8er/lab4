#pragma once
#include "String.h"

class Node {
private:
  String string; 
  Node* pNext; 

public: 
  Node();
  ~Node();
};