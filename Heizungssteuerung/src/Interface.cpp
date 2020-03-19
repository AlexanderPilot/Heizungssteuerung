/* Funktionen Interface */

/* Einbinden von Headerdateien */
#include "Interface.h"

interface::interface(void)
{
  
}

uint16_t interface::getSetpointTemperatur()
{
  return _tempSetpoint;
}
