/*dot.c 　赤い点を４個打つ*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
int x,y,k,c,sum;
int ratio=1;

void	dotpoints(void){
	glclear( );				// 画面クリア
	glcolor(255,255,255);		// 色を赤にする
for(k=0;k<24;k++){
for(y=0;y<255;y++){
for(x=0;x<255;x++){
sum=(x/(ratio+1))+(y/(ratio+1));
if(sum%2==0){
 gpnt(x,y);
}


}			// 座標(6,10)に点を打
}
	glflush( ); 			// 実際に画面に表示する
	ratio++;
	sleep(1);
	glclear();
}
}

int main( ){
	ginit(1);				// 画面の初期化
	gdisplay(dotpoints);	// dotpointsを実行
	return 0;
}