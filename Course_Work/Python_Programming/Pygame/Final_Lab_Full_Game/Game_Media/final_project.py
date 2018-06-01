#Group 6 final project: The candy man
# Coder: Alexis Garrett
# Game desinger: Amanda Geffner
# Audio/Story Boarding Jordan Johnston
# Artist: Jenny Maldonado

 

import pygame
import time
import random
import  os
import string
import sys
from pygame.locals import *
import textwrap
sweets = ["sweet.png","sweet2.png","sweet3.png","sweet4.png"]

class Player(object):
    def __init__(self):
        self.rect = pygame.Rect(32, 32, 24, 24)

    def move(self, dx, dy):
        
        
        if dx != 0:
            self.move_single_axis(dx, 0)
        if dy != 0:
            self.move_single_axis(0, dy)
    
    def move_single_axis(self, dx, dy):
        
        # Move the rect
        self.rect.x += dx
        self.rect.y += dy

        
        for wall in walls:
            if self.rect.colliderect(wall.rect):
                if dx > 0: 
                    self.rect.right = wall.rect.left
                if dx < 0: 
                    self.rect.left = wall.rect.right
                if dy > 0: 
                    self.rect.bottom = wall.rect.top
                if dy < 0: 
                    self.rect.top = wall.rect.bottom
class Wall(object):
    
    def __init__(self, pos):
        walls.append(self)
        self.rect = pygame.Rect(pos[0], pos[1], 24, 24)

class Sweet(object):
    def __init__(self, pos):
        candies.append(self)
        self.color = sweets[random.randint(0,3)]
        self.rect = pygame.Rect(pos[0], pos[1], 24, 24)
    
class Sweet2(object):
    def __init__(self, pos):
        candies2.append(self)
        self.color = sweets[random.randint(0,3)]
        self.rect = pygame.Rect(pos[0], pos[1], 24, 24)
# Initialise pygame
os.environ["SDL_VIDEO_CENTERED"] = "1"

pygame.init()
display_width = 800
display_height = 600

black = (0,0,0)
white = (255,255,255)
red = (255,0,0)
 
block_color = (53,115,255)

gameDisplay = pygame.display.set_mode((display_width,display_height))
pygame.display.set_caption('The CandyMan')
clock = pygame.time.Clock()
timer_effect = pygame.mixer.Sound('timer.wav')
def display_text_animation(string, size, position):
    text = ''
    for i in range(len(string)):
        pygame.font.init()
        gameDisplay.fill(black)
        text += string[i]
        font6 = pygame.font.SysFont("Yu Gothic", size, True, False)
        text_surface = font6.render(text, True, white)        
        gameDisplay.blit(text_surface, position)
        pygame.display.update()
        pygame.time.wait(100)

def blinker(string):
    for i in range(0,2):
        i= i % 2
        pygame.font.init()
        font5 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text5 = font5.render(string, True, blink[i])
        gameDisplay.blit(text5, [300,500])
        pygame.display.update()
        pygame.time.wait(100)
player = Player()

walls = []
level = [   
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"W                  W             W",
"W         WWWWWW   W   WWWWWW    W",
"W   WWWWC      W   W   W    W    W",
"W   W        WWWW  WWWWW    W    W",
"W WWW  WWWW                   C  W",
"W   W     W W  C                 W",
"W   W     W   WWW  WWWWW     WWWWW",
"W   WWW WWW   W W  W   W         W",
"W     W   W   W W  W   W  WWWW   W",
"WWW   W   WWWWW W  WWW      W    W",
"W W      WW                 W    W",
"W W   WWWW   WWW   W  WWWWWWW    W",
"W     W    E   W   W  W  C       W",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFWW",
]

finals = []
candies = []

x = y = 0
for row in level:
    for col in row:
        if col == "W":
            Wall((x, y))
        if col == "E":
            end_rectx = x
            end_recty = y
        if col == "F":
            finals.append(pygame.Rect(x, y, 24, 24))
        if col == "C":
            Sweet((x, y))
        x += 24
    y += 24
    x = 0

