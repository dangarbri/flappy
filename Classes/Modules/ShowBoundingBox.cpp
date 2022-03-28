#include "ShowBoundingBox.h"

USING_NS_CC;

ShowBoundingBox::ShowBoundingBox()
{
  autorelease();
  setName("BoundingBox");
  surface = DrawNode::create();
}

void ShowBoundingBox::onAdd()
{
  Node* owner = getOwner();
  Size size = owner->getContentSize();
  surface->setContentSize(size);
  surface->drawRect(Vec2{0, 0}, Vec2{size.width, size.height}, Color4F::WHITE);
}

void ShowBoundingBox::onEnter()
{
  getOwner()->addChild(surface, 999999);
}

void ShowBoundingBox::update(float dt)
{
  Node* owner = getOwner();
}

