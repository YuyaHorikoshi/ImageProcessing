/*dot.c �@�Ԃ��_���S�ł�*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
void	dotpoints(void){
	glclear( );				// ��ʃN���A
	glcolor(255,0,0);		// �F��Ԃɂ���
	gpnt(6,10);				// ���W(6,10)�ɓ_��ł�
	gpnt(5,10);				// ���W(5,10)�ɓ_��ł�
	gpnt(5,11);				// ���W(5,11)�ɓ_��ł�
	gpnt(6,11);				// ���W(6,11)�ɓ_��ł�
	glflush( ); 			// ���ۂɉ�ʂɕ\������
}

int main( ){
	ginit(1);				// ��ʂ̏�����
	gdisplay(dotpoints);	// dotpoints�����s
	return 0;
}