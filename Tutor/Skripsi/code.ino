#include <SPI.h>       
#include <MFRC522.h>
const int SS_PIN=53;
const int RST_PIN=5;
MFRC522 mfrc522(SS_PIN, RST_PIN); 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

#include <Servo.h>
Servo Portal1;
Servo Portal2;

#include <EEPROM.h>     
byte storedCard[4];   
byte readCard[4];   
byte masterCard[4];  

const int redLed=8;    
const int greenLed=9;
const int blueLed=10;
const int whiteLed=6;
const int yellowLed=7;

const int wipeA=11;
const int wipeB=12; 

bool S1=0; 
bool S2=0; 
bool S3=0; 
bool S4=0;
bool S5=0;
bool S6=0;
bool S7=0;
bool S8=0;
bool S9=0;
bool S10=0;
int slot=10;

const int ir1=22;
const int ir2=23;
const int ir3=24;
const int ir4=25;
const int ir5=26;
const int ir6=27;
const int ir7=28;
const int ir8=29;
const int ir9=30;
const int ir10=31;
const int irMasuk=32;
const int irKeluar=33;

bool hasilIR1;
bool hasilIR2;
bool hasilIR3;
bool hasilIR4;
bool hasilIR5;
bool hasilIR6;
bool hasilIR7;
bool hasilIR8;
bool hasilIR9;
bool hasilIR10;
bool hasilIRmasuk;
bool hasilIRkeluar;

boolean match = false;         
boolean programMode = false;  
boolean replaceMaster = false;

uint8_t successRead;    


