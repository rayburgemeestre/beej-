lib:
	cmake -B build
	cmake --build build
	sudo cmake --build build --target install

format:
	clang-format -i src/*
	clang-format -i examples/*
