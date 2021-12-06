#include "main.h"
//#include "homeshoulder.h"
//#include "chassis.h"

void homeShoulder (int homepos, Encoder sEncoder) {

   int eVal = encoderGet(sEncoder);
   printf("homeing started, stand by \n");

   while(digitalRead(LIMIT_SWITCH) == 1) {
     printf("looking for limit switch\n");
     liftSet(-50);

   }
   liftSet(0);
   encoderReset(sEncoder);
   eVal = encoderGet(sEncoder);

   homepos = 180;

   while(eVal < homepos) {
     liftSet(50);
     printf("moving to home pos %d \n", eVal);
     if(eVal > homepos) {
       liftSet(0);
     }
     eVal = encoderGet(sEncoder);
   }

}