void setup() {
  Serial.begin(9600); 
  SPI.begin(); 
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight(); 
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(wipeA, INPUT_PULLUP);
  pinMode(wipeB, INPUT_PULLUP);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(ir7, INPUT);
  pinMode(ir8, INPUT);
  pinMode(ir9, INPUT);
  pinMode(ir10, INPUT);
  pinMode(irMasuk, INPUT);
  pinMode(irKeluar, INPUT);
  Portal1.attach(2);
  Portal2.attach(3);
  lcd.setCursor(0,1);
  lcd.print("  Program Dimulai   ");
  delay(2500);
  lcd.clear();
  
  ///////////////////////////////////// Pembacaan sensor Infrared saat pertama dinyalakan ///////////////////////////                            
  Readsensor();
  int total= S1+S2+S3+S4+S5+S6+S7+S8+S9+S10;
  slot = slot-total;  


  //////////////////////////////////// Untuk menyimpan Master Card ///////////////////////////////////////////
  if (EEPROM.read(1) != 143) {
    Serial.println(F("Master Card belum di tentukan"));
    Serial.println(F("Scan Kartu untuk menentukan Master Card"));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Silahkan tap kartu");
    lcd.setCursor(0,1);
    lcd.print("untuk menentukan ");
    lcd.setCursor(0,2);
    lcd.print("Master Card");
    do {
      successRead = getID();            
      digitalWrite(blueLed, HIGH);    
      delay(200);
      digitalWrite(blueLed, LOW);
      delay(200);
    }
    while (!successRead);                 
    for ( uint8_t j = 0; j < 4; j++ ) {        
      EEPROM.write( 2 + j, readCard[j] );  
    }
    EEPROM.write(1, 143);                  
    Serial.println(F("Master Card telah ditentukan"));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Master Card telah");
    lcd.setCursor(0,1);
    lcd.print("Ditentukan");
    delay(2000);
  }
  Serial.println(F("-------------------"));
  Serial.println(F("ID Master Card"));
  for ( uint8_t i = 0; i < 4; i++ ) {          
    masterCard[i] = EEPROM.read(2 + i); 
    Serial.print(masterCard[i], HEX);
  }
  Serial.println("");
  Serial.println(F("-------------------"));
  Serial.println(F("Sistem siap"));
  cycleLeds();
}


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {

do {

  ////////////////////////////////////// Untuk Pushbutton A ///////////////////////////// 
  if (digitalRead(wipeA) == LOW) { 
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
    Serial.println(F("Push Button A ditekan"));
    Serial.println(F("Semua kartu akan di hapus dari sistem"));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Semua kartu akan");
    lcd.setCursor(0,1);
    lcd.print("Dihapus dari sistem");
    lcd.setCursor(0,2);
    lcd.print("Dalam 15 detik");
    delay(15000);                       
    if (digitalRead(wipeA) == HIGH) {    
      Serial.println(F("Memulai penghapusan ID"));
      for (uint8_t x = 0; x < EEPROM.length(); x = x + 1) { 
        if (EEPROM.read(x) == 0) {           

        }
        else {
          EEPROM.write(x, 0);      
          Serial.println("Penghapusan berhasil");
          Serial.println("Silahkan memulai ulang sistem");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Semua kartu telah");
          lcd.setCursor(0,1);
          lcd.print("Terhapus");
          delay(3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Silahkan mulai ulang");
          lcd.setCursor(0,1);
          lcd.print("alat");
          delay(2000);
          lcd.clear();
        }
      }
    }
  }

    successRead = getID(); 
    
    ///////////////////////////////////// Untuk Pushbutton B ////////////////////////////
    if (digitalRead(wipeB) == LOW) { 
      digitalWrite(redLed, HIGH); 
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      Serial.println(F("Push Button B ditekan"));
      Serial.println(F("Master Card akan terhapus dalam 10 detik"));
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Master Card akan");
      lcd.setCursor(0,1);
      lcd.print("Dihapus dari sistem");
      lcd.setCursor(0,2);
      lcd.print("Dalam 10 detik");
      delay(10000);
      if (digitalRead(wipeB) == HIGH) {
        EEPROM.write(1, 0);
        Serial.println(F("Penghapusan berhasil"));                  
        Serial.println(F("Silahkan mulai ulang sistem"));
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Master Card telah");
        lcd.setCursor(0,1);
        lcd.print("Terhapus");
        delay(3000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Silahkan mulai ulang");
        lcd.setCursor(0,1);
        lcd.print("alat");
        delay(2000);
        while (1);
      }
    }
    if (programMode) {
      cycleLeds();              
    }
    else {
      normalModeOn();     
    }
  }
  while (!successRead);

  /////////////////////////////// Masuk Program Mode //////////////////////////////
  if (programMode) {
    if ( isMaster(readCard) ) { 
      Serial.println(F("Master Card telah terdeteksi"));
      Serial.println(F("Keluar dari mode pengaturan"));
      Serial.println(F("-----------------------------"));
      programMode = false;
      lcd.clear();
      return;
    }
    else {
      if ( findID(readCard) ) { 
        Serial.println(F("Sistem mengetahui ID, mulai menghapus ID"));
        deleteID(readCard);
        Serial.println("-----------------------------");
        Serial.println(F("Silahkan scan kartu untuk menambahkan dan menghapus ID dari sistem"));
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Kartu telah Dihapus");
        lcd.setCursor(0,1);
        lcd.print("dari sistem");
        delay(1500);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Silahkan tap kartu");
        lcd.setCursor(0,1);
        lcd.print("Untuk menambahkan ");
        lcd.setCursor(0,2);
        lcd.print("      Atau");
        lcd.setCursor(0,3);
        lcd.print("Untuk Menghapus");

      }
      else {                    
        Serial.println(F("Sistem tidak mengetahui ID, mulai menambahkan ID"));
        writeID(readCard);
        Serial.println(F("-----------------------------"));
        Serial.println(F("Silahkan scan kartu untuk menambahkan dan menghapus ID dari sistem"));
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Kartu telah Ditambah");
        lcd.setCursor(0,1);
        lcd.print("pada sistem");
        delay(1500);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Silahkan tap kartu");
        lcd.setCursor(0,1);
        lcd.print("Untuk menambahkan ");
        lcd.setCursor(0,2);
        lcd.print("      Atau");
        lcd.setCursor(0,3);
        lcd.print("Untuk Menghapus");
      }
    }
  }
  else {
    if ( isMaster(readCard)) {   
      programMode = true;
      Serial.println(F("Selamat datang di mode pengaturan"));
      uint8_t count = EEPROM.read(0);   
      Serial.print(F("Ada "));     
      Serial.print(count);
      Serial.print(F(" ID di dalam sistem"));
      Serial.println("");
      Serial.println(F("Silahkan scan kartu untuk menambahkan dan menghapus ID dari sistem"));
      Serial.println(F("Silahkan scan Master Card ulang untuk keluar dari mode pengaturan"));
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Silahkan Tap Kartu");
      lcd.setCursor(0,1);
      lcd.print("Untuk menambahkan ");
      lcd.setCursor(0,2);
      lcd.print("      Atau");
      lcd.setCursor(0,3);
      lcd.print("Untuk Menghapus");
      Serial.println(F("-----------------------------"));
    }
    else {

      if ( findID(readCard) && hasilIRkeluar==0){
        Serial.println(F("Selamat Tinggal"));
        goodbye();
        return;
      }

      if ( findID(readCard) && slot==0 && hasilIRmasuk==0){
        Serial.println(F("Parkir Penuh"));
        full();
        return;
      }

      if ( findID(readCard) && slot>0 && hasilIRmasuk==0 ){ 
        Serial.println(F("Selamat Datang"));
        granted();
        return;
      }
      else {      
        Serial.println(F("Akses Ditolak"));
        denied();
      }
    }
  }
}

///////////////////////////////////////// Masuk Parkir //////////////////////////////////////
void granted (){
  slot=slot-1;
  Portal1.write(0);
  digitalWrite(whiteLed, HIGH);
  digitalWrite(blueLed, LOW);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("   Selamat datang  ");
  delay(3500);
  Portal1.write(90);
  digitalWrite(whiteLed, LOW);
  lcd.clear();  
}

///////////////////////////////////////// Akses ditolak ////////////////////////////////////
void denied() {
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("   Akses Ditolak ");
  delay(3500);
  lcd.clear();
}

///////////////////////////////////////// Parkir Penuh ////////////////////////////////////////
void full() {
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("   Parkir Penuh  ");
  delay(3500);
  lcd.clear();
}

///////////////////////////////////////// Keluar Parkir //////////////////////////////////////////
void goodbye() {
  slot=slot+1;
  Portal2.write(0);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(blueLed, LOW);
  delay(3500);
  Portal2.write(90);
  digitalWrite(yellowLed, LOW);
}

///////////////////////////////////////// scan kartu pada module RFID ///////////////////////////////////
uint8_t getID() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()) { 
    return 0;
  }
  Serial.println(F("ID yang terbaca:"));
  for ( uint8_t i = 0; i < 4; i++) { 
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
  }
  Serial.println("");
  mfrc522.PICC_HaltA(); 
  return 1;
}

