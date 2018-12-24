/*
 * scales.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: tyrone8980
 */
#include <iostream>
#include <string>
#include "music.h"
using namespace std;
void play_scales(string scale)
{
    int C4    = 262, CS4  = 277, D4    = 294, DS4  = 311, E4    = 330, //initialize notes
    F4    = 349, FS4  = 370, G4    = 392,GS4  = 415, A4    = 440, AS4  = 466, B4    = 494, C5    = 523,
    CS5 = 554, D5    = 587, DS5  = 622, E5    = 659, F5    = 698, FS5  = 740,
    G5    = 784, GS5  = 830,  A5    = 880, AS5  = 932 , B5    = 988 , C6    = 1047;

    int cmajor[8]={C4,D4,E4,F4,G4,A4,B4,C5},
    gmajor[8]={G4,A4,B4,C5,D5,E5,FS5,G5},
    dmajor[8]={D4,E4,FS4,G4,A4,B4,CS5,D5},
    amajor[8]={A4,B4,CS5,D5,E5,FS5,GS5,A5},
    emajor[8]={E4,FS4,GS4,A4,B4,CS5,DS5,E5},
    bmajor[8]={B4,CS5,DS5,E5,FS5,GS5,AS5,B5},
    fsmajor[8]={FS4,GS4,AS4,B4,CS5,DS5,F5,FS5},
    csmajor[8]={CS4,DS4,F4,FS4,GS4,AS4,C5,CS5},
    fmajor[8]={F4,G4,A4,AS4,C5,D5,E5},
    bbmajor[8]={AS4,C5,D5,DS5,F5,G5,A5,AS5},
    ebmajor[8]={DS4,F4,G4,GS4,AS4,C5,D5,E5},
    abmajor[8]={GS4,AS4,C5,CS5,DS5,F5,G5,GS5},
    dbmajor[8]={CS4,DS4,F4,FS4,GS4,AS4,C5,CS5},
    gbmajor[8]={FS4,GS4,AS4,B4,CS5,DS5,F5,FS5},
    cbmajor[8]={B4,CS5,DS5,E5,FS5,GS5,AS5,B5};
    if(scale == "C"){
        for(int i=0;i<(sizeof(cmajor)/sizeof(cmajor[0])); i++)
        {
            int d = 500;
            play_note(cmajor[i], d);
        }

    }
    else if(scale == "G"){
            for(int i=0;i<(sizeof(gmajor)/sizeof(gmajor[0])); i++)
            {
                int d = 500;
                play_note(gmajor[i], d);
            }

        }
    else if(scale == "A"){
            for(int i=0;i<(sizeof(amajor)/sizeof(amajor[0])); i++)
            {
                int d = 500;
                play_note(amajor[i], d);
            }

        }
    else if(scale == "D"){
            for(int i=0;i<(sizeof(dmajor)/sizeof(dmajor[0])); i++)
            {
                int d = 500;
                play_note(dmajor[i], d);
            }

        }
    else if(scale == "E"){
            for(int i=0;i<(sizeof(emajor)/sizeof(emajor[0])); i++)
            {
                int d = 500;
                play_note(emajor[i], d);
            }

        }
    else if(scale == "B"){
            for(int i=0;i<(sizeof(bmajor)/sizeof(bmajor[0])); i++)
            {
                int d = 500;
                play_note(bmajor[i], d);
            }

        }
    else if(scale == "F#"){
            for(int i=0;i<(sizeof(fsmajor)/sizeof(fsmajor[0])); i++)
            {
                int d = 500;
                play_note(fsmajor[i], d);
            }

        }
    else if(scale == "C#"){
            for(int i=0;i<(sizeof(csmajor)/sizeof(csmajor[0])); i++)
            {
                int d = 500;
                play_note(csmajor[i], d);
            }

        }
    else if(scale == "F"){
            for(int i=0;i<(sizeof(fmajor)/sizeof(fmajor[0])); i++)
            {
                int d = 500;
                play_note(fmajor[i], d);
            }

        }
    else if(scale == "Bb"){
            for(int i=0;i<(sizeof(bbmajor)/sizeof(bbmajor[0])); i++)
            {
                int d = 500;
                play_note(bbmajor[i], d);
            }

        }
    else if(scale == "Eb"){
            for(int i=0;i<(sizeof(ebmajor)/sizeof(ebmajor[0])); i++)
            {
                int d = 500;
                play_note(ebmajor[i], d);
            }

        }
    else if(scale == "Ab"){
            for(int i=0;i<(sizeof(abmajor)/sizeof(abmajor[0])); i++)
            {
                int d = 500;
                play_note(abmajor[i], d);
            }

        }
    else if(scale == "Db"){
            for(int i=0;i<(sizeof(dbmajor)/sizeof(dbmajor[0])); i++)
            {
                int d = 500;
                play_note(dbmajor[i], d);
            }

        }
    else if(scale == "Gb"){
            for(int i=0;i<(sizeof(gbmajor)/sizeof(gbmajor[0])); i++)
            {
                int d = 500;
                play_note(gbmajor[i], d);
            }

        }
    else{
            for(int i=0;i<(sizeof(cbmajor)/sizeof(cbmajor[0])); i++)
            {
                int d = 500;
                play_note(cbmajor[i], d);
            }

        }

}

void ask_user_for_scales()
{
    string scale;
    cout<<"Major Scales in order of sharps"<<endl;
    cout<< "C Major: type C"<<endl<<"G Major: type G"<<endl<<"D Major: type D"<<endl<<"A Major: type A"<<endl<<"E Major: type E"<<
            endl<<"B Major: type B"<<endl<<"F# Major: type F#"<<endl<<"C# Major: type C#"<<endl<<
            "Or in order of Flats"<<endl<< "F Major: type F"<<endl<<
            "Bb Major: type Bb"<<endl<<"Eb Major: type Eb"<<endl<<"Ab Major: type Ab"<<endl<<"Db Major: type Db"<<endl<<
            "Gb Major: type Gb"<<endl<<"Cb Major: type Cb"<<endl;
    cout<< "Using the input guidelines above, please input your desired scale"<<endl;
    cout<<"What Scale would you like me to play for you? "<<endl;
    cin>>scale;
    play_scales(scale);
    char answer;
    cout<<"Would you like to hear another scale? <y/n>"<<endl;
    cin>> answer;
    if(answer == 'y')
    {
        ask_user_for_scales();
    }
    else
    {
        cout<<"Thank you for your time!! "<<endl;
    }

}

