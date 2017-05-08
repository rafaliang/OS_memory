#include "utility.h"

double getAccessTime(int arraySize, int arrayStride){
	int num = arraySize/4;
	int* arr = new int[num];
	int i,j=0;
	for (i=0;i<num;++i){
		arr[i]=j;
		j+=arrayStride;
		if (j>=num) j%=num;
	}

	int idx=0;
	uint64_t start,end;
	i=0;
	rdtsc();
	end=rdtscp();
	start=rdtsc();
	for (;i<num;++i){
		idx = arr[idx];
	}
	end=rdtscp();
	return (end-start)*1.0/num;
}

int main(){
	/*
	int innerLoop = 10000;  // innerloop
	int len = 1024;       // number of ints
	int outerLoop = 50;
	vector<double> res;

	for (int i=0;i<outerLoop;++i){
		node* p = new node(len);
		node* head = p;
		int j;
		uint64_t start,end;
		for (j=0;j<innerLoop;++j){
			node* q = new node(len);
			p->next = q;
			p = p->next;
		}
		start = rdtsc();
		p = head;
		while(p->next) p=p->next;
		end = rdtscp();
		res.push_back((end-start)*1.0/innerLoop);
		cout << (end-start)*1.0/innerLoop << endl;
		len*=2;

	}
	*/

	int arraySize = 256;     //in B
	int arrayStride = 32;
	int outerLoop = 25;
	vector<double> res;

	for (int i=0;i<outerLoop;++i){
		double time=getAccessTime(arraySize,arrayStride);
		res.push_back(time);
		cout << i << "\t" << time << endl;
		arraySize*=2;
	}
	return 0;
}