#include "Bird.h"
#include "Constants.h"

USING_NS_CC;

Bird::Bird()
{
  autorelease();
  mSprite = Sprite::create("bird.png");
  setContentSize(mSprite->getContentSize());
  _setInitialPosition();
  addChild(mSprite);
}

void Bird::update(float dt)
{
  Node::update(dt);
}

void Bird::_setInitialPosition()
{
  Size size = this->getContentSize();
  float x = DESIGN_WIDTH / 2;
  float y = DESIGN_HEIGHT / 2;
  setPosition(Vec2{x, y});
}

