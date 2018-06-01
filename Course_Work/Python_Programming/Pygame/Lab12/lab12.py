import pygame
import random 
# Define some colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

class Rectangle():
   
    def __init__(self):
        self.x = random.randint(0,700)
        self.y = random.randint(0,500)
        self.height = random.randint(20,70)
        self.width = random.randint(20,70)
        self.color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
        self.change_x = random.randint(-3,3)
        self.change_y = random.randint(-3,3)
    def draw(self, screen):
        pygame.draw.rect(screen, self.color,[self.x,self.y,self.height,self.width] , 0)
    def move(self):
        self.x+=self.change_x
        self.y+=self.change_y
        self.height+=self.change_y
        self.width+=self.change_x
class Ellipse(Rectangle):
    def __init__(self):
        self.x = random.randint(0,700)
        self.y = random.randint(0,500)
        self.height = random.randint(20,70)
        self.width = random.randint(20,70)
        self.color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
        self.change_x = random.randint(-3,3)
        self.change_y = random.randint(-3,3)
    def draw(self, screen):
        pygame.draw.ellipse(screen, self.color,[self.x,self.y,self.height,self.width] , 0)
pygame.init()

size = (700, 500)
screen = pygame.display.set_mode(size)
 
pygame.display.set_caption("Lab 12")
done = False
clock = pygame.time.Clock()

while not done:
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
 

    screen.fill(WHITE)

    my_list=[]
    for i in range(1000):
        myrect = Rectangle()
        my_list.append(myrect)
    for i in range(1000):
        myellipse = Ellipse()
        my_list.append(myellipse)
    for i in my_list:
        i.draw(screen)
        i.move()
    
    pygame.display.flip()

    clock.tick(60)
 

pygame.quit()
