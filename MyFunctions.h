#pragma once
#include "String.h"
#include "FormNode.h"
#include <fstream> 
#include "List.h"

void clear(char* str, int length);
void Print(std::fstream& out, List& lst);
int CompareStrings(const char* c1, const char* s2);