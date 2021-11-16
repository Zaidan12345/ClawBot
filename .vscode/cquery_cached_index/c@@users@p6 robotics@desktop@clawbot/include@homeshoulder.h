//#include "main.h"
//#include "chassis.h"


/*void homeShoulder(int homepos) {
  int count = 0;
  Encoder encoder;
  homepos = 50;
printf("homing started, stand by \n");

while(digitalRead(LIMIT_SWITCH) != LOW){
  liftSet(-40);
			pinMode(LIMIT_SWITCH, INPUT);
	    encoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);

}
while(encoder < homepos) {
liftSet(-40);
}
printf("homing complete \n");
}
*/

#ifndef HOMESHOULDER_H
#define HOMESHOULDER_H
//#include "main.h"
void homeShoulder(int homepos);
#endif
