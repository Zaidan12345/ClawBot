#include "main.h"
#include "chassis.h"

void holdshoulder(int td) {//target degree
int kp = 1;
int maxs = 127;
Encoder shoulderEncoder;
shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
int error = td - encoderGet(shoulderEncoder);
int output = kp * error;
if(abs(error) < maxs){
  motorSet(4,-output);
}
else{
  motorSet(4,-(output/abs(output) * maxs));
  encoderReset(shoulderEncoder);
}
}
