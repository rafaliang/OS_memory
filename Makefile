ll:
	g++ -pthread -std=c++11 -O0  accessTime.cpp utility.h -o accessTime
clean:
	rm -rf *o accessTime
