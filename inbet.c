#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
int N=20;

void disp(void){
	double p0x=-170,p0y=20.0,q0x=-80.0,q0y=50.0;  // 最初の座標
	double pNx=170.0,pNy=50.0,qNx=150.0,qNy=-150; // 最後の座標
	double dpx, dpy, dqx, dqy;
double px,py,qx,qy;
	int j;
	glclear();
// スタートの色
glcolor(255,255,0);
// スタートの線
gline(p0x,p0y,q0x,q0y);
// 終りの線
gline(pNx,pNy,qNx,qNy);
// 一回の増加量
dpx=(pNx-p0x)/N;
dpy=(pNy-p0y)/N;
dqx=(qNx-q0x)/N;
dqy=(qNy-q0y)/N;
// 中割した点 p,q
px=dpx;
py=dpy;
qx=dqx;
qy=dqy;
 // 中割点の色
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
