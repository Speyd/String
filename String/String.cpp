#include "String.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void String::SetString(const char* lineP) {
	if (lineP != nullptr) {

		int min_index;
		if (this->line != nullptr)min_index = min(strlen(this->line) + 1, strlen(lineP) + 1);
		else min_index = strlen(lineP) + 1;

		delete[]this->line;
		if (min_index < strlen(lineP) + 1) { this->line = new char[min_index + 1]; line[min_index] = '\0'; }
		else this->line = new char[min_index]; 

		for (int i{ 0 }; i != min_index; i++)this->line[i] = lineP[i];
	}
}