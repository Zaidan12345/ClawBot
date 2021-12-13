#include "main.h"
#include "chassis.h"
void lineFollow(int R, int L, int C) {
  R = analogReadCalibrated(2);
  L = analogReadCalibrated(1);
  C = analogReadCalibrated(3);
  printf("Left: %d Right: %d Center: %d \n",R, L, C);
  if(C > L && C > R) {
    chassisSet(60, 60);
  } else if(R > L && R > C) {
    chassisSet(-60, 60);
  }else if(L > R && L > C) {
    chassisSet(60,-60);
  } else {
    chassisSet(-60, -60);
  }
}
