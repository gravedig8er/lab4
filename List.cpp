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

FormNode* List::GetHead() const {
  return head;
}

void List::sort() {
  if (!head || !head->GetNext()) return;
  
  FormNode* temp = new FormNode(); // упрощение манипуляций
  temp->SetNext(head);
  bool swapped;
  FormNode* last = nullptr; 
  
  do {
    swapped = 0;
    FormNode* prev = temp;
    FormNode* current = temp->GetNext();
    
    while (current && current->GetNext()) {
      FormNode* next = current->GetNext();
        
      if (next->lessThan(*current)) {
        prev->SetNext(next);
        current->SetNext(next->GetNext());
        next->SetNext(current);
        
        prev = next;
        
        swapped = 1;
      } 
      else {
        prev = current;
        current = next;
      }
    }
    
    last = current;
  } while (swapped);
  
  head = temp->GetNext();
  tail = last;
  
  delete temp;
}