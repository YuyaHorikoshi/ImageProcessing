/* �}�`����̏ꍇ�̗֊s���ǐ� */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz	1024	// �ő�摜�T�C�Y
#define		MaxBrt	255		// ��f�ő喾�邳

unsigned  char	dat[MaxSiz*MaxSiz];		// ���摜�p�z��
int				cm, hite, wide;			// �摜�̍����ƕ�
int				bpnt[MaxSiz*MaxSiz][2];	// (x,y) �֊s�_�i�[�z��
int				f[8][2]={{ 1, 0},{ 1,1},{ 0,1},{-1,1},
					{-1, 0},{-1, -1},{ 0, -1},{ 1, -1}};	// �W�����R�[�h
int				xst, yst, cnt;  		// �ǐՊJ�n�_�̍��W

void	get_data (int  agc, char  **agv)
{
	if (agc != 2){
		printf ("�g�p�@:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
	printf ("cm=%d, wide=%d, hite=%d\n", cm, wide, hite);
}

void	btracing (void)
{
	int		x, y, xc, yc, cn=0;
	int		cd, d;
  	for (y=0; y<hite; y++) for(x=0; x<wide; x++){// �ŏ��̍���f�̔���
		if (dat[y*wide+x]==MaxBrt)	goto found;
	}
	found:
	xst = x;	yst = y;					// �ŏ��̍���f�̍��W
	bpnt[cn][0] = xst;	bpnt[cn][1] = yst; 	// �֊s�_���W�Ɋi�[
 	printf ("found first pnt h=%d,w=%d\n", yst, xst);

	xc = xst;	 yc = yst;	cd = 4;			// �X�^�[�g���W�ƒT������
	do{
		d = cd;
		do{
			d = (d+1) % 8;				// �T�������̐ݒ�
			if (d==cd)	return;			// �P�����Ă��܂�����Ǘ��_
			x = xc + f[d][0];	y = yc + f[d][1];	// �T�����W�̌v�Z
		} while (dat[y*wide+x]==0);	// �}�`��f�ɂȂ�܂ŌJ��Ԃ�
		cn++;
		bpnt[cn][0] = xc;		bpnt[cn][1] = yc;	// �����֊s�_�ɒǉ���
		xc = x;	yc = y;				// ������V�����X�^�[�g���W�Ƃ���
		cd = (d+4);					// �V�����T�����������߂�
	} while (xc!=xst || yc!=yst);		// �ŏ��̃X�^�[�g���W�ɂԂ���܂�
	cnt = cn;
}

void	dispdisp (void)
{
	unsigned  char	v;
	int				x, y, k;
	glclear ( );
	for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		v = dat[y*wide+x];
		glcolor (v, v, v);  gpnt (x, y);
	}
	for(k=0; k<=cnt; k++){
		glcolor (255, 255, 255);
		gpnt (bpnt[k][0]-wide, bpnt[k][1]);
	}
	glflush ( );
}

int		main (int  argc, char  **argv)
{
	get_data (argc, argv);
	btracing ( );
	ginit (1);
	gdisplay (dispdisp);
    return  0;
}