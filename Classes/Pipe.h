#include "cocos2d.h"

class Pipe : public cocos2d::Node
{
public:
  Pipe();

private:
  cocos2d::Sprite* mSprite;

  void _destroyIfOffScreen();
  void update(float dt);
};
