#include "FormNode.h"
#include "Node.h"
#include "config.h"
#include "MyFunctions.h"

FormNode::FormNode(): head{nullptr}, cur{nullptr}, tail{nullptr}, pNext{nullptr} {}

FormNode::FormNode(const FormNode& other): head{nullptr}, tail{nullptr}, pNext{nullptr} {
  Node* current = other.head; 
  while (current) {
    this->push_back(current->GetData());
    current = current->GetNext();
  }
}

void FormNode::operator=(const FormNode& other) {
  if (this != &other) {
    this->reset();
    Node* current = other.head;
    while (current) {
      this->push_back(current->GetData());
      current = current->GetNext();
    }
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

bool FormNode::empty() const {
  if (head == nullptr) return 1;
  return 0;
}

Node* FormNode::GetHead() const { return head; }

int FormNode::getTotalLength() const {
  int total = 0;
  Node* current = head;
  while (current) {
    total += current->GetData().GetLength();
    current = current->GetNext();
  }
  return total;
}

bool FormNode::lessThan(const FormNode& other) const {
  // пустые строки
  if (this->empty() && !other.empty()) return true;
  if (!this->empty() && other.empty()) return false;
  if (this->empty() && other.empty()) return false;

  int len1 = this->getTotalLength();
  int len2 = other.getTotalLength();
  if (len1 < len2) return true;
  if (len1 > len2) return false;

  Node* n1 = this->head;
  Node* n2 = other.head;

  while (n1 && n2) {
      int cmp = CompareStrings(
          n1->GetData().GetLine(), 
          n2->GetData().GetLine()
      );

      if (cmp < 0) return true;  // блок this меньше
      if (cmp > 0) return false; // блок other меньше

      n1 = n1->GetNext();
      n2 = n2->GetNext();
  }

  return (n1 == nullptr && n2 != nullptr);
}