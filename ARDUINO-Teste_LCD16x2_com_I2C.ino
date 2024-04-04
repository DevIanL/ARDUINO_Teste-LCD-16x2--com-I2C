#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//DEFINIÇÕES

#define endereco 0x27 //ENDEREÇO ADIQUIRIDO ATRAVÉS DO SCANER I2C.
#define linhas 2 //QUANTIDADE DE LINHAS DO DISPLAY LCD.
#define colunas 16 //QUANTIDADE DE COLUNAS DO DIPLAY LCD.

//INSTANCIONANDO OBJETOS

LiquidCrystal_I2C lcd (endereco, colunas, linhas);

//DECLARAÇÕES DE VARIAVEIS

int piscar = 0;
int td = 0;
int coluna = 0;
int linha = 0;

void setup() 
{
  //PARA INICIAR O PROGRAMA DE FORMA CORRETA EVITANDO QUALQUER TIPO DE ERRO DE COMUNIÇÃO ENTRE O PROGRAMA E O DIPLAY COMEÇE POR:
  lcd.init(); //INICIA A COMUNICAÇÃO COM O LCD.
  lcd.backlight(); //LIGA A ILUMINAÇÃO DO DISPLAY.
  lcd.clear(); //LIMPA O DISPLAY.
  delay(3000); //QUANTIDADE DO TEMPO EM MILISEGUNDOS.

  // PISCAR 3 VEZES A TELA.
  while(piscar < 3)
  {
    lcd.backlight();
    delay(500);
    lcd.noBacklight(); //DESLIGA A ILUMINAÇÃO DO DISPLAY
    delay(500);
    piscar ++;
  }
  lcd.backlight();

  // EXIBIR A MENSAGEM NO DISPLAY, 
  lcd.print("MEU NOME E IAN!"); //EXIBE NA TELA A MENSAGEM AO SER DEFINIDA.
  lcd.setCursor(0, 1); /*DEFINE EM QUAL PARTE DO DISPALY A MENSAGEM SERÁ EXIBIDA, NESSE CASO A PRÓXIMA MENSAGEM SERÁ EXIBIDA NA COLUNA 0 LINHA 1.                                    
                          *OBS: A CONTAGEM DE LINHAS E COLUNAS NO DISPLAY DO LCD COMEÇA DO 0 E VAI ATÉ O 15
                      */    
  lcd.print("meu nome e ian!"); 
  delay(3000);
  lcd.clear();

  //TESTE DE FUNCIONAMENTO DE TODAS AS ÁREAS DO DISPLAY
  do
  {
    if(coluna <= 16)
    {
      lcd.print("$");
      delay(500);
      lcd.setCursor(coluna, linha);
      coluna ++;
    }else 
    { 
      coluna = coluna - 17;
      linha ++;
      while(coluna <= 16)
      {
        lcd.setCursor(coluna, linha);
        lcd.print("@");
        delay(500);
        coluna ++;
      } 
      lcd.clear();
      lcd.print("FIM DO PROGRAMA"); 
      delay(2000);
      lcd.clear();
      td ++;
    }
  }while(td < 1); 
  lcd.noBacklight();
}
void loop() 
{
  
  
}
