/**
 * This class when attached to a node will render a small
 * white dot at the node's specified position in the scene.
 *
 * This can be used to help debug anchor point errors. You will
 * be able to see where the anchor point is in the scene and use
 * that information to adjust it for your sprite as needed.
 *
 * To use, simply add this component to your node.
 */

#include "cocos2d.h"

class ShowAnchorPoint : public cocos2d::Component
{
public:
  ShowAnchorPoint();

private:
  cocos2d::DrawNode* surface;
  void onEnter();
  void drawRectOnSurface();
};
