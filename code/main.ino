#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize RFID reader
  SPI.begin();
  rfid.PCD_Init();
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  
  // Clear the LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RFID Reader Ready");
}

void loop() {
  // Check for RFID card presence
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  String rfidTag = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    rfidTag += String(rfid.uid.uidByte[i], HEX);
  }
  rfidTag.toUpperCase();
  Serial.println(rfidTag);
  
  lcd.clear();

  // Define actions based on RFID tag
  if (rfidTag == "62751D51") {
    // Example: ID for Rack 1, Row 1, Segment 1
    displayRackRowSegment(1, 1, 1);
  
  }
  else if (rfidTag == "6280CB51") {
    // Example: ID for Rack 1, Row 2, Segment 2
    displayRackRowSegment(1, 1, 2);
  
  }
  else if (rfidTag == "72716C51") {
    // Example: ID for Rack 2, Row 1, Segment 1
    displayRackRowSegment(1, 2, 1);
  }
  else if (rfidTag == "A8BB9F12") {
    // Example: ID for Rack 2, Row 2, Segment 2
    displayRackRowSegment(1, 2, 2);
  }
  else {
    // Unknown RFID
    lcd.setCursor(0, 0);
    lcd.print("Unknown ID");
    Serial.println("Unknown RFID Tag");
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void displayRackRowSegment(int rack, int row, int segment) {
  lcd.clear();
  lcd.setCursor(0, 0); // First line of the LCD
  lcd.print("RACK:");
  lcd.print(rack);
  lcd.print(" ROW:");
  lcd.print(row);
  
  lcd.setCursor(0, 1); // Second line of the LCD
  lcd.print("SEG:");
  lcd.print(segment);

  Serial.print("RACK: ");
  Serial.print(rack);
  Serial.print(", ROW: ");
  Serial.print(row);
  Serial.print(", SEG: ");
  Serial.println(segment);
}
