/* uart.lua has to be uploaded  first to esp8266 with ESPlorer */

boolean stringComplete = false;
String inputString ="";
void setup() {

  Serial.begin(115200);
  Serial1.begin(9600);
  while (!Serial1) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial1.println("dofile(\"uart.lua\")");
}

void loop() {

  while (Serial1.available()<=0) {
    Serial1.println("cmd_1(99)");
    delay(1000);
  }
}

void serialEvent1() {
  while (Serial1.available()>0) {
    // get the new byte:
    char inChar = (char)Serial1.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      delay(1500);
      Serial.println(inputString);
      inputString = "";
      stringComplete = true;
    } 
  }
}
