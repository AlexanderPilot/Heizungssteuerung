/***************************************************************************
 * Header für den Automatikmodus
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

/* Weitere Bibliotheken */
#include <Arduino.h>
#include "EEPROM.h"
#include "Settings.h"

class schedule
{
  public:
    schedule();

    void readSchedule();
    uint16_t getSetPointTemperatureFromSchedule(uint8_t timeHour, uint8_t timeMinute);
    
    void setStartTime(uint8_t startHour, uint8_t startMinute);
    void setEndTime(uint8_t endHour, uint8_t endMinute);

    void saveToEEPROM();
    void loadFromEEPROM();
    
  private:
    uint8_t _schedule[7][13][2]; //Wochentage, Schaltpunkte (Vorhalt für 3 Schaltungen), Temperatur
    uint8_t _weekday;
    uint8_t _startHour;
    uint8_t _endHour;
    uint8_t _startMinute;
    uint8_t _endMinute;

    settings *_scheduleSettings;
};
