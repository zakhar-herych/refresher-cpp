#include <iostream>
#include <string>
int main()
{
	std::cout << "Please enter your first name: " << std::endl;
	std::string name;
	std::cin >> name;
	std::string greeting = "Hello, " + name + "!";
	std::string stars(greeting.size()+4, '*');
	std::string frame(greeting.size()+2, ' ');
	frame = "*" + frame + "*";
	std::cout << stars << std::endl;
	std::cout << frame << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << frame << std::endl;
	std::cout << stars << std::endl;
	return 0;
}
