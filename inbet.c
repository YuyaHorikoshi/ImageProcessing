#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int N=20;

void disp(void){
	double p0x=-170,p0y=20.0,q0x=-80.0,q0y=50.0;  // �ŏ��̍��W
	double pNx=170.0,pNy=50.0,qNx=150.0,qNy=-150; // �Ō�̍��W
	double dpx, dpy, dqx, dqy;
double px,py,qx,qy;
	int j;
	glclear();
// �X�^�[�g�̐F
glcolor(255,255,0);
// �X�^�[�g�̐�
gline(p0x,p0y,q0x,q0y);
// �I��̐�
gline(pNx,pNy,qNx,qNy);
// ���̑�����
dpx=(pNx-p0x)/N;
dpy=(pNy-p0y)/N;
dqx=(qNx-q0x)/N;
dqy=(qNy-q0y)/N;
// ���������_ p,q
px=dpx;
py=dpy;
qx=dqx;
qy=dqy;
 // �����_�̐F
glcolor(0,255,0);
	for(j=1; j<N; j++){
	gline(p0x+px*j,p0y+py*j,q0x+qx*j,q0y+qy*j);	
	}
	glflush();
}

void main(){
	ginit(1);
	gdisplay(disp);
}
