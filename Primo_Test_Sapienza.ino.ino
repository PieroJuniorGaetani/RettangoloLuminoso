#define p1 P1State
#define p2 P2State
#define p3 P3State
#define p4 P1State
#define p5 P1State
#define p6 P1State



//HC RS04 Sensore ultrasuoni p1
const int p1_triggerPort = 41;
const int p1_echoPort = 39;

//HC RS04 Sensore ultrasuoni p2
const int p2_triggerPort = 37;
const int p2_echoPort = 35;

//HC RS04 Sensore ultrasuoni p3
const int p3_triggerPort = 33;
const int p3_echoPort = 31;

//HC RS04 Sensore ultrasuoni p4
const int p4_triggerPort = 29;
const int p4_echoPort = 27;

//HC RS04 Sensore ultrasuoni p5
const int p5_triggerPort = 25;
const int p5_echoPort = 23;

//HC RS04 Sensore ultrasuoni p6
const int p6_triggerPort = 21;
const int p6_echoPort = 19;







int caso = 0; // Caso zero significa tutto spento
int personeTotali = 0;




//Inizializazione persona. ciascun pin rappresenta una persona ed il numero associato rappresenta la posizione di essa nello schema

 int P1B = 53; 
 int P2B= 51;
 int P3B = 49;
 int P4B = 47;
 int P5B = 45;
 int P6B = 43;

//----//

//Inizializzazion Group Led. Ciascun pin rappresenta un gruppo di led ed ogni numero rappresenta la il grupppo di esso nello schema

 int G0 = 22; 
 int G1 = 24;
 int G2 = 26;
 int G3 = 28;
 int G4 = 30;
 int G5 = 32;
 int G6 = 34;
 int G7 = 36;
 int G8 = 38;
 int G9 = 40;
 int G10 = 42;
 int G11 = 44;
 int G12 = 46;
 int G13 = 48;

//----//


//Inizializazione persona. ciascun pin rappresenta una persona ed il numero associato rappresenta la posizione di essa nello schema

int P1State = 0;
int P2State = 0;
int P3State = 0;
int P4State = 0;
int P5State = 0;
int P6State = 0;


//----//



