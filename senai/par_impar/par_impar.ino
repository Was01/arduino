#define led_verde 9
#define led_vermelho 8


void setup()
{
  Serial.begin(9600);
  Serial.println("--- Verificador Par/Impar Arduino ---");
  Serial.println("Aguardando numero...");
  
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  
  // Garante que ambos os LEDs estao desligados ao iniciar
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW);
}

void loop()
{
  // Verifica se ha dados disponiveis para leitura
  if (Serial.available() > 0)
  {
    // Le o proximo numero inteiro (int) enviado pela serial.
    // Isso resolve o problema de ASCII vs. Valor.
    int num = Serial.parseInt(); 
    
    // IMPORTANTE: Limpa o buffer serial apos a leitura do numero.
    // Isso evita que o Arduino leia dados "antigos" ou o caracter de nova linha (newline).
    while(Serial.available()) {
        Serial.read();
    }

    Serial.print("Numero recebido: ");
    Serial.println(num);
    
    // --- Lógica de Par ou Ímpar ---
    if (num % 2 == 0)
    {
      Serial.println("PAR");
      digitalWrite(led_verde, HIGH);  // Liga LED Verde (Par)
      digitalWrite(led_vermelho, LOW);
    }
    else
    {
      Serial.println("IMPAR");
      digitalWrite(led_vermelho, HIGH); // Liga LED Vermelho (Ímpar)
      digitalWrite(led_verde, LOW);
    }
  }
}


