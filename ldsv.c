/* hyb256.bmp �Ƃ����t�@�C����ǂݍ���ŁCxxx.bmp�Ƃ����t�@�C�� */
/* �Ƃ��āA��������						*/
#include <windows.h>
#include <stdio.h>
#include "opgls.ft"

unsigned char dat[1024*1024*3];

int main(){
  int cm,ht,wd;
	loadbmpfile("bamb.bmp",&cm,&ht,&wd,dat);		// ���̓t�@�C��
	savebmpfile("xxx.bmp", cm,ht,wd,dat);			// �o�̓t�@�C��
	return 1;
}
