/* line.c	�ΐF�̐�����{����*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int x,y;
void draw_line(void){
	glclear( );				//��ʃN���A
	glcolor(255,255,255);		//�F��ΐF�ɂ���
	gline(0,256,0,-256);	//�_(-100,-50)����_(70,10)�ɐ�������
gline(-256,0,256,0);

glcolor(255,0,0);
for(x=0;x<100;x++){
gline(10+x,10,10+x,110);
}
glcolor(0,255,0);
for(x=0;x<100;x++){
gline(-10-x,10,-10-x,10+x);
}
glflush( );				//���ۂɉ�ʂɕ\������
}

int main( ){
	ginit(1);				//��ʂ̏�����
	gdisplay(draw_line);	//draw_line�֐������s����
return 0;
}