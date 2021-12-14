#include "main.h"
#include "USF.h"
#include "chassis.h"
//11 warnings
//Ultrasonic fSonar;
int distance;


void ultraSonicFollow(Ultrasonic sonic1) {
    distance = ultrasonicGet(sonic1);
    printf("The distance to an object is %d \n", distance);
    delay(30);
    if(distance > 30 && distance < 50) {
      chassisSet(50,-50); // forward
    } else if(distance < 29 && distance > 0) {
      chassisSet(-50,50); //backwards
    } else {
      chassisSet(0,0);
    }
    /*int rCount = 100;
    int lCount = 200;
    if (distance < 0) { //if less than -1
      while(rCount != 0 ){
        rCount--;
        chassisSet(30,40);
      }
    } else if(distance < 0) {//if still equal to -1
      while(lCount != 0 && distance < 0) {
        lCount--;
        chassisSet(40,30);
      }
    }*/


  }




  /*

whle(distance < 0) {//sensor is -1
  chassisSet(40,-40);
}
if(distance > 0 && distance > 30) {
  chassisSet(40,30);
}
  */

/*
while(distance > 0) {
  if(distance > 30) {
  drive forward
} else if(distance < 29) {
drive backwards
}

--------

if(distance > 30) {
drive forward
} else if(distance < 29) {
drive backwards
} else if (distance < 0) {

}
}
*/

/*

example"
all of this only held down when button is held
read ultra sonic sensor value
print the value
if(ultrasonic  > targetfollowdistance) {
  drive forward
} else if(ultrasonic < targetfollowdistance) {
  drive backward
}else {
stop drivng
}

*/
