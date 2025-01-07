/*const int MAXN = 1842;
volatile byte arr[MAXN];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  srand(analogRead(A0));
  for (int i = 1; i < MAXN; ++i) {
    long long ini = micros();
    for (int j = 0; j < 20; ++j) {
      for (int k = 0; k < i; ++k) {
        ++arr[k];
      }
    }
    long long end = micros();
    Serial.print(i);
    Serial.print(", ");
    Serial.println((double)(end - ini));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}*/
#include "arr.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  srand(analogRead(A0));
  for (int i = 1; i < MAXN; i+=1) {
    byte chcksum = 1;
    long long ini = micros();
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < i; ++k) {
        byte add; memcpy_P(&add, &arrays[k], sizeof add);
        chcksum ^= add;
      }
    }
    long long end = micros();
    Serial.println(chcksum);
    //Serial.println(freeMemory());
    Serial.print(i);
    Serial.print(", ");
    Serial.println((double)(end - ini));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

