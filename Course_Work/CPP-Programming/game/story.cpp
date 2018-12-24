/*
 * story.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: tyrone8980
 */
#include <ncurses.h>
#include <iostream>
#include "game.h"
#include <string>
#include <queue>
//ALL ascii art created by darren rion hall and Christopher Johnson!!! on their free website
//listed below... I did not!! create this art
//link is http://chris.com/ascii/index.php?art=creatures/dragons
using namespace std;


void story(){
	attron(COLOR_PAIR(1));
	clear();
	printw("HELP \n");
	printw("HELP \n");
	printw("HELP \n");
	refresh();
	getch();
    kitten();
	printw(" aahhhh Puurrrrrrrrrrrrrrrfect nyan\n");
	printw("Hello advenurer nyan!!\n");
	new_screen();
	printw ("Hmmmm....\n");
	printw("You look strong nyan!! I need your help nyan!!\n");
	printw("I know it may be hard to believe but I am a princess of the fairy kingdom nyan\n");
	printw("My NAME IS PUURRRRRTRICIAA!!!\n");
	printw("\n");
	kitten();
	printw("I have been turned into a cutie patootie kitten by an evil C++ Dragon\n");
	refresh();
	getch();
	printw("His name is......");
	new_screen();
	for(int i=10;i<21;i++)
	{
	  attron(COLOR_PAIR(3));
	  attron(A_BOLD);
	  mvprintw(i,10,"OREN SEGAL\n");
	  printw("\n");
	}
	new_screen();
	attroff(COLOR_PAIR(3));
	attroff(A_BOLD);
	kitten();
	attron(COLOR_PAIR(1));
	printw("Scary right? His exams have caused fear and poverty to all the Hofstra kids all throughout my kingdom nyann\n");
	printw("While I was Programming a magic code in python he turned me into a kitten and took away my magic powers nyan nyan \n ");
	printw("NOW I NEED YOUR HELP TO STOP HIM NYANNNNN!!!!\n");
	new_screen();
	printw("Do you want to help me NYANNNN????? <y/n> \n");
	kitten();
	refresh();
	string ans;
	ans = getstring();
	printw("\n");
	if( ans == "y"){
		sequence_two();
	}
	else
	{
		game_over();
	}

}
void sequence_two()
{
	clear();
	kitten();
	attron(COLOR_PAIR(1));
	printw("WOAHH nyann\n");
	printw("PURRRRRRRRRRRRFECT NYANNNN NYANNN NYANNN\n");
	printw("Thank you kind adventurer nyan nyan\n");
	printw("We will go fight him together!!! NYANN!!!\n");
	printw("WE will KICK HIS BUTTTTT\n");
	new_screen();
	printw("BUT BE WARNED ADVENTURER NYAN!!!!\n");
	printw("THE ONLYYY WAY TO BEAT HIM.....nyan....\n");
	printw("IS TO FIGHT FIRE WITH FIRE NYANNNNNNN!!!\n");
	kitten();
	printw("MORE SPECIFICALLY!! TO BEAT HIM!! WE MUST DEFEAT HIM IN A BATTLE OF BRAIN!! nyann \n");
	printw("and prove that our knowledge of coding is greater!!! than he shall fall and I will get my magic back!! nyann \n");
	printw("THEN EVERYON CAN REJOICE NYAN, and PeAcE WILL BE RESTORED TO THE HOFSTRA KINGDOM NYANNN \n");
	new_screen();
	printw("......");
	new_screen();
	printw("ARE YOU READY TO HEAD TO HIS DUNGEON(office) ADVENTURE?? <y/n>\n");
	printw("\n");
	kitten();
	refresh();
	string input = getstring();
	printw("\n");
	if(input == "y")
	{
		final_battle();
	}
	else
	{
		game_over();
	}

}
void final_battle()
{
	castle();
	printw("Okay we have arrived at his evil castle/ dungeon thingy nyannn\n");
	printw("Let's do this thinnggg!!!! NYANNNNN!!!\n");
	new_screen();
	printw("Take a look at yourself hero!! You look so strong nyan\n");
	printw("MANLY NYAN\n");
	printw("MATURE NYAN\n");
	new_screen();
	hero();
	refresh();
	getch();
	kitten();
	attron(COLOR_PAIR(1));
	printw("HAHAAA JUST KIDDING NYAN! WHAT WAS I THINKING WE ARE GOING TO DIE NYANN!!!\n");
	new_screen();
	printw("Uh-oh nyann...");
	printw("Did you hear that??? nyan");
	printw("Here he comes nyan!!!!!!\n");
	new_screen();
	 attron(COLOR_PAIR(2));
	 attron(A_BOLD);
	 printw(" !!!!!!!!!!!!!!!!!!!!THERE IT IS!!!!!!!!!!!!!!!!!!!!!!!!\n");
	 attroff(A_BOLD);
	 kitten();
	 printw("Do you see this scary looking monster?????????????\n");
	 printw(" THIS MONSTER IS C++\n");
	 attroff(COLOR_PAIR(2));
	 attron(COLOR_PAIR(3));
	 dragon();
	 printw("THIS WILL HAUNT YOUR NIGHTMARE AS A HOFSTRA C++ STUDENT");
	 new_screen();
	 dragon();
	 attron(COLOR_PAIR(3));
	 printw("MY NAME IS OREN SEGAL AND I SHALL DESTROY YOU WITH MY AMAZING C++ SKILLS");
	 printw("NOW FOES TAKE MY RATHHHHHHH!!!!!!!!!");
	 new_screen();
	 printw("\n");
	question_sequence();
	//if you win come out the loop and execute winning function
}
// I found the below function for using ncurses to get user input on
// http://stackoverflow.com/questions/26920261/read-a-string-with-ncurses-in-c
// created by user DevSOlar
string getstring()
{
	string input;
	nocbreak();
	echo();
	int ch = getch();
	while ( ch != '\n')
	{
		input.push_back(ch);
		ch = getch();
	}
	return input;
}
void new_screen()
{
	    refresh();
		getch();
		clear();
}
void game_over()
{
	initscr();
	start_color();


		clear();
	  printw("\n");
	  attron(COLOR_PAIR(3));
	  attron(A_BOLD);
	  printw("!!!!!!!!!!!!!!!!!!!!!!!!GAME OVER!!!!!!!!!!!!!!!!!!!!!!!");
	  printw("YOU                   HAVE                        DIED!!!!");
	  attroff(COLOR_PAIR(3));
	  attroff(A_BOLD);
	  printw("\n");
	  printw("\n");
      printw("                        ud$$$**$$$$$$$bc.\n");
      printw("                     u@**\"        4$$$$$$$Nu\n");
      printw("                   J                \"\"#$$$$$$r\n");
      printw("                  @                       $$$$b\n");
      printw("                .F                        ^*3$$$\n");
      printw("               :% 4                         J$$$N\n");
      printw("               $  :F                       :$$$$$\n");
      printw("              4F  9                       J$$$$$$$\n");
      printw("              4$   k             4$$$$bed$$$$$$$$$\n");
      printw("              $$r  'F            $$$$$$$$$$$$$$$$$r\n");
      printw("              $$$   b.           $$$$$$$$$$$$$$$$$N\n");
      printw("              $$$$$k 3eeed$$b    $$$Euec.\"$$$$$$$$$\n");
      printw(".@$**N.        $$$$$\" $$$$$$F'L $$$$$$$$$$$  $$$$$$$\n");
      printw(":$$L  'L       $$$$$ 4$$$$$$  * $$$$$$$$$$F  $$$$$$F         edNc\n");
      printw("@$$$$N  ^k      $$$$$  3$$$$*%   $F4$$$$$$$   $$$$$\"        d\"  z$N\n");
      printw(" $$$$$$   ^k     '$$$\"   #$$$F   .$  $$$$$c.u@$$$          J\"  @$$$$r\n");
     printw("    $$$$$$$b   *u    ^$L            $$  $$$$$$$$$$$$u@       $$  d$$$$$$\n");
     printw("   ^$$$$$$.    \"NL   \"N. z@*     $$$  $$$$$$$$$$$$$P      $P  d$$$$$$$\n");
     printw("    ^\"*$$$$b   '*L   9$E      4$$$  d$$$$$$$$$$$\"     d*   J$$$$$r\n");
     printw("        ^$$$$u  '$.  $$$L     \"#\" d$$$$$$\".@$$    .@$\"  z$$$$*\"\n");
     printw("          ^$$$$. ^$N.3$$$       4u$$$$$$$ 4$$$  u$*\" z$$$\"\n");
     printw("            '*$$$$$$$$ *$b      J$$$$$$$b u$$P $\"  d$$P\n");
     printw("               #$$$$$$ 4$ 3*$\"$*$ $\"$'c@@$$$$ .u@$$$P\n");
     printw("                \"$$$$  \"\"F~$ $uNr$$$^&J$$$$F $$$$#\n");
     printw("                 \"$$    \"$$$bd$.$W$$$$$$$$F $$\"\n");
     printw("                   ?k         ?$$$$$$$$$$$F'*\n");
     printw("                      9$$bL     z$$$$$$$$$$$F\n");
     printw("                       $$$$    $$$$$$$$$$$$$\n");
     printw("                        '#$$c  '$$$$$$$$$\"\n");
     printw("                         .@\"#$$$$$$$$$$$$b\n");
     printw("                      z*      $$$$$$$$$$$$N.\n");
     printw("                  e\"      z$$\"  #$$$k  '*$$.\n");
     printw("                u*      u@$P\"      '#$$c   \"$$c\n");
     printw("          u@$*\"\"\"       d$$\"            \"$$$u  ^*$$b.\n");
     printw("        :$F           J$P\"                ^$$$c   '\"$$$$$$bL\n");
     printw("       d$$  ..      @$#                      #$$b         '#$\n");
     printw("       9$$$$$$b   4$$                          ^$$k         '$\n");
     printw("        \"$$6\"\"$b u$$                             '$    d$$$$$P\n");
     printw("         '$F $$$$$\"                              ^b  ^$$$$b$\n");
     printw("           '$W$$$$\"                                'b@$$$$\"\n");
     printw("                                                     ^$$$*  '\n");

}


