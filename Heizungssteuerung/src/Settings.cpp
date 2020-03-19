/* Funktionen Settings */

/* Einbinden von Headerdateien */
#include "Settings.h"

settings::settings(void)
{
  
}

uint16_t settings::getTempSetpoint(void)
{
  _DEBUG_PRINT("Wunschtemperatur ausgelesen: ");
  _DEBUG_PRINTLN(_tempSetpoint);
  return _tempSetpoint;
}

void settings::setTempSetpoint(uint16_t tempSetpoint)
{
  _tempSetpoint = tempSetpoint;
  _DEBUG_PRINT("Wunschtemperatur gesetzt auf: ");
  _DEBUG_PRINTLN(_tempSetpoint);
}

uint8_t settings::getTempThd(void)
{
  return _tempThd;
}

void settings::setTempThd(uint8_t tempThd)
{
  _tempThd = tempThd;
}

uint8_t settings::getHeaterMode(void)
{
  _DEBUG_PRINT("Ausgelesener Heizmodus: ");
  _DEBUG_PRINTLN(_heaterMode);
  return _heaterMode;
}

void settings::setHeaterMode(uint8_t heaterMode)
{
  _heaterMode = heaterMode;
}

uint32_t settings::getDate(void)
{
  uint32_t tmpDate;
  Serial.println("Settings.getDate to be implemented");
  /*tmpDate = _year + _month<<16 + _day<<24;
  _DEBUG_PRINT("Datum: ");
  if(((tmpDate & 0xFF000000)>>24) < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINT((tmpDate & 0xFF000000)>>24);
  _DEBUG_PRINT(".");
  if(((tmpDate & 0x00FF0000)>>16) < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINT((tmpDate & 0x00FF0000)>>16);
  _DEBUG_PRINT(".");
  _DEBUG_PRINT((tmpDate & 0x0000FFFF));
  _DEBUG_PRINT(" --> ");
  _DEBUG_PRINTLN(tmpDate);*/
  return tmpDate;  
}

void settings::setDate(uint8_t day, uint8_t month, uint16_t year)
{
  this->setDay(day);
  this->setMonth(month);
  this->setYear(year);
  _DEBUG_PRINT("Datum wurde gesetzt: ");
  if(day < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINT(day);
  _DEBUG_PRINT(".");
  if(month < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINT(month);
  _DEBUG_PRINT(".");
  _DEBUG_PRINTLN(year);
}

uint16_t settings::getTime(void)
{
  uint16_t tmpTime;
  tmpTime = _minute + (_hour << 8);
  _DEBUG_PRINT("Uhrzeit: ");
  if(((tmpTime & 0xFF00)>>8) < 10)
  {
    _DEBUG_PRINT("0");
  } 
  _DEBUG_PRINT((tmpTime & 0xFF00)>>8);
  _DEBUG_PRINT(":");
  if((tmpTime & 0x00FF) < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINT(tmpTime & 0x00FF);
  _DEBUG_PRINT(" --> ");
  _DEBUG_PRINTLN(tmpTime);
  return tmpTime;
}

void settings::setTime(uint8_t hour, uint8_t minute)
{
  this->setHour(hour);
  this->setMinute(minute);
  _DEBUG_PRINT("Uhrzeit wurde gesetzt: ");
  if(hour < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINT(hour);
  _DEBUG_PRINT(":");
  if(minute < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINTLN(minute);
}

bool settings::getDaySymbol(void)
{
  return _daySymbol;
}

void settings::setDaySymbol(bool Day_on_off)
{
  _daySymbol = Day_on_off;
}

uint8_t settings::getDay(void)
{
  return _day;
}

void settings::setDay(uint8_t day)
{
  _day = day;
}

uint8_t settings::getMonth(void)
{
  return _month;
}

void settings::setMonth(uint8_t month)
{
  _month = month;
}

uint16_t settings::getYear(void)
{
  return _year;
}

void settings::setYear(uint16_t year)
{
  _year = year;
}

uint8_t settings::getHour(void)
{
  return _hour;
}

void settings::setHour(uint8_t hour)
{
  _hour = hour;
}

uint8_t settings::getMinute(void)
{
  return _minute;
}

void settings::setMinute(uint8_t minute)
{
  _minute = minute;
}

uint16_t settings::dec16ToBin(uint16_t dec16Num)
{
  int num = dec16Num;

  uint8_t bitsCount = sizeof( num ) * 8;
  char str[ bitsCount + 1 ];
  
  itoa( num, str, 2 );
  
  Serial.println( str );
}

uint8_t settings::dec8ToBin(uint8_t dec8Num)
{
  
}
