#include <iostream> 
#include <fstream> 
#include "List.h"
#include "String.h"
#include "FormNode.h"

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
      tempS[counter++] = ch; 

      if (counter == N) { // блок заполнился
        String str(tempS);
        tempNode.push_back(str); // записали в список-строку элемент

        counter = 0;
        reset(tempS); // сбрасываем строку
      }
    }
    else { // переход на следующую строку
      if (counter > 0) { // если в строке что-то есть
        String str(tempS);
        tempNode.push_back(str); // записали в список-строку
        reset(tempS); // обнулили строкуем новый блок 

        counter = 0; // обнулили так как начина
      }

      lst.push_back(tempNode);
      reset(tempNode); // обнуляем список-строку т.к переходим к следующей строке
    }
  }

  if (counter > 0) { // для корректной записи последней строки
    String str(tempS);
    tempNode.push_back(str);
  }
  if (!tempNode.empty()) {  // Если в tempNode есть данные
      lst.push_back(tempNode);
  }

  input.close();
  return 0;
}