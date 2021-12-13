#include "main.h"
//#include "chassis.h"
#include "homeshoulder.h"
#include "USF.h"
//#include "holdshoulder.h"


/*
----------------Buttons----------------
Right:

Left:
Ultrasonic follow - Left
Linefollow - Down


*/



void operatorControl() {
	int power;
	int turn;
	int the_R, the_L, the_C;
	int count = 0;
	int powerclaw;
	int turnclaw;
	int shoulderL = 22; //cm length of shoulder arm
	int forearmL = 28; //cm length of forarm
	int distance;

	Ultrasonic distancesonar;
	Ultrasonic fSonar;
	fSonar= ultrasonicInit(ORANGE_SENSOR,YELLOW_SENSOR);



	Encoder shoulderEncoder;
  shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
	encoderReset(shoulderEncoder);

	Encoder forearmE;
	forearmE = encoderInit(FORE_TOP_PORT, FORE_BOTTOM_PORT, false);
	encoderReset(forearmE);

  while (1) {
    power = joystickGetAnalog(1, 1); //vertial axis on left Joystick
    turn = joystickGetAnalog(1, 2); //horizontal axis on left joystick

		distancesonar = ultrasonicInit(2, 1);




    chassisSet(power - turn, power + turn);
	if (joystickGetDigital(1, 7, JOY_RIGHT)){
	 encoderReset(shoulderEncoder);
	 printf("encoder zeroed...");
	}
// -----------------------------HOLDshoulder V
	while (joystickGetDigital(1, 7, JOY_DOWN)){
 //commented out for now ... holdshoulder(1, shoulderEncoder);
 //printf("holding... \n");

 //now using this button for linefollow
	lineFollow(the_R, the_L, the_C); 

}



//------------------------------Homeshoulder V

		if (joystickGetDigital(1, 7, JOY_UP)) {
			homeShoulder(50, shoulderEncoder);

		}

//-----------------------------------------------------------CONTROL CLAW V
powerclaw = joystickGetAnalog(1, 3);
turnclaw = joystickGetAnalog(1, 4);
distance = ultrasonicGet(distancesonar);
clawSet(turnclaw, powerclaw);


//-----------------------------------CONTROL FOREARM  v


if(joystickGetDigital(1, 5, JOY_UP)) {
	foreSet(-127);
		printf("raising arm \n");
}
	else if(joystickGetDigital(1, 5, JOY_DOWN)) {
	foreSet(127);
	printf("lowering arm \n");
}
	 else {
	foreSet(0);

}


//---------------------------------} CONTROL SHOULDER   V


if(joystickGetDigital(1, 6, JOY_UP)) {
	liftSet(127); //pressing up, so lift should go up
}
		else if(joystickGetDigital( 1, 6, JOY_DOWN)) {
			liftSet(-127); //pressing down so lift should go down
		}
		else {
			liftSet(0); //no buttons are pressed, stop lift
		}
		//--------------------}  CONRTOL SHOULDER ^

		while(joystickGetDigital(1,7,JOY_LEFT)) {
			printf("usf working \n");
			ultraSonicFollow(fSonar);
		}
/* zaidens code for usf
if(joystickGetDigital(1, 8, JOY_UP)) {

	printf("front sonar %d \n", distance);
	if(distance > 20 && distance < 30){
		chassisSet(60, -60);//go forwards
	}
	if(distance < 16 && distance > 0){
chassisSet(-60, 60);//go backwards
	}
	if(distance < 0){
		chassisSet(60, 60);//look for object
		}
		else{
			chassisSet(0,0);//stop moving
		}
	}
}
*/






    delay(200);
}
  }//whileloop
