                            //DICHIARAZIONE LED
int ledRosso;
int ledGiallo;
int ledBianco;
int ledVerde;
                            //DICHIARAZIONE DURATA ACCENSIONE LED
int durataR;
int durataG;
int durataB;
int durataV;

void setup() {
                            //ASSEGNAZIONE LED
  ledRosso  = 13;
  ledGiallo = 11;
  ledBianco = 7;
  ledVerde  = 5;
                            //PINMODE
  pinMode(ledRosso, OUTPUT);
  pinMode(ledGiallo, OUTPUT);
  pinMode(ledBianco, OUTPUT);
  pinMode(ledVerde, OUTPUT);
                            //SERIALE
  Serial.begin(9600);
  durataR = inputSeriale("Quanti secondi deve durare il led rosso?", durataR);
  durataG = inputSeriale("Quanti secondi deve durare il led giallo?", durataG);
  durataB = inputSeriale("Quanti secondi deve durare il led bianco?", durataB);
  durataV = inputSeriale("Quanti secondi deve durare il led verde?", durataV);
}

int inputSeriale(String frase, int var){
  Serial.println(frase);
  while (Serial.available() == 0) {};
  String var1 = Serial.readString();
  Serial.println(var1);
  var = var1.toInt() * 1000;
  return var;
}

void accendiLed(int led_on, int led_off, int ritardo){
  digitalWrite(led_on, HIGH);
  digitalWrite(led_off, LOW);
  delay(ritardo);
}

void loop() {
  accendiLed(ledRosso, ledVerde, durataR);
  accendiLed(ledGiallo, ledRosso, durataG);
  accendiLed(ledBianco, ledGiallo, durataB);
  accendiLed(ledVerde, ledBianco, durataV);
}
