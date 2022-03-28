#include "Pipe.h"
#include "PipePair.h"
#include "Constants.h"

USING_NS_CC;

Pipe::Pipe()
{
  autorelease();
  // Load sprite and content size
  mSprite = Sprite::create("pipe.png");
  mSprite->getTexture()->setAliasTexParameters();
  setContentSize(mSprite->getContentSize());
  mSprite->setAnchorPoint(Vec2{0, 0});
  addChild(mSprite);

  // Set initial position
  setAnchorPoint(Vec2{0.0f, 0.0f});
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
    // puts("Destroying a pipe since it went off screen");
    PipePair* pair = dynamic_cast<PipePair*>(this->getParent());
    pair->onPipeDestroyed();

    // this->removeFromParentAndCleanup(true);
  }
}

void Pipe::setAsTopPipe(Vec2 bottomPipePosition)
{
  mSprite->setFlippedY(true);
  mSprite->setAnchorPoint(Vec2{0, 0});
  float y = bottomPipePosition.y + PIPE_SPACING + PIPE_OFFSET;
  setPositionY(y);
}

