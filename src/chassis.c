#include "main.h"
#include "chassis.h"

void clawSet(int turn, int grip){
  motorSet(2, grip);
  motorSet(3, turn);
}


void foreSet(int speed){
  motorSet(5, speed);
}


void chassisSet(int left, int right){
  motorSet(1, left);
  motorSet(10, right);
}


void liftSet(int speed) {
  motorSet(4, -speed);
}
