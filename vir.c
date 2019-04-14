/* raw�t�@�C���\���p�̃c�[���@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@*/
/* �g�p�@�Fvir�ɑ�����RAW�摜�t�@�C�����@�����@���̏��ɓ��� */
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"
unsigned  char		dat[1024*1024];
int		cm, hite, wide;
FILE		*fp;
void read_dat(int agc, char **agv){
	int		v,n=0;
	if (agc != 4){
		printf ("Usage:: %s  file.raw  hite  wide\n", agv[0]);  exit(-1);
    }
    if((fp = fopen (agv[1],"rb")) == NULL){
		printf("Can't open \"%s\".\n", agv[1]);	exit(1);
	}
	while (fgetc(fp) != EOF)	n++;			// �f�[�^���𒲂ׂ�
	printf ("n=%d\n", n);
	hite = atoi(agv[2]); wide = atoi(agv[3]);	// �R�}���h���C�����獂���E�����擾
	if (hite*wide == n)			cm = 1;			// �����~�����f�[�^���@�Ȃ�P�F
	else if (hite*wide*3 == n)	cm = 3;			// �����~���~�R���f�[�^���@�Ȃ�J���[
	else{
		printf("Size missmatch!\n");			// ����ȊO�̓G���[
		exit(2);
	}
	rewind (fp);								// �t�@�C���̐擪�ɖ߂�
}

void pict_pict(void){
     int	x, y, v0, v1, v2, n;
  	for (y=0; y<hite; y++) for (x=0; x<wide; x++){
	     if (cm==1){
			v0 = fgetc(fp);  glcolor(v0,v0,v0);  gpnt(x,y);
	     }
         else if (cm==3){
		 	v0 = fgetc(fp);  v1 = fgetc(fp); v2 = fgetc(fp);
		 	glcolor(v2,v1,v0);  gpnt(x,y);
		}
  	}
  	fclose(fp);
	glflush( );
}

int main (int  argc, char  **argv){
	read_dat (argc, argv);
	ginit (1);
	gdisplay (pict_pict);
	return  0;
}