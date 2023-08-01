#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#define N_CYCLE 7

void main(){
	const char * p_name = NULL;
	int child1_pid, child2_pid, clock = 0;
	char is_child2 = 0;
	
	child1_pid = fork();
	
	if (child1_pid){
		child2_pid = fork();
		if (child2_pid)
			p_name = "parent";
		else {
			p_name = "child2";
			is_child2 = 1;
		}
	} else 
		p_name = "child1";
	
	while (1){
		printf("afer %d sec, p_name:%s, p_id: %d \n",clock,p_name,get_pid());
		if (clock == 7 && is_child2){
			kill(child1_pid,1);
			printf("child1 is killed by child2!\n");
		}
		clock++;
		sleep(1);
	}
}

