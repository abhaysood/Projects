bif="bg.jpg"
mif="ball.png"


import pygame,sys
from pygame.locals import *
pygame.init()


screen= pygame.display.set_mode((640,360),0,32)

background=pygame.image.load(bif).convert()
mouse_c=pygame.image.load(mif).convert_alpha()

while True:
	for event in pygame.event.get():
		if event.type==QUIT:
			pygame.quit()
			sys.exit()


	screen.blit(background,(0,0))	
	x,y=pygame.mouse.get_pos()
	x-=mouse_c.get_width()/2
	y-=mouse_c.get_height()/2
	
	screen.blit(mouse_c,(x,y))	
	pygame.display.update()
