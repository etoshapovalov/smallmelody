// Small Melody - created by Andrey Shapovalov. 2020

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>

typedef struct Note {
    unsigned char duration : 2;
    unsigned char note : 6;
} Note;
unsigned char testMusicBlock[] = {
        0b00010110,0b01011000,0b00010110,0b01011001,0b00010100,0b00010100,0b00011000,0b01010001,0b00011000,0b01010100,0b00011000,0b00010001,0b01000000
};
Note* charToNote(unsigned char value){
    Note* note = malloc(sizeof(Note));
    note->duration = value >> (unsigned int)6;
    note->note = (value << (unsigned int)2)>>2;
    return note;
}
int noteNumberToFrequency(unsigned char number){
    float baseFreq = 440; //A4
    unsigned int baseNumber = 20;
    if(number == 0){
        return 0;
    }
    if(number == baseNumber){
        return (int)baseFreq;
    }
    float result = baseFreq;
    if(number < baseNumber){
        result /= (float)pow(1.06,baseNumber-number);
    } else if(number > baseNumber){
        result *= (float)pow(1.06,number-baseNumber);
    }
    return (int)roundf(result);
}

int main() {
    // Convert bytes to Note struct
    Note* melody[sizeof(testMusicBlock)/sizeof(unsigned char)];
    for(int i = 0; i < sizeof(testMusicBlock)/sizeof(unsigned char); i++){
        melody[i] = charToNote(testMusicBlock[i]);

    }

    // Calculate bpm delay (delay between beats)
    int bpm = 170;
    DWORD delay = 1000*(60.0/(bpm));


    // Play loop
    while(true){
        int ticksLeft = melody[0]->duration + 1;
        unsigned int currentNoteNumber = 0;
        while(currentNoteNumber < sizeof(melody)/sizeof(Note*)-1){

            Beep(noteNumberToFrequency(melody[currentNoteNumber]->note),delay*ticksLeft);

            //free(melody[currentNoteNumber]);
            currentNoteNumber++;
            ticksLeft = melody[currentNoteNumber]->duration + 1;
        }
    }
    return 0;
}
