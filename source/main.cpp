#include <iostream>
#include "module.hpp"
#include "standard_functions.hpp"

int main(int c, char* argv[]) {
	std::string version = "0.9.6";
	// load the path from shell
	// schema: ./loyitik /path/to/file.lytk
	std::string path = argv[1];
	path = path.substr(0);
	// check if any flags are passed
	// example: -v or --version
	// schema: ./loyitik -v
	if (c == 2) {
		if (argv[1][0] == '-' && argv[1][1] == 'v') {
			std::cout << "Loyitik Live Interpreter v" << version << "\nby zeankun.dev" << std::endl;
			return 0;
		}
		// -h
		if (argv[1][0] == '-' && argv[1][1] == 'h') {
			printf("Loyitik Live Interpreter v%s\nby zeankun.dev\n\n", version.c_str());
			printf("Schema: ./loyitik [options] [file]\n\n");
			printf("Options:\n");
			printf("-h = Help \n");
			printf("-v = Version\n");
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
