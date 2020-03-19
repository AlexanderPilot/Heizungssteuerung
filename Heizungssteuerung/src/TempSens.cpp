/* Funktionen Temperatursensor */

/* Einbinden von Headerdateien */
#include "TempSens.h"

sens::sens(void)
{
  
}

uint16_t sens::getRoomTemp()
{
  _DEBUG_PRINT("Raumtemperatur ausgelesen: ");
  _DEBUG_PRINTLN(_tempRoom);
  return _tempRoom;
}
