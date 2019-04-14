/* pi.c  Monte Carlo �@�ɂ�΂̌v�Z	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
void disp(void){
	int		x, y, r = 256;		// ���a256
	int		j, C, R;
	C=0;						// 1/4�~�̒��ɓ���_�̐�
	R=0;						// �����`�̒��ɓ���_�̐�
	glclear();
	for(j=0; j<1000000; j++){
		x = randi(r);			// 0�`255�̐������̗���
		y = randi(r);
		R = R+1;				// 1��ݐ�
		if((x*x+y*y) < (r*r)) {
			C = C+1; 	  		// 1/4�̉~�̒��Ȃ�+�P
			glcolor(255,0,0);	// �ԐF�ŕ`��
			gpnt(x,y);
		}else {
			glcolor(0,255,0);	// �ΐF�ŕ`��
			gpnt(x,y);
		}
	}
	glflush();
	printf("Pi=%f\n",4.0*C/R);	 // PI�̌v�Z����
}

void main(){
	ginit(1);
	gdisplay(disp);
}