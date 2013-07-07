import sys,pygame
from pygame.locals import *


pygame.init()

screen=pygame.display.set_mode((400,600))

screen.fill((255,255,255))

brush=pygame.image.load("ball.png")
brush=pygame.transform.scale(brush,(128,128))

pygame.display.update()

clock=pygame.time.Clock()

z=0

while True:
	clock.tick(60)
	x,y=pygame.mouse.get_pos()
	for event in pygame.event.get():
		if event.type==QUIT:
			pygame.quit()
			sys.exit()
		elif event.type==MOUSEBUTTONDOWN:	
			z=1
		elif event.type==MOUSEBUTTONUP:
			z=0
		elif z==1:
			screen.blit(brush,(x-64,y-64))
		pygame.display.update()
