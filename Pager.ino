/* 
  GTA 3 Pager Tune
  Connect a piezo buzzer or speaker to pin 9 or select a new pin.
*/
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define REST      0


int tempo = 70;

int buzzer = 9;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!

int melody[] = {
  
  // GTA 3 Pager Tune
  
  NOTE_FS5,11,NOTE_FS5,11,NOTE_FS5,11,REST, 95, NOTE_E5,18,NOTE_FS5,24, NOTE_A5,18, NOTE_FS5,16, REST, 45,NOTE_E5, 20,
  NOTE_FS5, 4,NOTE_D5, 11,NOTE_D5,11, NOTE_D5,18,NOTE_CS5, 11, NOTE_CS5, 11, NOTE_CS5,18, NOTE_E5, 12, NOTE_F5, 10, NOTE_FS5,4
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    delay(noteDuration);
    
    noTone(buzzer);
  }
}

void loop() {
}
