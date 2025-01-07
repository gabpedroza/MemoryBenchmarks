#include "tests.h"
/*
int* ar = new int[(int)len];
int* arr = new int[(int)len];
for(int i = 0; i < (int)len; ++i){
    ar[i] = i;
}
random_shuffle(ar, ar + (int)len);
int ind = ar[(int)len-1];
for(int i = 0; i < (int)len; ++i){
    arr[ind] = ar[i];
    ind = arr[ind];   
}
*/

int arr[MAXN];
void setup() {
  // put your setup code here, to run once:
  setCpuFrequencyMhz(240);
  srand(analogRead(A0));
  Serial.begin(1000000);
  for (int i = 0; i < 20; ++i) {
    int count = 0;
    long long ini = micros();
    for (int j = 0; j < 20; ++j) {
      for (int k = 0; arrays[i][k] != 0; k = arrays[i][k]) {
        ++count;
      }
    }
    count /= 20;
    ++count;
    long long end = micros();
    Serial.print(count);
    Serial.print(", ");
    Serial.println((double)(end - ini));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
