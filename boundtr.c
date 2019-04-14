/* 図形が一つの場合の輪郭線追跡 */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz	1024	// 最大画像サイズ
#define		MaxBrt	255		// 画素最大明るさ

unsigned  char	dat[MaxSiz*MaxSiz];		// 原画像用配列
int				cm, hite, wide;			// 画像の高さと幅
int				bpnt[MaxSiz*MaxSiz][2];	// (x,y) 輪郭点格納配列
int				f[8][2]={{ 1, 0},{ 1,1},{ 0,1},{-1,1},
					{-1, 0},{-1, -1},{ 0, -1},{ 1, -1}};	// ８方向コード
int				xst, yst, cnt;  		// 追跡開始点の座標

void	get_data (int  agc, char  **agv)
{
	if (agc != 2){
		printf ("使用法:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
	printf ("cm=%d, wide=%d, hite=%d\n", cm, wide, hite);
}

void	btracing (void)
{
	int		x, y, xc, yc, cn=0;
	int		cd, d;
  	for (y=0; y<hite; y++) for(x=0; x<wide; x++){// 最初の黒画素の発見
		if (dat[y*wide+x]==MaxBrt)	goto found;
	}
	found:
	xst = x;	yst = y;					// 最初の黒画素の座標
	bpnt[cn][0] = xst;	bpnt[cn][1] = yst; 	// 輪郭点座標に格納
 	printf ("found first pnt h=%d,w=%d\n", yst, xst);

	xc = xst;	 yc = yst;	cd = 4;			// スタート座標と探査方向
	do{
		d = cd;
		do{
			d = (d+1) % 8;				// 探索方向の設定
			if (d==cd)	return;			// １周してしまったら孤立点
			x = xc + f[d][0];	y = yc + f[d][1];	// 探査座標の計算
		} while (dat[y*wide+x]==0);	// 図形画素になるまで繰り返し
		cn++;
		bpnt[cn][0] = xc;		bpnt[cn][1] = yc;	// それを輪郭点に追加し
		xc = x;	yc = y;				// そこを新しいスタート座標とする
		cd = (d+4);					// 新しい探査方向を決める
	} while (xc!=xst || yc!=yst);		// 最初のスタート座標にぶつかるまで
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