///////////////////////////////////////// Program Mode ///////////////////////////////////
void cycleLeds() {

  digitalWrite(blueLed, LOW);
  delay(100);
  digitalWrite(blueLed, HIGH);
  delay(100);
  delay(200);
}

//////////////////////////////////////// Normal Mode ////////////////////////////////////
void normalModeOn () {
  digitalWrite(blueLed, HIGH);  
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  

  lcd.setCursor(0,0);
  lcd.print("Silahkan Tap Kartu");
  lcd.setCursor(0,1);
  lcd.print("Slot Tersedia =");
  lcd.setCursor(15,1);
  lcd.print(slot);

///////////////////////////////////////// Untuk Sensor IR //////////////////////////////
  hasilIR1 = digitalRead(ir1);
  hasilIR2 = digitalRead(ir2);
  hasilIR3 = digitalRead(ir3);
  hasilIR4 = digitalRead(ir4);
  hasilIR5 = digitalRead(ir5);
  hasilIR6 = digitalRead(ir6);
  hasilIR7 = digitalRead(ir7);
  hasilIR8 = digitalRead(ir8);
  hasilIR9 = digitalRead(ir9);
  hasilIR10 = digitalRead(ir10);
  hasilIRmasuk = digitalRead(irMasuk);
  hasilIRkeluar = digitalRead(irKeluar);

  //Untuk Slot parkir 1   
      if(hasilIR1==1){          
          lcd.setCursor(0,2);
          lcd.print("A1"); 
      }
      if(hasilIR1==0){
          lcd.setCursor(0,2);
          lcd.print("  ");
      }

  //Untuk Slot parkir 2   
      if(hasilIR2==1){          
          lcd.setCursor(0,3);
          lcd.print("A2"); 
      }
      else{
          lcd.setCursor(0,3);
        lcd.print("  ");
      }

  //Untuk Slot parkir 3   
      if(hasilIR3==1){          
          lcd.setCursor(3,2);
          lcd.print("A3"); 
      }
      else{
          lcd.setCursor(3,2);
        lcd.print("  ");
      }

  //Untuk Slot parkir 4   
      if(hasilIR4==1){          
          lcd.setCursor(3,3);
          lcd.print("A4"); 
      }
      else{
          lcd.setCursor(3,3);
          lcd.print("  ");
      }

  //Untuk Slot parkir 5   
      if(hasilIR5==1){          
          lcd.setCursor(6,2);
        lcd.print("A5"); 
      }
      else{
          lcd.setCursor(6,2);
          lcd.print("  ");
      }

    //Untuk Slot parkir 6   
      if(hasilIR6==1){          
          lcd.setCursor(10,2);
          lcd.print("B1"); 
      }
      else{
          lcd.setCursor(10,2);
          lcd.print("  ");
      }

  //Untuk Slot parkir 7   
      if(hasilIR7==1){          
          lcd.setCursor(10,3);
          lcd.print("B2"); 
      }
      else{
          lcd.setCursor(10,3);
          lcd.print("  ");
      }

  //Untuk Slot parkir 8   
      if(hasilIR8==1){          
          lcd.setCursor(13,2);
          lcd.print("B3"); 
      }
      else{
          lcd.setCursor(13,2);
          lcd.print("  ");
      }

  //Untuk Slot parkir 9   
      if(hasilIR9==1){          
          lcd.setCursor(13,3);
          lcd.print("B4"); 
      }
      else{
          lcd.setCursor(13,3);
          lcd.print("  ");
      }

  //Untuk Slot parkir 10   
      if(hasilIR10==1){          
          lcd.setCursor(16,2);
          lcd.print("B5"); 
      }
      else{
          lcd.setCursor(16,2);
          lcd.print("  ");
      }

}

