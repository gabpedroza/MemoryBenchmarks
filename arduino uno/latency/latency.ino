
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
#include"arr.h"
int arr[MAXN];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000);
  for (int i = 0; i < 17; ++i) {
    //memcpy_P(arr, (arrays[i]), sizeof arr);
    int count = 0;
    long long ini = micros();
    for (int j = 0; j < 20; ++j) {
      int k = 0;
      int add; memcpy_P(&add, &arrays[i][k], sizeof add);
      for (; add != 0; memcpy_P(&add, &arrays[i][k], sizeof add)) {
        k = add;
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
