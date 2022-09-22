#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
	int rc = fork();
	if ( rc < 0 ){
		std::cout << "fork fail~" << std::endl;
	}else if ( rc == 0 ){
		std::cout << "hello" << std::endl;
		exit(0);
//		return 1;
	}else{
		//rc = fork();
//		rc = 1;
		pid_t rt = waitpid(rc, NULL, 0);
		std::cout << "goodbye" <<std::endl;
	}

	return 0;
}
