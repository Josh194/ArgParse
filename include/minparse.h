#pragma once

#include <cstring>

namespace minparse {

	struct argument {
		char* arg;

		int argc;
		char** argv;
	};

	namespace {
		int index;

		int end_index;
		char** args;
	}

	void init(int argc, char** argv) {
		end_index = argc - 1;
		args = argv;

		index = 0;
	}

	inline argument parse() {
		int current_arg = index;

		while (true) {
			if (index == end_index + 1) {
				return {
					nullptr,
					-1,
					nullptr
				};
			}

			// Order could be a bit faster
			if (index++ == end_index || args[index][0] == '-') {
				return {
					args[current_arg] + 1,
					index - 1 - current_arg,
					args + current_arg + 1
				};
			}
		}
	}

}