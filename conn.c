/*dot.c 　赤い点を４個打つ*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

double x,y,b;
double a=0.01;
int k=10;

void	dotpoints(void){
	glclear( );				// 画面クリア
	glcolor(255,255,255);		// 色を赤にする
	gline(-620,0,620,0);
	gline(0,620,0,-620);
for(b=-10;b<=10;b++){
for(x=-20;x<=20;x++){

y=a*pow(x*k,2)+b*k;
glcolor(255,255,255);
gpnt(x*k,y);
if(x==20){
 break;
}
glcolor(0,0,255);
gline(x*k,y,(x+1)*k,a*pow((x+1)*k,2)+b*k);

}
}				// 座標(6,11)に点を打つ
	glflush( ); 			// 実際に画面に表示する
}

int main( ){
	ginit(1);				// 画面の初期化
	gdisplay(dotpoints);	// dotpointsを実行
	return 0;
}