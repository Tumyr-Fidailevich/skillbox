#include <iostream>
#include <limits>
#include <numeric>


bool compare(float value, float reference, float epsilon)
{
  return (value >= reference - epsilon) && (value <= reference + epsilon);
}

bool inputValidation()
{
  if (std::cin.fail() || std::cin.peek() != '\n')
  {
    std::cerr << "Input error\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }
  else
  {
    return true;
  }
}

bool dataValidation(std::string &velocity)
{
  size_t pos;
  float number = std::stof(velocity, &pos);
  if (pos != velocity.size())
  {
    return false;
  }
  return true;
}

int main()
{
  float velocity = 0.0f;
  do
  {
    char buffer[5];
    std::sprintf(buffer, "%.1f", velocity);
    std::cout << "Speed: " << buffer << " km/h\n";
    std::string deltaVelocity;
    std::cout << "Speed delta: ";
    std::cin >> deltaVelocity;
    if (inputValidation() && dataValidation(deltaVelocity))
    {
      velocity += std::stof(deltaVelocity);
      if (velocity > 150.0)
      {
        velocity = 150.0;
      }
    }

  } while (!compare(velocity, 0.00, 0.01) && velocity > 0);
}