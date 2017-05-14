#include "utility.h"

double getAccessTime(int arraySize, int arrayStride){
	unsigned int num = arraySize/sizeof(void*);
	void** arr = new void*[num];
	unsigned int steps = 1024*1024*32;
	//int* arr=(int*)malloc(arraySize);
	unsigned int i,j=0;
	for (i=0;i<num;++i){
		arr[i] = (void*) &arr[(i+arrayStride)%num];
	}

	void* p = arr[0];
	uint64_t start,end;
	i=0;
	rdtsc();
	end=rdtscp();
	start=rdtsc();
	for (;i<steps;++i){
		p = *p;
	}
	end=rdtscp();
	delete[] arr;
	return (end-start)*1.0/steps;
}

int main(){
	unsigned int arrayStride = 32;
	unsigned int arraySize = 32;     
	cout << "stride: " << arrayStride << endl;
	int outerLoop = 24;
	vector<double> res;

	for (int i=0;i<outerLoop;++i){
		double time=getAccessTime(arraySize,arrayStride);
		res.push_back(time);
		cout << i+5 << "\t" << time << endl;
		arraySize*=2;
	}
	
	return 0;
}
