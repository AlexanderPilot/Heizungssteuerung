/***************************************************************************
 * Header für die Heizungssteuerung
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

#define HEIZUNG_AN HIGH


/* Weitere Bibliotheken */
#include <Arduino.h>
#include "Settings.h"

class heizung
{
  public:
    heizung();
    void calculateHeater(uint16_t tempRoom, uint16_t tempSetpoint);
    void turnOn(bool on_off);
    
  private:
     
};
