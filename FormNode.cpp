#include "FormNode.h"

FormNode::FormNode(): head{nullptr}, cur{nullptr}, tail{nullptr}, pNext{nullptr} {}

FormNode::~FormNode() {

}

void FormNode::push_back(const String& str) {
  if (head == nullptr) {head = new Node(str); tail = head;} // !
  else {
    Node* temp = tail; 
    tail = new Node(str);
    temp->SetNext(tail); // ! 
  }
}