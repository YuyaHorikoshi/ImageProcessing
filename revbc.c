/* pict2.c	単色画像とカラー画像の表示 */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned  char	mdat[1024*1024];	// mdat:単色データ用配列
unsigned  char	cdat[1024*1024*3];	// cdat:カラーデータ用配列	
int				cmm, cmc;			// 画素サイズ(Byte)
int				wdm, htm;			// 単色画像の幅と高さ
int				wdc, htc;			// カラー画像の幅と高さ

void	get_file (void){			// 画像を読み込む関数
	//loadbmpfile ("mbamb.bmp"  , &cmm, &htm, &wdm, mdat);	// 単色
	loadbmpfile ("hyb256c.bmp", &cmc, &htc, &wdc, cdat);	// カラー
} 

void	pict (void){
	unsigned  char	r, g, b;
	int				x, y,gray;
	for(y=0; y<htc; y++)for(x=0; x<wdc; x++){		// カラー画像の表示
  		b = cdat[(y*wdc+x)*3];		// 点(x, y)の青成分
  		g = cdat[(y*wdc+x)*3+1];	// 点(x, y)の緑成分
  		r = cdat[(y*wdc+x)*3+2];	// 点(x, y)の赤成分
		glcolor (r, g, b);			// 色の指定
		gpnt (x, y);			// 第２象限に表示
	}
	for(y=0; y<htc; y++)for(x=0; x<wdc; x++){		// カラー画像の表示
  		b = cdat[(y*wdc+x)*3];		// 点(x, y)の青成分
  		g = cdat[(y*wdc+x)*3+1];	// 点(x, y)の緑成分
  		r = cdat[(y*wdc+x)*3+2];	// 点(x, y)の赤成分
		gray = 0.114*b + 0.587*g + 0.299*r;
		glcolor (255-gray, 255-gray, 255-gray);			// 色の指定
		gpnt (x-256, y);			// 第２象限に表示
	}
	glflush ( );
}

int		main (void){
	get_file ( );
	ginit (1);
	gdisplay (pict);
	return  0;
}