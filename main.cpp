#include <iostream> 
#include <fstream> 
#include "List.h"
#include "String.h"
#include "FormNode.h"
#include "MyFunctions.h"
#include "config.h"

int main() {
  std::fstream input, out; 
  input.open("input.txt", std::ios::in);
  if (!input.is_open()) {std::cout << "Check file\n"; return 0;}

  List lst; 
 
  char ch;
  int counter = 0; // количество символов в блоке, должно быть меньше N 

  FormNode tempNode; 

  char tempS[N + 1] = {};

  while (input.get(ch)) {
    if (ch == '\r') continue; 

    if (ch == '\n') {
      if (counter > 0) {
        tempS[counter] = '\0';
        tempNode.push_back(String(tempS));
        clear(tempS, N + 1);
        counter = 0;
      }

      lst.push_back(tempNode); // даже если пустой
      tempNode.reset();
    } 
    else {
        tempS[counter++] = ch;

        if (counter == N) {
          tempS[N] = '\0';
          tempNode.push_back(String(tempS));
          clear(tempS, N + 1);
          counter = 0;
        }
    }
  }
  // добавим остатки
  if (counter > 0) {
    tempS[counter] = '\0';
    tempNode.push_back(String(tempS));
    clear(tempS, N + 1);
  }

  lst.push_back(tempNode);

  out.open("output.txt", std::ios::out);
  if (!out.is_open()) {std::cout << "Check output file\n"; return 0;}

  Print(out, lst);

  input.close();
  return 0;
}