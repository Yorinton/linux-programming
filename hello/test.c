#include <stdio.h>

int main(int argc,char *argv[]){

    char s[] = "hello world";

    int i;
    for(i=0;i<11;i++){
	    char *ps = &s[i];
	    /* *ps2 = &s[1];*/
	    printf("s[%d]:%p/%c\n",i,ps,s[i]);
	}

    return 0;

}
