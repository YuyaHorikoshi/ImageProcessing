/* ���U�C�N�݂̂̏���*/
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

void	picture_and_hist (void){	// ���摜�ƂQ�l���q�摜�̕\��
	unsigned char	r,g,b ;
	int	x, y, i, j, h, m, sx, sy, k, s, t, u, v, w; 
	double hh, con;
        glclear ( );

// ���W�ϊ��i�P�����z��@�ˁ@�Q�����z��j
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
datb[x][y]=dat[(y*wide+x)*3+0];
datg[x][y]=dat[(y*wide+x)*3+1];
datr[x][y]=dat[(y*wide+x)*3+2];
}}
// ���W�ϊ��I��

// �J���[�摜�𔒍��摜�ɕϊ�
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
  	    b = datb[x][y];	// �_(x, y)�̐���
  	    g = datg[x][y];	// �_(x, y)�̗ΐ���
  	    r = datr[x][y];	// �_(x, y)�̐Ԑ���
            m = datb[x][y]*0.114+datg[x][y]*0.587+datr[x][y]*0.299;
  		datb[x][y] = m;	
  		datg[x][y] = m;	
  		datr[x][y] = m;	
	    glcolor (m, m, m);			
	    gpnt (x-256, y);
      	                  }
            glflush ( );
                          }
// �J���[�摜�𔒍��摜�ɕϊ��I�� 

// ���U�C�N����
//scanf("%d",&h);    // ���U�C�N�x�@���@�̓���
h=10;
for (y=0; y<hite; y=y+h){
for (x=0; x<wide; x=x+h){
for (j=0; j<h; j++)     {
for (i=0; i<h; i++)     {
dattb[x+i][y+j]=datb[x][y];
dattg[x+i][y+j]=datg[x][y];
dattr[x+i][y+j]=datr[x][y];
                         }}}} 
// ���U�C�N�����I��

// ���W�ϊ��i�Q�����z��@�ˁ@�P�����z��j
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
datt[(y*wide+x)*3+0]=dattb[x][y];
datt[(y*wide+x)*3+1]=dattg[x][y];
datt[(y*wide+x)*3+2]=dattr[x][y];
}}
// ���W�ϊ��I��

//�@�f�B�X�v���C�ւ̕\��
    for (y=0; y<hite; y++){
    for (x=0; x<wide; x++){
  		b = datt[(y*wide+x)*3+0];		// �_(x, y)�̐���
  		g = datt[(y*wide+x)*3+1];		// �_(x, y)�̐���
  		r = datt[(y*wide+x)*3+2];		// �_(x, y)�̐���
		glcolor (b, g, r);			
		gpnt (x, y);			
      	                  }
 	glflush ( );
                          }
//�@�f�B�X�v���C�ւ̕\���I��

} 

int	main (int  argc, char  **argv)
{
	get_data(argc,argv);
	ginit(1);
	gdisplay(picture_and_hist);
	return 0;
}