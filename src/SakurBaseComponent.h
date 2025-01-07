#ifndef SAKURCOMPONENT_H
#define SAKURCOMPONENT_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <iostream>
#include "SakurDefineComponent.h"

using namespace std;

/* DEFINISI CLASS */
class SakurBaseComponent
{
    public:
        SakurBaseComponent();
        ~SakurBaseComponent();

        void setupComponent ();
        void conditionLight ( int status, int firstDelay, int lastDelay );

        void setAdafruitOLED ();
        Adafruit_SSD1306 * adafruitOLED () const;
        
        void viewTextToOLED ();
        void viewTextKahfiQiana ();
        void viewTextWelcome ();
        void lightUPTheLED ();

        void plotTextToOLED (String teks, float ukuran,
                             int baris, int kolom );
        void displayText ();
        void clearDisplay();

        /* SENSOR LDR -- MASIH DIGABUNGKAN KARENA CODE HANYA SEDIKIT */

    private:
        Adafruit_SSD1306 * m_adafruit;

};

#endif