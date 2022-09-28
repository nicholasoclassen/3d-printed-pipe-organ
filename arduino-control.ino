//written by LMNC sam battle 2022, its an awful bit of code but does the job. each solenoid you adjust the note number (which midi note it responds to) and which midi channel. 
//so you only need to worry about the top bit of the code.

//modified by Okleshen to ignore midi channel, play 48 notes, and send to my specific ports. 
//I'm working with a breadboard midi port to RX0 on my mega, then ports 1-48 send digital 0V to trigger relay module.

//this version has logical OR (||) in the logic sections, so basically the midi crams into 3 octaves
//one thing to keep in mind using this version is that if there are note off commands coming from an out of range octave, they will cancel any sustained same note, either
//in the highest in-range octave or an out of range octave of the same side. basically overlap is an issue but this is a fine compromise
//also all occurrences of 1-12 are commented out

// 9/27/22 added servos 23-33. just replaces solenoid stuff. need to check direction and how the solenoids behave in setup/when power is (dis)connected

#include <MIDI.h>
#include <Servo.h>

int closed = 90;
int open = 110;

Servo servo23;
Servo servo24;
Servo servo25;
Servo servo26;
Servo servo27;
Servo servo28;
Servo servo29;
Servo servo30;
Servo servo31;
Servo servo32;
Servo servo33;

MIDI_CREATE_DEFAULT_INSTANCE();


//int Solenoid1Note = 36;
//int Solenoid2Note = 37;
//int Solenoid3Note = 38;
//int Solenoid4Note = 39;
//int Solenoid5Note = 40;
//int Solenoid6Note = 41;
//int Solenoid7Note = 42;
//int Solenoid8Note = 43;
//int Solenoid9Note = 44;
//int Solenoid10Note = 45;
//int Solenoid11Note = 46;
//int Solenoid12Note = 47;
int Solenoid13Note = 48;
int Solenoid14Note = 49;
int Solenoid15Note = 50;
int Solenoid16Note = 51;
int Solenoid17Note = 52;
int Solenoid18Note = 53;
int Solenoid19Note = 54;
int Solenoid20Note = 55;
int Solenoid21Note = 56;
int Solenoid22Note = 57;
int Solenoid23Note = 58;
int Solenoid24Note = 59;
int Solenoid25Note = 60;
int Solenoid26Note = 61;
int Solenoid27Note = 62;
int Solenoid28Note = 63;
int Solenoid29Note = 64;
int Solenoid30Note = 65;
int Solenoid31Note = 66;
int Solenoid32Note = 67;
int Solenoid33Note = 68;
int Solenoid34Note = 69;
int Solenoid35Note = 70;
int Solenoid36Note = 71;
int Solenoid37Note = 72;
int Solenoid38Note = 73;
int Solenoid39Note = 74;
int Solenoid40Note = 75;
int Solenoid41Note = 76;
int Solenoid42Note = 77;
int Solenoid43Note = 78;
int Solenoid44Note = 79;
int Solenoid45Note = 80;
int Solenoid46Note = 81;
int Solenoid47Note = 82;
int Solenoid48Note = 83;



//int Solenoid1 = 1;
//int Solenoid2 = 2;
//int Solenoid3 = 3;
//int Solenoid4 = 4;
//int Solenoid5 = 5;
//int Solenoid6 = 6;
//int Solenoid7 = 7;
//int Solenoid8 = 8;
//int Solenoid9 = 9;
//int Solenoid10 = 10;
//int Solenoid11 = 11;
//int Solenoid12 = 12;
int Solenoid13 = 13;
int Solenoid14 = 14;
int Solenoid15 = 15;
int Solenoid16 = 16;
int Solenoid17 = 17;
int Solenoid18 = 18;
int Solenoid19 = 19;
int Solenoid20 = 20;
int Solenoid21 = 21;
int Solenoid22 = 22;
int Solenoid23 = 23;
int Solenoid24 = 24;
int Solenoid25 = 25;
int Solenoid26 = 26;
int Solenoid27 = 27;
int Solenoid28 = 28;
int Solenoid29 = 29;
int Solenoid30 = 30;
int Solenoid31 = 31;
int Solenoid32 = 32;
int Solenoid33 = 33;
int Solenoid34 = 34;
int Solenoid35 = 35;
int Solenoid36 = 36;
int Solenoid37 = 37;
int Solenoid38 = 38;
int Solenoid39 = 39;
int Solenoid40 = 40;
int Solenoid41 = 41;
int Solenoid42 = 42;
int Solenoid43 = 43;
int Solenoid44 = 44;
int Solenoid45 = 45;
int Solenoid46 = 46;
int Solenoid47 = 47;
int Solenoid48 = 48;


