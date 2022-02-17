#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 
Claire Kraft
date: 9/16/2020
lesson three - taking the average of three numbers
*/

int main(int argc, char *argv[]) {
	
/* variables are named here */

	float a,b,c;
	float avg;
	
/* the variables are defined here */

	a=3;
	b=5;
	c=8;
	avg= (a+b+c)/3;
	
	printf("the answer is %f\n",avg);
	return (0);
}
