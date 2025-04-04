#include <iostream> 
#include <fstream> 
#include "List.h"
#include "String.h"
#include "FormNode.h"
#include "MyFunctions.h"

int main() {
  std::fstream input, out; 
  input.open("input.txt", std::ios::in);
  if (!input.is_open()) {std::cout << "Check file\n"; return 0;}

  List lst; 
 
  char ch;
  int counter = 0; // количество символов в блоке, должно быть меньше N 

  FormNode tempNode; 

  char tempS[N+1] = {};
  while (!input.eof()) { // находимся в файле 
    input.get(ch); 

    if (!input.eof() && ch != '\n') { // пока мы на нужной строке нужно считывать порцию в N символов 
      if (counter < N) tempS[counter++] = ch; 

      if (counter == N) { // блок заполнился
        tempS[N] = '\0';
        String str(tempS);
        tempNode.push_back(str); // записали в список-строку элемент
 
        counter = 0;
        memset(tempS, N+1);
      }
    }
    else { // переход на следующую строку
      if (counter > 0) { // если в строке что-то есть
        tempS[counter] = '\0';
        String str(tempS);
        tempNode.push_back(str); // записуали в список-строку
        
        memset(tempS, N+1);
        counter = 0; // обнулили так как начина
      }

      lst.push_back(tempNode);
      tempNode.reset(); // сбрасываем список-строку
    }
  }

  if (counter > 0) { // для корректной записи последней строки
    tempS[counter] = '\0';
    String str(tempS);
    tempNode.push_back(str);
  }
  if (!tempNode.empty()) {  // Если в tempNode есть данные
      lst.push_back(tempNode);
      tempNode.reset();
  }


  input.close();
  return 0;
}