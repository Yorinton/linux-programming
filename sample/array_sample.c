#include <stdio.h>

int main(void){

	//操作する配列の定義
	char chr[] = "Hello";
    int i_arr[] = {0, 1, 2, 3, 4};
    float f_arr[] = {0.0f, 0.1f, 0.2f, 0.3f, 0.4f};
    double d_arr[] = {0.0, 0.1, 0.2, 0.3, 0.4};

    //ポインタ変数の定義
    char *p_chr;
    int *p_int;
    float *p_flt;
    double *p_dbl;

    //アドレスを代入
    p_chr = chr;
    p_int = i_arr;
    p_flt = f_arr;
    p_dbl = d_arr;

    //出力
    printf("char型ポインタ変数p_chrの値：%p/参照先の値%c\n",p_chr,*p_chr);
    printf("配列charの１番目の要素のアドレス：%p/参照先の値%c\n",&chr[1],*(&chr[1]));
    printf("char型ポインタ変数(p_chr + 1):%p, 参照先の値:%c\n", p_chr + 1, *(p_chr + 1));
}