blink = [black,white]

def title_screen():
    titlescreen = True
    gameDisplay.fill(black)
    #display_text_animation("WORK IN PROGRESS", 25, [50,50])
    mystring = ["Directions:", "Play the 3 levels to help the candy man get his candy.","  ","Story"]
    mystring.append("The Candy Man lives in a magical candy land. One day, when he is in")
    mystring.append("his treasury room full of candy, a portal mysteriously opens up, transporting the")
    mystring.append("Candy Man and his treasure to a locked dungeon. Once the Candy Man arrives, his")
    mystring.append("goal is to take back his candy. The player must help the Candy Man escape the ")
    mystring.append("dungeon maze and take back as much of his candy as possible. ")
    mystring.append("  ")
    mystring.append("BONUS:")
    mystring.append("If you collect all the candy... you unlock a bonus round!!")
    mystring.append("   ")
    mystring.append("Press Enter To Play!")
    
    position = [25,50]
    text = ''
    for strings in mystring:
        for i in range(len(strings)):
            pygame.font.init()
            text += strings[i]
            font6 = pygame.font.SysFont("Yu Gothic", 25, True, False)
            text_surface = font6.render(text, True, white)        
            gameDisplay.blit(text_surface, position)
            pygame.display.update()
            pygame.time.wait(50)
        position[1]+= 20
        text = ''
            
    while titlescreen:
        pygame.display.update()
        clock.tick(15)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro = False
                pygame.quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                gameLoop(3)
                intro = False
def game_over():
    pygame.mixer.music.stop()
    pygame.mixer.music.load("EndSong.mp3")
    pygame.mixer.music.play(-1)
    titlescreen = True
    gameDisplay.fill(black)
    display_text_animation("Sorry You Lost!! Want To Play Again? Press Enter", 25, [200,500])
    final_logo = pygame.image.load("gameoverlogo2.png").convert()
    gameDisplay.blit(final_logo, [150,50])
    while titlescreen:
        pygame.display.update()
        clock.tick(15)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro = False
                pygame.quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                walls = []
                level = [   
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "W                  W             W",
                "W         WWWWWW   W   WWWWWW    W",
                "W   WWWWC      W   W   W    W    W",
                "W   W        WWWW  WWWWW    W    W",
                "W WWW  WWWW                   C  W",
                "W   W     W W  C                 W",
                "W   W     W   WWW  WWWWW     WWWWW",
                "W   WWW WWW   W W  W   W         W",
                "W     W   W   W W  W   W  WWWW   W",
                "WWW   W   WWWWW W  WWW      W    W",
                "W W      WW                 W    W",
                "W W   WWWW   WWW   W  WWWWWWW    W",
                "W     W    E   W   W  W  C       W",
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFWW",
                ]   

                finals = []
                candies = []

                x = y = 0
                for row in level:
                    for col in row:
                        if col == "W":
                            Wall((x, y))
                        if col == "E":
                            end_rectx = x
                            end_recty = y
                        if col == "F":
                            finals.append(pygame.Rect(x, y, 24, 24))
                        if col == "C":
                            Sweet((x, y))
                        x += 24
                    y += 24
                    x = 0
                gameLoop(3)
                intro = False

def game_intro():
    intro = True
    while intro:
        gameDisplay.fill(black)
        pygame.font.init()
        title = pygame.image.load("coollogo_com-935085.png").convert()
        title2 = pygame.image.load("start_game_logo.png").convert()
        title3 = pygame.image.load("lollipop.png").convert_alpha()
        title4 = pygame.image.load("lollipop2.png").convert_alpha()
        gameDisplay.blit(title, [50,50])
        gameDisplay.blit(title2, [175,300])
        gameDisplay.blit(title3, [650,300])
        gameDisplay.blit(title4, [25,300])
        #font5 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        #text5 = font5.render("Press Enter To Begin!", True, blink[1])
        #gameDisplay.blit(text5, [300,500])
        blinker("Press Enter To Begin!")
        pygame.display.update()
        clock.tick(15)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro = False
                pygame.quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                pygame.mixer.music.load("IceCream.mp3")
                pygame.mixer.music.play(-1)
                title_screen()
                intro = False
              
        
