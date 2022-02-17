
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
 

int main(int argc, char *argv[]) {
	
	char filename[50];
	char sa[10];
	int a;
	
    printf("here\n");

    int i,j,k,n;
    char name[200];
    char num[10];
    float sumred;
    float avgred;
    float sumgreen;
    float avggreen; 
    float sumblue;
    float avgblue;
    float sumr;
    float sumg;
    float sumb;
    float varred;
    float vargreen;
    float varblue;
    float stdevred;
    float stdevblue;
    float stdevgreen;
    float min;
    float max;
    float ranger;
    float rangeg;
    float rangeb;
    
    unsigned char *raw;
    unsigned int img[102][240][3];
    
    FILE *fp;
    FILE *fpout;
    
    fpout=fopen("output.txt","w");
    
    
    printf("here\n");
    
    // strcpy(name,"raw_images/sw001.bin");
    
    for(a=0;a<=143;a++) {
	strcpy(filename,"raw_images\\");
	strcat(filename, "sw");
	sprintf(sa,"%d",a);
	strcat(filename,sa);
	strcat(filename,"01.bin");
	// printf("%s\n",filename);
		
		
	
    
    	fp = fopen(filename,"r");
    	if(fp==NULL) {
        	printf("no file\n");
    }
    	raw = (unsigned char *) calloc(102*240*3,sizeof(unsigned char));
    	fread(raw,1,102*240*3,fp);
    	
    
    	fclose(fp);
    
    	n=0;
    	for(k=0;k<3;k++) {
        	for(j=0;j<240;j++) {
            	for(i=0;i<102;i++) {
                	img[i][j][k] = *(raw+n);
                	n++;
            }
        }
    }
    	free(raw);
    	sumred = 0;
    	sumgreen = 0;
    	sumblue = 0;
    	sumr=0;
    	sumg=0;
    	sumb=0;
    	for(j=0;j<240;j++) {
        	for(i=0;i<102;i++) {
            	sumred=sumred+img[i][j][0];
            	sumgreen=sumgreen+img[i][j][1]; 
            	sumblue=sumblue+img[i][j][2];
        	}
        
    	}
    	avgred= sumred/(240.0*102.0);
    	// printf("the average of the red is %f\n",avgred);
    	avggreen= sumgreen/(240.0*102.0);
    	// printf("the average of the red is %f\n",avggreen);
    	avgblue= sumblue/(240.0*102.0);
    	// printf("the average of the red is %f\n",avgblue);
    
    	sumr = 0;
    	sumg = 0;
    	sumb = 0;
    	for(j=0;j<240;j++) {
        	for(i=0;i<102;i++) {
            	sumr=sumr+((img[i][j][0])-avgred)*((img[i][j][0])-avgred);
            	sumg=sumg+((img[i][j][1]-avggreen)*(img[i][j][1]-avggreen));  
				sumb=sumb+((img[i][j][2]-avgblue)*(img[i][j][2]-avgblue)); 
        	}
        
    	}
    	varred= sumr/(240.0*102.0);
    	// printf("the varience of red is %f\n",varred);
    
    	vargreen= sumg/(240.0*102.0);
    	// printf("the varience of green is %f\n",vargreen);
    	varblue= sumb/(240.0*102.0);
    	// printf("the varience of blue is %f\n",varblue);
    	
    	/* stdevred = sqrt(varred);
    	printf("the standard variation of red is %f\n",stdevred);
    	stdevgreen = sqrt(vargreen);
    	printf("the standard variation of green is %f\n",stdevgreen);
    	stdevblue = sqrt(varblue);
    	printf("the standard variation of blue is %f\n",stdevblue); */
    
    
    	
    
    	// int i;
   		// float tmp;
    	
    
    
    	n = 0;
    	for(j=0;j<240;j++) {
        	for(i=0;i<102;i++) {
        	if(n==0) {
            	min = img[i][j][0];
            	max = img[i][j][0];
        	}
        	if(img[i][j][0]<min) {
                min = img[i][j][0];
        	}
        	if(img[i][j][0]>max) {
            	max = img[i][j][0];
        	}
        	n++;
    		}
		}
    	fclose(fp);
    	ranger = max;
    	// printf("red min %g max %g\n",min,max);
    	// printf("the range of the red is %g\n",ranger);
    
    		n = 0;
    		for(j=0;j<240;j++) {
        	for(i=0;i<102;i++) {
        	if(n==0) {
            	min = img[i][j][1];
            	max = img[i][j][1];
        	}
        	if(img[i][j][1]<min) {
                min = img[i][j][1];
        	}
        	if(img[i][j][1]>max) {
            	max = img[i][j][1];
        	}
        	n++;
    		}
		}
    	fclose(fp);
    	rangeg= max;
    	// printf("green min %g max %g\n",min,max);
    	// printf("the range of the green is %g\n",rangeg);
    
    	n = 0;
    	for(j=0;j<240;j++) {
        	for(i=0;i<102;i++) {
        	if(n==0) {
            	min = img[i][j][2];
            	max = img[i][j][2];
        	}
        	if(img[i][j][2]<min) {
                min = img[i][j][2];
        	}
        	if(img[i][j][2]>max) {
            	max = img[i][j][2];
        	}
        	n++;
    		}
		}
    	fclose(fp);
    	rangeb = max;
    	// printf("blue min %g max %g\n",min,max); 
    	// printf("the range of the blue is %g\n",rangeb);	
    	
    	fprintf(fpout,"%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",a,avgred,avggreen,avgblue,varred,vargreen,varblue,ranger,rangeg,rangeb);
    	
	}
	fclose(fpout);
	
	return 0;
}



