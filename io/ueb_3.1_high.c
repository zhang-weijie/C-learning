#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define N_BUFFER 128

int main(int argc, char * argv[]){
	char buffer[N_BUFFER];
	FILE *fp_in = NULL, *fp_out = NULL;
	char * p = NULL;	
	
	time_t t_0 = time(NULL), t_1 ; // timer init
 	clock_t tCPU_0 = clock() , tCPU_1;
 	float tCPU_del;

	fp_in = fopen("./geheim.in","r");
	fp_out = fopen("./geheim.out","a");
	
	
	while (fgets(buffer,sizeof(buffer),fp_in) != NULL){
		p = strstr(buffer,argv[1]);
		if (p) { 
        		printf("String found\n"); 
        		printf("First occurrence of string '%s' in buffer is '%s'", argv[1], p); 
    		} else
        		printf("String not found\n");
		fputs(buffer, fp_out);
	}
	
	fclose(fp_in);
	fclose(fp_out);
	
	
	t_1 = time(NULL);
	tCPU_1 = clock();
 	tCPU_del = (float)(tCPU_1 - tCPU_0)/CLOCKS_PER_SEC;
 	printf("Dauer = %ld sec, = %f sec \n",(long)(t_1-t_0),tCPU_del);
	
	exit(0);
}
