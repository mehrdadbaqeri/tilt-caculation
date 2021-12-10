#include <stdio.h>
#include <math.h>
#define PI 3.14159f

typedef struct{
  float roll;
  float pitch;
} Gesture_PositionTypeDef;

static void compute_tilt(float acc_x, float acc_y, float acc_z,
                         Gesture_PositionTypeDef *output)
{
  output->roll = (atan(acc_y / sqrt(pow(acc_x, 2) + pow(acc_z, 2))) * 180 / PI);
  output->pitch = (atan(acc_x / sqrt(pow(acc_y, 2) + pow(acc_z, 2))) * 180 / PI);
}


int main()
{
    Gesture_PositionTypeDef output;
    compute_tilt(30, 39, -15, &output);
    printf("Roll: %f, pitch: %f\n", output.roll, output.pitch);

    return 0;
}
