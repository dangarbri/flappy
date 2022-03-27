#include "Modules/ElapsedTime.h"

ElapsedTime::ElapsedTime()
{
  autorelease();
  setName("ElapsedTime");
  mElapsedTime = 0;
}

void ElapsedTime::update(float dt)
{
  mElapsedTime += dt;
}

float ElapsedTime::getElapsedTime()
{
  return mElapsedTime;
}
