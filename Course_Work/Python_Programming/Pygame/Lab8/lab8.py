import pygame
pygame.init()

BLACK = (0,0,0)
WHITE = (255,255,255)
BLUE = (0,0,255)
GREEN = (0,255,0)
RED = (255,0,0)

size = (500,500)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Dance Show")
clock = pygame.time.Clock()
done = False

#  Multiple colors
# multiple shapes
# a while or for loop to create repeated pattern
my_x = 230
my_arm1x = 200
my_arm2x = 260
my_leg1x = 210
my_leg2x = 250
delta = 5
my_arms = 90
delta2 = 2
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
    if(my_arms < 50):
        delta2 =  2
    elif(my_arms > 150):
        delta2 = -2
    
        
    if(my_arm2x > 450):
        delta = -5
    elif(my_leg1x < 25):
        delta = 5
    my_x += delta
    my_arm1x += delta
    my_arm2x += delta
    my_leg1x += delta
    my_leg2x += delta
    my_arms += delta2

    
    

    

    
    screen.fill(WHITE)
    # Draw Me
    pygame.draw.circle(screen, BLACK, [my_x,100], 20)
    pygame.draw.line(screen, RED, [my_x, 120], [my_x,200], 2)
    # Legs
    pygame.draw.line(screen, RED, [my_x, 200], [my_leg1x,250], 2)
    pygame.draw.line(screen, RED, [my_x, 200], [my_leg2x,250], 2)
    # Arms
    pygame.draw.line(screen, RED, [my_x, 150], [my_arm1x,my_arms], 2)
    pygame.draw.line(screen, RED, [my_x, 150], [my_arm2x,my_arms], 2)
    
    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
    text = font.render("Hofsfstra Dance Showcase", True, BLACK)
    screen.blit(text, [100,50])
    pygame.draw.rect(screen, BLACK, [0,250,500,100],0)
    x_location = 20
    for shapes in range(0,5):
        pygame.draw.rect(screen, BLUE, [x_location,450,50,50],0)
        pygame.draw.circle(screen, BLACK, [x_location + 25,425], 20)
        x_location += 100
        
    pygame.display.flip()

    clock.tick(60)
    
pygame.quit()
