# SmallMelody
Simple melody player, that requires single byte for a note.
### How does it work?
`0b01011000` - example single-byte note
- Two first MSB are (duration - 1) in ticks (of metronome). 
In this example: 1, results in two tick delay.
- Other bytes are "note number" - note calculated from A4 (number 20) 
In this example: C#5 (number 24)

If note number equals 0, it works like pause, with duration of note duration.

In example provided in source code, normal-sized melody is stored in just 13 bytes!

I don't think, somebody will need this project, but have fun btw!

##### Created by Andrey Shapovalov. 2020.