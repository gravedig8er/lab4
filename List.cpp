#include "List.h"
#include "config.h"

List::List(): head{nullptr}, cur{nullptr}, tail{nullptr} {}

List::List(const List& other) : head(nullptr), cur(nullptr), tail(nullptr) {
  FormNode* current = other.head;
  while (current) {
      FormNode* newNode = new FormNode(*current); // Использует конструктор копирования FormNode
      if (!head) {
          head = tail = newNode;
      } else {
          tail->SetNext(newNode);
          tail = newNode;
      }
      current = current->GetNext();
  }
}
List::~List() {
  FormNode* current = head;
  while (current) {
    FormNode* next = current->GetNext();
    delete current;
    current = next;
  }
}

void List::push_back(FormNode& temp) {
  FormNode* newNode = new FormNode(temp);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } 
  else {
    tail->SetNext(newNode);
    tail = newNode;
  }
}