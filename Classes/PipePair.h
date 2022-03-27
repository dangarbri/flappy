#pragma once

#include "cocos2d.h"
#include "Pipe.h"

class PipePair : public cocos2d::Node
{
public:
  PipePair(float yPos);
  Pipe* getPipe(int index);
  void pause();

private:
  Pipe* pipes[2];
  void _positionTopPipe();
};
