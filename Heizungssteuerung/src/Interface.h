/***************************************************************************
 * Header für das Benutzerinterface
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

/* Weitere Bibliotheken */
#include <Arduino.h>
#include "Settings.h"

class interface
{
  public:
    interface();
    uint16_t getSetpointTemperatur();
    
  private:
    uint16_t _tempSetpoint;
};
