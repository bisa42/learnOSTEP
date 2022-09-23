#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

int main(){
	int rc = fork();
	if ( rc < 0 ) {
		std::cout << "fork fail!" << std::endl;
	}else if ( rc == 0 ){
	//	int cc = wait(NULL);
		std::cout << "child pid:" << getpid() << std::endl;
		exit(1);
	}else {
		int wc = wait(NULL);	// 区别是谁先运行
		std::cout << "parent pid:" << getpid() << std::endl;
	}
	
	
	return 0;
}
