/* 平滑化　フィルタ */
#include <windows.h>
#include	<stdio.h>
#include	"opgls.ft"

#define		MaxSiz		1024
//#define		gp(y, x)	dat[(y)*wide+(x)]

double sort[10];
double dat2b[1024][1024];
double dat2g[1024][1024];
double dat2r[1024][1024];
unsigned char dat[1024*1024*3];
unsigned char 	datt[1024*1024*3];
int	 			cm, wide, hite,gray;

void	get_data (int  agc, char  **agv){

  	if (agc != 2){
		printf ("使用法:: %s  file.bmp\n", agv[0]);		exit(-1);
	}
	loadbmpfile(agv[1], &cm, &hite, &wide, dat);
}

void show(void){
	unsigned  char	gr, ddx, ddy;
	int				x, y,i,j,m,n,temp,med;
	int o=0;

 glclear ( );

for (y=0; y<hite; y++) for (x=0; x<wide; x++){
		//gr = gp(y, x);			//原画像の表示
		//glcolor (gr, gr, gr);	gpnt (x, y);
	}

for(y=0;y<hite;y++){
for(x=0; x<wide; x++){
dat2b[x][y]=dat[(y*wide+x)];
dat2g[x][y]=dat[(y*wide+x)];
dat2r[x][y]=dat[(y*wide+x)];
//printf("%d%d%d\n",dat2b[x][y],dat2g[x][y],dat2r[x][y]);
}
}
for(y=0;y<hite;y++){
for(x=0; x<wide; x++){
 gray = dat2b[x][y]*0.114+dat2g[x][y]*0.587+dat2r[x][y]*0.299;
  		dat2b[x][y] = gray;	
  		dat2g[x][y] = gray;	
  		dat2r[x][y] = gray;
                 glcolor (dat2b[x][y], dat2g[x][y], dat2r[x][y]);			
	    gpnt (x-256, y);
//printf("%d\n",m);
}
glflush();
}
	
    
    for (y=1; y<hite-1; y++) for (x=1; x<wide-1; x++){
for(j=0;j<3;j++){
for(i=0;i<3;i++){
sort[o]=dat2b[x+i][y+j];
o++;
}
}

for(m=0;m<9-1;m++){
for(n=9-1;n>m;n--){
 if(sort[n]<sort[n-1]){
  temp=sort[n];
sort[n]=sort[n-1];
sort[n-1]=temp;
}
}
}
med=sort[4];


datt[(y*wide+x)*3+0]=med;
datt[(y*wide+x)*3+1]=med;
datt[(y*wide+x)*3+2]=med;

		


o=0;
//printf("%d%d\n",med,sort[4]);	
	}
for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
         glcolor (datt[(y*wide+x)*3+0],datt[(y*wide+x)*3+1],datt[(y*wide+x)*3+2]);
         gpnt (x, y);
}
	glflush ( );
}
}

void	main (int  argc, char  **argv){
	get_data (argc, argv);
	ginit (1);
	gdisplay (show);
}