/* モザイクのみの処理*/
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned char 	dat[1024*1024*3];
unsigned char 	datt[1024*1024*3];
double 	datb[1024][1024];
double	datg[1024][1024];
double	datr[1024][1024];
double	dattb[1024][1024];
double	dattg[1024][1024];
double	dattr[1024][1024];

int	 			cm, wide, hite;

void	get_data (int  agc, char  **agv){
	loadbmpfile ("hyb256c.bmp", &cm, &hite, &wide, dat);
}

void	picture_and_hist (void){	// 原画像と２値化ヒ画像の表示
	unsigned char	r,g,b ;
	int	x, y, i, j, h, m, sx, sy, k, s, t, u, v, w; 
	double hh, con;
        glclear ( );

// 座標変換（１次元配列　⇒　２次元配列）
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
datb[x][y]=dat[(y*wide+x)*3+0];
datg[x][y]=dat[(y*wide+x)*3+1];
datr[x][y]=dat[(y*wide+x)*3+2];
}}
// 座標変換終了

// カラー画像を白黒画像に変換
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
  	    b = datb[x][y];	// 点(x, y)の青成分
  	    g = datg[x][y];	// 点(x, y)の緑成分
  	    r = datr[x][y];	// 点(x, y)の赤成分
            m = datb[x][y]*0.114+datg[x][y]*0.587+datr[x][y]*0.299;
  		datb[x][y] = m;	
  		datg[x][y] = m;	
  		datr[x][y] = m;	
	    glcolor (m, m, m);			
	    gpnt (x-256, y);
      	                  }
            glflush ( );
                          }
// カラー画像を白黒画像に変換終了 

// モザイク処理
//scanf("%d",&h);    // モザイク度　ｈ　の入力
h=10;
for (y=0; y<hite; y=y+h){
for (x=0; x<wide; x=x+h){
for (j=0; j<h; j++)     {
for (i=0; i<h; i++)     {
dattb[x+i][y+j]=datb[x][y];
dattg[x+i][y+j]=datg[x][y];
dattr[x+i][y+j]=datr[x][y];
                         }}}} 
// モザイク処理終了

// 座標変換（２次元配列　⇒　１次元配列）
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
datt[(y*wide+x)*3+0]=dattb[x][y];
datt[(y*wide+x)*3+1]=dattg[x][y];
datt[(y*wide+x)*3+2]=dattr[x][y];
}}
// 座標変換終了

//　ディスプレイへの表示
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
  		b = datt[(y*wide+x)*3+0];		// 点(x, y)の青成分
  		g = datt[(y*wide+x)*3+1];		// 点(x, y)の青成分
  		r = datt[(y*wide+x)*3+2];		// 点(x, y)の青成分
		glcolor (b, g, r);			
		gpnt (x, y);			
      	                  }
 	glflush ( );
                          }
//　ディスプレイへの表示終了

} 

int	main (int  argc, char  **argv)
{
	get_data(argc,argv);
	ginit(1);
	gdisplay(picture_and_hist);
	return 0;
}