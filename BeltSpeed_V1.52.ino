
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// encoder output pulses per 600 degree encoder 1 revolution (measured manually)
#define ENC_COUNT_REV 600

// Encoder output to Arduino Interrupt pin. Tracks the pulse count.
#define ENC_IN_RIGHT_A 2

// Keep track of the number of right wheel pulses
volatile float right_wheel_pulse_count = 0;

// One-second interval for measurements
int interval = 1000;
unsigned long previousMillis3 = 0;
const long interval3 = 3000; // Interval to update the display

// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;
float ttime = 0;
int hours = 0;
int mins = 0 ;
int secs = 0 ;
float beltspeed = 0;
float mmin = 0;
// Variable for RPM measuerment
float rpm_right = 0;


void setup() {

  // Open the serial port at 9600 bps
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  // Set pin states of the encoder
  pinMode(ENC_IN_RIGHT_A , INPUT_PULLUP);
  // pinMode(ENC_IN_RIGHT_B , INPUT);

  // Every time the pin goes high, this is a pulse
  attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_A), right_wheel_pulse, RISING);

}

void loop() {

  // Record the time
  currentMillis = millis();
  unsigned long currentMillis2 = millis();
  unsigned long currentMillis3 = millis();
  // If one second has passed, print the number of pulses
  if (currentMillis - previousMillis > interval) {

    previousMillis = currentMillis;

    // Calculate revolutions per minute
    rpm_right = (float)(right_wheel_pulse_count * 60.00 / ENC_COUNT_REV);
    beltspeed = (float) (0.32) * rpm_right; // Belt Speed in m/s // (circumfrence of drum) * rpm
    mmin = (float) beltspeed / 60; // Belt Speed in m/min
    ttime = (float) 2.700 / beltspeed;
    int total = ttime; // In Seconds+

    mins = total / 60;
    secs = total % 60;
    mins = mins % 60;

    Serial.print(F(" Pulses: "));
    Serial.println(right_wheel_pulse_count);
    Serial.print(F(" Speed: "));
    Serial.print(rpm_right);
    Serial.println(" RPM");
    Serial.print (F("Belt Speed m/s :"));
    Serial.println(beltspeed);
    Serial.print (F("Belt Speed m/min :"));
    Serial.println(mins);
    Serial.print(F("Time to complete 2.7m (min) : "));
    Serial.print(mins);
    Serial.print(F(":"));
    Serial.println(secs);
    
    right_wheel_pulse_count = 0;

  }

  if (currentMillis3 - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis3;

    lcd.setCursor(4, 0);

    if (mins < 10) lcd.print("0");
    lcd.print(mins);

    lcd.print(":");

    if (secs < 10) lcd.print("0");
    lcd.print(secs);

    lcd.setCursor(0, 1);
    lcd.print(mmin);
    lcd.setCursor(5, 1);
    lcd.print(" m/min");

  }


}

// Increment the number of pulses by 1
void right_wheel_pulse() {

  right_wheel_pulse_count++;

}
