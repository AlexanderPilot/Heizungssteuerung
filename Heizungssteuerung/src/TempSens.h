/***************************************************************************
 * Header für die Verwendung eines Temperatursensors
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

/* Weitere Bibliotheken */
#include <Arduino.h>
#include "Settings.h"

class sens
{
  public:
    sens();
    uint16_t getRoomTemp();
    
  private:
    uint16_t _tempRoom = 2300;
};
