.build_3rd:
	mkdir libs
	git clone git@github.com:Ogurrr/eten-algorithm.git libs/eten-algorithm
	
.build:
	g++ src/main.cpp -c -o build/main.o
	make -C libs/eten-algorithm .build
	g++ build/*.o -lssl -g -lcrypto -o build/eten-sum
	rm build/*.o