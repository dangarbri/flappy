#include "Modules/ExitOnEscape.hpp"

USING_NS_CC;

ExitOnEscape::ExitOnEscape()
{
  // Create the event dispatcher
  mKeyboardListener = EventListenerKeyboard::create();
  mKeyboardListener->onKeyPressed = CC_CALLBACK_2(ExitOnEscape::onKeyPressed, this);
  autorelease();
  setName("ExitOnEscape");
};

void ExitOnEscape::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
  if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
  {
    Director::getInstance()->end();
  }
}

void ExitOnEscape::onAdd()
{
  Node* owner = getOwner();
  owner->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mKeyboardListener, owner);
}

