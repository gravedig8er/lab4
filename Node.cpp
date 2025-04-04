#include "Node.h"

Node::Node(): string(), pNext{nullptr} {}

Node::Node(String str) {
  this->string = str; 
  pNext = nullptr; 
}

Node::~Node() {
  
}

void Node::SetNext(Node* pNext) {
  this->pNext = pNext; 
}