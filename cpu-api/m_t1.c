#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	int x = 100;
	printf("hello, this is main~(pid%d)\n",(int)getpid());
	int rc = fork();
	if( rc < 0 ){
		printf("this's no thread~");
		exit(1);
	}else if ( rc == 0 ) {
		printf("hello, I am child (pid:%d)\n",(int) getpid());
		x = 50;
		printf("child's x = %d\n",(int)getpid());
	}else {
		printf("hello, I am parent (pid:%d)\n",(int) getpid());
		x = 90;
		printf( "parent's x = %d\n" ,x );
	}

	return 0;

}
