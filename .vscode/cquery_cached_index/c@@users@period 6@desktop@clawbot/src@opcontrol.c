#include "main.h"
#include "chassis.c"
#include "homeshoulder.h"
#include "holdshoulder.c"

void operatorControl() {
	int power;
	int turn;
	int count = 0;
	Encoder encoder;
	int powerclaw;
	int turnclaw;

  while (1) {
    power = joystickGetAnalog(1, 1); //vertial axis on left Joystick
    turn = joystickGetAnalog(1, 2); //horizontal axis on left joystick
		count = encoderGet(encoder);
		    encoderReset(encoder);

    chassisSet(power - turn, power + turn);

// -----------------------------HOLDshoulder V
		if (joystickGetDigital(1, 6, JOY_DOWN)){
 holdshoulder(0);
}
//------------------------------Homeshoulder V

		if (joystickGetDigital(1, 7, JOY_UP)) {
			homeShoulder(50);
		}

//-----------------------------------------------------------CONTROL CLAW V
powerclaw = joystickGetAnalog(1, 4);
turnclaw = joystickGetAnalog(1, 3);

clawSet(turnclaw - powerclaw, powerclaw - turnclaw);


//-----------------------------------CONTROL FOREARM  v


if(joystickGetDigital(1, 5, JOY_UP)) {
	foreSet(127);
}
	else if(joystickGetDigital(1, 5, JOY_DOWN)) {
	foreSet(-127);
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
