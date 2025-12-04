/**********************************************************************
  Filename    : Thermometer
  Description : Making a thermometer by thermistor.
  Author      : www.freenove.com
  Modification: 2024/06/19
**********************************************************************/
#define PIN_ANALOG_IN   4

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(PIN_ANALOG_IN);                       // leer ADC
  double voltage = (float)adcValue / 4095.0 * 3.3;                // calcular voltaje
  double Rt = 10 * voltage / (3.3 - voltage);                     // resistencia del termistor
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0); // temperatura en Kelvin
  double tempC = tempK - 273.15;                                  // temperatura en Celsius

  Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC\n", adcValue, voltage, tempC);

  // Verificación de temperatura
  if (tempC > 30.0) {
    Serial.println("// NOS ESTAMOS ASANDO //");
  }

  delay(1000);
}

