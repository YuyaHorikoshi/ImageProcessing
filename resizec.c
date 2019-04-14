/* �C�ӂ̔{���ŉ摜���g�傷��(�J���[�Ή���) */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz	1024

unsigned  char	dat[MaxSiz*MaxSiz*3];		// ���摜�p�z��
unsigned  char	xdat[MaxSiz][MaxSiz][3];	// �������g��p�z��
unsigned  char	xydat[MaxSiz][MaxSiz][3];	// �c�����g��p�z��
int				dsty,dstx;				// �g���̔z��̑傫��
int				cm, hite,wide;			// ���摜�̕��A�����̒l
double			ratio;					// �g�嗦

void	get_data (int  agc, char  **agv){
  	if (agc != 3){
  		printf ("�g�p�@:: %s  file.bmp  ratio\n", agv[0]);		exit(-1);
  	}
  	ratio = atof (agv[2]);
  	loadbmpfile (agv[1], &cm, &hite, &wide, dat);	// ���摜�̓ǂݍ���
	dsty = ratio*hite;		dstx = ratio*wide;
  	printf ("ratio=%lf, hite=%d, wide=%d,  dsty=%d, dstx=%d\n",
  			ratio, hite, wide, dsty, dstx);
}

void	resize (double  ratio){
	double	p, t;
	int		k, x, y, c;
//�@�������̊g��k��  
 	for (y=0; y<wide; y++){
  		for (x=0; x<dstx; x++){
  			p = x/ratio;	k = p;	t = p - k;
			for(c=0; c<cm; c++){
				xdat[y][x][c] = (1.0-t)*dat[(y*wide+k)*cm+c] + t*dat[(y*wide+(k+1))*cm+c];
			}
  		}
	}
//�@�c�����̊g��k��
	for (x=0; x<dstx; x++){
		for (y=0; y<dsty; y++){
  			p = y/ratio;	k = p;	t = p - k;
			for(c=0; c<cm; c++){
				xydat[y][x][c] = (1.0-t)*xdat[k][x][c] + t*xdat[k+1][x][c];
			}
		}
	}
}	

void	pict_pict (void)
{
	unsigned  char	b, g, r;
	int				x, y;  	
  	glclear ( );
  	for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		if(cm==3){
			b = dat[(y*wide+x)*3];
  			g = dat[(y*wide+x)*3+1];
  			r = dat[(y*wide+x)*3+2];
		}else{
			b = g = r = dat[y*wide+x];
		}
		glcolor (r, g, b);	gpnt(x, y);
  	}	
  	for (y=0; y<dsty; y++) for (x=0; x<dstx; x++){
		if(cm==3){
			b = xydat[y][x][0];
			g = xydat[y][x][1];
			r = xydat[y][x][2];
		}else{
			b = g = r = xydat[y][x][0];
		}
		glcolor (r ,g, b);
  		gpnt (x-dstx, y);
  	}
  	glflush ( );
}

void	main (int  argc, char  **argv)
{
	get_data (argc, argv);
  	resize (ratio);
	ginit (1);
	gdisplay(pict_pict);
}