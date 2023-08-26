#include <SD.h>

#include <SPI.h>
#define cs_sd    5         //sd
File sdcard_file;//CAN
int RPM;
int i;
void sdInit(){

 if (SD.begin(cs_sd))
 {
   Serial.println("SD card is ready to use.");
 } else
 {
   Serial.println("SD card initialization failed");
  // hmiSdRed();
   
 }

 
 sdcard_file = writeFile(SD, "/hello.txt", "test ");


 if (sdcard_file) { 
   sdcard_file.println("TestDATA");
  //  sdcard_file.println("Time in (ms),RPM,TEMP,Brake");   
   sdcard_file.println("Time in (ms),RPM,TEMP");   
   sdcard_file.close(); // close the file
 }
 // if the file didn't open, print an error:
 else {
   Serial.println("error opening test.txt");
//   hmiSdRedGreen();
 }
}

void sdData(){

    sdcard_file = SD.open("data.txt", FILE_WRITE);
  if (sdcard_file) { 
   sdcard_file.print(millis());
   sdcard_file.print(",");   
   sdcard_file.print(RPM);
   //sdcard_file.print(",");
   //sdcard_file.print(TEMP);
  //  sdcard_file.print(",");
  //  sdcard_file.print(brakePress);  
   sdcard_file.println();  
   sdcard_file.close(); // close the file
 }
 // if the file didn't open, print an error:
 else {
   Serial.println("error opening test.txt");
//   hmiSdRedGreen();
 }

}

void setup (){
  Serial.begin(9600);
  digitalWrite(5,LOW);
  sdInit();
   }
  

void loop(){
  // for (i=0;i<1000;i++){
  //   RPM = i;
  //   }
  //   sdData();
  }
