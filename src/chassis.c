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


void holdshoulder(int on, Encoder shoulderEncoder) {//target degree
int td = 0;
int kp = 1;//constant of proportionality
int maxs = 127;//max speed
//Encoder shoulderEncoder;
//shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
//encoderReset(shoulderEncoder);
int error = td - encoderGet(shoulderEncoder);
int output = kp * error;
if(abs(error) < maxs){
  motorSet(4,-output);
}
else{
  motorSet(4,-(output/abs(output) * maxs));
}

}
