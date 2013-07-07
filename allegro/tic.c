#include <allegro.h>

BITMAP *xSprite;
BITMAP *oSprite;

int board[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0}; //This will be used to keep
                                             //track of the Xs and Os
int curSquare = 0; //This will keep track of the current square
                    //the selector is on
                                             
int turn = 1; //This will keep track of whose turn it is
              //1 Will be for X and 2 for O
              
int x = 0; //X and Y position of selector
int y = 0;

int tempX = 0; //holds temporary values used to clear selector
int tempY = 0;

void setupBoard(){ //This function will draw in the grid

    acquire_screen();
    
    line( screen, 200, 0, 200, 480, makecol( 255, 255, 255));
    line( screen, 400, 0, 400, 480, makecol( 255, 255, 255));
    line( screen, 0, 150, 680, 150, makecol( 255, 255, 255));
    line( screen, 0, 300, 680, 300, makecol( 255, 255, 255));
    
    rect( screen, x+1, y+1, x + 199, y + 149, makecol( 255, 255, 0));
        
    release_screen();
    
}    

void updateBoard(){ //draws in selector

    rect( screen, tempX+1, tempY+1, tempX + 199, tempY + 149, makecol( 0, 0, 0));  
    rect( screen, x+1, y+1, x + 199, y + 149, makecol( 255, 255, 0));  
    rest(100);
}  

void announceWinner(){ //Announces the winner

        
         if( turn == 1){
                   textout_ex( screen, font, "X Wins!!!!",  300, 240, makecol( 255, 0, 0), makecol(0, 0, 0));  
         } else {
                  textout_ex( screen, font, "O Wins!!!!",  300, 240, makecol( 255, 0, 0), makecol(0, 0, 0));  
         }  


}

void checkWin(){ //checks for a winner
    
    if( board[0] == turn && board[1] == turn &&  board[2] == turn){
        announceWinner();
    } else if( board[0] == turn &&  board[3] == turn  && board[6] == turn){
        announceWinner();
    } else if( board[0] == turn &&  board[4] == turn  && board[8] == turn){
        announceWinner();
    } else if( board[1] == turn &&  board[4] == turn  && board[7] == turn){
        announceWinner();
    } else if( board[2] == turn &&  board[4] == turn  && board[6] == turn){
        announceWinner();
    } else if( board[2] == turn &&  board[5] == turn  && board[8] == turn){
        announceWinner();
    } else if( board[3] == turn &&  board[4] == turn  && board[5] == turn){
        announceWinner();
    } else if( board[6] == turn &&  board[7] == turn  && board[8] == turn){
        announceWinner();
    }
    
}    

    

void drawXO(){ //draws in the X and O
   
   acquire_screen();
   
   if(turn == 1){
    draw_sprite( screen, xSprite, x, y);
    board[curSquare] = 1;
    checkWin();
    ++turn;   
  } else if( turn == 2){
    draw_sprite( screen, oSprite, x, y);
    board[curSquare] = 2;
    checkWin();
    --turn;
  }
  
  release_screen();
  
  rest(100);
  
  }      

void moveBox(){ //takes input
    
    clear_keybuf();
    tempX = x;
    tempY = y;
    
    if( key[KEY_UP] && y != 0){
    
        y -= 150;
        curSquare -=3;
        updateBoard();
            
    } else if( key[KEY_DOWN] && y != 300){
    
        y += 150;
        curSquare +=3;
        updateBoard();
            
    }  else if( key[KEY_RIGHT] && x != 400){
    
        x += 200;
        ++curSquare;
        updateBoard();
            
    } else if( key[KEY_LEFT] && x != 0){
    
        x -= 200;
        --curSquare;
        updateBoard();
            
    } else if( key[KEY_ENTER] && board[curSquare] == 0){
    
        drawXO();
            
    }          
    
}    

int main(){
 
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
    
    xSprite = load_bitmap( "x.bmp", NULL);
    
    oSprite = load_bitmap( "o.bmp", NULL);

    setupBoard();
    
    while( !key[KEY_ESC]){
        moveBox();    
        
    }    
    
    destroy_bitmap( xSprite);
    destroy_bitmap( oSprite);
    
    return 0;
    
}   
END_OF_MAIN();

