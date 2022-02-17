#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
Claire Kraft
date: 9/16/2020
Lesson 5 - learning Arrays while taking the average of four numbers 
*/


int main(int argc, char *argv[]) {
	float a[3];
	float avg;
	
// the number value in the [] always starts with 0 in C
	
	a[0]=3;
	a[1]=5;
	a[2]=8;
	a[3]=11;
	
	avg= (a[0]+a[1]+a[2]+a[3])/4;
	printf("the average of %f %f %f and %f is %f\n",a[0],a[1],a[2],a[3],avg);
	return 0;
}
