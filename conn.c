/*dot.c �@�Ԃ��_���S�ł�*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

double x,y,b;
double a=0.01;
int k=10;

void	dotpoints(void){
	glclear( );				// ��ʃN���A
	glcolor(255,255,255);		// �F��Ԃɂ���
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
}				// ���W(6,11)�ɓ_��ł�
	glflush( ); 			// ���ۂɉ�ʂɕ\������
}

int main( ){
	ginit(1);				// ��ʂ̏�����
	gdisplay(dotpoints);	// dotpoints�����s
	return 0;
}