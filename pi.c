/* pi.c  Monte Carlo –@‚É‚æƒÎ‚ÌŒvZ	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
void disp(void){
	int		x, y, r = 256;		// ”¼Œa256
	int		j, C, R;
	C=0;						// 1/4‰~‚Ì’†‚É“ü‚é“_‚Ì”
	R=0;						// ³•ûŒ`‚Ì’†‚É“ü‚é“_‚Ì”
	glclear();
	for(j=0; j<1000000; j++){
		x = randi(r);			// 0`255‚Ì³®”‚Ì—”
		y = randi(r);
		R = R+1;				// 1‚ğ—İÏ
		if((x*x+y*y) < (r*r)) {
			C = C+1; 	  		// 1/4‚Ì‰~‚Ì’†‚È‚ç+‚P
			glcolor(255,0,0);	// ÔF‚Å•`‰æ
			gpnt(x,y);
		}else {
			glcolor(0,255,0);	// —ÎF‚Å•`‰æ
			gpnt(x,y);
		}
	}
	glflush();
	printf("Pi=%f\n",4.0*C/R);	 // PI‚ÌŒvZŒ‹‰Ê
}

void main(){
	ginit(1);
	gdisplay(disp);
}