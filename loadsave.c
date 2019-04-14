/* BMP loadbmpfile とsavebmpfile のテストプログラム	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
unsigned char  dat[1024*1024];	// 画像ファイルのサイズの最大値
int main(int argc, char *argv[]){
	int  hite, wide, cm;
	if(argc != 3){
		printf("使用法:: %s  src.bmp, dest.bmp\n", argv[0]);
		exit(-1);
 	}
	loadbmpfile(argv[1], &cm, &hite, &wide, dat);
	printf("cm=%d, hite=%d,  wide=%d\n" ,cm, hite, wide);
	savebmpfile(argv[2], cm, hite, wide, dat);
	return 0;
}