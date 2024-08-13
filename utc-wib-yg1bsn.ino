// YG1BSN - Adang Hidayat
// 2024/08/13
// jam digital yang ada hari, tanggal UTC dan WIB, temperatur juga sih, yang pakai RTC Modul dan tampilan ke LCD 20x4, pakai yang Arduino UNO
// Menjelang hari pramuka ke 63

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"

LiquidCrystal_I2C lcd(0X27, 20, 4);
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Ahad", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
byte char_temp[8]={B00100,B01010,B01010,B01110,B01110,B11111,B11111,B01110}; // icon thermometer

void setup()
{
  rtc.begin();
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,char_temp);
  lcd.setCursor(0, 0);        
  lcd.print("Halowwww Barayaaaa!");
  lcd.setCursor(0,3);
  lcd.print("de YG1BSN");
  delay(5000);
  lcd.clear();
  if (rtc.lostPower()) {
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop()
{ 
  DateTime now = rtc.now();
  //lcd.setCursor(column,row);
//------------------------------Tampilan Hari dan Tanggal-----------------------------//
  lcd.setCursor(0,0); 
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.setCursor(10,0);
  if (now.day() <=9 )
  { 
    lcd.print("0");
    lcd.setCursor (13,0);
    lcd.print(now.day(),DEC);
  }
  else {lcd.print(now.day(),DEC);}
  lcd.setCursor(12,0); 
  lcd.print("-");
  lcd.setCursor(13,0);
  if (now.month() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(14,0);
    lcd.print(now.month(),DEC);
  }
  else {lcd.print(now.month(),DEC);}
  lcd.setCursor(15,0); 
  lcd.print("-");
  lcd.setCursor(16,0); 
  lcd.print(now.year(),DEC);  
//------------------------------Tampilan UTC-----------------------------//
  lcd.setCursor(17,1);        
  lcd.print("UTC");  
  lcd.setCursor(8,1); 
  if (now.hour() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(9,1);
    lcd.print(now.hour(),DEC);
  }
  else {lcd.print(now.hour()-7,DEC);}
  lcd.setCursor(10,1); 
  lcd.print(":");
  lcd.setCursor(11,1);
  if (now.minute() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(12,1);
    lcd.print(now.minute(),DEC);
  }
  else {lcd.print(now.minute(),DEC);}
  lcd.setCursor(13,1); 
  lcd.print(":");
  lcd.setCursor(14,1); 
  
  if (now.second() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(15,1);
    lcd.print(now.second(),DEC);
  }
  else {lcd.print(now.second(),DEC);}
  //------------------------------Tampilan WIB-----------------------------//
  lcd.setCursor(17,2);
  lcd.print("WIB");
  lcd.setCursor(8,2);
  if (now.hour() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(9,2);
    lcd.print(now.hour(),DEC);
  }
  else {lcd.print(now.hour(),DEC);}
  lcd.setCursor(10,2);
  lcd.print(":");
  lcd.setCursor(11,2);
  if (now.minute() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(12,2);
    lcd.print(now.minute(),DEC);
  }
  else {lcd.print(now.minute(),DEC);}
  lcd.setCursor(13,2); 
  lcd.print(":");
  lcd.setCursor(14,2); 
  
  if (now.second() <=9 )
  {
    lcd.print("0");
    lcd.setCursor(15,2);
    lcd.print(now.second(),DEC);
  }
  else {lcd.print(now.second(),DEC);}
//------------------------------Tampilan Suhu-----------------------------//
  lcd.setCursor(0,3);
  lcd.print("YG1BSN");
  lcd.setCursor(11,3);
  lcd.print(rtc.getTemperature());
  lcd.setCursor(16,3);
  lcd.write((char)223);
  lcd.setCursor(17,3);
  lcd.print("C");
  lcd.setCursor(19,3);  
  lcd.print(char(0));
}