def gameLoop(player_life):
    lives = player_life
    clock = pygame.time.Clock()
    font = pygame.font.Font(None,25)
    frame_count = 0 
    frame_rate = 60
    start_time = 35
    candy_count = 0
    #reset screen
    gameDisplay.fill(black)
    #Maze Game Logic
    gameExit = False
    has_key = False
    while not gameExit:
        #More logic
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                gameExit = True

        key = pygame.key.get_pressed()
        if key[pygame.K_LEFT]:
            player.move(-2, 0)
        if key[pygame.K_RIGHT]:
            player.move(2, 0)
        if key[pygame.K_UP]:
            player.move(0, -2)
        if key[pygame.K_DOWN]:
            player.move(0, 2)

        

    
        gameDisplay.fill((0, 0, 0))
        for wall in walls:
            pygame.draw.rect(gameDisplay, (255, 255, 255), wall.rect)
        #pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)
        keys = pygame.image.load("key.png").convert_alpha()
        if has_key == False:
            gameDisplay.blit(keys, [end_rectx,end_recty])
        my_player = pygame.image.load("icon.png").convert_alpha()
        gameDisplay.blit(my_player, player.rect)
        #pygame.draw.rect(gameDisplay, (255, 200, 0), player.rect)
        for end_rect in finals:
            pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)
        for candy in candies:
            c = pygame.image.load(candy.color).convert_alpha()
            gameDisplay.blit(c, candy)
            if player.rect.colliderect(candy):
                candy_count+=1
                candies.remove(candy)

        font1 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text1 = font1.render("Level 1 ", True, white)
        gameDisplay.blit(text1, [10,380])
        font2 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text2 = font2.render("Total Candy " + str(candy_count), True, white)
        gameDisplay.blit(text2, [10,395])
        font3 = pygame.font.SysFont("Yu Gothic", 30, True, False)
        text3 = font3.render("Lives:", True, white)
        gameDisplay.blit(text3, [10,425])
        title5 = pygame.image.load("candyheart.png").convert_alpha()
        for life in range(1,lives+1):
            gameDisplay.blit(title5, [83*life,405])

        
        
        if player.rect.colliderect(pygame.Rect(end_rectx,end_recty,24,24)):
            font = pygame.font.SysFont("Yu Gothic", 25, True, False)
            text = font.render("You Have the Key!!", True, white)
            gameDisplay.blit(text, [50,500])
            has_key = True
        for end_rect in finals:
            if player.rect.colliderect(end_rect) and has_key == False:
                if player.rect.y> 0: 
                    player.rect.bottom = wall.rect.top
                    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                    text = font.render("You Need To Find The Key!!", True, white)
                    gameDisplay.blit(text, [50,500])
                if player.rect.y < 0: 
                    player.rect.top = wall.rect.bottom
                    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                    text = font.render("You Need To Find The Key!!", True, white)
                    gameDisplay.blit(text, [50,500])
            
            

            if player.rect.colliderect(end_rect) and has_key == True:
                font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                text = font.render("You Won!!", True, white)
                gameDisplay.blit(text, [50,500])
                gameLoop2(candy_count,lives)
        total_seconds = start_time - frame_count // frame_rate
        if total_seconds < 0:
            total_seconds = 0
        minutes = total_seconds // 60
        seconds = total_seconds % 60
        output_string = "Time: {0:02}:{1:02}".format(minutes,seconds)
        clocktext = font.render(output_string, True, white)
        gameDisplay.blit(clocktext, [10,460])
        frame_count +=1
        clock.tick(frame_rate)
        if total_seconds == 0:
            lives -= 1
            timer_effect.play()
            gameLoop(lives)
        if lives == 0 :
            game_over()

        pygame.display.flip()



