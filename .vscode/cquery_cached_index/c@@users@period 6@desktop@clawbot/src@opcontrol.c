#include "main.h"
//#include "shoulder.c"
#include "chassis.c"
#include "homeshoulder.h"


//#include "forearm.c"
void holdShoulderAt(int td) {//target degree
int kp = 1;
int maxs = 127;
Encoder shoulderEncoder;
shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
int error = td - encoderGet(shoulderEncoder);
int output = kp * error;
if(abs(error) < maxs){
	liftSet(output);
}
else{
	liftSet(output/abs(output) * maxs);
}
}


void operatorControl() {
	int power;
	int turn;
	//int pot = 0;
	int count = 0;
	Encoder encoder;




  while (1) {
    power = joystickGetAnalog(1, 1); //vertial axis on left Joystick
    turn = joystickGetAnalog(1, 2); //horizontal axis on left joystick
	//	pot = analogRead(5);
		count = encoderGet(encoder);

	//	printf("the pot value %d \n", pot);
		//printf("the encoder value %d \n", count);

		    encoderReset(encoder);


    chassisSet(power - turn, power + turn);

		//------------------------------Homeshoulder V

		/*if(joystickGetDigital(1, 7, JOY_UP)) {
			homeShouler(50);
		}*/

//-----------------------------------FOREARM  v


if(joystickGetDigital(1, 5, JOY_UP)) {
	foreSet(127);
}
	else if(joystickGetDigital(1, 5, JOY_DOWN)) {
	foreSet(-127);
}
	 else {
	foreSet(0);
}


//---------------------------------} SHOULDER   V


if(joystickGetDigital(1, 6, JOY_UP)) {
	liftSet(127); //pressing up, so lift should go up
}
		else if(joystickGetDigital(1, 6, JOY_DOWN)) {
			liftSet(-127); //pressing down so lift should go down
		}

		else {
			liftSet(0); //no buttons are pressed, stop lift
		}
		//--------------------}  SHOULDER ^
		if (joystickGetDigital(1, 7, JOY_UP)) {
			homeShoulder(50);
		}




    delay(200);

  }
}
