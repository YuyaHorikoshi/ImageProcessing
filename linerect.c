/* line.c	緑色の線を一本引く*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int x,y;
void draw_line(void){
	glclear( );				//画面クリア
	glcolor(255,255,255);		//色を緑色にする
	gline(0,256,0,-256);	//点(-100,-50)から点(70,10)に線を引く
gline(-256,0,256,0);

glcolor(255,0,0);
for(x=0;x<100;x++){
gline(10+x,10,10+x,110);
}
glcolor(0,255,0);
for(x=0;x<100;x++){
gline(-10-x,10,-10-x,10+x);
}
glflush( );				//実際に画面に表示する
}

int main( ){
	ginit(1);				//画面の初期化
	gdisplay(draw_line);	//draw_line関数を実行する
return 0;
}