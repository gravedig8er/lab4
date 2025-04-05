#include "FormNode.h"
#include "Node.h"
#include "config.h"

FormNode::FormNode(): head{nullptr}, cur{nullptr}, tail{nullptr}, pNext{nullptr} {}

FormNode::FormNode(const FormNode& other): head{nullptr}, tail{nullptr}, pNext{nullptr} {
  Node* current = other.head; 
  while (current) {
    this->push_back(current->GetData());
    current = current->GetNext();
  }
}

FormNode::~FormNode() {
  reset();
}

void FormNode::push_back(const String str) {
  if (head == nullptr) {head = new Node(str); tail = head;} 
  else {
    Node* temp = tail; 
    tail = new Node(str);
    temp->SetNext(tail); 
  }
}

void FormNode::reset() {
  Node* current = head;
    while (current) {
      Node* next = current->GetNext();
      delete current; 
      current = next;
    }
  head = cur = tail = nullptr; 
}

void FormNode::SetNext(FormNode* pNext) {
  this->pNext = pNext; 
}

FormNode* FormNode::GetNext() {
  return pNext;
}

bool FormNode::empty() {
  if (head == nullptr) return 1;
  return 0;
}