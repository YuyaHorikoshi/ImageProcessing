/* rect.c  四角形を描く	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int x,y;
void draw_rect(void){
	glclear( );
for(x=0;x<16;x++){
	color16(1+x);		   //黄色にセット
	grect(-250+30*x,128,-220+30*x,0);	       //黄色で中塗りした四角形を描く
}

for(x=0;x<16;x++){
glcolor(16+16*x,16+16*x,16+16*x);
grect(-250+30*x,-10,-220+30*x,-138) ;
}

	glflush( );
}

void main( ){
	ginit(1);
	gdisplay(draw_rect);
}