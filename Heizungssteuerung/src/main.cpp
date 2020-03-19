#include "Display.h"
#include "TempSens.h"
#include "Interface.h"
#include "Settings.h"
#include "Heizung.h"
#include "Schedule.h"
#include <Wire.h>



//Objektdefinitionen
disp Display;
sens TempSens;
interface Interface;
settings Settings;
heizung Heizung;
ds3231 DS3231;
schedule Schedule1;

//globale Display Variablen
int dispTempRoom=1500;



/************************* Initialization Setup Function **************************/
void setup()
{
  /*Starten serielle Verbindung*/
  //_DEBUG_BEGIN(DEBUG_SERIAL_SPEED);
  Serial.begin(9600);
  /*Serial.println("Heizungssteuerung");
  Serial.println("Starte Initialisierung");
  _DEBUG_PRINTLN("Debugging Nachrichten aktiv");
  Serial.println("");
*/
  /*Initialisierung I2C*/
  Wire.begin();
  
  /*Initialisierung Pins*/
  pinMode(PIN_RELAIS,OUTPUT);

  /*Default Settings*/
/*
  Settings.setTempSetpoint(2200); //Temperatur um Faktor 100 multipliziert für Berechnungen
  Settings.setTempThd(100);       //beim Unterschied von 1°C zwischen Raum und Wunsch wird die Heizung aktiviert/deaktiviert
  Settings.setHeaterMode(0);      //manueller Modus beim Erststart
  Settings.setDate(1,1,2020);     //Datum: Tag, Monat, Jahr
  Settings.setTime(12,01);        //Uhrzeit: Stunde, Minute
  Settings.setDaySymbol(true);    //Tag Symbol anzeigen
  */
  /*Display initialisieren*/
  /*
  Display.setSetpointTemperaturToDisplay(Settings.getTempSetpoint());
  Display.setHeaterMode(Settings.getHeaterMode());
  Display.setDate(Settings.getDate());
  Display.setTime(Settings.getTime());
  Display.setDaySymbol(Settings.getDaySymbol());
*/
  
  //Serial.println("Initialisierung abgeschlossen");

//  Serial.println("");
}

void loop()
{
/*****************************************Variablendeklaration***************************************************/
  uint16_t tempRoom; //Raumtemperatur, wird vom Sensor gelesen
  /* Raumtemperatur
   * Wertebereich 0-65535
   * Zur Berechnung werden alle Temperaturen mit Faktor 100 verwendet (0 bis 655,35)
   */

  int16_t tempDiff;
  /* Temperaturdifferenz zwichen Raumtemperatur und Wunschtemperatur
   * Wertebereich -32768 - 32767
   * Zur Berechnung werden alle Temperaturen mit Faktor 100 verwendet (-327,68 bis +327,67)
   */
   
  uint16_t tempDiffAbs;
  /* Temperaturdifferenz absolut zwichen Raumtemperatur und Wunschtemperatur
   * Wertebereich 0-65535
   * Zur Berechnung werden alle Temperaturen mit Faktor 100 verwendet (0 bis 655,35)
   */

  uint8_t lastHeaterMode;

/*****************************************Heizungssteuerung***************************************************/

  /***dauerhafte Berechnung***/
  //Berechnung Temperaturdifferenz für Heizungssteuerung
  Heizung.calculateHeater(TempSens.getRoomTemp(),Settings.getTempSetpoint());
  
  //Abfrage ob Uhrzeit verändert ist. Falls ja neue Uhrzeit schrieben.
  if(Display.getTime() != Settings.getTime())
  {
    Display.setTime(Settings.getTime());
  }
  
  //Abfrage ob Datum verändert ist. Falls ja neues Datum schrieben.
  if(Display.getDate() != Settings.getDate())
  {
    Display.setDate(Settings.getDate());
  }

  //dispTempRoom = TempSens.getRoomTemp();
  Display.setTest(dispTempRoom);
  
  /***modusabhängige Berechnung***/
  switch(Settings.getHeaterMode())
  {
    case 0: //manueller Modus/konstant
      Display.setHeaterMode(0);
      Settings.setTempSetpoint(Display.getSetpointTemperaturFromDisplay()); //auslesen der Wunschtemperatur
      Display.setSetpointTemperaturToDisplay(Settings.getTempSetpoint());   //schreiben der Wunschtemperatur aufs Display
      break;
    case 1: //Automatikmodus/Zeitprogramm1
      Display.setHeaterMode(1);
      Settings.setTempSetpoint(Schedule.getSetPointTemperatureFromSchedule(Settings.getTime()); //ließt die Temp. aus dem Zeitprogramm mit der aktuellen Uhrzeit
      Display.setSetpointTemperaturToDisplay(Settings.getTempSetpoint());   //schreiben der Wunschtemperatur aufs Display
      break;
    case 4: //Ferien

      break;
    default:
      break;
  }

dispTempRoom++;
}