void winning_sequence()
{
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	printw("YOU WON \n");
	printw("YOU WON NYANNN YOU ACTUALLY WON\n");
	new_screen();
	kitten();
	printw("I CAN FEEL MY SELF CHANGING NYANN\n");
	printw("My powers are coming back to me!!!\n");
	new_screen();
	attron(COLOR_PAIR(5));
	princess();
	printw("\n");
	printw("THANK YOU YOUNG HERO\n");
	printw("YOU HAVE RETURNED ME TO MY TRUE FORM\n");
	printw("FOR THAT I HAVE TWO GIFTS FOR YOU\n");
	printw("FIRST I MUST TELL YOU TWO THINGS\n");
	printw("1. YOU HAVE BECOME VERY GOOD AT C++ AND I WISH FOR YOU TO CONTINUE PRACTICING\n");
	printw("2.THE TRUTH IS I AM ACTUALLY OREN SEGAL, AND I WAS TESTING YOU AND PUTTING YOU THROUGH \n");
	printw("MANY CHALLENGES,WITHOUT HELPING YOU, SO YOU CAN BECOME A VERY STRONG AND INDEPENDENT CODER");
	printw("REMEMBER SEGAL ALWAYS LOVES YOU< AND I WANT NOTHING BUT THE BEST FOR YOU \n");
	printw("THE SECOND THING I WOULD LIKE TO DO FOR YOU IS GRANT YOU ONE WISH!!!\n");
	printw("PLEASE ENTER YOUR WISH!!!!\n");
	string input = getstring();
	cout<< input <<endl;
	printw("WHAT AN INTERESTING WISH!!\n");
	new_screen();
	printw("THAT IS COOL AND ALL BUT OREN SEGAL HAS A BETTER IDEA \n");
	new_screen();
	princess();
	printw("Adventurer, I WILL PROVIDE YOU SOME LINKS FOR IMPROVING YOU CODING!!!\n");
	printw(" http://www.cplusplus.com/doc/tutorial/arrays/ \n");
	printw("https://www.codecademy.com/ \n");
	printw("https://mva.microsoft.com/ \n");
	printw("http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ \n");
	printw("https://www.udacity.com/?utm_source=adwords&utm_medium=search&utm_campaign=2016-03-adwords-search-brand&utm_source=google&utm_medium=cpc&utm_campaign=brand&gclid=CjwKEAiAp97CBRDr2Oyl-faxqRMSJABx4kh9eCJSm9q8I194-DE-XsfUmELXHtpOIn2Pj0K3I8ulYhoCpZTw_wcB \n");
	printw("https://repl.it/sessions \n");
	printw("https://www.codeavengers.com/ \n");
	printw("https://teamtreehouse.com/ \n");
	printw("\n");
	printw("NOW ADVENTURER GO AND BECOME A MASTER OF THE CODE");
	refresh();

}

