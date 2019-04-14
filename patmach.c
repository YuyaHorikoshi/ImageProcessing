/* �P�F�摜�̕����摜�̌��o�B���W�̕\�� */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz		1024

#define		orgfile		"lena.bmp"	// �摜
#define		partfile	"plena.bmp"	// �����摜

unsigned  char	dat[MaxSiz*MaxSiz];	// ���摜�p
unsigned  char	part[MaxSiz*MaxSiz];// �����摜�p

int		cm1, wide, hite;		// ���摜�̃p�����[�^
int		cm2, wd, ht;			// �����摜�̃p�����[�^
int		xs,ys;

int sq(int a){return  a*a ; }	// ����̊֐�

void	disp(void){
	unsigned  char	v;
	int				y, x, j, k;
	glclear ( );
  	for (y=0; y<hite; y++) for (x=0; x<wide; x++){
  		v = dat[y*wide+x];	glcolor (v, v, v); gpnt (x, y);
  	}
  	for (j=0; j<ht; j++) for (k=0; k<wd; k++){
		v = part[j*wd+k];	glcolor (v, v, v);	gpnt (k-100, j);
  	}
	glcolor (0, 0, 0);	// �����Ŏl�p��`��
	grectangle (xs, ys, xs+wd, ys+ht);
  	glflush ( );
}

void	get_data (void){
	loadbmpfile (orgfile, &cm1, &hite, &wide, dat);// ����̓ǂݍ���
	printf ("org::c/m=%d, hite=%d, wide=%d\n", cm1, hite, wide);
	loadbmpfile (partfile, &cm2, &ht, &wd, part);
    printf ("part::c/m=%d, ht=%d, wd=%d\n", cm2, ht, wd);
}

void	calc_error (void){
	int		x, y, j, k;				// �ŏ��l��^���鍶���̍��W
	int		S, So=0x7fffffff;		// So:�ŏ��l, �����l=0xfffffff
	printf ("������...\n");
   	for (y=0; y<hite-ht+1; y++) for (x=0; x<wide-wd+1; x++){
		S = 0;
		for (j=0; j<ht; j++) for(k=0; k<wd; k++){// ���摜�ƕ����摜
			S += sq(dat[(y+j)*wide+(x+k)] - part[j*wd+k]); // �̍��̎���̌v�Z
  		}
		if(S<=So){ 		 // ������������Βl�̒u�������ƍ��W�̋L��
			So = S;	 xs = x;	ys = y;	
		}
  	}
  	printf ("So=%d, xs=%d, ys=%d\n", So, xs, ys);
}

int		main (void)
{
	get_data ( );
	calc_error ( );
	ginit (1);
	gdisplay (disp);

}