/* “Ç‚İ‚ñ‚¾‰æ‘œ‚ğ‰æ‘œ”Z“x127‚Å‚Q’l‰» */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

unsigned char 	dat[1024*1024];
int	 			cm, wide, hite;

void	get_data (int  agc, char  **agv){
	if (agc != 2){
		printf ("g—p–@:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile (agv[1], &cm, &hite, &wide, dat);
}

void	picture_and_hist (void){	// Œ´‰æ‘œ‚Æ‚Q’l‰»ƒq‰æ‘œ‚Ì•\¦
	unsigned char	r ;
	int				x, y,i,j ;
        int th[16][16];
th[0][0]= 16; th[1][0]=144; th[2][0]= 48; th[3][0]=176;
th[0][1]=208; th[1][1]= 80; th[2][1]=240; th[3][1]=100;
th[0][2]= 64; th[1][2]=192; th[2][2]= 32; th[3][2]=160;
th[0][3]=255; th[1][3]=128; th[2][3]=224; th[3][3]= 96;

	glclear ( ) ;
    for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		r = dat[y*wide+x];
		glcolor (r, r, r);			// Œ´‰æ‘œ‚ğ
		gpnt (x, y);				// ‘æ‚PÛŒÀ‚É•\¦
		
		if (r< th[x%4][y%4])	r = 0; 		// –¾‚é‚³‚ª128ˆÈ‰º‚È‚ç r = 0
		else			r = 255;	// ‚»‚¤‚Å‚È‚¯‚ê‚Î r = 255
		glcolor (r, r, r);			// ‚Q’l‰»‰æ‘œ‚ğ
		gpnt (x-wide, y);			// ‘æ‚QÛŒÀ‚É•\¦

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