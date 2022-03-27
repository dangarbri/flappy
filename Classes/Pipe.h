#include "cocos2d.h"

class Pipe : public cocos2d::Node
{
public:
  Pipe();
  ~Pipe();

private:
  void update(float dt);

  cocos2d::Sprite* mSprite;
};
