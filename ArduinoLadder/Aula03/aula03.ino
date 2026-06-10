#include <Arduino.h>
#include <Servo.h>

/*
  PLC2_UNO_Nano_Leonardo
*/



#define MASK_8BIT 0xFF
#define MASK_16BIT 0xFFFF
#define MASK_32BIT 0xFFFFFFFF

//iobFile-tag
int16_t iFile[1] = {0};
int16_t iPreFile[1] = {0};
int16_t iUpFile[1] = {0};
int16_t iDownFile[1] = {0};

int16_t oFile[1] = {0};
int16_t oPreFile[1] = {0};
int16_t oUpFile[1] = {0};
int16_t oDownFile[1] = {0};

int16_t bFile[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int16_t bPreFile[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int16_t bUpFile[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int16_t bDownFile[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};




//ndfFile-tag
int16_t nFile[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int32_t dFile[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float   fFile[20] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};




//analog-tag
bool analogInPins[8] = {false,false,false,false,false,false,false,false};
bool analogOutPins[8] = {false,false,false,false,false,false,false,false};
bool servoOut[8] = {false,false,false,false,false,false,false,false};




//trc-tag
bool bsTArray[8] = {false,false,false,false,false,false,false,false};
int16_t preTArray[8] = {0,0,0,0,0,0,0,0};

int16_t preCArray[8] = {0,0,0,0,0,0,0,0};

int16_t lenRArray[8] = {0,0,0,0,0,0,0,0};




int16_t aiFile[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int16_t aoFile[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int16_t sFile[8] = {0,0,0,0,0,0,0,0};

uint8_t iPins[8] = {2, 3, A0, A1, A2, A3, A4, A5}; //INPUT pins
uint8_t oPins[8] = {4, 5, 6, 7, 8, 9, 10, 11};      //OUTPUT pins

boolean routines[28] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

boolean inJump = false;
int jumpCode = -1;
boolean labelEnabled = true;
boolean labelEnabledInt1 = true;
boolean labelEnabledInt2 = true;



struct Timer{
  boolean en;
  boolean tt;
  boolean dn;
  boolean bs;

  boolean enPre;
  boolean ttPre;
  boolean dnPre;
  boolean bsPre;

  boolean enUp;
  boolean ttUp;
  boolean dnUp;
  boolean bsUp;

  boolean enDown;
  boolean ttDown;
  boolean dnDown;
  boolean bsDown;

  boolean count;

  int16_t pre;
  int16_t acc;

  unsigned long startTime;
  unsigned long currentTime;
  unsigned long targetTime;
};

struct Counter{
  boolean cu;
  boolean cd;
  boolean dn;
  boolean ov;
  boolean un;
  boolean xx;

  boolean cuPre;
  boolean cdPre;
  boolean dnPre;
  boolean ovPre;
  boolean unPre;
  boolean xxPre;

  boolean cuUp;
  boolean cdUp;
  boolean dnUp;
  boolean ovUp;
  boolean unUp;
  boolean xxUp;

  boolean cuDown;
  boolean cdDown;
  boolean dnDown;
  boolean ovDown;
  boolean unDown;
  boolean xxDown;

  int16_t pre;
  int16_t acc;
};

struct Control{
  boolean en;
  boolean eu;
  boolean dn;
  boolean em;
  boolean er;
  boolean ul;
  boolean in;
  boolean fd;

  boolean enPre;
  boolean euPre;
  boolean dnPre;
  boolean emPre;
  boolean erPre;
  boolean ulPre;
  boolean inPre;
  boolean fdPre;

  boolean enUp;
  boolean euUp;
  boolean dnUp;
  boolean emUp;
  boolean erUp;
  boolean ulUp;
  boolean inUp;
  boolean fdUp;

  boolean enDown;
  boolean euDown;
  boolean dnDown;
  boolean emDown;
  boolean erDown;
  boolean ulDown;
  boolean inDown;
  boolean fdDown;

  int16_t len;
  int16_t pos;
};


Servo myServo0;
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;


struct Timer tFile[4];
struct Counter cFile[4];
struct Control rFile[4];


void updateRegisters();
void updateInput(boolean firstWord, boolean maskEnabled, int16_t mask);
void updateOutput(boolean firstWord, boolean maskEnabled, int16_t mask);
void initTCC();
void setBitWord(int fileType, int wordPos, int bitPos, boolean value);
bool getBitWord(int fileType, int wordPos, int bitPos);
int setBitToInt(int bitPos);
int clearBitToInt(int bitPos);
void mainRoutine();
void routine1();
void routine2();
void routine3();
void routine4();
void routine5();
void routine6();
void routine7();
void routine8();
void routine9();
void routine10();
void routine11();
void routine12();
void routine13();
void routine14();
void routine15();
void routine16();
void interrupt1();
void interrupt2();

//functions1-tag

void rungR0r0();



unsigned long startTime = 0;
unsigned long currentTime = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(13, OUTPUT);

  for(int i=0; i<8; i++){
    pinMode(iPins[i],INPUT);                                                    //To enable PULL-UP resistors change "INPUT" with "INPUT_PULLUP"
    pinMode(oPins[i],OUTPUT);
  }

  //interrupt-tag




  initTCC();


  for(int i = 0; i<8; i++){
      if(servoOut[i]){
        switch(i){
            case 1:
              myServo0.attach(oPins[i]);
            break;
            case 2:
              myServo1.attach(oPins[i]);
            break;
            case 5:
              myServo2.attach(oPins[i]);
            break;
            case 6:
              myServo3.attach(oPins[i]);
            break;
            case 7:
              myServo4.attach(oPins[i]);
            break;
        }//END switch
      }
  }


  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  mainRoutine();

  updateRegisters();

}


void updateRegisters(){
  bool tempState = false;

    //INPUT
    updateInput(true, false, 0);

    //OUTPUT
    updateOutput(true, false, 0);

    //BINARY
    for(int j = 0; j < 20; j++){

      for(int i = 0; i < 16; i++){

          if((!getBitWord(8, j, i)) && (getBitWord(2, j, i)))
            setBitWord(11, j, i, true);
          else if((getBitWord(8, j, i)) && (!getBitWord(2, j, i)))
            setBitWord(14, j, i, true);
          else{
            setBitWord(11, j, i, false);
            setBitWord(14, j, i, false);
          }


          tempState = getBitWord(2, j, i);
          setBitWord(8, j, i, tempState);

      }//END for

    }//END for

    //CTR
    for(int j = 0; j < 4; j++){

      if(j < 4){     //C R
        //Counter
        for(int k = 2; k < 8; k++ ){
          if((!getBitWord(16, j, k)) && (getBitWord(4, j, k)))
            setBitWord(19, j, k, true);
          else if((getBitWord(16, j, k)) && (!getBitWord(4, j, k)))
            setBitWord(22, j, k, true);
          else{
            setBitWord(19, j, k, false);
            setBitWord(22, j, k, false);
          }

          tempState = getBitWord(4, j, k);
          setBitWord(16, j, k, tempState);
        }

        //Control
        for(int k = 2; k < 10; k++ ){
          if((!getBitWord(17, j, k)) && (getBitWord(5, j, k)))
            setBitWord(20, j, k, true);
          else if((getBitWord(17, j, k)) && (!getBitWord(5, j, k)))
            setBitWord(23, j, k, true);
          else{
            setBitWord(20, j, k, false);
            setBitWord(23, j, k, false);
          }

          tempState = getBitWord(5, j, k);
          setBitWord(17, j, k, tempState);
        }
      }

      //Timer
      for(int k = 2; k < 6; k++ ){
        if((!getBitWord(15, j, k)) && (getBitWord(3, j, k)))
          setBitWord(18, j, k, true);
        else if((getBitWord(15, j, k)) && (!getBitWord(3, j, k)))
          setBitWord(21, j, k, true);
        else{
          setBitWord(18, j, k, false);
          setBitWord(21, j, k, false);
        }

        tempState = getBitWord(3, j, k);
        setBitWord(15, j, k, tempState);
      }

    }


}//END updateRegisters()

void initTCC(){
  for(int i = 0; i < 4; i++){
    tFile[i].en = false;
    tFile[i].tt = false;
    tFile[i].dn = false;
    tFile[i].bs = bsTArray[i];

    tFile[i].enPre = false;
    tFile[i].ttPre = false;
    tFile[i].dnPre = false;
    tFile[i].bsPre = bsTArray[i];

    tFile[i].enUp = false;
    tFile[i].ttUp = false;
    tFile[i].dnUp = false;
    tFile[i].bsUp = false;

    tFile[i].enDown = false;
    tFile[i].ttDown = false;
    tFile[i].dnDown = false;
    tFile[i].bsDown = false;

    tFile[i].pre = preTArray[i];
    tFile[i].acc = 0;

    tFile[i].startTime = 0;
    tFile[i].currentTime = 0;
    tFile[i].targetTime = 0;
  }

  for(int i = 0; i < 4; i++){
    cFile[i].cu = false;
    cFile[i].cd = false;
    cFile[i].dn = false;
    cFile[i].ov = false;
    cFile[i].un = false;
    cFile[i].xx = false;

    cFile[i].cuPre = false;
    cFile[i].cdPre = false;
    cFile[i].dnPre = false;
    cFile[i].ovPre = false;
    cFile[i].unPre = false;
    cFile[i].xxPre = false;

    cFile[i].cuUp = false;
    cFile[i].cdUp = false;
    cFile[i].dnUp = false;
    cFile[i].ovUp = false;
    cFile[i].unUp = false;
    cFile[i].xxUp = false;

    cFile[i].cuDown = false;
    cFile[i].cdDown = false;
    cFile[i].dnDown = false;
    cFile[i].ovDown = false;
    cFile[i].unDown = false;
    cFile[i].xxDown = false;

    cFile[i].pre = preCArray[i];
    cFile[i].acc = 0;


    rFile[i].en = false;
    rFile[i].eu = false;
    rFile[i].dn = false;
    rFile[i].em = false;
    rFile[i].er = false;
    rFile[i].ul = false;
    rFile[i].in = false;
    rFile[i].fd = false;

    rFile[i].enPre = false;
    rFile[i].euPre = false;
    rFile[i].dnPre = false;
    rFile[i].emPre = false;
    rFile[i].erPre = false;
    rFile[i].ulPre = false;
    rFile[i].inPre = false;
    rFile[i].fdPre = false;

    rFile[i].enUp = false;
    rFile[i].euUp = false;
    rFile[i].dnUp = false;
    rFile[i].emUp = false;
    rFile[i].erUp = false;
    rFile[i].ulUp = false;
    rFile[i].inUp = false;
    rFile[i].fdUp = false;

    rFile[i].enDown = false;
    rFile[i].euDown = false;
    rFile[i].dnDown = false;
    rFile[i].emDown = false;
    rFile[i].erDown = false;
    rFile[i].ulDown = false;
    rFile[i].inDown = false;
    rFile[i].fdDown = false;

    rFile[i].len = lenRArray[i];
    rFile[i].pos = 0;
  }
}

void updateInput(boolean firstWord, boolean maskEnabled, int16_t mask){
  boolean tempState = false;
  int tempInt = 0;
  int j = 0;

  for(int i = 0; i < 8; i++){

    boolean doIt = true;

    if(maskEnabled){

      tempInt = mask;

      if(j > 0)
        tempInt >>= j;

      tempInt &= 1;

      if(tempInt != 1)
        doIt = false;
    }//END if(maskEnabled)

    if(doIt){
      if(!analogInPins[i]){

        if((!getBitWord(6, 0, i)) && (getBitWord(0, 0, i)))
          setBitWord(9, 0, i, true);
        else if((getBitWord(6, 0, i)) && (!getBitWord(0, 0, i)))
          setBitWord(12, 0, i, true);
        else{
          setBitWord(9, 0, i, false);
          setBitWord(12, 0, i, false);
        }

        tempState = getBitWord(0, 0, i);
        setBitWord(6, 0, i, tempState);

        setBitWord(0, 0, i , digitalRead(iPins[i]));

      }//END if(!analogInPins[i])
      else
        aiFile[i] = analogRead(iPins[i]);
    }//END if(doIt)

    j++;
  }//END for
}

void updateOutput(boolean firstWord, boolean maskEnabled, int16_t mask){
  boolean tempState = false;
  int tempInt = 0;

  if(firstWord){
    for(int i = 0; i < 8; i++){

      boolean doIt = true;

      if(maskEnabled){
        tempInt = mask;

        if(i > 0)
          tempInt >>= i;

        tempInt &= 1;

        if(tempInt != 1)
          doIt = false;
      }//END if(maskEnabled)

      if(doIt){
        if(!analogOutPins[i]){

          if((!getBitWord(7, 0, i)) && (getBitWord(1, 0, i)))
            setBitWord(10, 0, i, true);
          else if((getBitWord(7, 0, i)) && (!getBitWord(1, 0, i)))
            setBitWord(13, 0, i, true);
          else{
            setBitWord(10, 0, i, false);
            setBitWord(13, 0, i, false);
          }


          tempState = getBitWord(1, 0, i);
          setBitWord(7, 0, i, tempState);

          digitalWrite(oPins[i], tempState);

        }//END if(!analogOutPins[i])
        else{
          if(servoOut[i]){

            int16_t tempValue = aoFile[i];

            if(tempValue > 180)
              tempValue = 180;
            if(tempValue < 0)
              tempValue = 0;

            switch(i){
                case 1:
                  myServo0.write(tempValue);
                break;
                case 2:
                  myServo1.write(tempValue);
                break;
                case 5:
                  myServo2.write(tempValue);
                break;
                case 6:
                  myServo3.write(tempValue);
                break;
                case 7:
                  myServo4.write(tempValue);
                break;
            }//END switch

          }
          else{
            analogWrite(oPins[i], aoFile[i]);
          }
        }//END else

      }//END if(doIt)

    }//END for
  }//END if(firstWord)
}

void setBitWord(int fileType, int wordPos, int bitPos, boolean value) {

    int temp = 0;
    bool setBit = true;

    switch(fileType){
      case 0:
        temp = iFile[wordPos];
        break;

      case 1:
        temp = oFile[wordPos];
        break;

      case 2:
        temp = bFile[wordPos];
        break;

      case 3:
        setBit = false;
        switch(bitPos){
          case 2:
            tFile[wordPos].bs = value;
            break;
          case 3:
            tFile[wordPos].dn = value;
            break;
          case 4:
            tFile[wordPos].tt = value;
            break;
          case 5:
            tFile[wordPos].en = value;
            break;
        }
        break;

      case 4:
        setBit = false;
        switch(bitPos){
          case 2:
            cFile[wordPos].xx = value;
            break;
          case 3:
            cFile[wordPos].un = value;
            break;
          case 4:
            cFile[wordPos].ov = value;
            break;
          case 5:
            cFile[wordPos].dn = value;
            break;
          case 6:
            cFile[wordPos].cd = value;
            break;
          case 7:
            cFile[wordPos].cu = value;
            break;
        }
        break;

      case 5:
        setBit = false;
        switch(bitPos){
          case 2:
            rFile[wordPos].fd = value;
            break;
          case 3:
            rFile[wordPos].in = value;
            break;
          case 4:
            rFile[wordPos].ul = value;
            break;
          case 5:
            rFile[wordPos].er = value;
            break;
          case 6:
            rFile[wordPos].em = value;
            break;
          case 7:
            rFile[wordPos].dn = value;
            break;
          case 8:
            rFile[wordPos].eu = value;
            break;
          case 9:
            rFile[wordPos].en = value;
            break;
        }
        break;

      case 6:
        temp = iPreFile[wordPos];
        break;
      case 7:
        temp = oPreFile[wordPos];
        break;
      case 8:
        temp = bPreFile[wordPos];
      break;
      case 9:
        temp = iUpFile[wordPos];
      break;
      case 10:
        temp = oUpFile[wordPos];
      break;
      case 11:
        temp = bUpFile[wordPos];
      break;
      case 12:
        temp = iDownFile[wordPos];
      break;
      case 13:
        temp = oDownFile[wordPos];
      break;
      case 14:
        temp = bDownFile[wordPos];
      break;

      case 15:
        setBit = false;
        switch(bitPos){
          case 2:
            tFile[wordPos].bsPre = value;
            break;
          case 3:
            tFile[wordPos].dnPre = value;
            break;
          case 4:
            tFile[wordPos].ttPre = value;
            break;
          case 5:
            tFile[wordPos].enPre = value;
            break;
        }
        break;

      case 16:
        setBit = false;
        switch(bitPos){
          case 2:
            cFile[wordPos].xxPre = value;
            break;
          case 3:
            cFile[wordPos].unPre = value;
            break;
          case 4:
            cFile[wordPos].ovPre = value;
            break;
          case 5:
            cFile[wordPos].dnPre = value;
            break;
          case 6:
            cFile[wordPos].cdPre = value;
            break;
          case 7:
            cFile[wordPos].cuPre = value;
            break;
        }
        break;

      case 17:
        setBit = false;
        switch(bitPos){
          case 2:
            rFile[wordPos].fdPre = value;
            break;
          case 3:
            rFile[wordPos].inPre = value;
            break;
          case 4:
            rFile[wordPos].ulPre = value;
            break;
          case 5:
            rFile[wordPos].erPre = value;
            break;
          case 6:
            rFile[wordPos].emPre = value;
            break;
          case 7:
            rFile[wordPos].dnPre = value;
            break;
          case 8:
            rFile[wordPos].euPre = value;
            break;
          case 9:
            rFile[wordPos].enPre = value;
            break;
        }
        break;

        case 18:
          setBit = false;
          switch(bitPos){
            case 2:
              tFile[wordPos].bsUp = value;
              break;
            case 3:
              tFile[wordPos].dnUp = value;
              break;
            case 4:
              tFile[wordPos].ttUp = value;
              break;
            case 5:
              tFile[wordPos].enUp = value;
              break;
          }
          break;

        case 19:
          setBit = false;
          switch(bitPos){
            case 2:
              cFile[wordPos].xxUp = value;
              break;
            case 3:
              cFile[wordPos].unUp = value;
              break;
            case 4:
              cFile[wordPos].ovUp = value;
              break;
            case 5:
              cFile[wordPos].dnUp = value;
              break;
            case 6:
              cFile[wordPos].cdUp = value;
              break;
            case 7:
              cFile[wordPos].cuUp = value;
              break;
          }
          break;

        case 20:
          setBit = false;
          switch(bitPos){
            case 2:
              rFile[wordPos].fdUp = value;
              break;
            case 3:
              rFile[wordPos].inUp = value;
              break;
            case 4:
              rFile[wordPos].ulUp = value;
              break;
            case 5:
              rFile[wordPos].erUp = value;
              break;
            case 6:
              rFile[wordPos].emUp = value;
              break;
            case 7:
              rFile[wordPos].dnUp = value;
              break;
            case 8:
              rFile[wordPos].euUp = value;
              break;
            case 9:
              rFile[wordPos].enUp = value;
              break;
          }
          break;
          case 21:
            setBit = false;
            switch(bitPos){
              case 2:
                tFile[wordPos].bsDown = value;
                break;
              case 3:
                tFile[wordPos].dnDown = value;
                break;
              case 4:
                tFile[wordPos].ttDown = value;
                break;
              case 5:
                tFile[wordPos].enDown = value;
                break;
            }
            break;

          case 22:
            setBit = false;
            switch(bitPos){
              case 2:
                cFile[wordPos].xxDown = value;
                break;
              case 3:
                cFile[wordPos].unDown = value;
                break;
              case 4:
                cFile[wordPos].ovDown = value;
                break;
              case 5:
                cFile[wordPos].dnDown = value;
                break;
              case 6:
                cFile[wordPos].cdDown = value;
                break;
              case 7:
                cFile[wordPos].cuDown = value;
                break;
            }
            break;

          case 23:
            setBit = false;
            switch(bitPos){
              case 2:
                rFile[wordPos].fdDown = value;
                break;
              case 3:
                rFile[wordPos].inDown = value;
                break;
              case 4:
                rFile[wordPos].ulDown = value;
                break;
              case 5:
                rFile[wordPos].erDown = value;
                break;
              case 6:
                rFile[wordPos].emDown = value;
                break;
              case 7:
                rFile[wordPos].dnDown = value;
                break;
              case 8:
                rFile[wordPos].euDown = value;
                break;
              case 9:
                rFile[wordPos].enDown = value;
                break;
            }
            break;


    }//END switch

    if(setBit){

      if (value)
          temp |= setBitToInt(bitPos);
      else
          temp &= clearBitToInt(bitPos);


      temp &= MASK_16BIT;

      switch(fileType){
        case 0:
          iFile[wordPos] = temp;
          break;
        case 1:
          oFile[wordPos] = temp;
          break;
        case 2:
          bFile[wordPos] = temp;
          break;


        case 6:
          iPreFile[wordPos] = temp;
          break;
        case 7:
          oPreFile[wordPos] = temp;
          break;
        case 8:
          bPreFile[wordPos] = temp;
        break;
        case 9:
          iUpFile[wordPos] = temp;;
        break;
        case 10:
          oUpFile[wordPos] = temp;
        break;
        case 11:
          bUpFile[wordPos] = temp;
        break;
        case 12:
          iDownFile[wordPos] = temp;
        break;
        case 13:
          oDownFile[wordPos] = temp;
        break;
        case 14:
          bDownFile[wordPos] = temp;
        break;
      }

    }//END if(getBit)
}


bool getBitWord(int fileType, int wordPos, int bitPos){

  int  tempInt = 0;
  bool temp = false;
  bool getBit = true;

  switch(fileType){
    case 0:
      tempInt = iFile[wordPos];
      break;

    case 1:
      tempInt = oFile[wordPos];
      break;

    case 2:
      tempInt = bFile[wordPos];
      break;

    case 3:
      getBit = false;
      switch(bitPos){
        case 2:
          temp = tFile[wordPos].bs;
          break;
        case 3:
          temp = tFile[wordPos].dn;
          break;
        case 4:
          temp = tFile[wordPos].tt;
          break;
        case 5:
          temp = tFile[wordPos].en;
          break;
      }
      break;

    case 4:
      getBit = false;
      switch(bitPos){
        case 2:
          temp = cFile[wordPos].xx;
          break;
        case 3:
          temp = cFile[wordPos].un;
          break;
        case 4:
          temp = cFile[wordPos].ov;
          break;
        case 5:
          temp = cFile[wordPos].dn;
          break;
        case 6:
          temp = cFile[wordPos].cd;
          break;
        case 7:
          temp = cFile[wordPos].cu;
          break;
      }
      break;

    case 5:
      getBit = false;
      switch(bitPos){
        case 2:
          temp = rFile[wordPos].fd;
          break;
        case 3:
          temp = rFile[wordPos].in;
          break;
        case 4:
          temp = rFile[wordPos].ul;
          break;
        case 5:
          temp = rFile[wordPos].er;
          break;
        case 6:
          temp = rFile[wordPos].em;
          break;
        case 7:
          temp = rFile[wordPos].dn;
          break;
        case 8:
          temp = rFile[wordPos].eu;
          break;
        case 9:
          temp = rFile[wordPos].en;
          break;
      }
      break;


      case 6:
        tempInt = iPreFile[wordPos];
        break;
      case 7:
        tempInt = oPreFile[wordPos];
        break;
      case 8:
        tempInt = bPreFile[wordPos];
      break;
      case 9:
        tempInt = iUpFile[wordPos];
      break;
      case 10:
        tempInt = oUpFile[wordPos];
      break;
      case 11:
        tempInt = bUpFile[wordPos];
      break;
      case 12:
        tempInt = iDownFile[wordPos];
      break;
      case 13:
        tempInt = oDownFile[wordPos];
      break;
      case 14:
        tempInt = bDownFile[wordPos];
      break;

      case 15:
        getBit = false;
        switch(bitPos){
          case 2:
            temp = tFile[wordPos].bsPre;
            break;
          case 3:
            temp = tFile[wordPos].dnPre;
            break;
          case 4:
            temp = tFile[wordPos].ttPre;
            break;
          case 5:
            temp = tFile[wordPos].enPre;
            break;
        }
        break;

      case 16:
        getBit = false;
        switch(bitPos){
          case 2:
            temp = cFile[wordPos].xxPre;
            break;
          case 3:
            temp = cFile[wordPos].unPre;
            break;
          case 4:
            temp = cFile[wordPos].ovPre;
            break;
          case 5:
            temp = cFile[wordPos].dnPre;
            break;
          case 6:
            temp = cFile[wordPos].cdPre;
            break;
          case 7:
            temp = cFile[wordPos].cuPre;
            break;
        }
        break;

      case 17:
        getBit = false;
        switch(bitPos){
          case 2:
            temp = rFile[wordPos].fdPre;
            break;
          case 3:
            temp = rFile[wordPos].inPre;
            break;
          case 4:
            temp = rFile[wordPos].ulPre;
            break;
          case 5:
            temp = rFile[wordPos].erPre;
            break;
          case 6:
            temp = rFile[wordPos].emPre;
            break;
          case 7:
            temp = rFile[wordPos].dnPre;
            break;
          case 8:
            temp = rFile[wordPos].euPre;
            break;
          case 9:
            temp = rFile[wordPos].enPre;
            break;
        }
        break;

        case 18:
          getBit = false;
          switch(bitPos){
            case 2:
              temp = tFile[wordPos].bsUp;
              break;
            case 3:
              temp = tFile[wordPos].dnUp;
              break;
            case 4:
              temp = tFile[wordPos].ttUp;
              break;
            case 5:
              temp = tFile[wordPos].enUp;
              break;
          }
          break;

        case 19:
          getBit = false;
          switch(bitPos){
            case 2:
              temp = cFile[wordPos].xxUp;
              break;
            case 3:
              temp = cFile[wordPos].unUp;
              break;
            case 4:
              temp = cFile[wordPos].ovUp;
              break;
            case 5:
              temp = cFile[wordPos].dnUp;
              break;
            case 6:
              temp = cFile[wordPos].cdUp;
              break;
            case 7:
              temp = cFile[wordPos].cuUp;
              break;
          }
          break;

        case 20:
          getBit = false;
          switch(bitPos){
            case 2:
              temp = rFile[wordPos].fdUp;
              break;
            case 3:
              temp = rFile[wordPos].inUp;
              break;
            case 4:
              temp = rFile[wordPos].ulUp;
              break;
            case 5:
              temp = rFile[wordPos].erUp;
              break;
            case 6:
              temp = rFile[wordPos].emUp;
              break;
            case 7:
              temp = rFile[wordPos].dnUp;
              break;
            case 8:
              temp = rFile[wordPos].euUp;
              break;
            case 9:
              temp = rFile[wordPos].enUp;
              break;
          }
          break;

          case 21:
            getBit = false;
            switch(bitPos){
              case 2:
                temp = tFile[wordPos].bsDown;
                break;
              case 3:
                temp = tFile[wordPos].dnDown;
                break;
              case 4:
                temp = tFile[wordPos].ttDown;
                break;
              case 5:
                temp = tFile[wordPos].enDown;
                break;
            }
            break;

          case 22:
            getBit = false;
            switch(bitPos){
              case 2:
                temp = cFile[wordPos].xxDown;
                break;
              case 3:
                temp = cFile[wordPos].unDown;
                break;
              case 4:
                temp = cFile[wordPos].ovDown;
                break;
              case 5:
                temp = cFile[wordPos].dnDown;
                break;
              case 6:
                temp = cFile[wordPos].cdDown;
                break;
              case 7:
                temp = cFile[wordPos].cuDown;
                break;
            }
            break;

          case 23:
            getBit = false;
            switch(bitPos){
              case 2:
                temp = rFile[wordPos].fdDown;
                break;
              case 3:
                temp = rFile[wordPos].inDown;
                break;
              case 4:
                temp = rFile[wordPos].ulDown;
                break;
              case 5:
                temp = rFile[wordPos].erDown;
                break;
              case 6:
                temp = rFile[wordPos].emDown;
                break;
              case 7:
                temp = rFile[wordPos].dnDown;
                break;
              case 8:
                temp = rFile[wordPos].euDown;
                break;
              case 9:
                temp = rFile[wordPos].enDown;
                break;
            }
            break;


  }//END switch


  if(getBit){
    if(bitPos > 0)
      tempInt >>= bitPos;

    tempInt &= 1;

    if(tempInt == 1)
      temp = true;

  }

  return temp;

}


int setBitToInt(int bitPos){
  int temp = 1;

  if(bitPos > 0){
    temp <<= bitPos;
  }

  return temp;
}


int clearBitToInt(int bitPos){
  int temp = 0xFFFE;

  if(bitPos > 0){
    for(int i=0; i<bitPos; i++){
      temp <<= 1;
      temp += 1;
    }//END for
  }//END if

  return temp;
}

void mainRoutine(){
  inJump = false;
  routines[0] = true;
  labelEnabled = true;
  do{
    //mr-tag

		if(!inJump)
			rungR0r0();


    labelEnabled = false;
  }while(inJump);
  routines[0] = false;
}

void routine1(){
  routines[1] = true;
  labelEnabled = true;
  do{
    //routine1-tag


    labelEnabled = false;
  }while(inJump);
  routines[1] = false;

}

void routine2(){
  routines[2] = true;
  labelEnabled = true;
  do{
    //routine2-tag


    labelEnabled = false;
  }while(inJump);
  routines[2] = false;
}

void routine3(){
  routines[3] = true;
  labelEnabled = true;
  do{
    //routine3-tag


    labelEnabled = false;
  }while(inJump);
  routines[3] = false;
}

void routine4(){
  routines[4] = true;
  labelEnabled = true;
  do{
    //routine4-tag


    labelEnabled = false;
  }while(inJump);
  routines[4] = false;
}

void routine5(){
  routines[5] = true;
  labelEnabled = true;
  do{
    //routine5-tag


    labelEnabled = false;
  }while(inJump);
  routines[5] = false;
}

void routine6(){
  routines[6] = true;
  labelEnabled = true;
  do{
    //routine6-tag


    labelEnabled = false;
  }while(inJump);
  routines[6] = false;
}

void routine7(){
  routines[7] = true;
  labelEnabled = true;
  do{
    //routine7-tag


    labelEnabled = false;
  }while(inJump);
  routines[7] = false;
}

void routine8(){
  routines[8] = true;
  labelEnabled = true;
  do{
    //routine8-tag


    labelEnabled = false;
  }while(inJump);
  routines[8] = false;
}

void routine9(){
  routines[9] = true;
  labelEnabled = true;
  do{
    //routine9-tag


    labelEnabled = false;
  }while(inJump);
  routines[9] = false;
}

void routine10(){
  routines[10] = true;
  labelEnabled = true;
  do{
    //routine10-tag


    labelEnabled = false;
  }while(inJump);
  routines[10] = false;
}

void routine11(){
  routines[11] = true;
  labelEnabled = true;
  do{
    //routine11-tag


    labelEnabled = false;
  }while(inJump);
  routines[11] = false;
}

void routine12(){
  routines[12] = true;
  labelEnabled = true;
  do{
    //routine12-tag


    labelEnabled = false;
  }while(inJump);
  routines[12] = false;
}

void routine13(){
  routines[13] = true;
  labelEnabled = true;
  do{
    //routine13-tag


    labelEnabled = false;
  }while(inJump);
  routines[13] = false;
}

void routine14(){
  routines[14] = true;
  labelEnabled = true;
  do{
    //routine14-tag


    labelEnabled = false;
  }while(inJump);
  routines[14] = false;
}

void routine15(){
  routines[15] = true;
  labelEnabled = true;
  do{
    //routine15-tag


    labelEnabled = false;
  }while(inJump);
  routines[15] = false;
}

void routine16(){
  routines[16] = true;
  labelEnabled = true;
  do{
    //routine16-tag


    labelEnabled = false;
  }while(inJump);
  routines[16] = false;
}

void interrupt1(){
  routines[17] = true;
  labelEnabledInt1 = true;
  do{
    //interrupt1-tag


    labelEnabledInt1 = false;
  }while(inJump);
  routines[17] = false;
}

void interrupt2(){
  routines[18] = true;
  labelEnabledInt2 = true;
  do{
    //interrupt2-tag


    labelEnabledInt2 = false;
  }while(inJump);
  routines[18] = false;
}


//functions-tag

void rungR0r0(){ 
 
 	bool o00 = getBitWord(1, 0, 0); 
 	bool i00 = getBitWord(0, 0, 0); 
 	bool i01 = getBitWord(0, 0, 1); 
 	bool e0 = ( i00) | ( o00); 
 	bool eF =  e0 & !i01; 
 	setBitWord(1, 0, 0, eF); 
} 
 
 


