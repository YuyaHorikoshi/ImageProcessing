/*dot.c �@�Ԃ��_���S�ł�*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
int x,y,k,c,sum;
int ratio=1;

void	dotpoints(void){
	glclear( );				// ��ʃN���A
	glcolor(255,255,255);		// �F��Ԃɂ���
for(k=0;k<24;k++){
for(y=0;y<255;y++){
for(x=0;x<255;x++){
sum=(x/(ratio+1))+(y/(ratio+1));
if(sum%2==0){
 gpnt(x,y);
}


}			// ���W(6,10)�ɓ_���
}
	glflush( ); 			// ���ۂɉ�ʂɕ\������
	ratio++;
	sleep(1);
	glclear();
}
}

int main( ){
	ginit(1);				// ��ʂ̏�����
	gdisplay(dotpoints);	// dotpoints�����s
	return 0;
}