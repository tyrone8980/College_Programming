/* music.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: tyrone8980
 */
#include <iostream>

#include <windows.h> // WinApi header
#include "music.h"
using namespace std;
// 60,000 milliseconds(1 minutes) / tempo (BPM) = Delay Time in milliseconds for quarter note beats
// 60,000 / 120 BPM = 500 milliseconds
//Whole note = 2000ms
//Half note = 1000ms
//Quarter note = 500ms
// Eighth note = 250ms
// sleep(milliseconds) for rests

void play_note(int n, int d)
{
    cout<<"The note is "<< n<<endl;
    cout<<"The duration is "<< d<<endl;
    Beep(n,d);

}
void play_sample_song()
{
    cout<< "I will now begin to play my special song."<< endl;
    cout<< "I hope you enjoy!!!!"<<endl;
    int wn = 2000, hn = 1000, qn = 500, en = 250, sn = 125, //initialize durations
            ent = 167, //eighth note triplet
    C4    = 262, CS4  = 277, D4    = 294, DS4  = 311, E4    = 330, //initialize notes
    F4    = 349, FS4  = 370, G4    = 392,GS4  = 415, A4    = 440, AS4  = 466, B4    = 494, C5    = 523,
    CS5 = 554, D5    = 587, DS5  = 622, E5    = 659, F5    = 698, FS5  = 740,
    G5    = 784, GS5  = 830,  A5    = 880, AS5  = 932 , B5    = 988 , C6    = 1047;

    int notes[] = {C4,C4,CS4,E4,F4,E4,F4,E4,D4,C4,C4,CS4,E4,F4,E4,F4,G4,G4,GS4,
    AS4,G4,GS4,F4,F4,G4,F4,E4,CS4,E4,F4,G4,F4,G4,F4,E4,CS4,C4,CS4,C4,C4,
    C4,C4,CS4,E4,F4,E4,F4,E4,D4,C4,C4,CS4};
    int duration[] = {en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,
            en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,en,
    en,en,en,en,en,en,en,en,en,en,en,en};


    // This is my song! Night in Tunisia
    for(int i=0,j=0;
            i<(sizeof(notes)/sizeof(notes[0])),
                    j<(sizeof(duration)/sizeof(duration[0])); i++,j++)
    {
    play_note(notes[i],duration[j]);
    }
}

int main()
{
    cout<<"Welcome to MusicMania!!"<<endl;
    cout<<"A fun little practice app created by Tyrone k Harmon Jr."<<endl;
    cout<<"----------Menu---------"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Option 1: Play a Major Scale"<<endl;
    cout<<"Option 2: Play a sample song"<<endl;
    cout<<"Option 3: Play your own song";
    cout<<"Option 4: Transpose a song"<<endl;
    int reply;
    cout<<"What is the option you would like to chose? "<<endl;
    cout<<" Option # "<<endl;
    cin>>reply;
    if(reply == 1)
    {
        ask_user_for_scales();
    }
    else if(reply == 3){
        ask_user_for_transpose();
    }
    else if(reply == 4){
    	play_user_song();
    }
    else
    {
        play_sample_song();
    }
    return 0;

}
