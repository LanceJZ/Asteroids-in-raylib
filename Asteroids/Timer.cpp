#include "Timer.h"

void Timer::Update(float deltaTime)
{
    TheSeconds += deltaTime;
}

void Timer::Set(float amountInSeconds)
{
    TheAmount = amountInSeconds;
}

void Timer::Reset()
{
    TheSeconds = 0;
}

bool Timer::Elapsed()
{
    return TheSeconds > TheAmount;
}
