#include "cocos2d.h"

class Bird : public cocos2d::Node
{
public:
  Bird();

private:
  void update(float dt);

  void _setInitialPosition();

  cocos2d::Sprite* mSprite;
};