void OnNoteOn(byte channel, byte note, byte velocity) {
 // if(note == Solenoid1Note)  digitalWrite(Solenoid1, LOW);
 // if(note == Solenoid2Note)  digitalWrite(Solenoid2, LOW);
 // if(note == Solenoid3Note)  digitalWrite(Solenoid3, LOW);
 // if(note == Solenoid4Note)  digitalWrite(Solenoid4, LOW);
 // if(note == Solenoid5Note)  digitalWrite(Solenoid5, LOW);
//  if(note == Solenoid6Note)  digitalWrite(Solenoid6, LOW);
 // if(note == Solenoid7Note)  digitalWrite(Solenoid7, LOW);
//  if(note == Solenoid8Note)  digitalWrite(Solenoid8, LOW);
//  if(note == Solenoid9Note)  digitalWrite(Solenoid9, LOW);
//  if(note == Solenoid10Note) digitalWrite(Solenoid10, LOW);
//  if(note == Solenoid11Note) digitalWrite(Solenoid11, LOW);
 // if(note == Solenoid12Note) digitalWrite(Solenoid12, LOW);
  if(note == Solenoid13Note || note == 36 || note == 24 || note == 12 || note == 0) digitalWrite(Solenoid13, LOW);
  if(note == Solenoid14Note || note == 37 || note == 25 || note == 13 || note == 1) digitalWrite(Solenoid14, LOW);
  if(note == Solenoid15Note || note == 38 || note == 26 || note == 14 || note == 2) digitalWrite(Solenoid15, LOW);
  if(note == Solenoid16Note || note == 39 || note == 27 || note == 15 || note == 3) digitalWrite(Solenoid16, LOW);
  if(note == Solenoid17Note || note == 40 || note == 28 || note == 16 || note == 4) digitalWrite(Solenoid17, LOW);
  if(note == Solenoid18Note || note == 41 || note == 29 || note == 17 || note == 5) digitalWrite(Solenoid18, LOW);
  if(note == Solenoid19Note || note == 42 || note == 30 || note == 18 || note == 6) digitalWrite(Solenoid19, LOW);
  if(note == Solenoid20Note || note == 43 || note == 31 || note == 19 || note == 7) digitalWrite(Solenoid20, LOW);
  if(note == Solenoid21Note || note == 44 || note == 32 || note == 20 || note == 8) digitalWrite(Solenoid21, LOW);
  if(note == Solenoid22Note || note == 45 || note == 33 || note == 21 || note == 9) digitalWrite(Solenoid22, LOW);
  if(note == Solenoid23Note || note == 46 || note == 34 || note == 22 || note == 10) servo23.write(open);
  if(note == Solenoid24Note || note == 47 || note == 35 || note == 23 || note == 11) digitalWrite(Solenoid24, LOW);
  if(note == Solenoid25Note) digitalWrite(Solenoid25, LOW);
  if(note == Solenoid26Note) digitalWrite(Solenoid26, LOW);
  if(note == Solenoid27Note) digitalWrite(Solenoid27, LOW);
  if(note == Solenoid28Note) digitalWrite(Solenoid28, LOW);
  if(note == Solenoid29Note) digitalWrite(Solenoid29, LOW);
  if(note == Solenoid30Note) digitalWrite(Solenoid30, LOW);
  if(note == Solenoid31Note) digitalWrite(Solenoid31, LOW);
  if(note == Solenoid32Note) digitalWrite(Solenoid32, LOW);
  if(note == Solenoid33Note) digitalWrite(Solenoid33, LOW);
  if(note == Solenoid34Note) digitalWrite(Solenoid34, LOW);
  if(note == Solenoid35Note) digitalWrite(Solenoid35, LOW);
  if(note == Solenoid36Note) digitalWrite(Solenoid36, LOW);
  if(note == Solenoid37Note || note == 84 || note == 96 || note == 108 || note == 120) digitalWrite(Solenoid37, LOW);
  if(note == Solenoid38Note || note == 85 || note == 97 || note == 109 || note == 121) digitalWrite(Solenoid38, LOW);
  if(note == Solenoid39Note || note == 86 || note == 98 || note == 110 || note == 122) digitalWrite(Solenoid39, LOW);
  if(note == Solenoid40Note || note == 87 || note == 99 || note == 111 || note == 123) digitalWrite(Solenoid40, LOW);
  if(note == Solenoid41Note || note == 88 || note == 100 || note == 112 || note == 124) digitalWrite(Solenoid41, LOW);
  if(note == Solenoid42Note || note == 89 || note == 101 || note == 113 || note == 125) digitalWrite(Solenoid42, LOW);
  if(note == Solenoid43Note || note == 90 || note == 102 || note == 114 || note == 126) digitalWrite(Solenoid43, LOW);
  if(note == Solenoid44Note || note == 91 || note == 103 || note == 115 || note == 127) digitalWrite(Solenoid44, LOW);
  if(note == Solenoid45Note || note == 92 || note == 104 || note == 116) digitalWrite(Solenoid45, LOW);
  if(note == Solenoid46Note || note == 93 || note == 105 || note == 117) digitalWrite(Solenoid46, LOW);
  if(note == Solenoid47Note || note == 94 || note == 106 || note == 118) digitalWrite(Solenoid47, LOW);
  if(note == Solenoid48Note || note == 95 || note == 107 || note == 119) digitalWrite(Solenoid48, LOW);
  
  }