void setup() {

  //Inizializzazione Pulsanti (B_utton) Persona come input (fase debugging)
  pinMode(P1B, INPUT);
  pinMode(P2B, INPUT);
  pinMode(P3B, INPUT);
  pinMode(P4B, INPUT);
  pinMode(P5B, INPUT);
  pinMode(P6B, INPUT);
  //----//

  //Inizializzazione Group come input
  pinMode(G0, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(G5, OUTPUT);
  pinMode(G6, OUTPUT);
  pinMode(G7, OUTPUT);
  pinMode(G8, OUTPUT);
  pinMode(G9, OUTPUT);
  pinMode(G10, OUTPUT);
  pinMode(G11, OUTPUT);
  pinMode(G12, OUTPUT);
  pinMode(G13, OUTPUT);
  //----//

  // setup trigger ultrasuoni 
  // P1
  pinMode(p1_triggerPort, OUTPUT);
  pinMode(p1_echoPort, INPUT);

    // P2
  pinMode(p2_triggerPort, OUTPUT);
  pinMode(p2_echoPort, INPUT);

    // P3
  pinMode(p3_triggerPort, OUTPUT);
  pinMode(p3_echoPort, INPUT);

    // P4
  pinMode(p4_triggerPort, OUTPUT);
  pinMode(p4_echoPort, INPUT);

  // P5
  pinMode(p5_triggerPort, OUTPUT);
  pinMode(p5_echoPort, INPUT);

    // P6
  pinMode(p6_triggerPort, OUTPUT);
  pinMode(p6_echoPort, INPUT);

  //----//
  
  Serial.begin(9600);

}

void loop() {

  funzionamentoButton();

  personeTotali = p1 + p2 + p3 + p4 + p5 + p6;
  if (personeTotali == 0){
    zero();
  }

  

  // print out the state of the button
  if (p1 == 0){
    digitalWrite(G0, HIGH);
    
  }else{
    delay(10); // Delay a little bit to improve simulation performance
    digitalWrite(G0, LOW);
  }

}


    
  

  void spento(){ 
       digitalWrite(G0, LOW);
       digitalWrite(G1, LOW);
       digitalWrite(G2, LOW);
       digitalWrite(G3, LOW);
       digitalWrite(G4, LOW);
       digitalWrite(G5, LOW);
       digitalWrite(G6, LOW);
       digitalWrite(G7, LOW);
       digitalWrite(G8, LOW);
       digitalWrite(G9, LOW);
       digitalWrite(G10, LOW);
       digitalWrite(G11, LOW);
       digitalWrite(G12, LOW);
       digitalWrite(G13, LOW);
  }

  //Algoritmo di funzionamento per riconoscimento di combinazione

  void zero(){
  spento();
  Serial.print("Caso [ 0 ] -");
  }

  void uno(){
    if (personeTotali == 1){
       caso = 0;
       Serial.print("Caso [ 1 ] -");
    }
  }


void verificaSituazione(){

//Gruppi di due persone
  
  //caso 2
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 2;
    Serial.print("Caso [ 2 ] -");
  }

    //caso 3
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 3;
    Serial.print("Caso [ 3 ] -");
  }

    //caso 4
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 4;
    Serial.print("Caso [ 4 ] -");
  }

    //caso 5
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 5;
    Serial.print("Caso [ 5 ] -");
  }

   //caso 6
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 1){
    caso = 6;
    Serial.print("Caso [ 6 ] -");
  }

    //caso 7
  if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 7;
    Serial.print("Caso [ 7 ] -");
  }

    //caso 8
  if (p1 == 0 && p2 == 2 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 6){
    caso = 8;
    Serial.print("Caso [ 8 ] -");
  }

      //caso 9
  if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 9;
    Serial.print("Caso [ 9 ] -");
  }

      //caso 10
  if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 10;
    Serial.print("Caso [ 10 ] -");
  }

      //caso 11
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 11;
    Serial.print("Caso [ 11 ] -");
  }

      //caso 12
  if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 1){
    caso = 12;
    Serial.print("Caso [ 12 ] -");
  }

      //caso 13
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 0){
    caso = 13;
    Serial.print("Caso [ 13 ] -");
  }

      //caso 14
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 14;
    Serial.print("Caso [ 14 ] -");
  }

      //caso 15
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 15;
    Serial.print("Caso [ 15 ] -");
  }

      //caso 16
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 16;
    Serial.print("Caso [ 16 ] -");
  }

      //caso 17
  if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 17;
    Serial.print("Caso [ 17 ] -");
  }

   // Gruppi da 3 //

      //caso 18
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 18;
    Serial.print("Caso [ 18 ] -");
  }

      //caso 19
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 19;
    Serial.print("Caso [ 19 ] -");
  }

      //caso 20
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 20;
    Serial.print("Caso [ 20 ] -");
  }

        //caso 21
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 1){
    caso = 21;
    Serial.print("Caso [ 21 ] -");
  }


        //caso 22
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 22;
    Serial.print("Caso [ 22 ] -");
  }


        //caso 23
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 23;
    Serial.print("Caso [ 23 ] -");
  }


        //caso 24
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 24;
    Serial.print("Caso [ 24 ] -");
  }


        //caso 25
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 25;
    Serial.print("Caso [ 25 ] -");
  }


        //caso 26
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 1){
    caso = 26;
    Serial.print("Caso [ 26 ] -");
  }


