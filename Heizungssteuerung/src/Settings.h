/***************************************************************************
 * Header für die Heizungseinstellungen
 *
 **************************************************************************/

/* Vermeidung Doppeldefinitionen */
#pragma once

/* Weitere Bibliotheken */
#include <Arduino.h>
#include <SoftwareSerial.h>


#define PIN_RELAIS 2
#define PIN_MODE 3
#define DEFAULT_LOW_TEMP 1800 //Temperatur um Faktor 100 erhöht
#define TEMP_THD 100
#define PIN_SWSER_TX 7
#define PIN_SWSER_RX 8
#define DEBUG_SERIAL_SPEED 9600
#define SERIAL_SPEED 9600

#define DEBUG_PRINT

#ifdef DEBUG_PRINT
  #define _DEBUG_BEGIN(x)       Serial.begin(x);
  #define _DEBUG_PRINT(x)       Serial.print(x);
  #define _DEBUG_PRINTLN(x)     Serial.println(x);
  #define _DEBUG_WRITE(x)       Serial.write(x);
#else
  #define _DEBUG_BEGIN(x)
  #define _DEBUG_PRINT(x)
  #define _DEBUG_PRINTLN(x)
  #define _DEBUG_WRITE(x)
#endif

#define PRINT_SEPARATOR         "-------------------------"
#define PRINT_SEPARATOR_LONG    "--------------------------------------------------"

class settings
{
  public:
    settings();
    uint16_t getTempSetpoint(void);
    void setTempSetpoint(uint16_t tempSetpoint);

    uint8_t getTempThd(void);
    void setTempThd(uint8_t tempThd);

    uint8_t getHeaterMode(void);
    void setHeaterMode(uint8_t tempThd);

    uint32_t getDate(void);
    void setDate(uint8_t day, uint8_t month, uint16_t year);

    uint16_t getTime(void);
    void setTime(uint8_t hour, uint8_t minute);

    bool getDaySymbol(void);
    void setDaySymbol(bool Day_on_off);
    
  private:
    uint8_t getDay(void);
    void setDay(uint8_t day);

    uint8_t getMonth(void);
    void setMonth(uint8_t month);

    uint16_t getYear(void);
    void setYear(uint16_t year);

    uint8_t getHour(void);
    void setHour(uint8_t hour);

    uint8_t getMinute(void);
    void setMinute(uint8_t minute);

    uint16_t dec16ToBin(uint16_t dec16Num);
    uint8_t dec8ToBin(uint8_t dec8Num);
    
    uint8_t _day;
    uint8_t _month;
    uint16_t _year;
    uint8_t _hour;
    uint8_t _minute;

    bool _daySymbol;
    
    uint16_t _tempSetpoint;
    /* Wunschtemperatur
   * Wertebereich 0-65535
   * Zur Berechnung werden alle Temperaturen mit Faktor 100 verwendet (0 bis 655,35)
   */
   
    uint8_t _tempThd;
    /* Temperaturschwelle, ab welcher Differenztemperatur die Heizung aktiviert/deaktiviert werden soll
   * Wertebereich 0 - 255
   * Zur Berechnung werden alle Temperaturen mit Faktor 100 verwendet (0 bis 2,55)
   */
    
    uint8_t _heaterMode;
    /* Modus der Heizung
   *  0 = manueller Modus
   *  1 = Automatikmodus
   *  Vorhalt für weiteren Modus
   */
};
