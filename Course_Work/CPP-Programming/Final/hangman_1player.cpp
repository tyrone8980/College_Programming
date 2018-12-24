/*
 * 1player.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: tyrone8980
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <fstream>

#include "hangman.h"
using namespace std;




void player_one_game(){
			string THE_WORD;            //the words to be guessed
			int wrong;
			string soFar;
			string used;
			string difficulty;
			srand(time(0));
			vector<string> words;  // collection of possible words to guess
			ifstream myfile("/home/tyrone8980/Words.txt");
			if (! myfile.is_open())
			{
				cout<<"file is not open"<<endl;
			}

			while (getline(myfile, THE_WORD))
			{
				words.push_back(THE_WORD);
			}

			cout <<"Easy = 12 guesses"<<endl;
			cout<<" Medium = 8 guesses"<<endl;
			cout<<"Hard = 5 guesses"<<endl;
			cout << "Would you like to on play easy, medium or hard? ";
			cin >> difficulty;
			std::transform(difficulty.begin(), difficulty.end(),difficulty.begin(), ::toupper);

			if(difficulty=="HARD"){
				do
				{
					const int MAX_WRONG = 5;  // maximum number of incorrect guesses allowed
					wrong =0;
					random_shuffle(words.begin(), words.end());
					THE_WORD = words[0];            // word to guess

					soFar = string(THE_WORD.size(), '-');          // word guessed so far
					used = "";                            // letters already guessed

													  // loop for current word

					while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
					{
						cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
						cout << "\nYou've used the following letters:\n" << used << endl;
						cout << "\nSo far, the word is:\n" << soFar << endl;

						used += askGuess(used);



					} // end of while ((wrong < MAX_WRONG) && (soFar != THE_WORD))

					  // shut down
					if (wrong == MAX_WRONG)
					{
						cout << "\nOh No!!you've been hanged!";
					}

					cout << "\nThe word was " << THE_WORD << " you almost had it please try again!"<<endl;

				} while (playAgain());


			}


			if(difficulty=="EASY"){
			do
			{
				const int MAX_WRONG = 12;  // maximum number of incorrect guesses allowed
				wrong =0;
				random_shuffle(words.begin(), words.end());
				THE_WORD = words[0];            // word to guess

				soFar = string(THE_WORD.size(), '-');          // word guessed so far
				used = "";                            // letters already guessed

												  // loop for current word

				while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
				{
					cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
					cout << "\nYou've used the following letters:\n" << used << endl;
					cout << "\nSo far, the word is:\n" << soFar << endl;

					used += askGuess(used);



				} // end of while ((wrong < MAX_WRONG) && (soFar != THE_WORD))

				  // shut down
				if (wrong == MAX_WRONG)
				{
					cout << "\nOh No!!you've been hanged!";
				}

				cout << "\nThe word was " << THE_WORD << " you almost had it please try again!"<<endl;

			} while (playAgain());


		}

			if(difficulty=="MEDIUM"){

			do
			{
				const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed
				wrong =0;
				random_shuffle(words.begin(), words.end());
				THE_WORD = words[0];            // word to guess

				soFar = string(THE_WORD.size(), '-');          // word guessed so far
				used = "";                            // letters already guessed

												  // loop for current word

				while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
				{
					cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
					cout << "\nYou've used the following letters:\n" << used << endl;
					cout << "\nSo far, the word is:\n" << soFar << endl;

					used += askGuess(used);



				} // end of while ((wrong < MAX_WRONG) && (soFar != THE_WORD))

				  // shut down
				if (wrong == MAX_WRONG)
				{
					cout << "\nOh No!!you've been hanged!";
				}

				cout << "\nThe word was " << THE_WORD << " you almost had it please try again!"<<endl;

			} while (playAgain());


		}

}




inline bool match(char letter, string word)
{
	return (word.find(letter) != string::npos);
}

char askGuess(string usedLettersStr)
{
	string THE_WORD;            //the words to be guessed
	int wrong=0;
	string soFar;
	string used;
	char guess;
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess); //make uppercase since secret word in uppercase
							//        while (used.find(guess) != string::npos)
	while (match(guess, used))
	{
		cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}


	//        if (THE_WORD.find(guess) != string::npos)
	if (match(guess, THE_WORD))
	{
		cout << "That's right! " << guess << " is in the word.\n";

		// update soFar to include newly guessed letter
		for (int i = 0; i < THE_WORD.length(); ++i)
			if (THE_WORD[i] == guess)
				soFar[i] = guess;
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		++wrong;
	}
	return guess;
}

bool playAgain() // function to play again while clearing system
{
	char again;
	cout << "\n\nWould you like to play again? <y/n>: ";
	cin >> again;

	cin.clear(); //clear and ignore cin
	cin.ignore();//because we don't even like the user!!! jk

	again = toupper(again);

	cout << string(50, '\n'); //idk how to clear screen so I will use this ghetto trick

	return (again == 'Y');
}



