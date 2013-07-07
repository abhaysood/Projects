
#include<stdio.h>
#include<allegro.h>
#define DOWN_RIGHT 1
#define UP_RIGHT 2
#define DOWN_LEFT 3
#define UP_LEFT 4

void moveball(void);
void reversevertical(void);
void reversehorizontal(void);
int ball_x;
int ball_y;
int direction;

BITMAP *ball;
BITMAP *buffer;

int main()
{

allegro_init();
install_keyboard();
set_color_depth(16);
set_gfx_mode(GFX_AUTODETECT,640,480,0,0);
ball=load_bitmap("ball.bmp",NULL);
buffer=create_bitmap(SCREEN_W,SCREEN_H);
ball_x=SCREEN_W/2;
ball_y=SCREEN_H/2;
srand(time(NULL));
direction= rand()%4;

while(!key[KEY_ESC])
{
moveball();
clear_to_color(screen,makecol(256,256,256));
blit(ball,buffer,0,0,ball_x,ball_y,ball->w,ball->h);
blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
clear_bitmap(buffer);
}
destroy_bitmap(ball);
destroy_bitmap(buffer);
return(0); 
}
END_OF_MAIN();	



void reversevertical()
{
if((direction%2)==0)
++direction;
else
--direction;
}

void reversehorizontal()
{
direction=(direction+2)%4;
}

void moveball()
{
switch(direction)
{
case DOWN_RIGHT:
++ball_x;
++ball_y;
break;
case DOWN_LEFT:
--ball_x;
++ball_y;
break;
case UP_RIGHT:
++ball_x;
--ball_y;
break;
case UP_LEFT:
--ball_x;
--ball_y;
break;
}

if(ball_y<=30||ball_y>=440)
reversevertical();
if(ball_x<=0||ball_x>=600)
reversehorizontal();
}




 
