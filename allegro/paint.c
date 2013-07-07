#include <allegro.h>
BITMAP* buffer;
int cursor_x=20;
int cursor_y=20;



void get_mouse_info()
{
	if(mouse_b & 1)
	{
	cursor_x=mouse_x;
	cursor_y=mouse_y;
	}
}
    
void circle_empty()
{
circle(buffer,cursor_x,cursor_y,20,makecol(0,0,255));
draw_sprite(screen,buffer,0,0);
}

void circle_fill()
{
circlefill(buffer,cursor_x,cursor_y,20,makecol(0,0,255));
draw_sprite(screen,buffer,0,0);
}


void rect_empty()
{
rect(buffer,cursor_x,cursor_y,cursor_x+20,cursor_y+20,makecol(0,0,255));
draw_sprite(screen,buffer,0,0);
}

void shape_menu()
{
 circle( screen, 50, 20, 20, makecol( 0,0,255));
 circlefill( screen, 50, 80, 20, makecol( 0,0,255));

 rect( screen,10,120,90,160,makecol( 0,0,255));
 rectfill( screen, 10, 180, 90, 220,makecol( 0,0,255));

 line( screen, 110, 0, 110, 479,makecol( 255,255,255));
}

int main()
{
allegro_init();
install_mouse();
install_keyboard();
set_color_depth(16);
set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
buffer = create_bitmap( 640, 480);
show_mouse(buffer);
	while(!key[KEY_ESC])
		{	
		shape_menu();
		get_mouse_info();
		circle_fill();
		
			if(cursor_x<=110&&cursor_y<=40)
			{
			circle_empty();
			}
			else if(cursor_x<=110&&cursor_y>=60||cursor_y<=120)
			{
			circle_fill();
			}
		}

return 0;   
}
END_OF_MAIN();


