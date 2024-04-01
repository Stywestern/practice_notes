#include <iostream>
#include <fstream>
#include <string>

bool is_pangram(std::string sentence) {
	char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int count = 0;
	for (char i : alphabet) {
		if (sentence.find(i) != std::string::npos || sentence.find(tolower(i)) != std::string::npos) {
			count++;
		}
	}
	if (count == 26) {
		return true;
	}
	else {
		return false;
	}
}

	int main()
	{
		std::cout << is_pangram("Waltz, bad nymph, for quick jigs vex.") << std::endl;
		std::cout << is_pangram("The five boxing wizards jump quickly.") << std::endl;
		std::cout << is_pangram("All those moments will be lost in time") << std::endl;
		std::cout << is_pangram("Like tears in rain") << std::endl;
		return 0;
	}
