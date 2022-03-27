#pragma once
#include "cocos2d.h"
#include "PipePair.h"

class Bird : public cocos2d::Node
{
public:
  Bird();
  bool collides(PipePair* pipePair);

private:
  cocos2d::Sprite* mSprite;
  cocos2d::EventListenerKeyboard* mListener;
  float mVelocity = 0;

  void update(float dt);

  void _setInitialPosition();
  void _initializeKeyboardListener();
  void _onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
  void _updateFallingVelocity(float dt);
  void _jump();
};
