/* rect.c  �l�p�`��`��	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int x,y;
void draw_rect(void){
	glclear( );
glcolor(255,255,255);
gline(0,256,0,-256);
gline(-256,0,256,0);
	glcolor(255,0,0);		   //�F�ɃZ�b�g
for(x=0;x<25;x++){
	grectangle(10+x,10+x,110-x,110-x); //�l�p�`�̐���`��
}	
	glflush( );
}

void main( ){
	ginit(1);
	gdisplay(draw_rect);
}