#include "RandomNumberGenerator.h"

#include <cstdlib>
#include <ctime>

RandomNumberGenerator::RandomNumberGenerator(int min, int max) :
    min(min),
    max(max)
{
    srand((unsigned) time(0));
}

int RandomNumberGenerator::GetMax() const
{
    return max;
}

int RandomNumberGenerator::GetMin() const
{
    return min;
}

int RandomNumberGenerator::GenerateRandomNumber() const
{
    auto numberGenerated = rand() % (max - min + 1) + min;
    return numberGenerated;
}
