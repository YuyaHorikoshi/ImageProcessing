/* hyb256.bmp というファイルを読み込んで，xxx.bmpというファイル */
/* として、書き込む						*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"

unsigned char dat[1024*1024*3];

int main(){
  int cm,ht,wd;
	loadbmpfile("bamb.bmp",&cm,&ht,&wd,dat);		// 入力ファイル
	savebmpfile("xxx.bmp", cm,ht,wd,dat);			// 出力ファイル
	return 1;
}
