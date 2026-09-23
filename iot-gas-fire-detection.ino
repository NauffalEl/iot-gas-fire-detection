#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C dengan alamat 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definisi
const int ledHijau = D7;
const int ledMerah = D8;
const int buzzer = D6;
const int sensorApi = D3;
const int sensorGas = A0;

// Nilai ambang batas untuk sensor gas (dapat disesuaikan sesuai sensor Anda)
const int gasThreshold = 300;

void setup() {
  // Inisialisasi pin
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorApi, INPUT);
  pinMode(sensorGas, INPUT);

  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Peringatan");
  delay(2000);  // Tunda 2 detik
  lcd.clear();
}

void loop() {
  // Membaca nilai sensor api
  int nilaiApi = digitalRead(sensorApi);
  // Membaca nilai sensor gas
  int nilaiGas = analogRead(sensorGas);

  // Cek apakah ada api atau gas
  if (nilaiApi == HIGH || nilaiGas > gasThreshold) {
    // Jika ada api atau gas, nyalakan LED merah dan buzzer, matikan LED hijau
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);
    digitalWrite(buzzer, HIGH);
    
    // Tampilkan peringatan di LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    if (nilaiApi == HIGH) {
      lcd.print("Deteksi Api!");
    }
    if (nilaiGas > gasThreshold) {
      lcd.setCursor(0, 1);
      lcd.print("Deteksi Gas!");
    }
  } else {
    // Jika tidak ada api atau gas, nyalakan LED hijau, matikan LED merah dan buzzer
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledMerah, LOW);
    digitalWrite(buzzer, LOW);

    // Tampilkan status aman di LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status: Aman");
  }

  delay(500);  // Tunda 500 ms sebelum membaca kembali
}
