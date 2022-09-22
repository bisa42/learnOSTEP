#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
// #include <string>
int main(){
	int f = open("1.txt",O_WRONLY|O_APPEND);
	int rc = fork();
	if( rc < 0 ){
		std::cout << "fork fail!" << std::endl;
	}else if( rc == 0 ){
		char words[] = "I'm child to write~\n";
		write(f, words, sizeof(words));
	}else {
		char words[] = "I'm parent to write~\n";
		write(f, words, sizeof(words));
	}
	close(f);
	
	return 0;
}
