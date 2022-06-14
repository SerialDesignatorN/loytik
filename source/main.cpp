#include <iostream>
#include "module.hpp"
#include "standard_functions.hpp"

int main(int c, char* argv[]) {
	// if arg is blank display schema
	if (c == 1) {
		printf("Schema: loytik [OPTIONS] file\n");
		printf("Type -h for possible options\n");
		return 0;
	}
	std::string version = "0.9.8";
	std::string path = argv[1];
	path = path.substr(0);
	if (c == 2) {
		if (argv[1][0] == '-' && argv[1][1] == 'v') {
			std::cout << "Loytik Live Interpreter v" << version << "\nby zeankun.dev" << std::endl;
			return 0;
		}
		// -h
		if (argv[1][0] == '-' && argv[1][1] == 'h') {
			printf("Loytik Live Interpreter v%s\nby zeankun.dev\n\n", version.c_str());
			printf("Schema: loyitik [options] [file]\n\n");
			printf("Options:\n");
			printf("-h = Help \n");
			printf("-v = Version\n");
			return 0;
		}
	}
	using namespace loytik;
	
	loytik_module m;
	
	add_standard_functions(m);
	
	m.add_external_function("greater", std::function<number(number, number)>([](number x, number y){
		return x > y;
	}));
	
	auto s_main = m.create_public_function_caller<void>("main");
	
	if (m.try_load(path.c_str(), &std::cerr)) {
		s_main();
	}
	
	return 0;
}
