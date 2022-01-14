#include <bits/stdc++.h>

#include "config.cpp"
#include "help.cpp"

void test() { 
	system(std::string("echo $(ls " + cfg.inp + ") > .cases.txt").c_str());
	std::ifstream cases(".cases.txt");
	std::string s, ss;
	while (getline(cases, s)) {
	
		std::cout << s << " - ";
	
		std::string input  = "\"" + cfg.inp + "\"/" + s;
		std::string output = "\"" + cfg.otp + "\"/" + s;
		std::string binary = cfg.program;

		std::string exec = "echo $(cat " + input + " | " + binary + ") > .output.txt";
		std::string comp = "echo $(diff .output.txt " + output + ") > .diff.txt";

		std::ofstream sh(".script.sh");
		sh << exec << "\n" << comp << "\n";
		sh.flush(); sh.close();

		system("chmod +x ./.script.sh");
		system("./.script.sh");
		
		std::ifstream diff(".diff.txt");
		std::string res; getline(diff, res);

		if (res == "") std::cout << "OK\n"; else std::cout << "WA\n";
		
		diff.close();
		
	}
}

int main(int argc, char* argv[]) {
	
	if (argc == 1) error("Use --help for help.");

	if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
		if (argc > 3) error("Too many argumets"); help();
	}

	if (std::string(argv[1]) == "--conf" || std::string(argv[1]) == "-c") {
		if (argc > 3) error("Too many argumets");
		cfg.read(); cfg.write(); cfg.display(); exit(0);
	}
	
	int arg_pointer = 1;

	if (std::string(argv[1]) == "--init" || std::string(argv[1]) == "-i") { init(); arg_pointer++; }
	if (!is_initialized()) error("You have to initialize the tester before using it.\n");

	cfg.read();
	cfg.write();

	bool should_test = false;

	for (; arg_pointer < argc; arg_pointer++) {
		std::string arg = argv[arg_pointer];
		if (arg == "--inp") cfg.inp = argv[++arg_pointer]; else
		if (arg == "--otp" || arg == "-o") cfg.otp = argv[++arg_pointer]; else
		if (arg == "--bin" || arg == "-b") cfg.program = argv[++arg_pointer]; else
		if (arg == "--mem" || arg == "-m") cfg.mem_lim = stoi(std::string(argv[++arg_pointer])); else
		if (arg == "--time" || arg == "-t") cfg.time_lim = stoi(std::string(argv[++arg_pointer])); else
		if (arg == "--test" || arg == "-r") should_test = true;
	}

	cfg.write();

	if (should_test) test();

}
