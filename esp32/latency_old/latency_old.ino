const int MAXN = 50000;
void setup() {
  // put your setup code here, to run once:
  setCpuFrequencyMhz(240); 
  Serial.begin(1000000);
  srand(analogRead(A0));
  for (int i = 1; i < MAXN; ++i) {
    int* arr = new int[i];
    long long ini = micros();
    for (int j = 0; j < 20; ++j) {
      for (int k = 0; k < i; ++k) {
        ++arr[k];
      }
    }
    long long end = micros();
    delete arr;
    Serial.print(i);
    Serial.print(", ");
    Serial.println((double)(end - ini));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
