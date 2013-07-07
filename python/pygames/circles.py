import pygame,sys
from pygame.locals import *


pygame.init()


screen= pygame.display.set_mode((640,360),0,32)

color=(255,255,0)
position=(300,176)

radius=30

while True:
	
	for event in pygame.event.get():
		if event.type==QUIT:
			pygame.quit()
			sys.exit()
	screen.lock()
		
	pygame.draw.circle(screen,color,position,radius)

	screen.unlock()
	
	pygame.display.update()






