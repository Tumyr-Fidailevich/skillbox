#include <iostream>

bool compare(float value, float reference, float epsilon)
{
  return (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main()
{
  float velocity = 0.0f;
  do
  {
    char buffer[5];
    std::sprintf(buffer, "%.1f", velocity);
    std::cout << "Speed: " << buffer << " km/h\n";
    float deltaVelocity;
    std::cout << "Speed delta: ";
    std::cin >> deltaVelocity;
    velocity += deltaVelocity;
    if (velocity > 150.0)
    {
      velocity = 150.0;
    }
  } while (!compare(velocity, 0.00, 0.01) && velocity > 0);
}