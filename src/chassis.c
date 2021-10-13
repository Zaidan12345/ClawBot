#include "main.h"
#include "chassis.h"

void clawSet(int speed){
  motorSet(2, speed);
}


void foreSet(int speed){
  motorSet(5, speed);
}


void chassisSet(int left, int right){
  motorSet(1, left);
  motorSet(10, right);
}


void shoulderSet(int speed){
  motorSet(6, speed);
}


void liftSet(int speed) {
  motorSet(4, -speed);
}