def gameLoop2(candy,player_life):
    walls.clear()
    lives = player_life
    clock = pygame.time.Clock()
    font = pygame.font.Font(None,25)
    frame_count = 0 
    frame_rate = 60
    start_time = 35
    candy_count = candy
    player = Player()
    level2 = [   
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    "W               C  W           E W",
    "WWWWWWWW        WWW          WWWWW",
    "F      W       W   W   W     W   W",
    "F      WC    WWWW  WWWWW     W   W",
    "W WWW  WWWW                      W",
    "W   W     W W     C              W",
    "W         W   WWW  WWWWW     WWWWW",
    "W   WWW WWW   W W  W   W         W",
    "W     W C W   W W  W C  W  WWWW  W",
    "WWW   W   WWWWW W  WWW      W    W",
    "W       WW                 W C   W",
    "W     WWWW   WWW   W  WWWWWWW    W",
    "W C            W   W             W",
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",   
    ]

    finals = []
    candies = []
    x = y = 0
    for row in level2:
        for col in row:
            if col == "W":
                Wall((x, y))
            if col == "E":
                end_rectx = x
                end_recty = y
            if col == "F":
                finals.append(pygame.Rect(x, y, 24, 24))
            if col == "C":
                candies.append(pygame.Rect(x,y,24,24))
            x += 24
        y += 24
        x = 0

    #reset screen
    gameDisplay.fill(black)
    #Maze Game Logic
    gameExit = False
    has_key = False
    while not gameExit:
        #More logic
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                gameExit = True

        key = pygame.key.get_pressed()
        if key[pygame.K_LEFT]:
            player.move(-2, 0)
        if key[pygame.K_RIGHT]:
            player.move(2, 0)
        if key[pygame.K_UP]:
            player.move(0, -2)
        if key[pygame.K_DOWN]:
            player.move(0, 2)

        

    
        gameDisplay.fill((0, 0, 0))
        for wall in walls:
            pygame.draw.rect(gameDisplay, (255, 255, 255), wall.rect)
        #pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)
        for candy in candies:
            c = pygame.image.load("sweet.png").convert_alpha()
            gameDisplay.blit(c, candy)
            if player.rect.colliderect(candy):
                candy_count+=1
                candies.remove(candy)
        
        keys = pygame.image.load("key.png").convert_alpha()
        if has_key == False:
            gameDisplay.blit(keys, [end_rectx,end_recty])
        my_player = pygame.image.load("icon.png").convert_alpha()
        gameDisplay.blit(my_player, player.rect)
        #pygame.draw.rect(gameDisplay, (255, 200, 0), player.rect)
        for end_rect in finals:
            pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)

        font1 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text1 = font1.render("Level 2 ", True, white)
        gameDisplay.blit(text1, [10,380])
        font2 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text2 = font2.render("Total Candy " + str(candy_count), True, white)
        gameDisplay.blit(text2, [10,395])
        font3 = pygame.font.SysFont("Yu Gothic", 30, True, False)
        text3 = font3.render("Lives:", True, white)
        gameDisplay.blit(text3, [10,425])
        title5 = pygame.image.load("candyheart.png").convert_alpha()
        for life in range(1,lives+1):
            gameDisplay.blit(title5, [83*life,405])
        
        if player.rect.colliderect(pygame.Rect(end_rectx,end_recty,24,24)):
            font = pygame.font.SysFont("Yu Gothic", 25, True, False)
            text = font.render("You Have the Key!!", True, white)
            gameDisplay.blit(text, [50,500])
            has_key = True
        for end_rect in finals:
            if player.rect.colliderect(end_rect) and has_key == False:
                if player.rect.x< 0: 
                    player.rect.right = wall.rect.left
                    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                    text = font.render("You Need To Find The Key!!", True, white)
                    gameDisplay.blit(text, [50,500])
                if player.rect.x > 0: 
                    player.rect.left = wall.rect.right
                    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                    text = font.render("You Need To Find The Key!!", True, white)
                    gameDisplay.blit(text, [50,500])
            if player.rect.colliderect(end_rect) and has_key == True:
                font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                text = font.render("You Won!!", True, white)
                gameDisplay.blit(text, [50,500])
                gameLoop3(candy_count, lives)
        total_seconds = start_time - frame_count // frame_rate
        if total_seconds < 0:
            total_seconds = 0
        minutes = total_seconds // 60
        seconds = total_seconds % 60
        output_string = "Time: {0:02}:{1:02}".format(minutes,seconds)
        clocktext = font.render(output_string, True, white)
        gameDisplay.blit(clocktext, [10,460])
        frame_count +=1
        clock.tick(frame_rate)
        if total_seconds == 0:
            lives -= 1
            timer_effect.play()
            gameLoop2(candy_count,lives)
        if lives == 0 :
            game_over()
            
        pygame.display.flip()
                

