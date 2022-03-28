#include "PipePair.h"
#include "Constants.h"
#include <cassert>

PipePair::PipePair(float yPos)
{
    autorelease();
    setName("pipe pair");
    pipes[0] = new Pipe();
    pipes[0]->setPositionY(yPos - PIPE_OFFSET);
    pipes[1] = new Pipe();
    _positionTopPipe();
    addChild(pipes[0], 0);
    addChild(pipes[1], 1);
    setPosition(0, 0);
    scheduleUpdate();
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

void PipePair::pause()
{
  Node::pause();
  pipes[0]->pause();
  pipes[1]->pause();
}

void PipePair::onPipeDestroyed()
{
  // When the pipes go off screen they destroy
  // themselves. When that happens, this should
  // also destroy itself.
  mDestroyCount += 1;
  if (mDestroyCount == 2)
  {
    removeFromParentAndCleanup(true);
  }
}