//////////////////////////////////////// Untuk sensor infrared saat pertama dinyalakan /////////////////////////////////
void Readsensor(){


if(digitalRead(ir1) == 0){S1=1;}
if(digitalRead(ir2) == 0){S2=1;}
if(digitalRead(ir3) == 0){S3=1;}
if(digitalRead(ir4) == 0){S4=1;}
if(digitalRead(ir5) == 0){S5=1;}
if(digitalRead(ir6) == 0){S6=1;}
if(digitalRead(ir7) == 0){S7=1;}
if(digitalRead(ir8) == 0){S8=1;}
if(digitalRead(ir9) == 0){S9=1;}
if(digitalRead(ir10) == 0){S10=1;}
}

//////////////////////////////////////// Mendapatkan ID dari EEPROM //////////////////////////////
void readID( uint8_t number ) {
  uint8_t start = (number * 4 ) + 2;    
  for ( uint8_t i = 0; i < 4; i++ ) {     
  storedCard[i] = EEPROM.read(start + i);   
  }
}

///////////////////////////////////////// menambahkan ID ke EEPROM ///////////////////////////////////
void writeID( byte a[] ) {
  if ( !findID( a ) ) {     
    uint8_t num = EEPROM.read(0);
    uint8_t start = ( num * 4 ) + 6;  
    num++;             
    EEPROM.write( 0, num );     
    for ( uint8_t j = 0; j < 4; j++ ) {   
      EEPROM.write( start + j, a[j] ); 
    }
    successWrite();
    Serial.println(F("Berhasil menambahkan ID ke sistem"));
  }
  else {
    failedWrite();
    Serial.println(F("Gagal menambahkan ID ke sistem"));
  }
}

