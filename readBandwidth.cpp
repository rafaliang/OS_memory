#include "utility.h"

double getBandwidth(){
	unsigned long long arraySize = 1024*1024*512;
	unsigned long long arrayStride = 64;
	unsigned long long num = arraySize/sizeof(unsigned long long);
	unsigned long long* arr = new unsigned long long[num];
	unsigned long long steps = 1024*1024*32;
	unsigned long long idx=0;

	arrayStride/=sizeof(unsigned long long);
	unsigned long long i;
	for (i=0;i<num;++i){
		arr[i]=(i+arrayStride)%num;
	}

	for (i=0;i<num;++i){
		idx = arr[idx];
	}

	idx=0;
	uint64_t start,end;
	i=0;
	rdtsc();
	rdtscp();
	start=rdtsc();
	for (;i<steps/128;++i){
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
		idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];idx = arr[idx];
	}
	end=rdtscp();
	delete[] arr;
	return (end-start)*1.0/steps;
}

int main(){
	//cout << getBandwidth() << endl;
	cout << "size of unsigned long long: "<<sizeof(unsigned long long)<<endl;
	cout << 2700000000*1.0*64/getBandwidth()<< endl;
	//cout << getBandwidth() << endl;
	return 0;
}