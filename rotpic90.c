/* �摜�f�[�^�̉�]�F�����v�����X�O�x�̉�] */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"
#define		MaxSiz	1024

unsigned char	dat[MaxSiz*MaxSiz];				    // �摜�f�[�^�i�[�p�z��
unsigned char	rot[MaxSiz][MaxSiz];
int				cm, wide, hite;

void	get_data (int  agc, char  **agv){
  	if (agc != 2){
  		printf ("�g�p�@:: %s  file.bmp\n", agv[0]);		exit(-1);
  	}
	loadbmpfile (agv[1], &cm, &hite, &wide,dat);	// �摜�̓ǂݍ���
}

void	rotcalc (void){
	int		x, y;
  	for (x=0; x<wide; x++) for (y=0; y<hite; y++){
  		rot[x][hite-1-y] = dat[y*wide+x];
  	}
}

void	disp (void)
{
	unsigned char	v ;
	int				x, y, j, k;
	glclear ( );
	for (y=0; y<hite; y++){
		for(x=0; x<wide; x++){
			v = dat[y*wide+x];
			glcolor (v, v, v);	gpnt (x, y);
		}
  	}
	for (k=0; k<wide; k++){
		for (j=0; j<hite; j++){
			v = rot[k][j];
			glcolor (v, v, v);	gpnt (j-wide, k);
		}
  	}
  	glflush ( );
}

int		main (int  argc, char **argv)
{
	get_data (argc, argv);
	rotcalc ( );
	ginit (1);
	gdisplay (disp);
}