// ** IL caso che sarebbe dovuto essere 27 a causa di un errore di riscrittura è stato portato a caso 38 

        //caso 27
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 27;
    Serial.print("Caso [ 27 ] -");
  }


        //caso 28
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 1){
    caso = 28;
    Serial.print("Caso [ 28 ] -");
  }


        //caso 29
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 0){
    caso = 29;
    Serial.print("Caso [ 29 ] -");
  }


        //caso 30
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 30;
    Serial.print("Caso [ 30 ] -");
  }


        //caso 31
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 31;
    Serial.print("Caso [ 31 ] -");
  }


        //caso 32
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 32;
    Serial.print("Caso [ 32 ] -");
  }


        //caso 33
  if (p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0){
    caso = 33;
    Serial.print("Caso [ 33 ] -");
  }

          //caso 34
  if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 34;
    Serial.print("Caso [ 34 ] -");
  }

          //caso 35
  if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 35;
    Serial.print("Caso [ 35 ] -");
  }

          //caso 36
  if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 36;
    Serial.print("Caso [  ] -");
  }

          //caso 37
  if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 37;
    Serial.print("Caso [ 37 ] -");
  }

          //caso 38 **Sarebbe dovuto essere 27
  if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 0){
    caso = 38;
    Serial.print("Caso [ 38 ] -");
  }


  // Gruppi da 4 //

          //caso 39
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 0){
    caso = 39;
    Serial.print("Caso [ 39 ] -");
  }

          //caso 40
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 0){
    caso = 40;
    Serial.print("Caso [ 40 ] -");
  }

          //caso 41
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 0 && p6 == 1){
    caso = 41;
    Serial.print("Caso [ 41 ] -");
  }

          //caso 42
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 0){
    caso = 42;
    Serial.print("Caso [ 42 ] -");
  }

          //caso 43
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 43;
    Serial.print("Caso [ 43; ] -");
  }

  //A1

          //caso 44
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 44;
    Serial.print("Caso [ 44 ] -");
  }

          //caso 45
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 45;
    Serial.print("Caso [ 45 ] -");
  }

            //caso 46
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 46;
    Serial.print("Caso [  ] -");
  }

              //caso 47
  if (p1 == 1 && p2 == 0 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 47;
    Serial.print("Caso [ 47 ] -");
  }


              //caso 48
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 48;
    Serial.print("Caso [ 48 ] -");
  }

