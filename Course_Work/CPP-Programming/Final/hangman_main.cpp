/*
 * Main.cpp
 *  CSC 16
 *  Professor Oren, Segal
 *  FINAL PROJECT: Hangman
 *  Finalized on: Dec 1, 2016
 *      Authors: Richie Lawless
 *      Dianna Albanese
 *      Tyrone Harmon Jr.
 */
/// Our game of Hangman
// Created for the purpose of pleasing the great Segal

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <fstream>
#include "hangman.h"
using namespace std;

int main()
{
	int players;
	cout << "Welcome Master! Prepare to begin our game of Hangman.  Good luck!\n";
	cout << "How many players? <1/2> ";
	cin >> players;
	if(players== 2)
	{
		player_two_game();
	}

	if(players== 1)
	{
		player_one_game();
	}
}

