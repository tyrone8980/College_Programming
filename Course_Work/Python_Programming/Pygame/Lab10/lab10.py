import pygame
#1 Create at least two different functions tht draw an object to the screen.
# Your own unique image
#2 use keyboard and mouse to control two different items on the screen
#
#
#colors
BLACK    = (   0,   0,   0)
WHITE    = ( 255, 255, 255)
GREEN    = (   0, 255,   0)
RED      = ( 255,   0,   0)
BLUE     = (   0,   0, 255)
pi = 3.141592653
#window
size = [700,500]
screen = pygame.display.set_mode(size)
pygame.display.set_caption("My first game")
#to exit loop
done=False
#how fast screen updates
clock=pygame.time.Clock()
pygame.mouse.set_visible(0)
x_coord = 0
y_coord = 0
x_speed = 0
y_speed = 0
#---------------------main program loop---------------------
pygame.init()
def draw_mouse(screen,x,y):
    pygame.draw.circle(screen, BLACK, [100+x,100+y],25)
    pygame.draw.circle(screen, BLACK, [80+x,70+y],15)
    pygame.draw.circle(screen, BLACK, [120+x,70+y],15)
    pygame.draw.circle(screen, RED, [100+x,115+y],5)
    pygame.draw.circle(screen, WHITE, [90+x,90+y],2)
    pygame.draw.circle(screen, WHITE, [110+x,90+y],2)
    pygame.draw.polygon(screen, BLUE, ([99+x,110+y],[95+x,105+y],[105+x,105+y]),2)

def draw_cat(screen,x,y):
    pygame.draw.circle(screen, BLACK, [200+x,200+y],40)
    pygame.draw.polygon(screen, BLACK, ([170+x,120+y],[140+x,180+y],[180+x,180+y]))
    pygame.draw.polygon(screen, BLACK, ([230+x,120+y],[220+x,180+y],[260+x,180+y]))
    pygame.draw.circle(screen, RED, [200+x,230+y],5)
    pygame.draw.circle(screen, WHITE, [180+x,190+y],2)
    pygame.draw.circle(screen, WHITE, [220+x,190+y],2)
    pygame.draw.polygon(screen, WHITE, ([198+x,220+y],[190+x,210+y],[210+x,210+y]),0)
    # -----Events
font = pygame.font.Font(None, 25)
while done == False:
    for event in pygame.event.get(): 
        if event.type==pygame.QUIT: 
            done = True #exits loop
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                x_speed= -1
            if event.key == pygame.K_RIGHT:
                x_speed = 1
            if event.key == pygame.K_UP:
                y_speed=-1
            if event.key == pygame.K_DOWN:
                y_speed = 1
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                x_speed= 0
            if event.key == pygame.K_RIGHT:
                x_speed = 0
            if event.key == pygame.K_UP:
                y_speed=-0
            if event.key == pygame.K_DOWN:
                y_speed = 0
            
#--------------

#-------Game Logic
    pos = pygame.mouse.get_pos()
    mx = pos[0] #gets x coordinate
    my = pos[1]#get y coordinate
    x_coord += x_speed
    y_coord += y_speed
#-----------------

#----------Drawings
    screen.fill(WHITE)
    draw_cat(screen,x_coord,y_coord)
    draw_mouse(screen,mx,my)
    pygame.display.flip()
#------------------

#How many frames per second?
clock.tick(20)

#------------------------------END main program loop-----------------