def gameLoop3(candy,player_life):
    walls.clear()
    lives = player_life
    clock = pygame.time.Clock()
    font = pygame.font.Font(None,25)
    frame_count = 0 
    frame_rate = 60
    start_time = 35
    candy_count = candy
    player = Player()
    level3 = [   
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    "W                  W C           W",
    "W         WWWWWW   W   WWWWWW    W",
    "W   WWWW       W   W   W    W    W",
    "W   W    C   WWWW  WWWWW    W    W",
    "W WWW  WWWW                      W",
    "W   W     W W            C       W",
    "W   W  C  W   WWW  WWWWW     WWWWW",
    "W   WWW WWW   W W  W   W  C      W",
    "W     W   W   W W  W   W  WWWW   W",
    "WWW   W   WWWWW W  WWW      W    W",
    "W W      WW                 W    W",
    "W W   WWWW   WWW   W  WWWWWWW    W",
    "W  C          W E  W  W         W",
    "WFFWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",   
    ]


    finals = []
    candies = []
    x = y = 0
    for row in level3:
        for col in row:
            if col == "W":
                Wall((x, y))
            if col == "E":
                end_rectx = x
                end_recty = y
            if col == "F":
                finals.append(pygame.Rect(x, y, 24, 24))
            if col == "C":
                candies.append(pygame.Rect(x, y, 24, 24))
            x += 24
        y += 24
        x = 0
    #reset screen
    gameDisplay.fill(black)
    #Maze Game Logic
    gameExit = False
    has_key = False
    while not gameExit:
        #More logic
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                gameExit = True

        key = pygame.key.get_pressed()
        if key[pygame.K_LEFT]:
            player.move(-2, 0)
        if key[pygame.K_RIGHT]:
            player.move(2, 0)
        if key[pygame.K_UP]:
            player.move(0, -2)
        if key[pygame.K_DOWN]:
            player.move(0, 2)

        

    
        gameDisplay.fill((0, 0, 0))
        for wall in walls:
            pygame.draw.rect(gameDisplay, (255, 255, 255), wall.rect)
        #pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)
        keys = pygame.image.load("key.png").convert_alpha()
        if has_key == False:
            gameDisplay.blit(keys, [end_rectx,end_recty])
        my_player = pygame.image.load("icon.png").convert_alpha()
        gameDisplay.blit(my_player, player.rect)
        #pygame.draw.rect(gameDisplay, (255, 200, 0), player.rect)
        for end_rect in finals:
            pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)
        for candy in candies:
            c = pygame.image.load("sweet3.png").convert_alpha()
            gameDisplay.blit(c, candy)
            if player.rect.colliderect(candy):
                candy_count+=1
                candies.remove(candy)
                
        font1 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text1 = font1.render("Level 3 ", True, white)
        gameDisplay.blit(text1, [10,380])
        font2 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text2 = font2.render("Total Candy " + str(candy_count), True, white)
        gameDisplay.blit(text2, [10,395])
        font3 = pygame.font.SysFont("Yu Gothic", 30, True, False)
        text3 = font3.render("Lives:", True, white)
        gameDisplay.blit(text3, [10,425])
        title5 = pygame.image.load("candyheart.png").convert_alpha()
        for life in range(1,lives+1):
            gameDisplay.blit(title5, [83*life,405])
        
        if player.rect.colliderect(pygame.Rect(end_rectx,end_recty,24,24)):
            font = pygame.font.SysFont("Yu Gothic", 25, True, False)
            text = font.render("You Have the Key!!", True, white)
            gameDisplay.blit(text, [50,500])
            has_key = True
        for end_rect in finals:
            if player.rect.colliderect(end_rect) and has_key == False:
                if player.rect.y> 0: 
                    player.rect.bottom = wall.rect.top
                    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                    text = font.render("You Need To Find The Key!!", True, white)
                    gameDisplay.blit(text, [50,500])
                if player.rect.y < 0: 
                    player.rect.top = wall.rect.bottom
                    font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                    text = font.render("You Need To Find The Key!!", True, white)
                    gameDisplay.blit(text, [50,500])
            
            

            if player.rect.colliderect(end_rect) and has_key == True:
                font = pygame.font.SysFont("Yu Gothic", 25, True, False)
                text = font.render("You Won!!", True, white)
                gameDisplay.blit(text, [50,500])
                if candy_count > 15:
                    bonus_round(candy_count)
                else:
                    game_outro(candy_count)
        total_seconds = start_time - frame_count // frame_rate
        if total_seconds < 0:
            total_seconds = 0
        minutes = total_seconds // 60
        seconds = total_seconds % 60
        output_string = "Time: {0:02}:{1:02}".format(minutes,seconds)
        clocktext = font.render(output_string, True, white)
        gameDisplay.blit(clocktext, [10,460])
        frame_count +=1
        clock.tick(frame_rate)
        if total_seconds == 0:
            lives -= 1
            timer_effect.play()
            gameLoop3(candy_count,lives)
        if lives == 0 :
            game_over()
        

        pygame.display.flip()


