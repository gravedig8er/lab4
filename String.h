#pragma once

const int N = 20; 

class String {
private: 
  char line[N+1];
  int length; 

public: 
  String();
  String(const String& other);
  ~String();
  String(char* src);
  int GetLength();
  void SetLength(int length);
  void operator = (const String& other);
  void reset(); 
};