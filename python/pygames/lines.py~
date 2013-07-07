import pygame,sys
from pygame.locals import *


pygame.init()


screen= pygame.display.set_mode((640,360),0,32)

color=(255,111,123)

pos1=(20,20)
pos2=(100,100)

while True:
	
	for event in pygame.event.get():
		if event.type==QUIT:
			pygame.quit()
			sys.exit()
	screen.lock()
		
	pygame.draw.line(screen,color,pos1,pos2,20)

	screen.unlock()
	
	pygame.display.update()






