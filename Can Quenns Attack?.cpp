#include <iostream>
#include <fstream>
#include <string>

bool quenn_in_range(int x1, int y1, int x2, int y2) {
	int quenn1[2] = { x1, y1 };
	int quenn2[2] = { x2, y2 };

	if (x1 == x2 || y1 == y2) {
		return true;
	}
	else {
		bool intermediate_bool = false;
		for (int i = 0; i <= 8; i++) {
			if ((x1 + i == x2 && y1 + i == y2) || (x1 == x2 + i && y1 + i == y2) || (x1 + i == x2 && y1 == y2 + i) || (x1 == x2 + i && y1 == y2 + i)) {
				intermediate_bool = true;
				break;
			}
			else {
				intermediate_bool = false;
			}
		}
		return intermediate_bool;
	}
}

	int main()
	{
		std::cout << quenn_in_range(1, 2, 1, 8) << std::endl; 
		std::cout << quenn_in_range(1, 2, 8, 2) << std::endl;
		std::cout << quenn_in_range(1, 2, 2, 3) << std::endl; 
		std::cout << quenn_in_range(1, 2, 6, 6) << std::endl; 
		std::cout << quenn_in_range(2, 3, 5, 6) << std::endl; 
		std::cout << quenn_in_range(1, 3, 5, 6) << std::endl; 
		return 0;
	}
