/* pict2.c	�P�F�摜�ƃJ���[�摜�̕\�� */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned  char	mdat[1024*1024];	// mdat:�P�F�f�[�^�p�z��
unsigned  char	cdat[1024*1024*3];	// cdat:�J���[�f�[�^�p�z��	
int				cmm, cmc;			// ��f�T�C�Y(Byte)
int				wdm, htm;			// �P�F�摜�̕��ƍ���
int				wdc, htc;			// �J���[�摜�̕��ƍ���

void	get_file (void){			// �摜��ǂݍ��ފ֐�
	//loadbmpfile ("mbamb.bmp"  , &cmm, &htm, &wdm, mdat);	// �P�F
	loadbmpfile ("hyb256c.bmp", &cmc, &htc, &wdc, cdat);	// �J���[
} 

void	pict (void){
	unsigned  char	r, g, b;
	int				x, y,ave,gray;
	for (y=0; y<htc; y++) for(x=0; x<wdc; x++) { 	// �P�F�摜�̕\��
		b = cdat[(y*wdc+x)*3];		// �_(x, y)�̐���
  		g = cdat[(y*wdc+x)*3+1];	// �_(x, y)�̗ΐ���
  		r = cdat[(y*wdc+x)*3+2];	// �_(x, y)�̐Ԑ���			// �_(x, y)�̖��邳
		glcolor (r, g, b);			// �O���[�̖��Â̎w��
		gpnt (x, y);				// ��P�ی��ɕ\��
	}
	for(y=0; y<htc; y++)for(x=0; x<wdc; x++){		// �J���[�摜�̕\��
  		b = cdat[(y*wdc+x)*3];		// �_(x, y)�̐���
  		g = cdat[(y*wdc+x)*3+1];	// �_(x, y)�̗ΐ���
  		r = cdat[(y*wdc+x)*3+2];	// �_(x, y)�̐Ԑ���
                ave=(b+g+r)/3;
		glcolor (ave, ave, ave);			// �F�̎w��
		gpnt (x-256, y-256);			// ��Q�ی��ɕ\��
	}
	for (y=0; y<htc; y++) for(x=0; x<wdc; x++) { 	// �P�F�摜�̕\��
		b = cdat[(y*wdc+x)*3];		// �_(x, y)�̐���
  		g = cdat[(y*wdc+x)*3+1];	// �_(x, y)�̗ΐ���
  		r = cdat[(y*wdc+x)*3+2];	// �_(x, y)�̐Ԑ���			// �_(x, y)�̖��邳
		gray=0.114*b + 0.587*g + 0.299*r;
		glcolor (gray, gray, gray);			// �O���[�̖��Â̎w��
		gpnt (x, y-256);				// ��P�ی��ɕ\��
	}
	glflush ( );
}

int		main (void){
	get_file ( );
	ginit (1);
	gdisplay (pict);
	return  0;
}