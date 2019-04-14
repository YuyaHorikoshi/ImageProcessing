/* line.c	緑色の線を一本引く*/
#include <stdio.h>
#include "opgls.ft"

void draw_line(void){
	glclear( );				//画面クリア
	glcolor(0,255,0);		//色を緑色にする
	gline(-100,-50,70,10);	//点(-100,-50)から点(70,10)に線を引く
	glflush( );				//実際に画面に表示する
}

int main( ){
	ginit(1);				//画面の初期化
	gdisplay(draw_line);	//draw_line関数を実行する
return 0;
}