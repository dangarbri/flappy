#pragma once
#include "cocos2d.h"

class Pipe : public cocos2d::Node
{
public:
  Pipe();
  void setAsTopPipe(cocos2d::Vec2 bottomPipePosition);

private:
  cocos2d::Sprite* mSprite;

  void _destroyIfOffScreen();
  void update(float dt);
};
