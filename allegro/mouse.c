#include <allegro.h>

BITMAP* buffer;

int cursor_x = 20;
int cursor_y = 20;

void getMouseInfo(){

     if(mouse_b & 1){

                  cursor_x = mouse_x;
                  cursor_y = mouse_y;

     }

}

void updateScreen(){

     circlefill ( buffer, cursor_x, cursor_y, 20, makecol( 0, 0, 255));
     draw_sprite( screen, buffer, 0, 0);

}

int main(){
    
    allegro_init();
    install_mouse();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
    
    buffer = create_bitmap( 640, 480);
    
    show_mouse(buffer);
    
    while( !key[KEY_ESC]){
    
           getMouseInfo();
           updateScreen();
    }

    return 0;
    
}
END_OF_MAIN();