def game_outro(candy):
    pygame.mixer.music.stop()
    pygame.mixer.music.load("CANDY2.mp3")
    pygame.mixer.music.play(-1,60)
    outro = True
    candy_count = candy
    while outro:
        gameDisplay.fill(black)
        pygame.font.init()
        title = pygame.image.load("endgame.png").convert()
        title3 = pygame.image.load("lollipop.png").convert_alpha()
        title4 = pygame.image.load("lollipop2.png").convert_alpha()
        gameDisplay.blit(title, [50,25])
        gameDisplay.blit(title3, [650,300])
        gameDisplay.blit(title4, [25,300])
        font4 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text4 = font4.render("You Found " + str(candy_count)+ " candies!!", True, white)
        gameDisplay.blit(text4, [50,500])
        text9 = font4.render("Press Enter To Play Again!", True, white)
        gameDisplay.blit(text9, [50,520])
        pygame.display.update()
        clock.tick(15)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro = False
                pygame.quit()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                walls = []
                level = [   
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "W                  W             W",
                "W         WWWWWW   W   WWWWWW    W",
                "W   WWWWC      W   W   W    W    W",
                "W   W        WWWW  WWWWW    W    W",
                "W WWW  WWWW                   C  W",
                "W   W     W W  C                 W",
                "W   W     W   WWW  WWWWW     WWWWW",
                "W   WWW WWW   W W  W   W         W",
                "W     W   W   W W  W   W  WWWW   W",
                "WWW   W   WWWWW W  WWW      W    W",
                "W W      WW                 W    W",
                "W W   WWWW   WWW   W  WWWWWWW    W",
                "W     W    E   W   W  W  C       W",
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWFFWW",
                ]   

                finals = []
                candies = []

                x = y = 0
                for row in level:
                    for col in row:
                        if col == "W":
                            Wall((x, y))
                        if col == "E":
                            end_rectx = x
                            end_recty = y
                        if col == "F":
                            finals.append(pygame.Rect(x, y, 24, 24))
                        if col == "C":
                            Sweet((x, y))
                        x += 24
                    y += 24
                    x = 0

                gameLoop(3)
                intro = False
    
                
    #Exit Game
    pygame.quit()
    quit()

