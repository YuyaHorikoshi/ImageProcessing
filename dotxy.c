/*dot.c �@�Ԃ��_���S�ł�*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
int x,y;
void	dotpoints(void){
	glclear( );				// ��ʃN���A
	glcolor(255,0,0);		// �F��Ԃɂ���
for(x=0;x<50;x++){
	gpnt(x,4*x);
}
for(x=0;x<50;x++){
glcolor(255,255,255);				// ���W(5,11)�ɓ_��ł�
	gpnt(x,x);
}				// ���W(6,11)�ɓ_��ł�
	glflush( ); 			// ���ۂɉ�ʂɕ\������
}

int main( ){
	ginit(1);				// ��ʂ̏�����
	gdisplay(dotpoints);	// dotpoints�����s
	return 0;
}