import pygame, random, sys
from pygame.locals import *

WINDOWWIDTH = 400
WINDOWHEIGHT = 600
TEXTCOLOR = (255, 255, 255)
BACKGROUNDCOLOR = (0, 0, 0)
FPS = 60
#BADDIESIZE=
BADDIESPEED=5
ADDNEWBADDIERATE = 30
PLAYERMOVERATE = 6

def terminate():
    pygame.quit()
    sys.exit()

def waitForPlayerToPressKey():
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                terminate()
            if event.type == KEYDOWN:
                if event.key == K_ESCAPE: # pressing escape quits
                    terminate()
                return

def playerHasHitBaddie(playerRect, baddies):
    for b in baddies:
        if playerRect.colliderect(b['rect']):
            return True
    return False

def drawText(text, font, surface, x, y):
    textobj = font.render(text, 1, TEXTCOLOR)
    textrect = textobj.get_rect()
    textrect.topleft = (x, y)
    surface.blit(textobj, textrect)

# set up pygame, the window, and the mouse cursor
pygame.init()
mainClock = pygame.time.Clock()
windowSurface = pygame.display.set_mode((WINDOWWIDTH, WINDOWHEIGHT))
pygame.display.set_caption('Dodger')
pygame.mouse.set_visible(False)

# set up fonts
font = pygame.font.SysFont(None, 48)

# set up images
playerImage = pygame.image.load('car_enemy.png')
playerRect = playerImage.get_rect()
baddieImage = pygame.image.load('car_me.png')


topScore = 0
while True:
    # set up the start of the game
    baddies = []
    score = 0
    playerRect.topleft = (WINDOWWIDTH / 2, WINDOWHEIGHT - 90)
    moveLeft = moveRight = moveUp = moveDown = False
  
    baddieAddCounter = 0
  

    while True: # the game loop runs while the game part is playing
        score += 1 # increase score

        for event in pygame.event.get():
            if event.type == QUIT:
                terminate()

            if event.type == KEYDOWN:
          
                if event.key == K_LEFT :
                    moveRight = False
                    moveLeft = True
                if event.key == K_RIGHT :
                    moveLeft = False
                    moveRight = True
               

            if event.type == KEYUP:
                if event.key == K_ESCAPE:
                        terminate()

                if event.key == K_LEFT: 
                    moveLeft = False
                if event.key == K_RIGHT :
                    moveRight = False
               

        # Add new baddies at the top of the screen, if needed.
        baddieAddCounter += 1
        if baddieAddCounter == ADDNEWBADDIERATE:
            baddieAddCounter = 0
            baddieSize = 60
            newBaddie = {'rect': pygame.Rect(random.randint(0, WINDOWWIDTH-baddieSize), 0 - baddieSize, baddieSize, baddieSize),
                        'speed': random.randint(5, 7),
                        'surface':pygame.transform.scale(baddieImage, (baddieSize, baddieSize)),
                        }


            baddies.append(newBaddie)

        # Move the player around.
        if moveLeft and playerRect.left > 0:
            playerRect.move_ip(-1 * PLAYERMOVERATE, 0)
        if moveRight and playerRect.right < WINDOWWIDTH:
            playerRect.move_ip(PLAYERMOVERATE, 0)
        
       

        # Move the baddies down.
        for b in baddies:
            b['rect'].move_ip(0, b['speed'])
                
            
         # Delete baddies that have fallen past the bottom.
        for b in baddies[:]:
            if b['rect'].top > WINDOWHEIGHT:
                baddies.remove(b)
                

        # Draw the game world on the window.
        windowSurface.fill(BACKGROUNDCOLOR)

        # Draw the score and top score.
        drawText('Score: %s' % (score), font, windowSurface, 10, 0)
        drawText('Top Score: %s' % (topScore), font, windowSurface, 10, 40)

        # Draw the player's rectangle
        windowSurface.blit(playerImage, playerRect)

        # Draw each baddie
        for b in baddies:
            windowSurface.blit(b['surface'], b['rect'])

        pygame.display.update()

        # Check if any of the baddies have hit the player.
        if playerHasHitBaddie(playerRect, baddies):
            if score > topScore:
                topScore = score # set new top score
            break

        mainClock.tick(FPS)

    # Stop the game and show the "Game Over" screen.
    

    drawText('GAME OVER', font, windowSurface, (WINDOWWIDTH / 2)-100, (WINDOWHEIGHT / 2)-50)
    drawText('Play Again.', font, windowSurface, (WINDOWWIDTH / 2 - 80) , (WINDOWHEIGHT / 2) )
    pygame.display.update()
    waitForPlayerToPressKey()

    gameOverSound.stop()
