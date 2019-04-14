/*dot.c 　赤い点を４個打つ*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
int x,y;
void	dotpoints(void){
	glclear( );				// 画面クリア
	glcolor(255,0,0);		// 色を赤にする
for(x=0;x<50;x++){
	gpnt(x,4*x);
}
for(x=0;x<50;x++){
glcolor(255,255,255);				// 座標(5,11)に点を打つ
	gpnt(x,x);
}				// 座標(6,11)に点を打つ
	glflush( ); 			// 実際に画面に表示する
}

int main( ){
	ginit(1);				// 画面の初期化
	gdisplay(dotpoints);	// dotpointsを実行
	return 0;
}