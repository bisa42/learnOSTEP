#include <iostream>
#include <unistd.h>
#include <stdio.h>
int main(){
	int rc = fork();
	if( rc < 0 ){
		std::cout << "fork fail" << std::endl;
		exit(1);
	}else if ( rc == 0 ){
		std::cout << "child's pid:" << getpid() << std::endl;
		//  int execl( const char *path, const char *arg, ...);
		// l是file，p是path；l要去路径下找文件、p要通过文件名找路径
		execl("/bin/ls", "-a", "-l", NULL);
		// NULL代表后面没有参数了
//		execlp("ls", "-a", "-l", "m_t4.cpp", NULL);
		char *argv[] = {"-a", "-l", "m_t4.cpp", NULL};
		// int execvp ( const char *file, char *const argv[]);	
//		execvp("ls", argv);		// v是参数数组
		char *envp[] = {"/bin"};	// e是环境变量数组，用户传进的环境会覆盖搜索的默认环境变量
		// int execle( const char *file, const char *arg, ..., char *const envp[]);
//		execle("ls", "-a", "-l", NULL, envp);
//		execvp("ls", argv);
		perror("error exec\n"); 	// exec很容易失败且没提示
		std::cout << "child's pid:" << getpid() << std::endl;
		exit(1);
	}else {
		std::cout << "parent's pid:" << getpid() << std::endl;
	}

	return 0;
}
