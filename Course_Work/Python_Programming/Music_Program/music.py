import winsound #this is where I will get my beeps
import time  #this is how I will define pauses/rests
# I imported the winsound library in order to send beeps to the user's computer
# the winsound beep function takes in the following 
# winsound.beep(frequency( in hertz), duration(millieseconds)
# 60,000 ms(1 minutes) / Tempo (BPM) = Delay Time in ms for quarter note beats
# 60,000 / 120 BPM = 500 ms
#Whole note = 2000ms
#Half note = 1000ms
#Quarter note = 500ms
# Eigth note = 250ms
# I will use time.sleep(seconds) to make rests in the songs
#a Quarter note in seconds equals 60/BPMS
#therefore,
#  (60/120)*4 = Whole rest = 2 seconds
#  (60/120)*2 = Half rest = 1 second
#  (60/ 120) = Quarter rest = 0.5 seconds
#  (60/120)* 0.5 = Eigth rest = 0.25 seconds
wrest = 2 # Now I will make the rest global so I can use them anytime I want
hrest = 1 
qrest = 0.50
erest = 0.25
def user_rest(time): #this way I can easily call a rest if needed in an algorithm
	time.sleep(time)
def program_one():
	#We are going to play a major scale
	#Starting from A =440z and ending at A = 880z
	# A major scale is A,B,C#,D,E,F#,G#,A
	print(" I will now play the A Major scale for you!")
	print("A") # I will print every number so I can see and hear the scale
	winsound.Beep(440,500) #A
	print("B")
	winsound.Beep(494,500)#B
	print("C#")
	winsound.Beep(554,500)# C sharp
	print("D")
	winsound.Beep(587,500)# D
	print("E")
	winsound.Beep(659,500)# E
	print("F#")
	winsound.Beep(740,500)# F sharp
	print("G#")
	winsound.Beep(831,500)# G sharp
	print("A Octave")
	winsound.Beep(880,500)# A octave
	print("Thank you for your time")
notes = [] #this way I can have an array of all of the users note
durations = [] #the durations of each note
times_to_play = [] #how many times to play each note
# this next function will accept the users desired notes
# and use them as input for out winsound.beep(f,d,t) function
def ask_user_for_note():
	x = True
	while(x):
			note = int(input("What is your starting frequency in hertz? ")) #recieve user input
			notes.append(note) #add input to array of note
			print(" Whole note = w")
			print(" Half note = h") #show user the value of all the notes
			print(" Quarter note = q")
			print(" Eigth note = e")
			duration = input("What is the duration of your note?<w/h/q/e> ")
			if( duration =="w"):
				duration = 2000 # change the notes from characters to actual integer values
				durations.append(duration)# add that duration to the array of durations
			elif( duration =="h"):        # so I know how long to play each note
				duration = 1000 
				durations.append(duration)
			elif( duration == "q"):
				duration = 500
				durations.append(duration)
			else:
					duration = 250
					durations.append(duration)
			times_played = int(input("How many times would you like me to play that note? "))
			times_to_play.append(times_played)
			answer = input("Would you like to enter another note? <y/n> ")
			if(answer == "y"): 
				increment_user_note(note) #to increase the previous hertz or decrease it 
			else:
				for i, j, k in zip(notes,durations,times_to_play):
					play_note(i,j,k) # will play what the user has entered so far 
				x = False #this way we can end the loop
def increment_user_note(note):
	x = True
	while(x == True):
			
			increment=float(input("How many hertz would you like me to increment your note? "))
			next_note= note + increment #this increments or decrements the next note
			notes.append(next_note)
			print(" Whole note = w")
			print(" Half note = h")
			print(" Quarter note = q")
			print(" Eigth note = e")
			duration = input("What is the duration of your note?<w/h/q/e> ")
			if( duration =="w"): #converts duration from character to usuable integer
				duration = 2000 
				durations.append(duration)# add those durations to array of durations
			elif( duration =="h"):
				duration = 1000 
				durations.append(duration)
			elif( duration == "q"):
				duration = 500
				durations.append(duration)
			else:
				duration = 250
				durations.append(duration)
			times_played = int(input("How many times would you like me to play that note? "))
			times_to_play.append(times_played)
			answer = input("Would you like to play another note? <y/n>")
			if(answer== "y"):
				x = True
			else:
				for i, j, k in zip(notes,durations,times_to_play):
					play_note(i,j,k)
				x = False # once again to end loop
def play_note(frequency,duration,times_play):
	f = int(frequency) 
	d = int(duration)
	t = int(times_play)
	i = 0 # I made i = 0 so I can iterate the while loop for times the note needs to be played
	while(i<t): 
		winsound.Beep(f,d)
		#increment i so the loop will eventually stop when i = times the note needs to be
		#played
		i+=1
	
def program_two():
	#I make x = true so that I can start the loop inside of ask_user_for_note
	ask_user_for_note()
	# the following takes for all i in notes, and for all j in duration and for all 
	# K in times_to_play, each note has its according duration and how many
	#times it needs to be played, for each iteration of function play_note()
	for i, j, k in zip(notes,durations,times_to_play):
		play_note(i,j,k)

		
def program_three():
	print("For this program, I will play a song for you")
	#My song is 
	notes= [370,392,466,440,392,349,294,392,523]
	durations = [250,250,250,250,250,250,250,250,250]
	times_to_play = [1,1,1,1,1,1,1,1,1]
	for i, j, k in zip(notes,durations,times_to_play):
		play_note(i,j,k)
	#for my own little rests I will call on the rest variables I created at the beginning
	# of the program
	time.sleep(qrest)
	time.sleep(erest)
	notes= [466,440,466,699,587,466,392,440,294,392,277]
	durations = [500,250,250,250,250,250,250,250,250,250,2000]

	times_to_play = [1,1,1,1,1,1,1,1,1,1,1]
	for i, j, k in zip(notes,durations,times_to_play):
		play_note(i,j,k)
	final_answer= input(" Did you like my song? <y/n> ")
	if(final_answer == "y"):
		print("Thank you very much!!")
	else:
		print("Well, thanks for listening I guess")
	
	
def main():
	#to make it more user friendly
	#and to add all three programs together into one main program.
	print(" Play A major scale? <a>")
	print(" Play your own song? <o>")
	print(" Or would you like to hear my song? <m>")
	last_answer = input("What operation would you like to execute? <a/o/m> ")
	if(last_answer == "a"):
		program_one() #will play A major scale
	elif(last_answer == "o"):
		program_two() # will allow user to play their own song with
		#their starting variable
		# Number of hertz to increase frequency in each iteration
		# number of times to iterate the nore
		
	else:
		program_three() 
		
main()# Now I call main function so it can run the whole program

