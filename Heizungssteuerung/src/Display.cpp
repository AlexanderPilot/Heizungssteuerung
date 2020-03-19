/* Funktionen Display */

/* Einbinden von Headerdateien */
#include "Display.h"

disp::disp(void)
{
  
}

void disp::initialize(void)
{
  
}

uint16_t disp::getSetpointTemperaturFromDisplay(void)
{
  _DEBUG_PRINT("Wunschtemperatur vom Display ausgelesen: ");
  _DEBUG_PRINTLN(_tempSetpoint);
  return _tempSetpoint;
}

void disp::setSetpointTemperaturToDisplay(uint16_t tempSetpoint)
{
  _tempSetpoint = tempSetpoint;
  Serial.print("tempSetpoint.val=");
  Serial.print(_tempSetpoint);
  _DEBUG_PRINT("Wunschtemperatur am Display wird gesetzt auf: ");
  _DEBUG_PRINTLN(_tempSetpoint);
}

void disp::setHeaterStatusToDisplay(bool symHeaterOn)
{
  _symHeaterOn = symHeaterOn;
  _DEBUG_PRINT("Heizungssymbol am Display wird ");
  _DEBUG_PRINTLN(_symHeaterOn ? "aktiviert" : "deaktiviert");
}

void disp::setHeaterMode(byte heaterMode)
{
  _heaterMode = heaterMode;
  _DEBUG_PRINT("Steuerungsmodus am Display wird gesetzt auf: ");
  _DEBUG_PRINTLN(_heaterMode);
}

void disp::setTempThd(uint8_t tempThd)
{
  _tempThd = tempThd;
}

void disp::setRoomTemp(uint8_t tempRoom)
{
  Serial.print("tempRoom.val=");
  //Serial.print("n0.val=");
  Serial.print(tempRoom);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

uint32_t disp::getDate(void)
{
  _DEBUG_PRINT("Datum vom Display ausgelesen: ");
  _DEBUG_PRINTLN("to be implemented");
  return true;
}

void disp::setDate(uint32_t date)
{
  _DEBUG_PRINT("Datum am Display wird gesetzt auf: ");
  _DEBUG_PRINTLN("to be implemented");
}

uint16_t disp::getTime(void)
{
  _DEBUG_PRINT("Uhrzeit vom Display ausgelesen: ");
  _DEBUG_PRINTLN("to be implemented");
  return true;
}

void disp::setTime(uint16_t time)
{
  
  _DEBUG_PRINT("Uhrzeit am Display wird gesetzt auf: ");
  
  if(((time & 0xFF00)>>8) < 10)
  {
    _DEBUG_PRINT("0");
  } 
  _DEBUG_PRINT((time & 0xFF00)>>8);
  _DEBUG_PRINT(":");
  if((time & 0x00FF) < 10)
  {
    _DEBUG_PRINT("0");
  }
  _DEBUG_PRINTLN(time & 0x00FF);
}

void disp::setDaySymbol(bool daySymbol)
{
  
}

void disp::setTest(uint32_t testVar)
{
  Serial.print("tempRoom.val=");
  Serial.print(testVar);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
