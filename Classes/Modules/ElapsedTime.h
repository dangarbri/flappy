#include "cocos2d.h"

class ElapsedTime : public cocos2d::Component
{
public:
  ElapsedTime();
  float getElapsedTime();
  void resetTimer();

private:
  float mElapsedTime = 0;
  void update(float dt);
};
