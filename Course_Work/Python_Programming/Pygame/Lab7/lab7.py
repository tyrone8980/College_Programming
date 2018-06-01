def main():
	print(" Welcome adventurer")
	character_name = input("What is your name")
	character_attack = 0
	print(" Please choose a weapon")
	print(" sword     knife     magic_wand")
	character_weapon = input("What do you desire?")
	if(character_weapon == "sword"):
		character_attack+= 50
	elif( character_weapon == "knife"):
		character_attack+= 25
	else:
		character_attack+= 20
	print(" You have chosen the " + character_weapon)
	print(" Alright brave adventurer " + character_name + " are you ready to begin your journey?")
	class Monster:
		def __init__(self, name, health, attack):
			self.name = name
			self.health = health
			self.attack = attack
		def declare_monster(self):
			print("Warning Warning Warning ")
			print(" A new Monster has appeared, prepare for battle_sequence ")
			print(self.name + " Has appeared!!")
		def battle_sequence(self):
			character_health = 500
			while(self.health != 0 and character_health!= 0):
				print(self.name)
				print(self.health)
				print(character_name)
				print(character_health)
				print("What would you like to do? ")
				answer = input("attack  potion  ")
				if(answer == "attack"):
					self.health -= character_attack
				elif(answer == "potion"):
					character_health += 50
				else:
					print(" Attempt Failed")
					print(" Entering Monster phase: ")
				print(" Monster Phase Begin ")
				character_health -= self.attack
			if(self.health <=0):
				print(" You Have defeated the monster!!")
				if(self.name == "Dragon"):
					print("CONGRATULATIONS YOU HAVE BEAT THE GAME ADVENTURER!!!! ")
			elif(character_health <= 0 ):
				print(" You have lost...game over...")


	rat = Monster("Rat",50,2)
	rat.declare_monster()
	rat.battle_sequence()
	ork = Monster("ork",100,20)
	ork.declare_monster()
	ork.battle_sequence()
	Knight = Monster("Dark Knight",200,25)
	Knight.declare_monster()
	Knight.battle_sequence()
	print("You have reached the final boss!!! Prepare for a serious battle!! ")
	Dragon = Monster("Dragon",300,50)
	Dragon.declare_monster()
	Dragon.battle_sequence()


main()
