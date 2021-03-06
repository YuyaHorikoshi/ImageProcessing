/* 読み込んだ画像を画像濃度127で２値化 */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned char 	dat[1024*1024];
int	 			cm, wide, hite;

void	get_data (int  agc, char  **agv){
	if (agc != 2){
		printf ("使用法:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
}

void	picture_and_hist (void){	// 原画像と２値化ヒ画像の表示
	unsigned char	r ;
	int				x, y ;
	glclear ( ) ;
    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		r = dat[y*wide+x];
		glcolor (r, r, r);			// 原画像を
		gpnt (x, y);				// 第１象限に表示
		
		if (r < 128)	r = 0; 		// 明るさが128以下なら r = 0
		else			r = 255;	// そうでなければ r = 255
		glcolor (r, r, r);			// ２値化画像を
		gpnt (x-wide, y);			// 第２象限に表示
 	}	
 	glflush ( );			
}

int	main (int  argc, char  **argv)
{
	get_data(argc,argv);
	ginit(1);
	gdisplay(picture_and_hist);
	return 0;
}