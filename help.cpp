#include <iostream>

void help() {
	std::cout
		<< "Cases - a program to automatically check your code on test cases before you submit it."
		<< "\n"
		<< "--help | -h         displays this message\n"
		<< "--init | -i         initializes the tester. (Do this before using the program)\n"
		<< "--bin  | -b [path]  sets test binary located to [path] (default: ./main)\n"
		<< "--test | -r [path]  tests the binary located (at [path] (if specified))\n"
		<< "--time | -t [ms]    sets time limit in millisecond (default: 1000)\n"
		<< "--mem  | -m [mb]    sets memory limit in megabytes (default: 256)\n"
		<< "--otp  | -o [dir]   sets case output directory (default: ./output)\n"
		<< "--conf | -c         outputs current config\n"
		<< "--inp [dir]         sets case input directory (default: ./input)\n"
	;
	exit(0);
}
