#include "../include/minparse.h"

#include <iostream>

int main() {
	constexpr int argc = 7;
	char* argv[argc] = {
		(char*) "-a\0",
		(char*) "a1\0",
		(char*) "-ba\0",
		(char*) "b1\0",
		(char*) "b2\0",
		(char*) "-c\0",
		(char*) "-da\0"
	};

	minparse::init(argc, argv);

	while (true) {
		minparse::argument arg = minparse::parse();

		if (arg.argc == -1) {
			break;
		}

		std::cout << arg.arg << " " << arg.argc << " ";

		for (int i = 0; i < arg.argc; i++) {
			std::cout << arg.argv[i] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}