#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class String {
private:

	static int amount_string;
	char* line;

public:

	String(const char* lineP, const int size) :line{ new char[size < 0 ? size * -1 : size == 0 ? 81 : size] }{

		amount_string++;

		if (lineP != nullptr) {

			int min_size = min(size, int(strlen(lineP)));

			for (int i{ 0 }; i <= min_size; i++)this->line[i] = lineP[i];

		}
		else this->line = nullptr;
	}

	String(const char* lineP) :String{lineP, 81} {}

	String(const int size) :String{ nullptr, size } {}

	String() :String{ nullptr, 81 } {}

	~String() { delete[]this->line;}

	static int GetAmountString() { return amount_string; }

	string GetString() { return this->line == nullptr?"Empty string":this->line; }

	static void SetAmountString(const int amount_stringP) { amount_string = amount_stringP; }

	void SetString(const char* lineP);
};