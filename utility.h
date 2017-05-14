#ifndef utility_H
#define utility_H

#include <iostream>
#include <time.h>
#include <vector>
#include <unistd.h>  
#include <sys/types.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h> 
#include <x86intrin.h>
#include <sys/syscall.h>
#include <typeinfo> 


using namespace std;

struct node{
	node* next;
	//unsigned int num;
	node(){
		next = NULL;
		//num=d;
	}
	
};

static inline uint64_t rdtsc(){
	unsigned int cycles_high, cycles_low;

	asm volatile ("CPUID\n\t"
								"RDTSC\n\t"
								"mov %%edx, %0\n\t"
								"mov %%eax, %1\n\t"
								: "=r" (cycles_high), "=r" (cycles_low)
								::"%rax", "%rbx", "%rcx", "%rdx");
	
	return ((uint64_t)cycles_high << 32) | cycles_low;
}

static inline uint64_t rdtscp(){
	unsigned int cycles_high1, cycles_low1;
	
	asm volatile("RDTSCP\n\t"
							"mov %%edx, %0\n\t"
							"mov %%eax, %1\n\t"
							"CPUID\n\t"
							: "=r" (cycles_high1), "=r" (cycles_low1)
							::"%rax", "%rbx", "%rcx", "%rdx");
	
	return ((uint64_t)cycles_high1 << 32) | cycles_low1;
}
#endif