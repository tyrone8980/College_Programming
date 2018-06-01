import string
import pygame

print("Part One")
number = 10
for i in range(11):
  for  j in range(1, i):
    print (number, end=" ")
    number+=1
  print( )
  
print( )
print( )
print("Part Two")
square = int(input("How many rows do you want?  "))

for row in range(square):
  if(row==0 or row == square- 1):
    print("o" * (square*2), end=" ")
    print( )
  else:
    print("o", " " * ((square*2) - 4),  "o")

      

print("Part Three")

n = int(input("Enter any positive integer  "))
numberList = [i*2-1 for i in range(1, n+1)]
reverse_range = range(0,n)
for n_row in range(0, n):    
    # left number
    for number in numberList[:(n-n_row)]:
        print(number, end=" ") 
    # space
    for number in range(n_row):
        print( ' ', ' ', end=" ")
    # right number
    for number in reversed(numberList[:(n-n_row)]):
        print( number, end=" ")
    print ( )
for n_row in reversed(range(0, n)):    
    # left number
    for number in numberList[:(n-n_row)]:
        print(number, end=" ") 
    # space
    for number in range(n_row):
        print( ' ', ' ', end=" ")
    # right number
    for number in reversed(numberList[:(n-n_row)]):
        print( number, end=" ")
    print ( )
    
print( )
print( )

print("Part Four")

pygame.init()

BLACK = (0,0,0)
WHITE = (255,255,255)
BLUE = (0,0,255)
GREEN = (0,255,0)
RED = (255,0,0)

size = (500,500)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("My Grid")
clock = pygame.time.Clock()
done = False

while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
    screen.fill(BLACK)
  
    
    
    x_location = 0
    y_location = 0
    for row in range(0,250):
        for colm in range(0,250):
            pygame.draw.rect(screen, GREEN, [x_location,y_location,2,2],0)
            x_location += 5
        y_location +=5
        x_location = 0
            
    pygame.display.flip()

    clock.tick(60)
    
pygame.quit()

