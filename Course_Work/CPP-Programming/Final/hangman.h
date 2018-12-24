/*
 * hangman.h
 *
 *  Created on: Dec 7, 2016
 *      Author: tyrone8980
 */

#ifndef HANGMAN_H_
#define HANGMAN_H_
using namespace std;
#include <string>

bool match(char letter, string word);
char askGuess(string usedLettersStr); //tells the compiler of method askGuess
bool playAgain();
void player_one_game();
void player_two_game();


#endif /* HANGMAN_H_ */

