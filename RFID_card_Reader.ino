OUR CODE
#include<SPI.h> // THIS IS A LIABRARY
#include<MFRC522.h> // THIS IS THE LIBRARY FOR THE RFID CARD READER
#include<LiquidCrystal.h> // THIS IS THE LIBRARY OR HEADER FILE FOR THE LCD SCREEN WE USED
LiquidCrystal lcd(7,6,5,4,3,2); // THIS IS THE VARIABLE AND PIN DECLARATION FOR THE LCD SCREEN WE USED
#define SS_PIN 10 // THIS IS SIMPLY A DIGITAL PIN DECLATION FOR THE RFID CARD READER ASSIGNING SSPIN TO PIN 10
#define RST_PIN 9 // THIS IS ALSO A DIGITAL PIN DECLATION FOR THE RFID CARD READER ASSIGNING RSTPIN TO PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // THIS A FUCTION DEFINITON SAYING THAT INPUT IS PASSED THROUGH PIN SS AND PIN RST
void setup() // THIS IS THE VOID SETPUP FUNCTION . IT ALLOW A CODE TO RUN ONCE. IT IS ALSO USE FOR INITIALIZATION OF CERTAIN THINGS
{
 Serial.begin(9600); // THIS FUNCTION SIMPLY MEANS INITIALIZATION OF THE SERIAL MONITOR
 mfrc522.PCD_Init(); // THIS FUNCTION SIMPLY MEANS THE INITIALIZATION OF THE CARD READER
 lcd.begin(16,2); // THIS FUNTION SIMPLY MEANS THE INITIALIZATION OF THE LCD SCREEN WE USED
 SPI.begin(); // THIS FUNCTION SIMPLY MENAS THE INITIALIZATION OF THE SPI
 lcd.setCursor(0,0); // THIS FUNCTION SIMPLY MEANS THE NEXT FUNCTION BELOW WILL BE PRINTED ON COLUMN 0 AND ROW 0 OF THE LCD
 lcd.print("Welcome Team 7"); // THIS FUNCTION SIMPLY TELLS THE LCD TO DISPLAY "Welcome Team 7"
 delay(2000); // THIS FUNCTION SIMPLY MEANS THAT THE FUCTION ABOVE IS DISPLAY FOR 2 SECONDS OR 2000MILLISECONDS
 lcd.clear(); // THIS FUNCTION SIMPLY CLEARS THE LCS SCREEN AFTER THE MESSAE HAS BEEN DISPLAYED
 Serial.println(F("Key Card Lock")); // THIS FUNCTION SIMPLY MEANS THAT "KEY CARD LOCK WILL BE PRINTED ON THE SERIAL MONITOR
 lcd.setCursor(0,0);
 lcd.print("PLACE ID CARD");
 Serial.println("Put your card to the reader...");
 Serial.println();

}
// this part of the program repeats itself//
// this code only grants access to memebers of group 7 computer engineering
void loop(){ // THIS IS THE LOOP FUNCTION , WHERE EVERYTHING INSIDE IT RUNS MORE THAT ONCE
 if ( ! mfrc522.PICC_IsNewCardPresent()) { // THIS FUNCTION MEANS THAT IF THE CARD READER SENSES AND ID CARD IT RETURNS A DEFAULT VALUE TO
READ IT
 return;
 }
 if ( ! mfrc522.PICC_ReadCardSerial()) {
 return;
 }
 Serial.println(F("CARD ID:")); // THIS SIMPLY MEANS THAT "CARD ID " WILL BE DISPLAYED ON THE SERIAL MONITOR
 String content =""; // THIS SIMPY SAY THAT THE VARIABLE NAME "CONTENT " IS A STRING
 byte letter; // THIS SIMPLY MEANS THAT THE VARIABLE NAME "LETTER" IS A BYTE
 for(byte i=0;i<mfrc522.uid.size; i++) // THIS SIMPLY MEANS THAT THE FUNCTION WILL RUN AS LONG AS THE READ DATA IS UP THE THE CARDREADER
ARRAY SIZE
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0": " ");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
 content.concat(String(mfrc522.uid.uidByte[i], HEX)); // THIS SIMPLY DEFINES THE DATA READ FROM THE CARD READER TO BE IN HEXDECIMALS
 }
 Serial.println();
 Serial.print("Message :"); //THIS SIMPLY PRINTS "MESSAGE" ON THE SERIAL MONITOR
 content.toUpperCase();
 if(content.substring(1) =="94 E8 90 91") // THIS IS A DECISION STATEMENT COMPARING THE STRING OF THE CARD TO THIS SET OF HEXADECIMALS" 94 E8
