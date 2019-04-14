/* rawファイル表示用のツール　　　　　　　　　　　　　　　　　*/
/* 使用法：virに続いてRAW画像ファイル名　高さ　幅の順に入力 */
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
	while (fgetc(fp) != EOF)	n++;			// データ個数を調べる
	printf ("n=%d\n", n);
	hite = atoi(agv[2]); wide = atoi(agv[3]);	// コマンドラインから高さ・幅を取得
	if (hite*wide == n)			cm = 1;			// 高さ×幅＝データ個数　なら単色
	else if (hite*wide*3 == n)	cm = 3;			// 高さ×幅×３＝データ個数　ならカラー
	else{
		printf("Size missmatch!\n");			// それ以外はエラー
		exit(2);
	}
	rewind (fp);								// ファイルの先頭に戻る
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