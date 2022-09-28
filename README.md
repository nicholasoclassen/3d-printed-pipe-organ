# 3d-printed-pipe-organ
3D printed pipe organ. All parts made utilizing parametric modeling in Fusion 360.

This project runs off an arduino mega receiving midi data from RX pin. My code is a modified version of Look Mum No Computer's diapason board code. First 10 notes use solenoids connected to a relay module, the rest use servos with the arduino servo library.

Parameters and formulas for pipes available at https://docs.google.com/spreadsheets/d/1giEFY-kfD_iiunVlE5T_Pnbb6S3v9OQezWPmD6x2kjA/edit?usp=sharing

I plan on adding files with all of the parametric models when I have them completed.

Required libraries: 
Arduino Midi Library by FortySevenEffects (https://github.com/FortySevenEffects/arduino_midi_library)
Servo by Arduino (https://github.com/arduino-libraries/Servo)

If I find time after completion, I will put together a build guide.
