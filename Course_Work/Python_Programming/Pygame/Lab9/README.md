# Lab 9 Functions

Write this as all one program. The entire thing should be able to run straight through.

There are several parts to this program. Here is a description of each part:
#### Part 1

```
(5 pts) Write a function called min3 that will take three numbers as parameters and return the smallest value.
If more than one number tied for smallest, still return that smallest number. Use a proper if/elif/else chain. 
Once you've finished writing your function, copy/paste the following code and make sure that it runs against the function you created:
print(min3(4, 7, 5))
print(min3(4, 5, 5))
print(min3(4, 4, 4))
print(min3(-2, -6, -100))
print(min3("Z", "B", "A"))
You should get this result:

4
4
4
-100
A
The function should return the value, not print the value. 
Also, while there is a min function built into Python, don't use it. 
Please use if statements and practice creating it yourself. 
Leave the testing statements in the program so the instructor can check the program. 
If you also get None to print out, then chances are you are using print instead of return in your function.
```
#### Part 2

```
(5 pts) Write a function called box that will output boxes given a height and width. 
Once you've finished writing your function, copy and paste the following code after it and make sure it works with the function you wrote:
box(7,5)  # Print a box 7 high, 5 across
print()   # Blank line
box(3,2)  # Print a box 3 high, 2 across
print()   # Blank line
box(3,10) # Print a box 3 high, 10 across
You should get the following results from the sample code:

*****
*****
*****
*****
*****
*****
*****
 
**
**
**
 
**********
**********
**********
```

#### Part 3

```
(5 pts) Write a function called find that will take a list of numbers, my_list, along with one other number, key.
Have it search the list for the value contained in key. 
Each time your function finds the key value, print the array position of the key. 
You will need to juggle three variables, one for the list, one for the key, and one for the position of where you are in the list.
This code will look similar to the Chapter 7 code for iterating though a list using the range and len functions. 
Start with that code and modify the print to show each element and its position. 
Then instead of just printing each number, add an if statement to only print the ones we care about.

Copy/paste this code to test it:

my_list = [36, 31, 79, 96, 36, 91, 77, 33, 19, 3, 34, 12, 70, 12, 54, 98, 86, 11, 17, 17]
 
find(my_list, 12)
find(my_list, 91)
find(my_list, 80)
...check for this output:

Found 12 at position 11
Found 12 at position 13
Found 91 at position 5
Use a for loop with an index variable and a range. 
Inside the loop use an if statement. 
The function can be written in about four lines of code.
```

#### Part 4

```
Write one program that has the following:
(15 pts, 5 for each function) Functions:
Write a function named create_list that takes in a list size and returns a list of random numbers from 1-6. i.e.,
calling create_list(5) should return 5 random numbers from 1-6. 
(Remember, Chapter 7 has code showing how to do something similar, creating a list out of five numbers the user enters. Here, you need to create random numbers rather than ask the user.) 

To test, use this code against the function you wrote:
my_list = create_list(5)
print(my_list)
And you should get output of five random elements that looks something like:
[2,5,1,6,3]
Write a function called count_list that takes in a list and a number. Have the function return the number of times the specified number appears in the list. 
To test, use this code against the function you wrote:
count = count_list([1,2,3,3,3,4,2,1],3)
print(count)
And you should get output something like:
3
Write a function called average_list that returns the average of the list passed into it. 
To test, use this code against the function you wrote:
avg = average_list([1,2,3])
print(avg)
And you should get output something like:
2
```
#### Part 5 

```
(10 pts) Now that the functions have been created, use them all in a main program that will:
Create a list of 10,000 random numbers from 1 to 6. This should take one line of code. Use the function you created earlier in the lab.)
Print the count of 1 through 6. (That is, print the number of times 1 appears in the 10,000. And then do the same for 2-6.)
Print the average of all 10,000 random numbers.
```
