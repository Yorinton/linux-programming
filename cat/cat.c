#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void do_cat(const char *path);
static void die(const char *s);

int
main(int argc,char *argv[]){
	int i;

	if(argc < 2){//引数が指定されてない場合(1個目はコマンド名なので" < 2 ")
		fprintf(stderr, "%s：filename is not given\n", argv[0]);//argv[0]はプログラム名
		exit(1);
	}
	//1番目の引数から順番にdo_catを実行していく
	for(i=1;i<argc;i++){
		do_cat(argv[i]);//argv[i]はi番目の引数で指定されたファイル名
	}
	exit(0);
}

#define BUFFER_SIZE 2048

static void
do_cat(const char *path){
	int fd;//ファイルディスクリプタ
	unsigned char buf[BUFFER_SIZE];
	int n;

	//指定したパスのファイルを開く(ストリームを作る)
	fd = open(path,O_RDONLY);
	if(fd < 0) die(path);

	//ファイルを読んで、標準出力に書き出す
	for(;;){
		n = read(fd,buf,sizeof buf);
		if(n < 0) die(path);
		if(n == 0) break;
		if((write(STDOUT_FILENO,buf,n) < 0))die(path);
	}

	//ストリームを破棄する
	if(close(fd) < 0) die(path);
}

static void
die(const char *s){
	perror(s);
	exit(1);
}



