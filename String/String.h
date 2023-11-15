#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
	using namespace std;
	class String {
	private:

		static int amount_string;
		char* line;

	public:

		String(const char* lineP, const int size) :line{ new char[size < 0 ? size * -1 : size == 0 ? 81 : size] } {

			amount_string++;

			if (lineP != nullptr) {

				int min_size = min(size, int(strlen(lineP)));

				for (int i{ 0 }; i <= min_size; i++)this->line[i] = lineP[i];

			}
			else this->line = nullptr;
		}

		String(const char* lineP) :String{ lineP, 81 } {}

		String(const int size) :String{ nullptr, size } {}

		String() :String{ nullptr, 81 } {}

		String(const String& string) = delete;

		String(String&& string) :line{ string.line } {

			amount_string++;
			string.line = nullptr;

		}

		~String() { delete[]this->line; }

		String& operator=(String&& string) {

			if (this != &string) {

				line = string.line;
				string.line = nullptr;

			}

			return *this;
		}

		char& operator[](int index) {

			assert((index >= 0 && index < strlen(line) - 1) and "Index out of range!");
			return line[index];

		}

		char operator[](int index)const {

			assert((index >= 0 && index < index < strlen(line) - 1) and "Index out of range!");
			return line[index];

		}


		int operator()(const char symbol)const {

			const char* location = strchr(line, symbol);

			return location != nullptr ? location - line + 1 : -1;

		}


		static int GetAmountString() { return amount_string; }

		string GetString() { return this->line == nullptr ? "Empty string" : this->line; }

		static void SetAmountString(const int amount_stringP) { amount_string = amount_stringP; }

	};