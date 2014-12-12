
//Define variaveis para os botaos
int b1 = 0;
int b2 = 0;
int b3 = 0;
int b4 = 0;
int b5 = 0;
int b6 = 0;

int cima = 0;
int baixo = 0;
int esq = 0;
int dir = 0;

int start = 0;
int select = 0;

int player = 1;

//Setup
//Configura os pinos como PULLUP - habilitando a resistencia interna pq aparentemente nossa resistencia nao funcionou;
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP); 

//Inicializa o Keyboard
  Keyboard.begin();
  
//Solta todas as teclas 'just in case'
  Keyboard.releaseAll();

if (!digitalRead(8)) {
  if (!digitalRead(7)) {
    player = 2;
  }
  if (!digitalRead(6)) {
    player = 3;
  }
  if (!digitalRead(5)) {
    player = 4;
  }



}


}


//Funcao que checa se a variavel 'button' esta LOW e responde com a telca 'k'
void check(int button, char k) {
   //se a variavel 'button' estiver LOW
  if(button==LOW){ 
    //Aperta o botao 'k'
    Keyboard.press(k);
  }
  //Se a variavel 'button' estiver HIGH
  else if (button==HIGH) {
    // Solta o botao 'k'
    Keyboard.release(k);
  }
}

//Loop!
void loop() {
  //Le o valor de cada Pino e atribui o valor pra variavel
  b1 = digitalRead(7);
  b2 = digitalRead(6);
  b3 = digitalRead(5);
  b4 = digitalRead(4);
  b5 = digitalRead(3);
  b6 = digitalRead(2);
  
  cima = digitalRead(11);
  baixo = digitalRead(13);
  esq = digitalRead(10);
  dir = digitalRead(12);
  
  start = digitalRead(8);
  select = digitalRead(9);
  
  
  // Chama a funcao para checar cada botao, passando o botao e a tecla de retorno como resposta

  if (player==1) {
    check(b1, 'q');
    check(b2, 'w');
    check(b3, 'e');
    check(b4, 'r');
    check(b5, 't');
    check(b6, 'y');
    
    check(cima, KEY_UP_ARROW);
    check(baixo, KEY_DOWN_ARROW);
    check(esq, KEY_LEFT_ARROW);
    check(dir, KEY_RIGHT_ARROW);
    check(start, KEY_F1);
    check(select, KEY_F2);
  }
  else if (player==2) {
    check(b1, 'a');
    check(b2, 's');
    check(b3, 'd');
    check(b4, 'f');
    check(b5, 'g');
    check(b6, 'h');
    
    check(cima, 'j');
    check(baixo, 'k');
    check(esq, 'l');
    check(dir, ';');
    check(start, KEY_F3);
    check(select, KEY_F4);
  }
  // Espera 10 milisegundos soh de onda
  delay(10);
}
