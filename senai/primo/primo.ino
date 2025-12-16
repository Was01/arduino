#define led_vermelho 8
#define led_verde 9

void setup()
{
     pinMode(led_vermelho, OUTPUT);
     pinMode(led_verde, OUTPUT);
     Serial.begin(9600);
     Serial.println("Aguardando numero...");

     // Garante que ambos os LEDs estao desligados
     digitalWrite(led_vermelho, LOW);
     digitalWrite(led_verde, LOW);
}

void loop() {
    // Verifica se algum dado esta disponivel
    if (Serial.available() > 0) {
        // Le o proximo numero inteiro enviado pela serial
        int num = Serial.parseInt(); 
        
        // Limpa o buffer serial apos a leitura
        while(Serial.available()) {
            Serial.read();
        }

        Serial.print("Numero recebido: ");
        Serial.println(num);

        // --- Inicio da Verificacao de Primo ---
        
        // 0 e 1 nao sao primos por definicao
        if (num <= 1) {
            Serial.println("Nao e numero primo (<= 1)");
            digitalWrite(led_vermelho, HIGH); // Liga Vermelho
            digitalWrite(led_verde, LOW);
            return; // Sai do loop para aguardar a proxima entrada
        }
        
        // 2 e o unico numero primo par
        if (num == 2) {
            Serial.println("Numero primo (2)");
            digitalWrite(led_vermelho, LOW);
            digitalWrite(led_verde, HIGH); // Liga Verde
            return;
        }
        
        int primo = 1; // Assume que e primo (1)
        
        // O loop for e otimizado para ir ate a raiz quadrada de num,
        // mas o codigo original ia ate num - 1, o que tambem funciona, 
        // mas e menos eficiente. Mantenho a estrutura original (ate < num)
        // para maior clareza com base no seu codigo.
        
        for(int divisor = 2; divisor < num; divisor++) {
            // Se o resto da divisao for 0, o numero nao e primo
            if (num % divisor == 0) {
                primo = 0; // Define como nao primo
                break;     // Nao precisa testar mais divisores
            }
        }
        
        // --- Fim da Verificacao de Primo ---
        
        // Verifica o resultado final APOS o loop for
        if (primo == 1) {
            Serial.println("Numero primo!");
            digitalWrite(led_vermelho, LOW);
            digitalWrite(led_verde, HIGH); // Liga Verde
        } else {
            Serial.println("Nao e numero primo!");
            digitalWrite(led_vermelho, HIGH); // Liga Vermelho
            digitalWrite(led_verde, LOW);
        }
    }
    }


