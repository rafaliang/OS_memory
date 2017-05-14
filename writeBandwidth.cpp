#include "utility.h"

double getBandwidth(){
	unsigned long long arraySize = 1024*1024*64;
	unsigned long long arrayStride = 64;
	unsigned long long num = arraySize/sizeof(unsigned long long);
	unsigned long long* arr = new unsigned long long[num];
	
	
	arrayStride/=sizeof(unsigned long long);
	unsigned long long steps = num/arrayStride;
	unsigned long long i;
	for (i=0;i<num;++i){
		arr[i]=0;
	}

	unsigned long long idx=0;
	unsigned long long total=0;
	uint64_t start,end;

	int outerLoop=arrayStride;
	unsigned long long j=0;
	
	rdtsc();
	rdtscp();
	
	for (;j<outerLoop;++j){
		idx = j%arrayStride;

		//unsigned long long* arr = new unsigned long long[num];
		start=rdtsc();
		for (i=0;i<steps/128;++i){
			//start=rdtsc();
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride; arr[idx]=1; idx+=arrayStride;
			// end=rdtscp();
			// total+=(end-start);
			// cout << j << ":\t"<< end-start << endl;
			
		}
		end=rdtscp();
		//delete[] arr;
		//if (j>0)
		total+=(end-start);
		cout << j << ":\t"<< end-start << endl;

	}
	
	//
	return total*1.0/steps/(outerLoop);
}

int main(){
	//cout << getBandwidth() << endl;
	cout << "size of unsigned long long: "<<sizeof(unsigned long long)<<endl;
	cout << 2700000000*1.0*64/getBandwidth()<< endl;
	//cout << getBandwidth() << ed
	return 0;
}