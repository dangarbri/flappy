#include "cocos2d.h"
#include "Pipe.h"

class PipePair : public cocos2d::Node
{
public:
  PipePair();

private:
  Pipe* pipes[2];
  Pipe* getPipe(int index);
  void _positionTopPipe();
};
