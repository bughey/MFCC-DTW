.PHONY: build
build:
	g++ *.cpp -o bin/main

.PHONY: run
run:
	bin/main