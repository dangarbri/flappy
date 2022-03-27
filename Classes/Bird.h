#include "cocos2d.h"

class Bird : public cocos2d::Node
{
public:
  Bird();

private:
  cocos2d::Sprite* mSprite;
  float mVelocity = 0;

  void update(float dt);

  void _setInitialPosition();
  void _updateFallingVelocity(float dt);
};
