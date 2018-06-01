import random

def min3(param1, param2, param3):
    if(param2 < param1 and param2 < param3):
        return param2
    elif(param3 < param2 and param3 < param1):
        return param3
    else:
        return param1


print(min3(4, 7, 5))
print(min3(4, 5, 5))
print(min3(4, 4, 4))
print(min3(-2, -6, -100))
print(min3("Z", "B", "A"))
print( ) 

def box(param1, param2):
    for x in range(param1):
        print("*" * param2)



box(7,5)  # Print a box 7 high, 5 across
print()   # Blank line
box(3,2)  # Print a box 3 high, 2 across
print()   # Blank line
box(3,10) # Print a box 3 high, 10 across
print( )

def find(my_list,key):
    in_array = False
    for i in my_list:
        if(key == i):
            in_array = True
            print(key, "is in the array at position ", i)
    if(in_array == False):
        print("Sorry your number is not in the array")


my_list = [36, 31, 79, 96, 36, 91, 77, 33, 19, 3, 34, 12, 70, 12, 54, 98, 86, 11, 17, 17]
 
find(my_list, 12)
find(my_list, 91)
find(my_list, 80)
print( ) 
def create_list(list_size):
    my_array = []
    for i in range(list_size):
        my_array.append(random.randint(1,6))
    return my_array

my_list = create_list(5)
print(my_list)

print( )

def count_list( list1, number ):
    count = 0
    for i in list1:
        if( i == number):
            count +=1

    return count

count = count_list([1,2,3,3,3,4,2,1],3)
print(count)
print( )

def average_list(list2):
    sumation = 0
    for i in list2:
        sumation += i

    return (sumation/(len(list2)))
            
avg = average_list([1,2,3])
print(avg)
print( )

print("Now solving the final problem " )
print( )
print(" Creating a list of 10,000 random numbers from 1 to 6 ")
final_list = create_list(10000)
print(" Printing the Count of 1 through 6" )
for i in range(1,6):
    print(i, "appears ",count_list(final_list, i ), " times")

print( ) 
print(" Now printing average of the whole list " )

print( average_list(final_list))
       

    
    
