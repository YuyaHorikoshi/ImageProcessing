/* �P�F�摜�̕����摜�̌��o	*/
#include <windows.h>
#include <stdio.h>

int org[5][6] ={{4,9,6,3,7,8},		// ���摜
				{9,3,4,4,6,0},
				{6,5,0,9,0,0},
				{6,5,0,2,8,6},
				{7,4,2,7,7,9}};
int prt[2][4] ={{3,4,4,6},			// �����摜
				{5,0,9,0}};

int sq (int a){ return  a*a ; }		// ����̌v�Z

void		main (void)
{
	int		x, y, j, k;
	int		xs, ys;					// �ŏ��l��^���鍶���̍��W
	int		S, So=0xFFFF;			// So:�ŏ��l�B�����l=0xffff
  					
   	for (y=0; y<5-3+1; y++) for (x=0; x<6-4+1; x++){
  		S = 0;
		for (j=0; j<2; j++) for (k=0;	k<4; k++){
			S += sq(org[y+j][x+k] - prt[j][k]); // ���̎���̍��v
  		}
		if (S<So){ 				// �����ŏ��l�Ȃ�
	  		So = S;	 xs = x;	ys = y;
  		}	
  		printf ("S=%3d (x=%d, y=%d)\t", S, x, y);
  		printf ("So=%3d (xs=%d, ys=%d)\n", So, xs, ys);
  	}
}