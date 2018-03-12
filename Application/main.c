#include "../config.h"


int main(){
 motor_init();
 while(1){
  uint8 val = readLineTracer();
  switch (val) {
    //01110//00100
    case 14:
    case 4:
    RobotMove(FORWARD,80,FORWARD,80);
    break;
    //01000//01100//11000//10000
    case 1:
    case 2:
    case 6:
    case 3:
    RobotMove(FORWARD,70,FORWARD,90);
    break;
    //00010//00110//00011//00001
    case 16:
    case 8:
    case 12:
    case 24:
    RobotMove(FORWARD,90,FORWARD,70);
    break;
    //00000
    case 0 :
    motor_stop();
    default:
    RobotMove(FORWARD,90,FORWARD,90);
    break;
  }
}

  return 0;

}


///motor test code
/*
int main(){
  DDRD =0xFF;
  DDRB =0XFF;
  PORTB |= (1<<4);
  PORTB |= (1<<7);
  PORTD |= (1<<6);
  PORTD &= ~(1<<7);
}
*/
