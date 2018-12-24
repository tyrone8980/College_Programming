/*
 * play_user_song.cpp
 *
 *  Created on: Dec 12, 2016
 *      Author: tyrone8980
 */
#include <iostream>
#include <string>
#include "music.h"
using namespace std;
void play_user_song()
{
	 int C4    = 262, CS4  = 277, D4    = 294, DS4  = 311, E4    = 330, //initialize notes
	            F4    = 349, FS4  = 370, G4    = 392,GS4  = 415, A4    = 440, AS4  = 466, B4    = 494, C5    = 523,
	            CS5 = 554, D5    = 587, DS5  = 622, E5    = 659, F5    = 698, FS5  = 740,
	            G5    = 784, GS5  = 830,  A5    = 880, AS5  = 932 , B5    = 988 , C6    = 1047;
	    int wn = 2000, hn = 1000, qn = 500, en = 250, sn = 125, //initialize durations
	                ent = 167; //eighth note triplet

	    cout<<"C4    = 262, CS4  = 277, D4    = 294, DS4  = 311, E4    = 330"<<endl;
	    cout<<"    F4    = 349, FS4  = 370, G4    = 392,GS4  = 415, A4    = 440, AS4  = 466, B4    = 494, C5    = 523"<<endl;
	    cout<<"CS5 = 554, D5    = 587, DS5  = 622, E5    = 659, F5    = 698, FS5  = 740"<<endl;
	    cout<<" G5    = 784, GS5  = 830,  A5    = 880, AS5  = 932 , B5    = 988 , C6    = 1047"<<endl;
	    cout<<"whole note = 2000, half note = 1000, quarter note = 500, eighth note  = 250, sixteenth note = 125, eighth note triplet = 167"<<endl;
	    cout<<"I will transpose a song for you but, first please enter each note and each notes durations please! "<<endl;
	    bool cont;
	    while(cont)
	    {
	    	int x,y, array_size;
	    	cout<<"How many notes does your song have? "<<endl;
	    	cin>> array_size;
	    	int notes[array_size], durations[array_size];
	    	for(int i=0; i<array_size;i++){
	    		cout<< "What is the frequency of your note? "<<endl;
	    		cin>> x;
	    	}

	        for(int i=0;i<array_size;i++)
	        {
	        	cout<<"Using the duration list above:"<<endl;
	        	cout<<"what is that note's duration? "<<endl;
	        	cin>>y;

	        }

	        char next_reply;
	        cout<<"Would you like to enter another note? <y/n>"<<endl;
	        cin>> next_reply;
	        if(next_reply == 'y')
	        {
	            cont = true;
	        }
	        else
	        {
	            for(int i=0, j=0; i < array_size, j <array_size; i++, j++)
	            {
	            	play_note(i, j);
	            }
	        }

	    }
}


