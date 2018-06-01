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

while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
    screen.fill(WHITE)
    # Draw Me
    pygame.draw.circle(screen, BLACK, [230,100], 20)
    pygame.draw.line(screen, RED, [230, 120], [230,200], 2)
    # Legs
    pygame.draw.line(screen, RED, [230, 200], [210,250], 2)
    pygame.draw.line(screen, RED, [230, 200], [250,250], 2)
    # Arms
    pygame.draw.line(screen, RED, [230, 150], [200,90], 2)
    pygame.draw.line(screen, RED, [230, 150], [260,90], 2)
    
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
