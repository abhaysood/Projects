#include <allegro.h>


int main(){
 
    allegro_init();
    install_keyboard();
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
    
    acquire_screen();

    clear_to_color( screen, makecol( 255, 255, 255));

    circle( screen, 50, 20, 20, makecol( 255, 0, 0));
    circlefill( screen, 50, 80, 20, makecol( 0,255, 0));

    rect( screen, 10, 120, 90,160, makecol( 0, 0, 255));
    rectfill( screen, 10, 180, 90, 220, makecol( 12, 34, 200));
    line( screen, 110, 0, 110, 479, makecol( 255, 0, 0));
    line( screen, 130, 130, 170, 130, makecol( 255, 0, 0));
    line( screen, 170, 130, 150, 150, makecol( 255, 0, 0));
    
    floodfill( screen, 140, 135, makecol( 255, 255, 0));

    triangle( screen, 200, 200, 200, 220, 220, 210, makecol( 213, 79, 40)); 

    release_screen();

    readkey();
    
    return 0;
    
}   
END_OF_MAIN();