class candify(object):
    def __init__(self, pos):
        candies.append(self)
        self.posx = pos[0]
        self.posy = pos[1]
        self.rect = pygame.Rect(pos[0], pos[1], 24, 24)
def bonus_round(mycandy):
    candy_count = mycandy
    walls.clear()
    clock = pygame.time.Clock()
    font = pygame.font.Font(None,25)
    frame_count = 0 
    frame_rate = 60
    start_time = 15
    candy_count = 0
    player = Player()
    levelB = [   
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
    "W   CCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCW",
    "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",   
    ]

    finals = []
    candies = []
    x = y = 0
    for row in levelB:
        for col in row:
            if col == "W":
                Wall((x, y))
            if col == "E":
                end_rectx = x
                end_recty = y
            if col == "F":
                finals.append(pygame.Rect(x, y, 24, 24))
            if col == "C":
                candies.append(pygame.Rect(x,y,24,24))
            x += 24
        y += 24
        x = 0
    #reset screen
    gameDisplay.fill(black)
    #Maze Game Logic
    gameExit = False
    while not gameExit:
        #More logic
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True
                pygame.quit()
                quit()

        key = pygame.key.get_pressed()
        if key[pygame.K_LEFT]:
            player.move(-4, 0)
        if key[pygame.K_RIGHT]:
            player.move(4, 0)
        if key[pygame.K_UP]:
            player.move(0, -4)
        if key[pygame.K_DOWN]:
            player.move(0, 4)

        

    
        gameDisplay.fill((0, 0, 0))
        for wall in walls:
            pygame.draw.rect(gameDisplay, (255, 255, 255), wall.rect)
        #pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)
        for candy in candies:
            c = pygame.image.load("gold.png").convert_alpha()
            gameDisplay.blit(c, candy)
            if player.rect.colliderect(candy):
                candy_count+=1
                candies.remove(candy)
            
        my_player = pygame.image.load("icon.png").convert_alpha()
        gameDisplay.blit(my_player, player.rect)
        #pygame.draw.rect(gameDisplay, (255, 200, 0), player.rect)
        for end_rect in finals:
            pygame.draw.rect(gameDisplay, (255, 0, 0), end_rect)

        font1 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text1 = font1.render("BONUS ROUND!!!! GO CANDY CRAZYYYY ", True, white)
        gameDisplay.blit(text1, [10,380])
        font2 = pygame.font.SysFont("Yu Gothic", 25, True, False)
        text2 = font2.render("Total Candy " + str(candy_count), True, white)
        gameDisplay.blit(text2, [10,395])
        
        total_seconds = start_time - frame_count // frame_rate
        if total_seconds < 0:
            total_seconds = 0
        minutes = total_seconds // 60
        seconds = total_seconds % 60
        output_string = "Time: {0:02}:{1:02}".format(minutes,seconds)
        clocktext = font.render(output_string, True, white)
        gameDisplay.blit(clocktext, [10,460])
        frame_count +=1
        clock.tick(frame_rate)
        if total_seconds == 0:
            game_outro(candy_count)
            
        pygame.display.flip()
    
game_intro()
