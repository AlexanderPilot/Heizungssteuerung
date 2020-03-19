/* Funktionen Heizung */

/* Einbinden von Headerdateien */
#include "Heizung.h"

heizung::heizung(void)
{
  
}

void heizung::calculateHeater(uint16_t tempRoom, uint16_t tempSetpoint)
{
  int16_t tempDiff;
  uint16_t tempDiffAbs;
  
  //Berechnung Temperaturdifferenz Wunsch zu Ist
  tempDiff = tempSetpoint - tempRoom;
  /* positiv --> Wunsch größer als Raumtemperatur --> Heizung an
  * negativ --> Raum größer als Wunschtemperatur --> Heizung aus
  */

  //Berechnung Betrag der Temperaturdifferenz
  tempDiffAbs= abs(tempDiff);

  //Entscheidung ob Temperaturdifferenz Einfluss auf Heizung haben soll
  if(tempDiffAbs >= TEMP_THD)
      {
        if(tempDiff > 0)
        {
          _DEBUG_PRINTLN("Wunschtemperatur größer als Raumtemperatur");
          this->turnOn(true);
        }
        else
        {
          _DEBUG_PRINTLN("Raumtemperatur größer als Wunschtemperatur");
          this->turnOn(false);
        }
      }
}

void heizung::turnOn(bool on_off)
{
  /* Aktivierung des Relais
 * Heizung am NO Ausgang des Relais anschließen
 * Ausgang = HIGH --> Heizung aus
 * Ausgang = LOW --> Heizung an
 */
  if(on_off == true)
  {
    digitalWrite(PIN_RELAIS,HEIZUNG_AN);
    _DEBUG_PRINTLN("Heizung ein");
  }
  else
  {
    digitalWrite(PIN_RELAIS,!HEIZUNG_AN);
    _DEBUG_PRINTLN("Heizung aus");
  }
}
