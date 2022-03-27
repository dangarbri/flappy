#include "ShowAnchorPoint.h"

USING_NS_CC;

ShowAnchorPoint::ShowAnchorPoint()
{
  autorelease();
  surface = DrawNode::create();
  drawRectOnSurface();
}

void ShowAnchorPoint::onEnter()
{
  Node* owner = getOwner();
  Vec2 ownerPosition = owner->getPosition();
  surface->setPosition(ownerPosition);
  owner->getScene()->addChild(surface, 99999999);
}

void ShowAnchorPoint::drawRectOnSurface()
{
  Rect rect(0, 0, 1, 1);
  surface->drawRect(Vec2{0,0}, Vec2{1, 1}, Color4F::WHITE);
}

