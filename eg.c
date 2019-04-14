/* �������@�t�B���^ */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz		1024
#define		gp(y, x)	dat[(y)*wide+(x)]

unsigned  char	dat[MaxSiz*MaxSiz];
int	 			cm, wide, hite;
int				dn[MaxSiz][MaxSiz],
				dw[MaxSiz][MaxSiz];
int 	nline[3][3]={{1,1,1},			// ���`�������t�B���^		
					 {1,1,1},
					 {1,1,1}};
int		wline[3][3]={            {0,-1,0},			// �d�ݕt�����`�������t�B���^
					 {-1,5,-1},
					 {0,-1,0}};

void	get_data (int  agc, char  **agv){
  	if (agc != 2){
		printf ("�g�p�@:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile(agv[1], &cm, &hite, &wide, dat);
}

void	calc_diff (void){
	int		x, y, j, k;
	int		ddn, ddw;			   // ddn:�P�����ρAddw:���S�ɏd��
  	for (y=1; y<hite-1; y++) for (x=1; x<wide-1; x++){
 		ddn = 0;		ddw = 0;
  		for (j=-1; j<2; j++) for (k=-1; k<2; k++){
			//ddn += gp(y+j, x+k)*nline[j+1][k+1];	// �d�݂Ȃ�
			ddw += gp(y+j, x+k)*wline[j+1][k+1];	// �d�ݕt��
  		}
  		//dn[y][x] = ddn/9;
  		dw[y][x] = ddw;
if(ddw>255 || ddw<0){
 dw[y][x]=gp(y,x);
}
  	}
}

void show(void){
	unsigned  char	gr, ddx, ddy;
	int				x, y;
	glclear ( );
    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		gr = gp(y, x);			//���摜�̕\��
		glcolor (gr, gr, gr);	gpnt (x, y);
	}
    for (y=1; y<hite-1; y++) for (x=1; x<wide-1; x++){
		ddx = dw[y][x];			// ���`�������t�B���^
		glcolor (ddx, ddx, ddx);	gpnt (x-wide, y);

		//ddy = dw[y][x];			// �d�ݕt�����`�������t�B���^
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