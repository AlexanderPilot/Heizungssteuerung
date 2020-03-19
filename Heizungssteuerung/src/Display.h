/***************************************************************************
 * Header für die Verwendung des Nextion Displays
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

/* Weitere Bibliotheken */
#include <Arduino.h>
#include "Settings.h"

class disp
{
  public:
    disp(void);
    void initialize(void);

    uint16_t getSetpointTemperaturFromDisplay(void);
    void setSetpointTemperaturToDisplay(uint16_t tempSetpoint);
    
    void setHeaterStatusToDisplay(bool symHeaterOn);

    void setHeaterMode(uint8_t heaterMode);

    void setTempThd(uint8_t tempThd);

    void setRoomTemp(uint8_t tempRoom);

    uint32_t getDate(void);
    void setDate(uint32_t date);

    uint16_t getTime(void);
    void setTime(uint16_t time);
    
    void setDaySymbol(bool daySymbol);

    void setTest(uint32_t testVar);
    
  private:
    uint16_t _tempSetpoint;
    boolean _symHeaterOn;
    uint8_t _heaterMode;
    uint8_t _tempThd;
    uint8_t _tempRoom;
    uint32_t _date;
    uint16_t _time;
    bool _daySymbol;
};
