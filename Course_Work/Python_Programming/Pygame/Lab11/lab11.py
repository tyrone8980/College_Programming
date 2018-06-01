#################
#####Check List#####
# Program has its own directory
# Function that draws something to screen
# Control Item Via keyboard
# bitmapped graphic
# music
# sound when user hits a button 
import pygame
import random
import os
current_path = os.path.dirname("C:/Users/harmo/AppData/Local/Programs/Python/Python36-32/lab11")
print (os.getcwd())
BLACK    = (   0,   0,   0)
WHITE    = ( 255, 255, 255)
GREEN    = (   0, 255,   0)
RED      = ( 255,   0,   0)
BLUE     = (   0,   0, 255)
COLORS = [BLACK,WHITE,GREEN,RED,BLUE]
#window
screen_width = 852
screen_height = 450
screen = pygame.display.set_mode([screen_width,screen_height])
class Food(pygame.sprite.Sprite):
    def __init__(self, color, width, height):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface([width, height])
        self.image.fill(color)
        self.rect = self.image.get_rect()
    def update(self):
        self.rect.y += 1
        if self.rect.y >597:
            self.rect.y = - 20
            self.rect.x = random.randrange(860)
class PlayerBlock(Food):
    def update(self):
        player_position = pygame.mouse.get_pos()
        self.rect.x=player_position[0] + 95#gets x coordinate
        self.rect.y=player_position[1]+ 150#get y coordinate
pygame.init()
    # -----Events
food_list = pygame.sprite.Group()
all_sprites_list = pygame.sprite.Group()
for i in range(20):
    food = Food(COLORS[random.randint(0,4)], 10, 10)
    food.rect.x = random.randrange(screen_width)
    food.rect.y = random.randrange(screen_height)
    food_list.add(food)
    all_sprites_list.add(food)
player_point = PlayerBlock(BLUE, 30, 30)
all_sprites_list.add(player_point)
class Game():
    food_list = None
    all_sprites_list = None
    player_point = None
    game_over = False
    score = 0
    def __init__(self):
        self.score = 0
        self.game_over = False
        self.food_list = pygame.sprite.Group()
        self.all_sprites_list = pygame.sprite.Group()
        for i in range(50):
            food = Food(COLORS[random.randint(0,4)], 10, 10)
            food.rect.x=random.randrange(screen_width)
            food.rect.y=random.randrange(-300,screen_height)
            self.food_list.add(food)
            self.all_sprites_list.add(food)
        self.player_point = PlayerBlock(COLORS[random.randint(0,4)], 10, 10)
        self.all_sprites_list.add(self.player_point)
    def process_event(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return True
            if event.type == pygame.MOUSEBUTTONDOWN:
                if self.game_over:
                    self.__init__()
        return False
    def logic(self):
        if not self.game_over:
            self.all_sprites_list.update()
            food_hit_list = pygame.sprite.spritecollide(self.player_point,self.food_list,True)
            for food in food_hit_list:
                self.score += 1
                print(self.score)
    def display_frame(self,screen):
        background_image = pygame.image.load(os.path.join(current_path, "LED3.jpg")).convert()
        screen.blit(background_image, [0,0])
        player_position = pygame.mouse.get_pos()
        mx = player_position[0] #gets x coordinate
        my = player_position[1]#get y coordinate
        player = pygame.image.load("alexis2.png").convert_alpha()
        screen.blit(player, [mx,my])
        #display = font.render("Score: "+str(score),True, BLUE)
        if self.game_over:
                   font = pygame.font.Font(None, 25)
                   text = font.render("GAME OVER", True, BLACK)
                   x = (screen_width//2)-(text.get_width()//2)
                   x = (screen_height//2)-(text.get_height()//2)
                   screen.blit(text, [x,y])
        if not self.game_over:
                   self.all_sprites_list.draw(screen)
        pygame.display.flip()
def main():
    pygame.init()
    #to exit loop
    done= False
   #how fast screen updates
    clock=pygame.time.Clock()
    pygame.mouse.set_visible(0)
    
    player = pygame.image.load("alexis.png").convert_alpha()
    player.set_colorkey(WHITE)
    pygame.mixer.music.load("TRAP.mp3")
    pygame.mixer.music.play(-1)
    #click_sound = pygame.mixer.Sound("laser.mp3")
    game = Game()
    while not done:
        done = game.process_event()
        game.logic()
        game.display_frame(screen)
        clock.tick(20)
    pygame.quit()
main()
#--------------

#-------Game Logic

#-----------------

#----------Drawings
    
    
#------------------

#How many frames per second?

#------------------------------END main program loop-----------------
