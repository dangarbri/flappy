#pragma once

#include "cocos2d.h"
#include "Pipe.h"

class PipePair : public cocos2d::Node
{
public:
  PipePair(float yPos);
  Pipe* getPipe(int index);
  void pause();
  void onPipeDestroyed();

private:
  int mDestroyCount = 0;
  Pipe* pipes[2];
  void _positionTopPipe();
};
