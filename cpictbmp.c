/* �J���[�r�b�g�}�b�v�t�@�C���̕\��.�摜�̕����R�͂S�̔{���̎�	*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"

FILE	*fp;
int wide,hite,cm,dat[1024*1024];

void get_data(){
  int j,h[54],palette[1024],x,y,c;
  	fp=fopen("hyb256c.bmp","rb");	    // �J���[�摜�t�@�C�����J��
  	for(j=0; j<54; j++)	h[j]=fgetc(fp);			// �w�b�_�̓ǂݍ��� 
  	wide=h[18]+h[19]*256;						  // �摜�̕��̌v�Z
  	hite=h[22]+h[23]*256;						// �摜�̍����̌v�Z
  	cm=h[28];						  // �摜���P�F���J�����A������
  	printf("��=%d,  ����=%d,  ���=%d\n",wide,hite,cm);
  	for(y=0; y<hite; y++)for(x=0; x<wide; x++){
  		for(c=0; c<3; c++) dat[(y*wide+x)*3+c]=fgetc(fp);
  	}
  	fclose(fp);
}

void disp(void){
  int x,y,v,r,g,b;
  	for(y=0; y<hite; y++) for(x=0; x<wide; x++){
  		v=(y*wide+x)*3;
		b=dat[v];	g=dat[v+1];		r=dat[v+2];
		glcolor(r,g,b);
		gpnt(x,y);
  	}
  	glflush();
  	fclose(fp);
}

void main(){
	get_data();
	ginit(1);
	gdisplay(disp);
}