/*
 * questions.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: tyrone8980
 */
#include <iostream>
#include <string>
#include <ncurses.h>
#include <queue>
#include "game.h"
using namespace std;

void question_sequence()
{
	int segal_life = 900, hero_life = 250;
	queue<string>q;
		q.push("1.The cin>> input statement is used to receive data from keyboard<t/f>??");//t
		q.push("2.The cout<< output statement is used to print text on the screen<t/f>?");//t
		q.push("3.A comment in C++ language starts with */ and ends with /*? <t/f>?");//f
		q.push("4.The break command is used to exit a loop<t/f>?");//t
		q.push("5.An address stored by a pointer can be specified by the programmer<t/f>?");//f
		q.push("6.The address operator(&) is used to get the address of a variable by putting it in front of the variable.<t/f>?");//t
		q.push("7.Which of the following is not a standard data type? a.int    b.char    c.float    d.date");//d
		q.push("8.Which of the C++ loops is not a pretest loop? a. for loop   b. while loop   c. do while loop");//c
		q.push("9.The operator * is used to get value stored at an address that is pointed by a pointer.");//t
		q.push("10.Which of the following statements initializes the pointer to the address of x variable? a. int *ptr=x;     b. int *ptr=&x;     c. int &ptr=&x;      d. int *ptr=*x;");//b
		q.push("11.In C++, we can declare a structure using \"structure\" keyword.<t/f>?");//f
		q.push("12.Which of the following are binary expressions?a--b   b.++a   c. a+=1   d. a++");//c
		q.push("13.If originally x=10 and y=5 what is the value of each of the expressions:++x+y ");     //16
		q.push("14. If originally x=10 and y=5 what is the value of each of the expressions:--x+y");//14
		q.push("15.Which of the following statements about the while loop is not true?a.The while loop is a posttest loop.\n b.Testing condition is made before each iteration.\n c.The while loop statement must terminate with a semi-colon.     ");//a
		q.push("16.When an array is partially initialized, the rest of its elements will automatically be set to zero?<t/f>");//f
		q.push("17.The whole array can be passed to a function. However, it can't be changed by the code in that function?<t/f>");//f
		q.push("18.A two-dimensinal array represents data in the form of table with rows and columns? <t/f>");//t
		q.push("19.If you have an array of 20 elements, what is the good way to assign a value to each element?a.Assigning each element individually without using a loopb.Using a loop to assign a value to each element");//b
		q.push("FINAL QUESTION!!! Worth 1000 attack points What is Oren Segal's favorite word?");// memory
	queue<string>ans;
		ans.push("t");
		ans.push("t");
		ans.push("f");
		ans.push("t");
		ans.push("f");
		ans.push("t");
		ans.push("d");
		ans.push("c");
		ans.push("t");
		ans.push("b");
		ans.push("f");
		ans.push("c");
		ans.push("16");
		ans.push("14");
		ans.push("a");
		ans.push("f");
		ans.push("f");
		ans.push("t");
		ans.push("b");
		ans.push("memory");
	while((segal_life>0) && (hero_life>0))
	{
		attron(COLOR_PAIR(3));
		cout<< "segal's life points are: "<<segal_life<<"\n";
		attron(COLOR_PAIR(1));
		cout<<"Your life points are: "<< hero_life<<endl;

				string answer, computer_answer;
							cout<<endl;
							cout<<endl;
							cout<< q.front() <<endl;
									q.pop();
									answer = getstring();
									computer_answer = ans.front();
									ans.pop();
									if(answer == computer_answer)
									{
										segal_life -=50;

									}
									else
									{
										hero_life -=50;

									}





	}
	if(hero_life <= 0)
	{
		game_over();
	}
	else
	{
		winning_sequence();
	}
}