void OnNoteOff(byte channel, byte note, byte velocity) {
 // if(note == Solenoid1Note)  digitalWrite(Solenoid1, HIGH);
 // if(note == Solenoid2Note)  digitalWrite(Solenoid2, HIGH);
 // if(note == Solenoid3Note)  digitalWrite(Solenoid3, HIGH);
 // if(note == Solenoid4Note)  digitalWrite(Solenoid4, HIGH);
//  if(note == Solenoid5Note)  digitalWrite(Solenoid5, HIGH);
//  if(note == Solenoid6Note)  digitalWrite(Solenoid6, HIGH);
 // if(note == Solenoid7Note)  digitalWrite(Solenoid7, HIGH);
 // if(note == Solenoid8Note)  digitalWrite(Solenoid8, HIGH);
//  if(note == Solenoid9Note)  digitalWrite(Solenoid9, HIGH);
//  if(note == Solenoid10Note) digitalWrite(Solenoid10, HIGH);
//  if(note == Solenoid11Note) digitalWrite(Solenoid11, HIGH);
 // if(note == Solenoid12Note) digitalWrite(Solenoid12, HIGH);
  if(note == Solenoid13Note || note == 36 || note == 24 || note == 12 || note == 0) digitalWrite(Solenoid13, HIGH);
  if(note == Solenoid14Note || note == 37 || note == 25 || note == 13 || note == 1) digitalWrite(Solenoid14, HIGH);
  if(note == Solenoid15Note || note == 38 || note == 26 || note == 14 || note == 2) digitalWrite(Solenoid15, HIGH);
  if(note == Solenoid16Note || note == 39 || note == 27 || note == 15 || note == 3) digitalWrite(Solenoid16, HIGH);
  if(note == Solenoid17Note || note == 40 || note == 28 || note == 16 || note == 4) digitalWrite(Solenoid17, HIGH);
  if(note == Solenoid18Note || note == 41 || note == 29 || note == 17 || note == 5) digitalWrite(Solenoid18, HIGH);
  if(note == Solenoid19Note || note == 42 || note == 30 || note == 18 || note == 6) digitalWrite(Solenoid19, HIGH);
  if(note == Solenoid20Note || note == 43 || note == 31 || note == 19 || note == 7) digitalWrite(Solenoid20, HIGH);
  if(note == Solenoid21Note || note == 44 || note == 32 || note == 20 || note == 8) digitalWrite(Solenoid21, HIGH);
  if(note == Solenoid22Note || note == 45 || note == 33 || note == 21 || note == 9) digitalWrite(Solenoid22, HIGH);
  if(note == Solenoid23Note || note == 46 || note == 34 || note == 22 || note == 10) servo23.write(closed);
  if(note == Solenoid24Note || note == 47 || note == 35 || note == 23 || note == 11) digitalWrite(Solenoid24, HIGH);
  if(note == Solenoid25Note) digitalWrite(Solenoid25, HIGH);
  if(note == Solenoid26Note) digitalWrite(Solenoid26, HIGH);
  if(note == Solenoid27Note) digitalWrite(Solenoid27, HIGH);
  if(note == Solenoid28Note) digitalWrite(Solenoid28, HIGH);
  if(note == Solenoid29Note) digitalWrite(Solenoid29, HIGH);
  if(note == Solenoid30Note) digitalWrite(Solenoid30, HIGH);
  if(note == Solenoid31Note) digitalWrite(Solenoid31, HIGH);
  if(note == Solenoid32Note) digitalWrite(Solenoid32, HIGH);
  if(note == Solenoid33Note) digitalWrite(Solenoid33, HIGH);
  if(note == Solenoid34Note) digitalWrite(Solenoid34, HIGH);
  if(note == Solenoid35Note) digitalWrite(Solenoid35, HIGH);
  if(note == Solenoid36Note) digitalWrite(Solenoid36, HIGH);
  if(note == Solenoid37Note || note == 84 || note == 96 || note == 108 || note == 120) digitalWrite(Solenoid37, HIGH);
  if(note == Solenoid38Note || note == 85 || note == 97 || note == 109 || note == 121) digitalWrite(Solenoid38, HIGH);
  if(note == Solenoid39Note || note == 86 || note == 98 || note == 110 || note == 122) digitalWrite(Solenoid39, HIGH);
  if(note == Solenoid40Note || note == 87 || note == 99 || note == 111 || note == 123) digitalWrite(Solenoid40, HIGH);
  if(note == Solenoid41Note || note == 88 || note == 100 || note == 112 || note == 124) digitalWrite(Solenoid41, HIGH);
  if(note == Solenoid42Note || note == 89 || note == 101 || note == 113 || note == 125) digitalWrite(Solenoid42, HIGH);
  if(note == Solenoid43Note || note == 90 || note == 102 || note == 114 || note == 126) digitalWrite(Solenoid43, HIGH);
  if(note == Solenoid44Note || note == 91 || note == 103 || note == 115 || note == 127) digitalWrite(Solenoid44, HIGH);
  if(note == Solenoid45Note || note == 92 || note == 104 || note == 116) digitalWrite(Solenoid45, HIGH);
  if(note == Solenoid46Note || note == 93 || note == 105 || note == 117) digitalWrite(Solenoid46, HIGH);
  if(note == Solenoid47Note || note == 94 || note == 106 || note == 118) digitalWrite(Solenoid47, HIGH);
  if(note == Solenoid48Note || note == 95 || note == 107 || note == 119) digitalWrite(Solenoid48, HIGH);
  
  }

