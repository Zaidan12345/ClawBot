#ifdef CHASSIS_H
#define CHASSIS_H
#include "main.h"

void clawSet(int turn, int grip);


void foreSet(int speed);


void chassisSet(int left, int right);


void shoulderSet(int speed);

void liftSet(int speed);

void holdshoulder(int td, Encoder shoulderEncoder);

void straightline(int x, int y);

#endif
