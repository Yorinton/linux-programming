#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]){
    int i;
    
    printf("argc = %d\n",argc);
    for(i = 0;i < argc;i++){
    	int j;
    	for(j=0;j<5;j++){
    		char arg = argv[i][j];
    		char *pargs = &arg;
        	printf("argv[%d|%d]=%c/%p\n",i,j,arg,pargs);
        }
    }
    exit(0);
}
