#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void do_wc(int fd, const char *path);
static void die(const char *s);

int
main(int argc,char *argv[]){
	int i;

	if(argc < 2){
		fprintf(stderr, "%s：filename is not given\n", argv[0]);//argv[0]はプログラム名
		exit(1);
	}

	for(i=1;i < argc;i++){
		char *path = argv[i];
		int fd = open(path,O_RDONLY);
		if(fd < 0) die(path);
		do_wc(fd,argv[i]);
		if(close(fd) < 0) die(path);
	}
	exit(0);
}

#define BUFFER_SIZE 2048

static void
do_wc(int fd,const char *path){
	unsigned long count = 0;

	for(;;){

		unsigned char buf[BUFFER_SIZE];//BUFFER_SIZEはchar型配列の要素数

		int n = read(fd,buf,sizeof buf);
		if(n < 0) die(path);
		if(n == 0) break;

		unsigned long i;
		for(i=0;i<BUFFER_SIZE;i++){
			if(buf[i] == '\n'){//bufはポインタ、buf[i]はchar
				count++;
			}
		}
	}
	printf("行数：%lu\n", count);

}

static void
die(const char *s){
	perror(s);
	exit(1);
}