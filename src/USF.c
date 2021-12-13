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
    } else if(distance < 0) {
      chassisSet(30,30);
    }else {
      chassisSet(0,0);
    }
}

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
