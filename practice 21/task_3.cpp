#include <iostream>
#include <vector>
#include <cmath>

struct myVector
{
    double x = 0;
    double y = 0;
    double z = 0;
};

bool isNumber(std::string &number)
{
    try
    {
        std::stod(number);
    }
    catch (const std::invalid_argument &e)
    {
        return false;
    }
    return true;
}

myVector add(myVector &first_vector, myVector &second_vector)
{
    myVector result;
    result.x = first_vector.x + second_vector.x;
    result.y = second_vector.y + second_vector.y;
    result.z = second_vector.z + second_vector.z;
    return result;
}

myVector substract(myVector &first_vector, myVector &second_vector)
{
    myVector result;
    result.x = first_vector.x - second_vector.x;
    result.y = second_vector.y - second_vector.y;
    result.z = second_vector.z - second_vector.z;
    return result;
}

myVector scale(myVector &vector, double &scalar)
{
    myVector result;
    result.x = vector.x * scalar;
    result.y = vector.y * scalar;
    result.z = vector.z * scalar;
    return result;
}

double length(myVector &vector)
{
    double result = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    return result;
}

myVector normalize(myVector &vector)
{
    myVector result;
    result.x = vector.x / length(vector);
    result.y = vector.y / length(vector);
    result.z = vector.z / length(vector);
    return result;
}

int main()
{
    std::string operation;
    std::cout << "Input operation: ";
    std::cin >> operation;
    std::string x, y, z;
    if (operation == "add")
    {
        myVector fisrtVector;
        myVector secondVector;
        std::cout << "Input first vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        else
        {
            fisrtVector.x = std::stod(x);
            fisrtVector.y = std::stod(y);
            fisrtVector.z = std::stod(z);
        }
        std::cout << "Input second vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        else
        {
            secondVector.x = std::stod(x);
            secondVector.y = std::stod(y);
            secondVector.z = std::stod(z);
        }
        myVector result = add(fisrtVector, secondVector);
        std::cout << "x: " << result.x << " y: " << result.y << " z: " << result.z << std::endl;
    }
    else if (operation == "substract")
    {
        myVector fisrtVector;
        myVector secondVector;
        std::cout << "Input first vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        else
        {
            fisrtVector.x = std::stod(x);
            fisrtVector.y = std::stod(y);
            fisrtVector.z = std::stod(z);
        }
        std::cout << "Input second vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        else
        {
            secondVector.x = std::stod(x);
            secondVector.y = std::stod(y);
            secondVector.z = std::stod(z);
        }
        myVector result = substract(fisrtVector, secondVector);
        std::cout << "x: " << result.x << " y: " << result.y << " z: " << result.z << std::endl;
    }
    else if (operation == "scale")
    {
        myVector fisrtVector;
        std::cout << "Input vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        else
        {
            fisrtVector.x = std::stod(x);
            fisrtVector.y = std::stod(y);
            fisrtVector.z = std::stod(z);
        }
        std::cout << "Input scalar: ";
        std::cin >> x;
        if (!isNumber(x))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        double scalar = std::stod(x);
        myVector result = scale(fisrtVector, scalar);
        std::cout << "x: " << result.x << " y: " << result.y << " z: " << result.z << std::endl;
    }
    else if (operation == "length")
    {
        myVector fisrtVector;
        std::cout << "Input vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }
        else
        {
            fisrtVector.x = std::stod(x);
            fisrtVector.y = std::stod(y);
            fisrtVector.z = std::stod(z);
        }
        std::cout << "Length: " << length(fisrtVector);
    }
    else if (operation == "normalize")
    {
        myVector fisrtVector;
        std::cout << "Input vector: ";
        std::cin >> x >> y >> z;
        if (!isNumber(x) && isNumber(y) && isNumber(z))
        {
            std::cout << "Invalid arguments" << std::endl;
            return 1;
        }else{
            fisrtVector.x = std::stod(x);
            fisrtVector.y = std::stod(y);
            fisrtVector.z = std::stod(z);
        }
        myVector result = normalize(fisrtVector);
        std::cout << "x: " << result.x << " y: " << result.y << " z: " << result.z << std::endl;
    }
    else
    {
        std::cout << "Invalid operation" << std::endl;
    }
    return 0;
}