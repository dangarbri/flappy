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
  mSprite->setAnchorPoint(Vec2{0, 0});
  setAnchorPoint(Vec2{0, 1.0});
  setPositionX(DESIGN_WIDTH);
  setPositionY(random<float>(DESIGN_HEIGHT / 4, 10));

  // Make sure update gets called
  scheduleUpdate();
}

void Pipe::update(float dt)
{
  Node::update(dt);

  float x = getPositionX();
  x += PIPE_SCROLL * dt;
  setPositionX(x);
}

Pipe::~Pipe()
{
  puts("Pipe destroyed");
}