90 91"
 {
 lcd.clear();
 Serial.println("Authorised"); // THIS SIMPLY PRINTS AUTHORISED ON THE SERIAL MONITOR
 lcd.print("Ugo Uchechi"); // THIS PRINTS "UGO UCHECHI" IF THE DECISION IS TRUE
 Serial.println("Ugo Uchechi");
 delay(1000); // THIS DELAYS THE DISPLAY TIME BY 1 SECOND
 lcd.clear(); // THIS CLEARS THE NAME AND MOVES TO PRINT THE MATRIC NO ON LINE65
 lcd.print("17CJ022547");
 Serial.println("17CJ022547");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH); //HIS SIMPLY TELL THE BUZZER TO BEAP TWICE IF WHEN THE CARD IS DETECTED " BUZZER ON "
 delay(1000);
 digitalWrite(8,LOW); //THIS SIMPLY TELL THE BUZZER TO BEAP TWICE IF WHEN THE CARD IS DETECTED "BUZZER OFF"
 delay(1000);
 digitalWrite(8,HIGH); //THIS SIMPLY TELL THE BUZZER TO BEAP TWICE IF WHEN THE CARD IS DETECTED "BUZZER ON"
 delay(1000);
 digitalWrite(8,LOW); // THIS SIMPLY TELL THE BUZZER TO BEAP TWICE IF WHEN THE CARD IS DETECTED "BUZZER OFF"
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else if(content.substring(1) =="A4 81 D6 91")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("Oyinkansola");
 Serial.println("Oyinkansola");
 delay(1000);
 lcd.clear();
 lcd.print("17CJ022527");
 Serial.println("17CJ022527");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(1000);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }

 else if(content.substring(1) =="62 79 7B A5")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("Oreoluwa");
 Serial.println("Oreoluwa");
 delay(1000);
 lcd.clear();
 lcd.print("17CE023397");
 Serial.println("17CE023397");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else if(content.substring(1) =="87 43 80 06")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("Oma");
 Serial.println("Oma");
 delay(1000);
 lcd.clear();
 lcd.print("17CJ022517");
 Serial.println("17CJ022517");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(1000);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else if(content.substring(1) =="F4 46 BB 91")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("Gesinde Abisolu");
 Serial.println("Gesinde Abisolu");
 delay(1000);
 lcd.clear();
 lcd.print("17CJ022497");
 Serial.println("17CJ022497");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(1000);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else if(content.substring(1) =="64 99 D5 91")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("James Kolade");
 Serial.println("James Kolade");
 delay(1000);
 lcd.clear();
 lcd.print("17CJ022507");
 Serial.println("17CJ022507");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(1000);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else if(content.substring(1) =="04 61 65 2D")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("Emmanuel Apa");
 Serial.println("Emmanuel Apa");
 delay(1000);
 lcd.clear();
 lcd.print("17CJ022477");
 Serial.println("17CJ022477");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 Serial.println("Priscilla");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(1000);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else if(content.substring(1) =="E4 B7 C9 91")
 {
 lcd.clear();
 Serial.println("Authorised");
 lcd.print("Priscilla");
 Serial.println("Priscilla");
 delay(1000);
 lcd.clear();
 lcd.print("17CJ022537");
 Serial.println("17CJ022537");
 delay(1000);
 lcd.clear();
 lcd.print("ACCESS GRANTED");
 Serial.println("Priscilla");
 delay(1000);
 lcd.clear();
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(1000);
 digitalWrite(8,HIGH);
 delay(1000);
 digitalWrite(8,LOW);
 delay(500);
 lcd.print("PLACE ID CARD");
 }
 else
 {
 lcd.clear();
 lcd.print("ACCESS DENIED"); // THIS SIMPLY DISPLAYS "ACCESS DENIED " ON THE LCD IF AN UNRECOGNIZED CARD IS PLACED TO THE CARD READER
 Serial.println("ACCESS DENIED");
 delay(500); // THIS DISPLAYS THE MESSAGE ON THE LCD SCREEN FOR 1 SECOND
 lcd.clear(); // THIS CLEARS THE MEASSAGE DISPLAYED ON THE LCD SCREEN
 lcd.print("PLACE ID CARD");
 }
 }
 
