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
  mSprite->setAnchorPoint(Vec2{0, 0});
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
  setAnchorPoint(Vec2{0.5f, 0.5f});
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

bool Bird::collides(PipePair *pipePair)
{
  Pipe* bottom = pipePair->getPipe(0);
  Pipe* top = pipePair->getPipe(1);
  Rect bbox = this->getBoundingBox();
  // Shrink the bird's bounding box a little bit for
  // collision detection purposes. Gives the user some
  // room to "scrape" the pipes.
  bbox.origin.x += 4;
  bbox.origin.y += 4;
  bbox.size.width -= 8;
  bbox.size.height -= 8;
  // Return true if the bird intersects either pipe
  return bbox.intersectsRect(bottom->getBoundingBox()) ||
         bbox.intersectsRect(top->getBoundingBox());
}