///////////////////////////////////////// Menghapus ID dari EEPROM ///////////////////////////////////
void deleteID( byte a[] ) {
  if ( !findID( a ) ) { 
    failedWrite();     
    Serial.println(F("Gagal menghapus ID dari sistem"));
  }
  else {
    uint8_t num = EEPROM.read(0);   
    uint8_t slot;       
    uint8_t start;      
    uint8_t looping;    
    uint8_t j;
    uint8_t count = EEPROM.read(0); 
    slot = findIDSLOT( a );  
    start = (slot * 4) + 2;
    looping = ((num - slot) * 4);
    num--;      
    EEPROM.write( 0, num ); 
    for ( j = 0; j < looping; j++ ) {       
      EEPROM.write( start + j, EEPROM.read(start + 4 + j)); 
    }
    for ( uint8_t k = 0; k < 4; k++ ) {      
      EEPROM.write( start + j + k, 0);
    }
    successDelete();
    Serial.println(F("Berhasil menghapus ID dari sistem"));
  }
}

///////////////////////////////////////// pengecekan Bytes ///////////////////////////////////
boolean checkTwo ( byte a[], byte b[] ) {
  if ( a[0] != 0 )     
    match = true;     
  for ( uint8_t k = 0; k < 4; k++ ) {  
    if ( a[k] != b[k] )    
      match = false;
  }
  if ( match ) {     
    return true;      
  }
  else  {
    return false;     
  }
}

///////////////////////////////////////// menemukan slot ///////////////////////////////////
uint8_t findIDSLOT( byte find[] ) {
  uint8_t count = EEPROM.read(0);      
  for ( uint8_t i = 1; i <= count; i++ ) {   
    readID(i);                
    if ( checkTwo( find, storedCard ) ) {   
      return i;        
      break;         
    }
  }
}

///////////////////////////////////////// Mendapatkan ID dari EEPROM ///////////////////////////////////
boolean findID( byte find[] ) {
  uint8_t count = EEPROM.read(0);  
  for ( uint8_t i = 1; i <= count; i++ ) { 
    readID(i);      
    if ( checkTwo( find, storedCard ) ) {   
      return true;
      break;  
    }
    else {   
    }
  }
  return false;
}

///////////////////////////////////////// berhasil menyimpan ke EEPROM ///////////////////////////////////

void successWrite() {
  digitalWrite(blueLed, LOW);   
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  
  delay(200);
  digitalWrite(greenLed, HIGH);  
  delay(200);
  digitalWrite(greenLed, LOW); 
  delay(200);
  digitalWrite(greenLed, HIGH); 
  delay(200);
  digitalWrite(greenLed, LOW);  
  delay(200);
  digitalWrite(greenLed, HIGH);  
  delay(200);
}

///////////////////////////////////////// gagal menyimpan ke EEPROM ///////////////////////////////////

void failedWrite() {
  digitalWrite(blueLed, LOW);   
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW); 
  delay(200);
  digitalWrite(redLed, HIGH);   
  delay(200);
  digitalWrite(redLed, LOW);  
  delay(200);
  digitalWrite(redLed, HIGH);  
  delay(200);
  digitalWrite(redLed, LOW);  
  delay(200);
  digitalWrite(redLed, HIGH);  
  delay(200);
}

///////////////////////////////////////// berhasil menghapus ID dari EEPROM ///////////////////////////////////

void successDelete() {
  digitalWrite(blueLed, LOW);  
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW); 
  delay(200);
  digitalWrite(greenLed, HIGH);  
  delay(200);
  digitalWrite(greenLed, LOW);
  delay(200);
  digitalWrite(greenLed, HIGH); 
  delay(200);
  digitalWrite(greenLed, LOW); 
  delay(200);
  digitalWrite(greenLed, HIGH); 
  delay(200);
}

/////////////////////////////////////////// pengecekan ID yang terbaca apakah Mastercard //////////////////////
boolean isMaster( byte test[] ) {
  if ( checkTwo( test, masterCard ) )
    return true;
  else
    return false;
}