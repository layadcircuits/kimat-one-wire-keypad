/***************************************************************************
 Example Code using the Kimat One Wire Keypad.
 Please download the library from https://github.com/AndrewMascolo/OnewireKeypad
 
 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
 The Saleng Mobile Robot Shield is designed and made by Layad Circuits.
 By supporting our products, you support local innovation and share in the movement
 to spur local ingenuity. 
  
 Author(s): C.D.Malecdan for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2017/09/27 - initial release
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 +63-916-442-8565
 ***************************************************************************/
#include <OnewireKeypad.h>

char KEYS[] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};


OnewireKeypad <Print, 16 > KP2(Serial, KEYS, 4, 4, A0, 4700, 1000, 10000, ExtremePrec );

void setup () {
  Serial.begin(115200);


  // This method is set in the constructor with a default value of 5.0
  // You only need to include this method if your Arduino is not supplying 5v to
  // the keypad. ie. ~4.7v or even with 3.3v Arduino boards too.
  //KP2.SetKeypadVoltage(5.0);
  KP2.SetKeypadVoltage(4.95);
}
void loop()
{

  if ( char key = KP2.Getkey() ) {
    
    switch (KP2.Key_State()) {
      case PRESSED:
        Serial << "Key: " << key << " State: ";
        Serial.println("PRESSED");
        break;

      case RELEASED:
        Serial << "Key: " << key << " State: ";
        Serial.println("RELEASED");
        break;

      case HELD:
        Serial << "Key: " << key << " State: ";
        Serial.println("HOLDING");
        break;
    }
  }
}


