#pragma once

#include "cocos2d.h"

class ShowBoundingBox : public cocos2d::Component
{
public:
  ShowBoundingBox();

private:
  cocos2d::DrawNode* surface;
  void onEnter();
  void onAdd();
  void update(float dt);
};
