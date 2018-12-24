/*
 * music.h
 *
 *  Created on: Dec 11, 2016
 *      Author: shado
 */

#ifndef MUSIC_H_
#define MUSIC_H_
#include <string>
using namespace std;
void play_note(int n, int d);
void play_sample_song();
void play_scales(string scale);
void ask_user_for_scales();
void transpose(int note, int duration);
void ask_user_for_transpose();
void play_user_song();
#endif /* MUSIC_H_ */

