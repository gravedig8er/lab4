#pragma once

const int N = 20; 

class String {
private: 
  char line[N+1];
  int length; 

public: 
  String();
  ~String();
  int GetLength();
  void SetLength(int length);
};