void setup() {

servo23.attach(23);
servo24.attach(24);
servo25.attach(25);
servo26.attach(26);
servo27.attach(27);
servo28.attach(28);
servo29.attach(29);
servo30.attach(30);
servo31.attach(31);
servo32.attach(32);
servo33.attach(33);

 // pinMode(Solenoid1, OUTPUT);
 // pinMode(Solenoid2, OUTPUT);
 // pinMode(Solenoid3, OUTPUT);
//  pinMode(Solenoid4, OUTPUT);
//  pinMode(Solenoid5, OUTPUT);
//  pinMode(Solenoid6, OUTPUT);
//  pinMode(Solenoid7, OUTPUT);
//  pinMode(Solenoid8, OUTPUT);
//  pinMode(Solenoid9, OUTPUT);
//  pinMode(Solenoid10, OUTPUT);
//  pinMode(Solenoid11, OUTPUT);
//  pinMode(Solenoid12, OUTPUT);
  pinMode(Solenoid13, OUTPUT);
  pinMode(Solenoid14, OUTPUT);
  pinMode(Solenoid15, OUTPUT);
  pinMode(Solenoid16, OUTPUT);
  pinMode(Solenoid17, OUTPUT);
  pinMode(Solenoid18, OUTPUT);
  pinMode(Solenoid19, OUTPUT);
  pinMode(Solenoid20, OUTPUT);
  pinMode(Solenoid21, OUTPUT);
  pinMode(Solenoid22, OUTPUT);
 // pinMode(Solenoid23, OUTPUT);
 // pinMode(Solenoid24, OUTPUT);
 // pinMode(Solenoid25, OUTPUT);
 // pinMode(Solenoid26, OUTPUT);
 // pinMode(Solenoid27, OUTPUT);
// pinMode(Solenoid28, OUTPUT);
 // pinMode(Solenoid29, OUTPUT);
 // pinMode(Solenoid30, OUTPUT);
 // pinMode(Solenoid31, OUTPUT);
 // pinMode(Solenoid32, OUTPUT);
 // pinMode(Solenoid33, OUTPUT);
  pinMode(Solenoid34, OUTPUT);
  pinMode(Solenoid35, OUTPUT);
  pinMode(Solenoid36, OUTPUT);
  pinMode(Solenoid37, OUTPUT);
  pinMode(Solenoid38, OUTPUT);
  pinMode(Solenoid39, OUTPUT);
  pinMode(Solenoid40, OUTPUT);
  pinMode(Solenoid41, OUTPUT);
  pinMode(Solenoid42, OUTPUT);
  pinMode(Solenoid43, OUTPUT);
  pinMode(Solenoid44, OUTPUT);
  pinMode(Solenoid45, OUTPUT);
  pinMode(Solenoid46, OUTPUT);
  pinMode(Solenoid47, OUTPUT);
  pinMode(Solenoid48, OUTPUT);

//  digitalWrite(Solenoid1, HIGH);
//  digitalWrite(Solenoid2, HIGH);
//  digitalWrite(Solenoid3, HIGH);
//  digitalWrite(Solenoid4, HIGH);
//  digitalWrite(Solenoid5, HIGH);
//  digitalWrite(Solenoid6, HIGH);
//  digitalWrite(Solenoid7, HIGH);
//  digitalWrite(Solenoid8, HIGH);
//  digitalWrite(Solenoid9, HIGH);
//  digitalWrite(Solenoid10, HIGH);
//  digitalWrite(Solenoid11, HIGH);
//  digitalWrite(Solenoid12, HIGH);
  digitalWrite(Solenoid13, HIGH);
  digitalWrite(Solenoid14, HIGH);
  digitalWrite(Solenoid15, HIGH);
  digitalWrite(Solenoid16, HIGH);
  digitalWrite(Solenoid17, HIGH);
  digitalWrite(Solenoid18, HIGH);
  digitalWrite(Solenoid19, HIGH);
  digitalWrite(Solenoid20, HIGH);
  digitalWrite(Solenoid21, HIGH);
  digitalWrite(Solenoid22, HIGH);
 // digitalWrite(Solenoid23, HIGH);
 // digitalWrite(Solenoid24, HIGH);
 // digitalWrite(Solenoid25, HIGH);
 // digitalWrite(Solenoid26, HIGH);
 // digitalWrite(Solenoid27, HIGH);
 // digitalWrite(Solenoid28, HIGH);
 // digitalWrite(Solenoid29, HIGH);
 // digitalWrite(Solenoid30, HIGH);
 // digitalWrite(Solenoid31, HIGH);
 // digitalWrite(Solenoid32, HIGH);
 // digitalWrite(Solenoid33, HIGH);
  digitalWrite(Solenoid34, HIGH);
  digitalWrite(Solenoid35, HIGH);
  digitalWrite(Solenoid36, HIGH);
  digitalWrite(Solenoid37, HIGH);
  digitalWrite(Solenoid38, HIGH);
  digitalWrite(Solenoid39, HIGH);
  digitalWrite(Solenoid40, HIGH);
  digitalWrite(Solenoid41, HIGH);
  digitalWrite(Solenoid42, HIGH);
  digitalWrite(Solenoid43, HIGH);
  digitalWrite(Solenoid44, HIGH);
  digitalWrite(Solenoid45, HIGH);
  digitalWrite(Solenoid46, HIGH);
  digitalWrite(Solenoid47, HIGH);
  digitalWrite(Solenoid48, HIGH);
  
  
  MIDI.setHandleNoteOff(OnNoteOff);
  MIDI.setHandleNoteOn(OnNoteOn) ;
  MIDI.begin(MIDI_CHANNEL_OMNI);

servo23.write(closed);
servo24.write(closed);
servo25.write(closed);
servo26.write(closed);
servo27.write(closed);
servo28.write(closed);
servo29.write(closed);
servo30.write(closed);
servo31.write(closed);
servo32.write(closed);
servo33.write(closed);
  
}

void loop() {
  MIDI.read();
}
