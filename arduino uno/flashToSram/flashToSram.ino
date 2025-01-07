const int MAXN = 1842;
const byte flash[MAXN];

void setup() {
  // put your setup code here, to run once:
  byte arr[MAXN];
  Serial.begin(2000000);
  srand(analogRead(A0));
  for (int i = 1; i < MAXN; ++i) {
    long long ini = micros();
    for (int j = 0; j < 20; ++j) {
      memcpy_P(arr, &(flash), (sizeof arr[0])*(long long)i);
    }
    long long end = micros();
    Serial.print(i);
    Serial.print(", ");
    Serial.println((double)(end - ini));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
