#include "Node.h"
#include "String.h"

Node::Node(): string(), pNext{nullptr} {}

Node::Node(const String& str) {
  this->string = str; 
  pNext = nullptr; 
}

Node::~Node() {
  
}

void Node::SetNext(Node* pNext) {
  this->pNext = pNext; 
}

String Node::GetData() {
  return string;
}

Node* Node::GetNext() {
  return pNext; 
}