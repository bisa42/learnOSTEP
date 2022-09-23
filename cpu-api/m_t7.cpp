#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	int rc = fork();
	if( rc < 0 ){
		printf("fork fail");
	}else if ( rc == 0){
		printf("child pid:%d\n", (int)getpid());
		fclose(stdout);
		printf("can U see me?");
	}else{
		int wc = wait(NULL);
		printf("parent pid:%d\n", (int)getpid());
		printf("U can see me now~\n");
	}
	return 0;
}
