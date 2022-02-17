#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Claire Kraft 
9/20/2020
Lesson 9: Learning how to input from a file 
*/

int main(int argc, char *argv[]) {
		/* all the variables were named here */

	float a[3];
	float sum;
	float avg;
	int i;
	
	FILE *fp;
	
// variables are assigned
	fp = fopen("in.txt","r");
	fscanf(fp,"%g",&a[0]);
	fscanf(fp,"%g",&a[1]);
	fscanf(fp,"%g",&a[2]);	
	
	fclose (fp);
	
/* this is the code for the loop. this loop starts at i=0 will go until i is 4 or greater. 
i++ means i=i+1, it increases in increments of one.*/
	
	for(i=0;i<3;i++){
		sum=sum+a[i];
		printf("%f\n",sum);
	}
	
/* the average is the sum from the loop divided by the number of numbers being averaged. */
	
	avg= sum/3;
	printf("\nthe average is %f\n",avg);
	return 0;
}
