#include "MyFunctions.h"
#include "config.h"

void clear(char* str, int length) {
  for (int i = 0; i < length; i++) {
    str[i] = '\0';
  }
}

void Print(std::fstream& out, List& lst) {
  FormNode* currentForm = lst.GetHead();
  const char* arrow = " -> ";
  const char* internalNull = "nullptr";
  const char* externalSeparator = "\n\t\\|/\n";

  while (currentForm) {
      Node* currentNode = currentForm->GetHead();

      if (!currentNode) {
          out << arrow << internalNull;
      } else {
          while (currentNode) {
              String data = currentNode->GetData();
              out << data.GetLine() << arrow;
              currentNode = currentNode->GetNext();
          }
          out << internalNull;
      }

      currentForm = currentForm->GetNext();

      if (currentForm)
          out << externalSeparator;
  }

  out << externalSeparator << internalNull;
}
