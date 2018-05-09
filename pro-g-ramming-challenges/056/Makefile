default: release

release:
	clang++ -std=c++17 -stdlib=libstdc++ -Wall -Werror -Wpedantic -L/usr/lib/ -lboost_program_options -I/usr/include/ pwgen.cpp -o pwgen
run:
	@if [ -f ./pwgen ]; then ./pwgen ${ARGS}; else echo "run make first"; fi
clean:
	rm ./pwgen

