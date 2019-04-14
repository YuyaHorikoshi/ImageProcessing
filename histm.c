/* �ǂݍ��񂾉摜�̃q�X�g�O�������摜�Ƌ��ɕ\������	*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned  char	dat[1024*1024];
int	 			cm, wide, hite;
int 			hist[256];				// 256�K���̓x�����i�[

void	get_data (int  agc, char  **agv){
	if (agc != 2){
		printf ("�g�p�@:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
}

void	calc_hist (void){
	int		j, x, y;
	for (j=0; j<256; j++)	hist[j] = 0;	// �x���p�z��̏�����
	for (y=0; y<hite; y++) for(x=0; x<wide; x++){
		hist[dat[y*wide+x]]++;				// �x���̌v�Z
	}
}

void	normalize (void){
	int		j, gmx = 0;				// �ő�l�v�Z�̏����l�Ƃ���0��ݒ�
  	for (j=0; j<256; j++){
  		if (hist[j] > gmx)	gmx = hist[j];	// �ő�l�̌v�Z
  	}
  	printf ("max_value = %d\n", gmx);	// �ő�l��255�ɂ��鐳�K���̌v�Z
	for (j=0; j<256; j++)	hist[j] = 256*(hist[j]/(gmx+0.000001));   //0.000001��gm���O�̎��̑Ή�
}
void	picture_and_hist (void){	// �q�X�g�O�����Ɖ摜�̕\��
	unsigned  char	c;
	int				j, x, y;
glclear();
	glcolor(255,255,255);		// ���ŕ\��
  	for (j=0; j<256; j++)  gline (j, 0, j, hist[j]);

    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		c = dat[y*wide+x];
		glcolor (c, c, c);
		gpnt (x-wide, y);		// ��Q�ی��ɕ\��
 	}
	glflush ( );
}

int		main (int  argc, char  **argv){
	get_data (argc, argv);
	calc_hist ( );
	normalize ( );
	ginit (1);
	gdisplay (picture_and_hist);
	return  0;
}