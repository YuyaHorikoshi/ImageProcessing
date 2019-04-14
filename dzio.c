/* フルカラー画像を白黒画像で表示 */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned  char	dat[1024*1024*3];
unsigned  char	output[1024*1024*3];
int				cm, wide, hite;

void	get_data (int agc, char **agv){
	if (agc != 3){
		 printf ("使用法:: %s  file.bmp\n", agv[0]);	exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);  // 画像読み込み
}

void	disp (void){
	unsigned  char	r, g, b, gray;
	int				x, y ,th[16][16], i, j, k;
	glclear ( ) ;
        th[0][0]= 16; th[1][0]=144; th[2][0]= 48; th[3][0]=176;
        th[0][1]=208; th[1][1]= 80; th[2][1]=240; th[3][1]=100;
        th[0][2]= 64; th[1][2]=192; th[2][2]= 32; th[3][2]=160;
        th[0][3]=255; th[1][3]=128; th[2][3]=224; th[3][3]= 96;
//	int				x, y;
//白黒変換開始
  	for (y=0; y<hite; y++) for(x=0; x<wide; x++){
		b = dat[(y*wide+x)*3];				// 点(x, y)の青成分
		g = dat[(y*wide+x)*3+1];			// 点(x, y)の緑成分
		r = dat[(y*wide+x)*3+2];			// 点(x, y)の赤成分

		glcolor (r, g, b);					// 原画像を
		gpnt (x, y);						// 第１象限に描く

		gray = 0.114*b + 0.587*g + 0.299*r;	// 視感度特性を考慮した
		glcolor (gray, gray, gray);			// 白黒画像を
		gpnt (x, y-hite);
					// 第４象限に描く
		dat[(y*wide+x)*3]   = gray ;		        // datに白黒画像を入れる
		dat[(y*wide+x)*3+1] = gray ;			// datに白黒画像を入れる
		dat[(y*wide+x)*3+2] = gray ;			//datに白黒画像を入れる


//		gray = (b + g + r)/3;				// 単純平均した
//		glcolor (gray, gray, gray);			// 白黒画像を
//		gpnt (x-wide, y-hite);				// 第３象限に描く
	}
  	glflush ( );
//  白黒変換終了

//  ディザ化開始
         j=0;
    for (y=0; y<hite; y++){
           if (j == 4) j=0;	
         i=0; 
    for (x=0; x<wide; x++){
           if (i == 4) i=0;
		r = dat[(y*wide+x)*3];           //３つおきに呼び出す   
		if (r < th[i][j])	r = 0; 		// 明るさが閾値未満なら r = 0
		else			r = 255;	// そうでなければ r = 255
		output[(y*wide+x)*3+0] = r ;		        // outputに処理結果を入れる
		output[(y*wide+x)*3+1] = r ;			// outputに処理結果を入れる
		output[(y*wide+x)*3+2] = r ;			// outputに処理結果を入れる

		glcolor (r, r, r);			// ２値化画像なので
		gpnt (x-wide, y);			// 第２象限に表示
           i=i+1; 

 	}
           j=j+1;	
 	glflush ( );
        }		



}

int main(int argc, char **argv){
	get_data(argc,argv);
	ginit(1);
        disp();
  savebmpfile(argv[2], cm, hite, wide, output); // ディザ画像の出
	//gdisplay(disp);
  	return 0;
}