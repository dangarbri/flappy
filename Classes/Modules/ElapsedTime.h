#include "cocos2d.h"

class ElapsedTime : public cocos2d::Component
{
public:
  ElapsedTime();
  float getElapsedTime();

private:
  float mElapsedTime = 0;
  void update(float dt);
};
