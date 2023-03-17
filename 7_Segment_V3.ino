/*
  Define an array segPins contains the pins that are connected to the 7 segments of the display.
  Also define an array digits which contains the binary values for each digit 0-9, 1 representing a segment to be turned on and 0 representing a segment to be turned off.
  In the setup function, set all segment pins as outputs using a for loop.
  In the loop function, display digits 0-9.
  The displayDigit function turns on the segments for that digit based on the binary values in the digits array.
  Turns on the segments using another for loop and digitalWrite function with using HIGH parameters based on the binary values in the digits array.
*/

//define pins for the 7 segment display
int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

//define segments for each digit (0-9) in binary form
int digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, //0
  {0, 1, 1, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1}, //2
  {1, 1, 1, 1, 0, 0, 1}, //3
  {0, 1, 1, 0, 0, 1, 1}, //4
  {1, 0, 1, 1, 0, 1, 1}, //5
  {1, 0, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 0, 0, 1, 1}  //9
};

void setup() {
  //set all segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop() {
  //display digits 0-9 repeatedly
  for (int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000); //delay for 1 second
  }
}

void displayDigit(int digit) {
  //turn off all segments
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], LOW);
  }

  //turn on segments based on the binary values in the digit array
  for (int i = 0; i < 7; i++) {
    if (digits[digit][i] == 1) {
      digitalWrite(segPins[i], HIGH);
    }
  }
}
