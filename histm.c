/* 読み込んだ画像のヒストグラムを画像と共に表示する	*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned  char	dat[1024*1024];
int	 			cm, wide, hite;
int 			hist[256];				// 256階調の度数を格納

void	get_data (int  agc, char  **agv){
	if (agc != 2){
		printf ("使用法:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
}

void	calc_hist (void){
	int		j, x, y;
	for (j=0; j<256; j++)	hist[j] = 0;	// 度数用配列の初期化
	for (y=0; y<hite; y++) for(x=0; x<wide; x++){
		hist[dat[y*wide+x]]++;				// 度数の計算
	}
}

void	normalize (void){
	int		j, gmx = 0;				// 最大値計算の初期値として0を設定
  	for (j=0; j<256; j++){
  		if (hist[j] > gmx)	gmx = hist[j];	// 最大値の計算
  	}
  	printf ("max_value = %d\n", gmx);	// 最大値を255にする正規化の計算
	for (j=0; j<256; j++)	hist[j] = 256*(hist[j]/(gmx+0.000001));   //0.000001はgmが０の時の対応
}
void	picture_and_hist (void){	// ヒストグラムと画像の表示
	unsigned  char	c;
	int				j, x, y;
glclear();
	glcolor(255,255,255);		// 白で表示
  	for (j=0; j<256; j++)  gline (j, 0, j, hist[j]);

    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		c = dat[y*wide+x];
		glcolor (c, c, c);
		gpnt (x-wide, y);		// 第２象限に表示
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