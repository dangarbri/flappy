#include "Bird.h"
#include "Constants.h"

USING_NS_CC;

Bird::Bird()
{
  autorelease();
  mSprite = Sprite::create("bird.png");
  mSprite->getTexture()->setAliasTexParameters();
  setContentSize(mSprite->getContentSize());
  _setInitialPosition();
  _initializeKeyboardListener();
  addChild(mSprite);
  scheduleUpdate();
}

void Bird::update(float dt)
{
  Node::update(dt);
  _updateFallingVelocity(dt);
}

void Bird::_setInitialPosition()
{
  Size size = this->getContentSize();
  float x = DESIGN_WIDTH / 2;
  float y = DESIGN_HEIGHT / 2;
  setPosition(Vec2{x, y});
}

void Bird::_updateFallingVelocity(float dt)
{
  mVelocity = mVelocity - GRAVITY * dt;

  float y = getPositionY();
  setPositionY(y + mVelocity);
}

void Bird::_initializeKeyboardListener()
{
    mListener = EventListenerKeyboard::create();
    mListener->onKeyPressed = CC_CALLBACK_2(Bird::_onKeyPressed, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(mListener, this);
}

void Bird::_onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event)
{
  if (key == EventKeyboard::KeyCode::KEY_SPACE)
  {
    _jump();
  }
}

void Bird::_jump()
{
  mVelocity = JUMP_VELOCITY;
}
