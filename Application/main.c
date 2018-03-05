#include "../config.h"


int main(){
  DDRC =0xFF;
  GPIO_InitPort('C',0xFF);
  while (1) {
    //direction
    GPIO_SetPin('C',0);
    GPIO_ClearPin('C',1);
    //enable
    GPIO_SetPin('C',2);
  }
  return 0;
}


///motor test code
/**
int main(){
  DDRC =0xFF;
  while (1) {
    //direction
    PORTC |= (1<<PC0);
    PORTC &= ~(1<<PC1);
    //enable
    PORTC |= (1<<PC2);

  return 0;
}
**/
