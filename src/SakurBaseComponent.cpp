#include "SakurBaseComponent.h"

/* IMPLEMENTASI */
SakurBaseComponent::SakurBaseComponent () {
    // constructor
    this->setAdafruitOLED ();
}

SakurBaseComponent::~SakurBaseComponent () {
    // destrcutor
    delete m_adafruit;
}

void SakurBaseComponent::setupComponent () {
    pinMode (LED_ORI, OUTPUT);
    Serial.begin ( BOUND );

    /* set adafritoled */
    if (!this->adafruitOLED()->begin(SSD1306, PORT)) 
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);       
    }

    this->adafruitOLED()->clearDisplay();
}

void SakurBaseComponent::setAdafruitOLED () 
{
    this->m_adafruit = new Adafruit_SSD1306 (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
}

Adafruit_SSD1306 * SakurBaseComponent::adafruitOLED () const
{
    return this->m_adafruit;
}

void SakurBaseComponent::conditionLight ( int status, int firstDelay, int lastDelay )
{
    delay ( firstDelay );
    digitalWrite ( LED_ORI, status );
    delay ( lastDelay );
}

void SakurBaseComponent::viewTextToOLED ()
{
    this->plotTextToOLED ( "Edspert.Id", 2, 0, 5 );
    this->plotTextToOLED ( "Aman mas SON\"", 1.5, 20, 20 );
    this->plotTextToOLED ( "Make+Compile using:", 1.5, 30, 10 );
    this->plotTextToOLED ( "VSCode", 3, 42, 5 );
    this->displayText();
    
    delay(1000);
    this->clearDisplay();
}

void SakurBaseComponent::viewTextKahfiQiana()
{
    this->plotTextToOLED ("KAHFI", 2.5, 0, 20);
    this->plotTextToOLED ("QIANA", 2.5, 20, 20);
    this->plotTextToOLED ("SAKUR", 3, 40, 20);
    this->displayText();
    
    delay(2000);
    this->clearDisplay();
}

void SakurBaseComponent::viewTextWelcome()
{
    this->plotTextToOLED ("Welcome!", 2.5, 20, 10);
    this->displayText();

    delay (1000);
    this->clearDisplay();
}

void SakurBaseComponent::plotTextToOLED (String teks, float ukuran, int baris, int kolom )
{
    this->adafruitOLED()->setTextSize (ukuran);
    this->adafruitOLED()->setTextColor (WHITE);
    this->adafruitOLED()->setCursor (kolom, baris);
    this->adafruitOLED()->println(teks);
}

void SakurBaseComponent::displayText() {
    this->adafruitOLED()->display();
}

void SakurBaseComponent::clearDisplay() {
    this->adafruitOLED()->clearDisplay();
}

void SakurBaseComponent::lightUPTheLED()
{
    this->conditionLight ( 1, 100, 100 );
    this->conditionLight ( 0, 0, 50 );
    this->conditionLight ( 1, 0, 100 );
    this->conditionLight ( 0, 0, 50 );
    this->conditionLight ( 1, 0, 100 );
}
