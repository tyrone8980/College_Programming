
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <fstream>
#include "hangman.h"
using namespace std;

void player_two_game()
{
	string THE_WORD;            //the words to be guessed
	int wrong;
	string soFar;
	string used;
	string difficulty;
	srand(time(0));
	vector<string> words;  // collection of possible words to guess
	ifstream myfile("/home/tyrone8980/Words.txt");


	while (getline(myfile, THE_WORD))
	{
		words.push_back(THE_WORD);
	}

					do
					{
						const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed
						wrong = 0;
						cout<< "Player 2, please type in a word for Player 1 to guess! "<<endl
								<<"butt make sure they aren't cheating or looking!"<<endl
								<<"go ahead silly type in your word! "<<endl;
						cin>> THE_WORD;            // player 2's word to guess
						//the next string is to make everything capitalized
						//like our other words
						std::transform(THE_WORD.begin(), THE_WORD.end(),THE_WORD.begin(), ::toupper);
						soFar = string(THE_WORD.size(), '-');          // word guessed so far
						used = "";                            // letters already guessed

														  // loop for current word

						while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
						{	cout << "Are you ready player 1? "<<endl;
							cout << "Player 2 has typed in a hard one for you!" <<endl;
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





