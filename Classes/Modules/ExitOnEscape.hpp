#pragma once

#include "cocos2d.h"

class ExitOnEscape : public cocos2d::Component
{
public:
  ExitOnEscape();

private:
  cocos2d::EventListenerKeyboard* mKeyboardListener;

  void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

  void onAdd();
};
