

// ########################
// #                      #
// # como criar arquivo   #
// ########################




/*


#include <SD.h>
File arquivoTXT;

void setup()
{
  Serial.begin(9600);
  SD.begin(10);      // o parametro e' o pino conectado ao CS do modulo
  
  arquivoTXT = SD.open("texto.txt", FILE_WRITE);
  if (arquivoTXT) {
    arquivoTXT.println("Teste de arquivos TXT em SD no Arduino");
    arquivoTXT.println("teste raphael");
     arquivoTXT.close();
    Serial.println("OK.");
  } else {
    Serial.println("Erro ao abrir ou criar o arquivo texto.txt.");
  }
}


void loop(void) { 
}

*/


// ########################
// #                      #
// # como ler um arquivo  #
// ########################

#include <SD.h>
File arquivoTXT;

void setup()
{
  Serial.begin(9600);
  SD.begin(10);

  arquivoTXT = SD.open("cliente1.txt");
  if (arquivoTXT) {
    while (arquivoTXT.available()) {
        Serial.write(arquivoTXT.read());
    }
    arquivoTXT.close();
  } else {
    Serial.println("Erro ao abrir o arquivo texto.txt");
  }
}

void loop(void) { 
}
