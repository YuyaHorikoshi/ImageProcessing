/* line.c	�ΐF�̐�����{����*/
#include <stdio.h>
#include "opgls.ft"

void draw_line(void){
	glclear( );				//��ʃN���A
	glcolor(0,255,0);		//�F��ΐF�ɂ���
	gline(-100,-50,70,10);	//�_(-100,-50)����_(70,10)�ɐ�������
	glflush( );				//���ۂɉ�ʂɕ\������
}

int main( ){
	ginit(1);				//��ʂ̏�����
	gdisplay(draw_line);	//draw_line�֐������s����
return 0;
}