                            //DICHIARAZIONE LED
int ledRosso;
int ledGiallo;
int ledBianco;
int ledVerde;
                            //DICHIARAZIONE DURATA ACCENSIONE LED E CICLI
int durataR;
int durataG;
int durataB;
int durataV;
int cicli;
int richiesta;

void setup() {
                            //ASSEGNAZIONE LED E RICHIESTA
  ledRosso  = 13;
  ledGiallo = 11;
  ledBianco = 7;
  ledVerde  = 5;
  richiesta = 0;
                            //PINMODE
  pinMode(ledRosso, OUTPUT);
  pinMode(ledGiallo, OUTPUT);
  pinMode(ledBianco, OUTPUT);
  pinMode(ledVerde, OUTPUT);
                            //SERIALE ED INPUT DEI CICLI
  Serial.begin(9600);
  Serial.println("Dopo quanti cicli si deve resettare il tempo?");
  while(Serial.available() == 0) {};
  cicli = Serial.readString().toInt();
  Serial.println(cicli);
}

int inputSeriale(String frase, int var){
  var = random(1,5) * 1000;
  Serial.println(frase + (var / 1000));
  return var;
}

void accendiLed(int led_on, int led_off, int ritardo){
  digitalWrite(led_on, HIGH);
  digitalWrite(led_off, LOW);
  delay(ritardo);
}

void loop() {
  if (cicli == richiesta)                 //VALORI RANDOM DI DURATE
  {
    Serial.println("Nuove durate:");
    durataR = inputSeriale("Secondi durata rosso: ", durataR);
    durataG = inputSeriale("Secondi durata giallo: ", durataG);
    durataB = inputSeriale("Secondi durata bianco: ", durataB);
    durataV = inputSeriale("Secondi durata verde: ", durataV);
    richiesta = 0;
  }
  richiesta++;
  accendiLed(ledRosso, ledVerde, durataR);
  accendiLed(ledGiallo, ledRosso, durataG);
  accendiLed(ledBianco, ledGiallo, durataB);
  accendiLed(ledVerde, ledBianco, durataV);
}
