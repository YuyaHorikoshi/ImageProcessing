/* �ǂݍ��񂾉摜���摜�Z�x127�łQ�l�� */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned char 	dat[1024*1024];
int	 			cm, wide, hite;

void	get_data (int  agc, char  **agv){
	if (agc != 2){
		printf ("�g�p�@:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
}

void	picture_and_hist (void){	// ���摜�ƂQ�l���q�摜�̕\��
	unsigned char	r ;
	int				x, y ;
	glclear ( ) ;
    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		r = dat[y*wide+x];
		glcolor (r, r, r);			// ���摜��
		gpnt (x, y);				// ��P�ی��ɕ\��
		
		if (r < 128)	r = 0; 		// ���邳��128�ȉ��Ȃ� r = 0
		else			r = 255;	// �����łȂ���� r = 255
		glcolor (r, r, r);			// �Q�l���摜��
		gpnt (x-wide, y);			// ��Q�ی��ɕ\��
 	}	
 	glflush ( );			
}

int	main (int  argc, char  **argv)
{
	get_data(argc,argv);
	ginit(1);
	gdisplay(picture_and_hist);
	return 0;
}