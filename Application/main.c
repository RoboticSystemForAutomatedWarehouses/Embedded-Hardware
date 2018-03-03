#include "../config.h"


int main(){
  motor_init();


  while (1) {
    //direction
    PORTC |= (1<<PC0);
    PORTC &= (~(1<<PC1));
    //enable
    PORTC |= (1<<PC2);
  }
  return 0;
}
