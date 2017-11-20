#include <stdio.h>

int main(void){
	int num = 1;//int型変数
	int *p_num;//int型のポインタ変数定義
	p_num = &num;//ポインタ変数p_numに変数numアドレスを代入

	printf("int型変数numの値：%d\n",num);
	printf("int型ポインタ変数p_numのアドレス：%p\n",p_num);
	printf("int型ポインタ変数p_numの参照先の値：%d\n",*p_num);//*p_numでp_numに格納された値を参照している

	return 0;
}