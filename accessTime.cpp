#include "utility.h"

double getAccessTime(unsigned long long arraySize, unsigned long long arrayStride){
	unsigned long long num= arraySize/sizeof(unsigned long long);
	unsigned long long* arr = new unsigned long long[num];
	unsigned long long steps = 1024*1024*1024;
	//int* arr=(int*)malloc(arraySize);
	arrayStride/=sizeof(unsigned long long);
	unsigned long long i;
	for (i=0;i<num;++i){
		arr[i]=(i+arrayStride)%num;
	}

	unsigned long long idx=0;
	uint64_t start,end;
	i=0;
	rdtsc();
	end=rdtscp();
	start=rdtsc();
	for (;i<steps;++i){
		idx = arr[idx];
	}
	end=rdtscp();
	delete[] arr;
	return (end-start)*1.0/steps;
}

double getAccessTime2(unsigned int arraySize, unsigned int arrayStride){
	unsigned int num = arraySize/sizeof(node);
	arrayStride /= sizeof(node);
	node** arr = new node*[num];
	unsigned int steps = 1024*1024*32;
	//int* arr=(int*)malloc(arraySize);
	//node** arr = (node**)malloc(arraySize);
	unsigned int i;
	for (i=0;i<num;++i){
		arr[i]=new node();
	}
	for (i=0;i<num;++i){
		arr[i]->next=arr[(i+arrayStride)%num];
	}
	node* n=arr[0];
	uint64_t start,end;
	i=0;
	rdtsc();
	end=rdtscp();
	start=rdtsc();
	for (;i<steps;++i){
		n = n->next;
	}
	end=rdtscp();
	delete[] arr;
	return (end-start)*1.0/steps;
}

int main(){
	int initialSize = 8;
	unsigned int arrayStride = 128;
	unsigned int arraySize = 1<<initialSize;     
	cout << "stride: " << arrayStride << endl;
	cout << "initial arraysize: "<<arraySize<<endl;
	int outerLoop = 30-initialSize;
	vector<double> res;

	for (int i=0;i<outerLoop;++i){
		double time=getAccessTime(arraySize,arrayStride);
		res.push_back(time);
		cout << i+initialSize << "\t" << time << endl;
		arraySize*=2;
	}
	
	return 0;
}
