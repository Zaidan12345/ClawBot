#include "main.h"
#include "chassis.h"
#include "homeshoulder.h"
//#include "holdshoulder.h"




void operatorControl() {
	int power;
	int turn;
	int count = 0;
	int powerclaw;
	int turnclaw;
	int shoulderL = 22; //cm length of shoulder arm
	int forearmL = 29; //cm length of forarm


	Encoder shoulderEncoder;
  shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
	encoderReset(shoulderEncoder);

	Encoder forearmE;
	forearmE = encoderInit(FORE_TOP_PORT, FORE_BOTTOM_PORT, false);
	encoderReset(forearmE);

  while (1) {
    power = joystickGetAnalog(1, 1); //vertial axis on left Joystick
    turn = joystickGetAnalog(1, 2); //horizontal axis on left joystick




    chassisSet(power - turn, power + turn);
	if (joystickGetDigital(1, 7, JOY_RIGHT)){
	 encoderReset(shoulderEncoder);
	 printf("encoder zeroed...");
	}
// -----------------------------HOLDshoulder V
	while (joystickGetDigital(1, 7, JOY_DOWN)){
 holdshoulder(1, shoulderEncoder);
 printf("holding... \n");
}



//------------------------------Homeshoulder V

		if (joystickGetDigital(1, 7, JOY_UP)) {
			homeShoulder(50);

		}

//-----------------------------------------------------------CONTROL CLAW V
powerclaw = joystickGetAnalog(1, 3);
turnclaw = joystickGetAnalog(1, 4);

clawSet(turnclaw, powerclaw);


//-----------------------------------CONTROL FOREARM  v


if(joystickGetDigital(1, 5, JOY_UP)) {
	foreSet(127);
		printf("raising arm \n");
}
	else if(joystickGetDigital(1, 5, JOY_DOWN)) {
	foreSet(-127);
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





    delay(200);

  }
}
