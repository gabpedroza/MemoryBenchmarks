#include "arr.h"
void setup() {
  // put your setup code here, to run once:
  setCpuFrequencyMhz(240); 
  Serial.begin(1000000);
  srand(analogRead(A0));
  for (int i = 1; i < MAXN; i+=100) {
    int chcksum = 1;
    long long ini = micros();
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < i; ++k) {
        chcksum ^= arrays[k];
      }
    }
    long long end = micros();
    Serial.println(chcksum);
    Serial.print(i);
    Serial.print(", ");
    Serial.println((double)(end - ini));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
