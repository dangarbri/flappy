#include "Pipe.h"
#include "Constants.h"

USING_NS_CC;

Pipe::Pipe()
{
  autorelease();
  // Load sprite and content size
  mSprite = Sprite::create("pipe.png");
  mSprite->getTexture()->setAliasTexParameters();
  setContentSize(mSprite->getContentSize());
  addChild(mSprite);

  // Set initial position
  mSprite->setAnchorPoint(Vec2{0, 1.0f});
  setAnchorPoint(Vec2{0.0f, 0.0});
  setPositionX(DESIGN_WIDTH);

  // Make sure update gets called
  scheduleUpdate();
}

void Pipe::update(float dt)
{
  Node::update(dt);

  float x = getPositionX();
  x += PIPE_SCROLL * dt;
  setPositionX(x);

  _destroyIfOffScreen();
}

void Pipe::_destroyIfOffScreen()
{
  float x = getPositionX();
  Size size = getContentSize();
  if ((x + size.width) < 0)
  {
    this->removeFromParentAndCleanup(true);
  }
}

void Pipe::setAsTopPipe(Vec2 bottomPipePosition)
{
  mSprite->setFlippedY(true);
  mSprite->setAnchorPoint(Vec2{0, 0});
  float y = bottomPipePosition.y + PIPE_SPACING;
  setPositionY(y);
}
