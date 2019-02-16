int ledRosso;
int ledGiallo;
int ledBianco;
int ledVerde;
int durataR;
int durataG;
int durataB;
int durataV;

void setup() {
  // put your setup code here, to run once:
  ledRosso  = 13;
  ledGiallo = 11;
  ledBianco = 7;
  ledVerde  = 5;
  
  pinMode(ledRosso, OUTPUT);
  pinMode(ledGiallo, OUTPUT);
  pinMode(ledBianco, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  Serial.begin(9600);
  inputSeriale("Quanti secondi deve durare il led rosso?", durataR);
  inputSeriale("Quanti secondi deve durare il led giallo?", durataG);
  inputSeriale("Quanti secondi deve durare il led bianco?", durataB);
  inputSeriale("Quanti secondi deve durare il led verde?", durataV);
}


int inputSeriale(String frase, int var){
  Serial.println(frase);
  while (Serial.available() == 0) {};
  var = Serial.readString().toInt() * 1000;
  Serial.println(var + " secondi");
  return var;
}

void loop() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRosso, HIGH);
  delay(durataR);
  digitalWrite(ledRosso, LOW);
  digitalWrite(ledGiallo, HIGH);
  delay(durataG);
  digitalWrite(ledGiallo, LOW);
  digitalWrite(ledBianco, HIGH);
  delay(durataB);
  digitalWrite(ledBianco, LOW);
  digitalWrite(ledVerde, HIGH);
  delay(durataV);
}