//END A

              //caso 49
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 49;
    Serial.print("Caso [ 49 ] -");
  }


              //caso 50
  if (p1 == 0 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 50;
    Serial.print("Caso [ 50 ] -");
  }


              //caso 51
  if (p1 == 0 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 51;
    Serial.print("Caso [ 51 ] -");
  }


              //caso 52
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 52;
    Serial.print("Caso [ 52 ] -");
    
                //caso 53
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 53;
    Serial.print("Caso [ 53 ] -");
  }

              //caso 54
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 0){
    caso = 54;
    Serial.print("Caso [ 54 ] -");
  }

  //Gruppi 5

                //caso 55
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 0){
    caso = 55;
    Serial.print("Caso [ 55 ] -");
  }

                //caso 56
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 0 && p6 == 1){
    caso = 56;
    Serial.print("Caso [ 56 ] -");
  }

                //caso 57
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 0 && p5 == 1 && p6 == 1){
    caso = 57;
    Serial.print("Caso [ 57 ] -");
  }

                //caso 58
  if (p1 == 1 && p2 == 1 && p3 == 0 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 58;
    Serial.print("Caso [ 58 ] -");
  }

                //caso 59
  if (p1 == 1 && p2 == 0 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 59;
    Serial.print("Caso [ 59 ] -");
  }

                //caso 60
  if (p1 == 0 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 60;
    Serial.print("Caso [ 60 ] -");
  }

                //caso 61
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 61;
    Serial.print("Caso [ 61 ] -");
  }

  // Gruppo di 6

                //caso 62
  if (p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1 && p5 == 1 && p6 == 1){
    caso = 62;
    Serial.print("Caso [ 62 ] -");
  }


  
  }
  
  
  

}







  

  void funzionamentoButton(){
      // read the input pin button
  P1State = digitalRead(P1B);
  P2State = digitalRead(P2B);
  P3State = digitalRead(P3B);
  P4State = digitalRead(P4B);
  P5State = digitalRead(P5B);
  P6State = digitalRead(P6B);
  
  }

  void funzionamentoUltrasuoni(){
    P1UltrasuoniHCRS04();
    P2UltrasuoniHCRS04();
    P3UltrasuoniHCRS04();
    P4UltrasuoniHCRS04();
    P5UltrasuoniHCRS04();
    P6UltrasuoniHCRS04();
  }



  void P1UltrasuoniHCRS04(){
      
  //porta bassa l'uscita del trigger
  digitalWrite( p1_triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( p1_triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( p1_echoPort, LOW );
   
  long durata = pulseIn( p1_echoPort, HIGH );
   
  long distanza = 0.034 * durata / 2;
   
  Serial.print("distanza: ");
   
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
  Serial.println("Fuori portata   ");
  }
  else{ 
  Serial.print(distanza); 
  Serial.println(" cm     ");
  }

   //Distanza in cm , quindi attualmente setto per 1mt
  if(distanza < 1000){
   P1State = 1;
  
  }
  else{
   P1State = 0;
  }
   
  
   
  
 }





  void P2UltrasuoniHCRS04(){
      
  //porta bassa l'uscita del trigger
  digitalWrite( p2_triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( p2_triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( p2_echoPort, LOW );
   
  long durata = pulseIn( p2_echoPort, HIGH );
   
  long distanza = 0.034 * durata / 2;
   
  Serial.print("distanza: ");
   
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
  Serial.println("Fuori portata   ");
  }
  else{ 
  Serial.print(distanza); 
  Serial.println(" cm     ");
  }

   //Distanza in cm , quindi attualmente setto per 1mt
  if(distanza < 1000){
   P2State = 1;
  
  }
  else{
   P2State = 0;
  }
   
  
   

  }
  


  void P3UltrasuoniHCRS04(){
      
  //porta bassa l'uscita del trigger
  digitalWrite( p3_triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( p3_triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( p3_echoPort, LOW );
   
  long durata = pulseIn( p3_echoPort, HIGH );
   
  long distanza = 0.034 * durata / 2;
   
  Serial.print("distanza: ");
   
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
  Serial.println("Fuori portata   ");
  }
  else{ 
  Serial.print(distanza); 
  Serial.println(" cm     ");
  }

   //Distanza in cm , quindi attualmente setto per 1mt
  if(distanza < 1000){
   P3State = 1;
  
  }
  else{
   P3State = 0;
  }
   
  
   

  }
  


  void P4UltrasuoniHCRS04(){
      
  //porta bassa l'uscita del trigger
  digitalWrite( p4_triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( p4_triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( p4_echoPort, LOW );
   
  long durata = pulseIn( p4_echoPort, HIGH );
   
  long distanza = 0.034 * durata / 2;
   
  Serial.print("distanza: ");
   
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
  Serial.println("Fuori portata   ");
  }
  else{ 
  Serial.print(distanza); 
  Serial.println(" cm     ");
  }

   //Distanza in cm , quindi attualmente setto per 1mt
  if(distanza < 1000){
   P4State = 1;
  
  }
  else{
   P4State = 0;
  }
   
  
   

  }
  


  void P5UltrasuoniHCRS04(){
      
  //porta bassa l'uscita del trigger
  digitalWrite( p5_triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( p5_triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( p5_echoPort, LOW );
   
  long durata = pulseIn( p5_echoPort, HIGH );
   
  long distanza = 0.034 * durata / 2;
   
  Serial.print("distanza: ");
   
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
  Serial.println("Fuori portata   ");
  }
  else{ 
  Serial.print(distanza); 
  Serial.println(" cm     ");
  }

   //Distanza in cm , quindi attualmente setto per 1mt
  if(distanza < 1000){
   P5State = 1;
  
  }
  else{
   P5State = 0;
  }
   
  
   

  }
  


  void P6UltrasuoniHCRS04(){
      
  //porta bassa l'uscita del trigger
  digitalWrite( p6_triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( p6_triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( p6_echoPort, LOW );
   
  long durata = pulseIn( p6_echoPort, HIGH );
   
  long distanza = 0.034 * durata / 2;
   
  Serial.print("distanza: ");
   
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
  Serial.println("Fuori portata   ");
  }
  else{ 
  Serial.print(distanza); 
  Serial.println(" cm     ");
  }

   //Distanza in cm , quindi attualmente setto per 1mt
  if(distanza < 1000){
   P6State = 1;
  
  }
  else{
   P6State = 0;
  }

  }
  

  
