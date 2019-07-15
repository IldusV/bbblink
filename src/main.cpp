//============================================================================
// Name        : hww.cpp
// Author      : ildusV
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main() {
  cout << "LED Flash Start usr2" << endl;
  FILE *LEDHandle = NULL;
  char *LEDBrightness = "/sys/class/leds/beaglebone:green:usr2/brightness";

  for(int i = 0; i < 10; i++){
    if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
      fwrite("0", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
      cout << "ON usr2" << endl;
    }
    else{
      cout << "Can't write On usr2" << endl;
    }
    usleep(1000000);

    if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
      fwrite("1", sizeof(char), 1, LEDHandle);
      fclose(LEDHandle);
      cout << "OFF usr2" << endl;
    }
    else{
      cout << "Can't write Off usr2" << endl;
    }
    usleep(1000000); //sleep here
  }
  cout << "LED Flash End usr2" << endl;
  return 0;
}
