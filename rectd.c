/* rect.c  四角形を描く	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int x,y;
void draw_rect(void){
	glclear( );
glcolor(255,255,255);
gline(0,256,0,-256);
gline(-256,0,256,0);
	glcolor(255,0,0);		   //青色にセット
for(x=0;x<25;x++){
	grectangle(10+x,10+x,110-x,110-x); //四角形の線を描く
}	
	glflush( );
}

void main( ){
	ginit(1);
	gdisplay(draw_rect);
}