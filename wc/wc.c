#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int do_wc(const char *path);
static void die(const char *s);

int
main(int argc,char *argv[]){
	int i;

	if(argc < 2){
		fprintf(stderr, "%s：filename is not given\n", argv[0]);//argv[0]はプログラム名
		exit(1);
	}

	for(i=1;i < argc;i++){
		int count = do_wc(argv[i]);
		// int *p_co = &count;
		printf("行数：%d\n",count);
		count = 0;
	}

	exit(0);
}

#define BUFFER_SIZE 2048

static int
do_wc(const char *path){
	int fd;//ファイルディスクリプタ
	unsigned char buf[BUFFER_SIZE];//BUFFER_SIZEはchar型配列の要素数
	int n;

	fd = open(path,O_RDONLY);

	int count = 0;
	for(;;){
		n = read(fd,buf,sizeof buf);
		if(n < 0) die(path);
		if(n == 0) break;

		int i;
		for(i=0;i<BUFFER_SIZE;i++){
			// printf("%p\n",buf);
			if(buf[i] == '\n'){//bufはポインタ、buf[i]はchar
				count++;
			}
		}
	}

	if(close(fd)<0)die(path);

	return count + 1;

}

static void
die(const char *s){
	perror(s);
	exit(1);
}