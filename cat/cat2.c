#include <stdio.h>
#include <stdlib.h>

int
main(int argc,char *argv[]){

	//基本openして読み書きして閉じる
	//オープン、クローズ、読み書きは失敗の場合のエラー処理を記述
	int i;

	for(i=1;i<argc;i++){

		FILE *f;//FILE・・fdのこと(ストリーム)
		int c;

		f = fopen(argv[i],"r");//f・・システムコールで言うfd

		if(!f){//fopenはエラーだとNULLを返す
			perror(argv[i]);
			exit(0);
		}
		//fgetcで読み込んだ結果をputcharで標準出力
		while((c = fgetc(f)) != EOF){//ストリームfから1バイト読み込んで返す
			if(putchar(c) < 0)exit(1);//cを標準出力に書き込み
		}

		if(fclose(f) == EOF){
			perror(argv[i]);
			exit(0);
		}
	}
	exit(0);
}