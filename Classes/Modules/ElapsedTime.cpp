#include "Modules/ElapsedTime.h"

ElapsedTime::ElapsedTime()
{
  autorelease();
  setName("ElapsedTime");
  resetTimer();
}

void ElapsedTime::update(float dt)
{
  mElapsedTime += dt;
}

float ElapsedTime::getElapsedTime()
{
  return mElapsedTime;
}

void ElapsedTime::resetTimer()
{
  mElapsedTime = 0;
}
