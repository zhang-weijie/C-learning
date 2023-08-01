#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void main(){
	const char * p_name = NULL;
	int son1_pid, son2_pid, grandson1_pid, grandson2_pid, grandson3_pid, grandson4_pid, clock = 0;
	
	son1_pid = fork();
	
	if (son1_pid){
		son2_pid = fork();
		if (son2_pid)
			p_name = "parent";
		else {
			grandson3_pid = fork();
			if (grandson3_pid){
				grandson4_pid = fork();
				if (grandson4_pid)
					p_name = "son2";
				else
					p_name = "grandson4";
			}
			else
				p_name = "grandson3";
			
		}
	} else { 
		grandson1_pid = fork();
		if (grandson1_pid){
			grandson2_pid = fork();
			if (grandson2_pid)
				p_name = "son1";
			else
				p_name = "grandson2";
		} else
			p_name = "grandson1";
	}
	
	while (1){
		printf("afer %d sec, p_name:%s, p_id: %d \n",clock,p_name,getpid());
		clock++;
		sleep(1);
	}
}

