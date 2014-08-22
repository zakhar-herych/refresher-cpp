#include <iostream>
#include <string>

int main() {
	std::cout << "Please, enter your name: " << std::endl;
	std::string name;
	std::cin >> name;
	const std::string greeting = "Hello, " + name + "!";
	int pad_x = 2;
	std::cout << "Specify side padding: " << std::endl;
	std::cin >> pad_x;
	int pad_y = 1;
	std::cout << "Specify top padding: " << std::endl;
	std::cin >> pad_y;
	const int rows = pad_y * 2 + 3;
	const std::string::size_type cols = greeting.size() + pad_x*2 + 2;
	std::cout << std::endl;
	std::string::size_type c = 0;
	for (int r=0; r < rows; ++r){
		for (int c=0; c < cols; ++c){
			if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
				std::cout << "*";
			} else if (r == pad_y + 1 && c == pad_x + 1) {
				std::cout << greeting;
				c += greeting.size()-1;
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
