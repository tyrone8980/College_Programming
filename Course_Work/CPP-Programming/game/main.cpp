/*
 * main.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: tyrone8980
 */

#include <ncurses.h>
#include <iostream>
#include "game.h"
int main(void) {
    initscr();
    raw();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));

    mvprintw(0,20,"                                  /   \\       \n");
    mvprintw(1,20," _                        )      ((   ))     (  \n");
    mvprintw(2,20,"(@)                      /|\\      ))_((     /|\\                \n");
    mvprintw(3,20,"|-|                     / | \\    (/\\|/\\)   / | \\                      (@)\n");
    mvprintw(4,20,"| | -------------------/--|-voV---\\`|'/--Vov-|--\\---------------------|-|\n");
    mvprintw(5,20,"|-|                         '^`   (o o)  '^`                          | |\n");
    mvprintw(6,20,"| |                               `\\Y/'                               |-|\n");
    mvprintw(7,20,"|-|                  Welcome to King Harmon's C++ Adventure           | |\n");
    mvprintw(8,20,"| |                    join me as we explore the world of             |-|\n");
    mvprintw(9,20,"|-|                                 C++                               | |\n");
    mvprintw(10,20,"| |                                 C++                               |-|\n");
    mvprintw(11,20,"|_|_________________________________C++_______________________________| |\n");
    mvprintw(12,20,"(@)              l   /\\ /         ( (       \\ /\\   l                `\\|-|\n");
    mvprintw(13,20,"                 l /   V           \\ \\       V   \\ l                  (@)\n");
    mvprintw(14,20,"                 l/                _) )_          \\I\n");
    mvprintw(15,20,"                                    `\\ /'\n");
    mvprintw(16,25,"This is all for you Oren Segal!!\n");
    attron(COLOR_PAIR(2));
    mvprintw(19,20,"Please enjoy!!!\n");
    mvprintw(20,20,"Made by Tyrone K Harmon Jr.");
    attroff(A_BOLD);

    refresh();
    char x;
    x = getch();
    if(x)
    {
    	clear();
    	mvprintw(10,10,"ARE YOU READY TO BEGIN YOUNG ADVENTURER??\n");
    	mvprintw(11,10,"PRESS ANY BUTTTON\n");
    	refresh();
    	if(x)
    	{
    		clear();
    		attron(COLOR_PAIR(1));
    		printw("Okay let me explain the rules a little bit\n");
    		printw("In this world, c++ is love, c++ is life!!\n");
    		printw("Your fate relies purely on your answers to c++ syntax questions\n");
    		printw("Surviving this world means you are a strong enough warrior to take on \n");
    		printw("..........");
    		attroff(COLOR_PAIR(1));
    		attron(COLOR_PAIR(3));
    		attron(A_BOLD);
    		printw("Hofstra's C++ Class!!!");
    		attroff(COLOR_PAIR(1));
    		attroff(A_BOLD);
    		printw("If you are ready to begin this journey, type any button");
    		if(x)
    		{
    			story();
    			getch();
    		}
    	}
    }
    endwin();
}

