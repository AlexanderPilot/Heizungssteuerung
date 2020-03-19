/* Funktionen Automatikmodus */

/* Einbinden von Headerdateien */
#include "Schedule.h"

schedule::schedule(void)
{
  _scheduleSettings = new settings();
  //Default Initialbedatung (keine Schaltungen vorhanden)
  
}

void schedule::readSchedule()
{
  _DEBUG_PRINTLN("Übersicht Zeitplan");

  
}

void schedule::setStartTime(uint8_t startHour, uint8_t startMinute)
{
  
}

void schedule::setEndTime(uint8_t endHour, uint8_t endMinute)
{
  
}

void schedule::saveToEEPROM()
{
  _DEBUG_PRINTLN("Zeitplan wurde erfolgreich auf den EEPROM gespeichert");
}

void schedule::loadFromEEPROM()
{
  _DEBUG_PRINTLN("Zeitplan wurde erfolgreich vom EEPROM gelesen");
}
