/* 単色画像の部分画像の検出。座標の表示 */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz		1024

#define		orgfile		"lena.bmp"	// 画像
#define		partfile	"plena.bmp"	// 部分画像

unsigned  char	dat[MaxSiz*MaxSiz];	// 原画像用
unsigned  char	part[MaxSiz*MaxSiz];// 部分画像用

int		cm1, wide, hite;		// 原画像のパラメータ
int		cm2, wd, ht;			// 部分画像のパラメータ
int		xs,ys;

int sq(int a){return  a*a ; }	// 自乗の関数

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
	glcolor (0, 0, 0);	// 黒線で四角を描く
	grectangle (xs, ys, xs+wd, ys+ht);
  	glflush ( );
}

void	get_data (void){
	loadbmpfile (orgfile, &cm1, &hite, &wide, dat);// 原画の読み込み
	printf ("org::c/m=%d, hite=%d, wide=%d\n", cm1, hite, wide);
	loadbmpfile (partfile, &cm2, &ht, &wd, part);
    printf ("part::c/m=%d, ht=%d, wd=%d\n", cm2, ht, wd);
}

void	calc_error (void){
	int		x, y, j, k;				// 最小値を与える左下の座標
	int		S, So=0x7fffffff;		// So:最小値, 初期値=0xfffffff
	printf ("処理中...\n");
   	for (y=0; y<hite-ht+1; y++) for (x=0; x<wide-wd+1; x++){
		S = 0;
		for (j=0; j<ht; j++) for(k=0; k<wd; k++){// 原画像と部分画像
			S += sq(dat[(y+j)*wide+(x+k)] - part[j*wd+k]); // の差の自乗の計算
  		}
		if(S<=So){ 		 // もし小さければ値の置き換えと座標の記憶
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