#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Claire Kraft
date: 9/16/2020
Lesson 7 project, learning loops with arrays. */

int main(int argc, char *argv[]) {

/* all the variables were named here */

	float a[3];
	float sum;
	float avg;
	int i;
	
	a[0]=3;
	a[1]=5;
	a[2]=8;
	a[3]=11;
	
/* this is the code for the loop. this loop starts at i=0 will go until i is 4 or greater. 
i++ means i=i+1, it increases in increments of one.*/
	
	for(i=0;i<4;i++){
		sum=sum+a[i];
		printf("%f\n",sum);
	}
	
/* the average is the sum from the loop divided by the number of numbers being averaged. */
	
	avg= sum/4;
	printf("the answer is %f\n",avg);
	return 0;
}
