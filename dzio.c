/* �t���J���[�摜�𔒍��摜�ŕ\�� */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned  char	dat[1024*1024*3];
unsigned  char	output[1024*1024*3];
int				cm, wide, hite;

void	get_data (int agc, char **agv){
	if (agc != 3){
		 printf ("�g�p�@:: %s  file.bmp\n", agv[0]);	exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);  // �摜�ǂݍ���
}

void	disp (void){
	unsigned  char	r, g, b, gray;
	int				x, y ,th[16][16], i, j, k;
	glclear ( ) ;
        th[0][0]= 16; th[1][0]=144; th[2][0]= 48; th[3][0]=176;
        th[0][1]=208; th[1][1]= 80; th[2][1]=240; th[3][1]=100;
        th[0][2]= 64; th[1][2]=192; th[2][2]= 32; th[3][2]=160;
        th[0][3]=255; th[1][3]=128; th[2][3]=224; th[3][3]= 96;
//	int				x, y;
//�����ϊ��J�n
  	for (y=0; y<hite; y++) for(x=0; x<wide; x++){
		b = dat[(y*wide+x)*3];				// �_(x, y)�̐���
		g = dat[(y*wide+x)*3+1];			// �_(x, y)�̗ΐ���
		r = dat[(y*wide+x)*3+2];			// �_(x, y)�̐Ԑ���

		glcolor (r, g, b);					// ���摜��
		gpnt (x, y);						// ��P�ی��ɕ`��

		gray = 0.114*b + 0.587*g + 0.299*r;	// �����x�������l������
		glcolor (gray, gray, gray);			// �����摜��
		gpnt (x, y-hite);
					// ��S�ی��ɕ`��
		dat[(y*wide+x)*3]   = gray ;		        // dat�ɔ����摜������
		dat[(y*wide+x)*3+1] = gray ;			// dat�ɔ����摜������
		dat[(y*wide+x)*3+2] = gray ;			//dat�ɔ����摜������


//		gray = (b + g + r)/3;				// �P�����ς���
//		glcolor (gray, gray, gray);			// �����摜��
//		gpnt (x-wide, y-hite);				// ��R�ی��ɕ`��
	}
  	glflush ( );
//  �����ϊ��I��

//  �f�B�U���J�n
         j=0;
    for (y=0; y<hite; y++){
           if (j == 4) j=0;	
         i=0; 
    for (x=0; x<wide; x++){
           if (i == 4) i=0;
		r = dat[(y*wide+x)*3];           //�R�����ɌĂяo��   
		if (r < th[i][j])	r = 0; 		// ���邳��臒l�����Ȃ� r = 0
		else			r = 255;	// �����łȂ���� r = 255
		output[(y*wide+x)*3+0] = r ;		        // output�ɏ������ʂ�����
		output[(y*wide+x)*3+1] = r ;			// output�ɏ������ʂ�����
		output[(y*wide+x)*3+2] = r ;			// output�ɏ������ʂ�����

		glcolor (r, r, r);			// �Q�l���摜�Ȃ̂�
		gpnt (x-wide, y);			// ��Q�ی��ɕ\��
           i=i+1; 

 	}
           j=j+1;	
 	glflush ( );
        }		



}

int main(int argc, char **argv){
	get_data(argc,argv);
	ginit(1);
        disp();
  savebmpfile(argv[2], cm, hite, wide, output); // �f�B�U�摜�̏o
	//gdisplay(disp);
  	return 0;
}