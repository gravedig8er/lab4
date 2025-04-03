#pragma once

const int N = 20; 

class String {
private: 
  char line[N+1];
  int length; 

public: 
  String();
  ~String();
  String(char* src);
  int GetLength();
  void SetLength(int length);
};