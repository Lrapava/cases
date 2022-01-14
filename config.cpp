#include <bits/stdc++.h>
#define error(x) { std::cout << x << "\n"; exit(-1); }

bool exists(std::string s) {
	std::ifstream file(s);
	return file.is_open();
}

class config {
public:
	std::string inp = "./input";
	std::string otp = "./output";
	std::string program  = "./main";
	int time_lim = 1000;
	int mem_lim  = 256;

	config() {}
	
	void read() {
		std::ifstream cfg_file(".testercfg");
		if (!cfg_file.is_open()) error("tester failed to initialize.");
		getline(cfg_file, inp);
		getline(cfg_file, otp);
		getline(cfg_file, program);
		cfg_file >> time_lim;
		cfg_file >> mem_lim;
		cfg_file.close();
	}
	
	void write() {
		std::ofstream cfg_file(".testercfg");
		cfg_file << inp << "\n" << otp << "\n" << program << "\n" << time_lim << "\n" << mem_lim << "\n";
		cfg_file.flush();
		cfg_file.close();
	}

	void display() {
		std::cout 
		<< "Testcase input:   " << inp << "\n"
		<< "Testcase output:  " << otp << "\n"
		<< "Binary location:  " << program << "\n"
		<< "Time limit:       " << time_lim << " (ms)\n"
		<< "Memory limit:     " << mem_lim << " (mb)\n"
		;
	}
	
private:
};

bool is_initialized() {
	return exists(".testercfg");
}

config cfg;

void init() {
	cfg.display();
	cfg.write();
	system("mkdir input output");
}
