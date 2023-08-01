#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


#define N_BUFFER 128

int main(int argc, char *argv[]){
	int nread = N_BUFFER;
	char buffer[N_BUFFER];
	
	time_t t_0 = time(NULL), t_1;
	clock_t tCPU_0 = clock(), tCPU_1;
	float tCPU_del;
	
	int in = open("geheim.in",O_RDONLY);
	int out = open("geheim.out", O_WRONLY | O_CREAT);
	

	char * p = NULL;	
	while (N_BUFFER == nread){
		nread = read(in, buffer, N_BUFFER);
		p = strstr(buffer,argv[1]);
		if (p){
			printf("String found!\n");
			printf("First occurence of string '%s' in buffer is '%s'\n", argv[1], p);
		} else 
			printf("String not found!\n");
		write(out,buffer,nread);
	}

	close(in);
	close(out);
	
	t_1 = time(NULL);
	tCPU_1 = clock();
	tCPU_del = (float)(tCPU_1 - tCPU_0)/CLOCKS_PER_SEC;
	printf("Dauer = %ld sec, = %f sec \n", (long)(t_1 - t_0), tCPU_del);	

	exit(0);
}
