#include <vector>

class RandomNumberGenerator
{
    public:
        RandomNumberGenerator(int min, int max);
        int GetMax() const;
        int GetMin() const;
        int GenerateRandomNumber() const;

    private:
        int min;
        int max;
};