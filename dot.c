/*dot.c 　赤い点を４個打つ*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
void	dotpoints(void){
	glclear( );				// 画面クリア
	glcolor(255,0,0);		// 色を赤にする
	gpnt(6,10);				// 座標(6,10)に点を打つ
	gpnt(5,10);				// 座標(5,10)に点を打つ
	gpnt(5,11);				// 座標(5,11)に点を打つ
	gpnt(6,11);				// 座標(6,11)に点を打つ
	glflush( ); 			// 実際に画面に表示する
}

int main( ){
	ginit(1);				// 画面の初期化
	gdisplay(dotpoints);	// dotpointsを実行
	return 0;
}