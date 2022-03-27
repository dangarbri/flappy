#include "PipePair.h"
#include <cassert>

PipePair::PipePair()
{
    pipes[0] = new Pipe();
    pipes[1] = new Pipe();
    _positionTopPipe();
    addChild(pipes[0], 0);
    addChild(pipes[1], 1);
    setPosition(0, 0);
}

Pipe* PipePair::getPipe(int index)
{
  assert(index < 2);
  return pipes[index];
}

void PipePair::_positionTopPipe()
{
  // By default, the pipe spawns on the bottom.
  // This function positions the upper pipe to be facing down
  // and be the appropriate distance away.
  Pipe* topPipe = pipes[1];
  topPipe->setAsTopPipe(pipes[0]->getPosition());
}
