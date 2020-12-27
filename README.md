# argparse 1.0.0-prerelease
A barebones, header-only argument parsing library for C++.

---
Usage is extremely simple; just initialize minparse with `argc` and `argv` from your main function, then parse in a loop like so:
```C++
#include "minparse.h"

int main(int argc, char** argv) {
	minparse::init(argc, argv);

	minparse::argument arg = {};

	while (minparse::parse(&arg)) {
		for (int i = 0; i < arg.argc; i++) {
			// arg.argv[i] holds the current argument value
		}
	}

	return 0;
}
```

No registering arguments, no standard error messages, everything is up to you.

Basic documentation can be found in the sole header file.

---
All functions and data structures are held in the `minparse` namespace, and the header is extremely small, only including the `<cstring>` header, and containing minimal code.

Any parameter prefixed by a '-' is considered an argument, anything after an argument is considered a value of that argument.
If the parameter list does not begin with an argument, attempting to parse the list will always return false.
The library can work on any number of parameter lists by calling `minparse::init()` before beginning to parse each one.
