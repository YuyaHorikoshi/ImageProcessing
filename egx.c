/* 平滑化　フィルタ */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz		1024
#define		gp(y, x)	dat[(y)*wide+(x)]

unsigned  char	dat[MaxSiz*MaxSiz];
int	 			cm, wide, hite;
double				dn[MaxSiz][MaxSiz],
				dw[MaxSiz][MaxSiz];
int 	nline[3][3]={{1,1,1},			// 線形平滑化フィルタ		
					 {1,1,1},
					 {1,1,1}};
int		wline[3][3]={            {0,-1,-0},			// 重み付き線形平滑化フィルタ
					 {-1,5,-1},
					 {-0,-1,0}};
int xline[3][3]={{-1,0,1},
		 {-2,0,2},
		 {-1,0,1}};

int yline[3][3]={{-1,-2,-1},
		 {0,0,0},
		 {1,2,1}};

double px,py;


void	get_data (int  agc, char  **agv){
  	if (agc != 2){
		printf ("使用法:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile(agv[1], &cm, &hite, &wide, dat);
}

void	calc_diff (void){
	int		x, y, j, k;
int p=1;
	int		ddn, ddw ,ddc;			   // ddn:単純平均、ddw:中心に重み
  	for (y=1; y<hite-1; y++) for (x=1; x<wide-1; x++){
 		ddn = 0;		ddw = 0;px=0;py=0;
  		for (j=-1; j<2; j++) for (k=-1; k<2; k++){
			//ddn += gp(y+j, x+k)*nline[j+1][k+1];	// 重みなし
			//ddw += gp(y+j, x+k)*wline[j+1][k+1];	// 重み付き
                        //ddc += exp(-(pow(j,2)+pow(k,2)/2*p))*exp(-pow(fabs(gp(y,x)-gp(y+j, x+k)),2)/2*p);
px+=xline[j+1][k+1]*gp(y+j,x+k);
py+=yline[j+1][k+1]*gp(y+j,x+k);
//printf("%d\n",xline[j][k]);
  		}
  		//dn[y][x] = ddn/9;
  		//dw[y][x] = ddw;
		dw[y][x]=abs(sqrt(pow(px,2)+pow(py,2)));

  	}
}

void show(void){
	unsigned  char	gr, ddx, ddy;
	int				x, y;
	glclear ( );
    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		gr = gp(y, x);			//原画像の表示
		glcolor (gr, gr, gr);	gpnt (x, y);
	}
    for (y=1; y<hite-1; y++) for (x=1; x<wide-1; x++){
		ddx = dw[y][x];			// 線形平滑化フィルタ
		glcolor (ddx, ddx, ddx);	gpnt (x-wide, y);

		//ddy = dw[y][x];			// 重み付き線形平滑化フィルタ
		//glcolor (ddy, ddy, ddy);	gpnt (x-wide, y-hite);	
	}
	glflush ( );
}

void	main (int  argc, char  **argv){
	get_data (argc, argv);
	calc_diff ( );
	ginit (1);
	gdisplay (show);
}