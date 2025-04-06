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
  const char* inter = "nullptr";
  const char* sep = "\n\t\\|/\n";

  while (currentForm) {
      Node* currentNode = currentForm->GetHead();

      if (!currentNode) {
        out << arrow << inter;
      } else {
          while (currentNode) {
            String data = currentNode->GetData();
            out << data.GetLine() << arrow;
            currentNode = currentNode->GetNext();
          }
          out << inter;
      }

      currentForm = currentForm->GetNext();

      if (currentForm)
        out << sep;
  }

  out << sep << inter;
}

int CompareStrings(const char* s1, const char* s2) {
  int i = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] < s2[i]) return -1;
    if (s1[i] > s2[i]) return 1;
    i++;
  }
  if (s1[i] == '\0' && s2[i] != '\0') return -1;
  if (s1[i] != '\0' && s2[i] == '\0') return 1;
  return 0;
}