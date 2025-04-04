#include "List.h"

List::List(): head{nullptr}, cur{nullptr}, tail{nullptr} {}

List::~List() {
  FormNode* current = head;
  while (current) {
    FormNode* next = current->GetNext();
    delete current;
    current = next;
  }
}

void List::push_back(FormNode& temp) {
  if (head == nullptr) {head = new FormNode(temp); tail = head;}
  else {
    FormNode* current = tail; 
    tail = new FormNode(temp);
    current->SetNext(tail);
  }
}