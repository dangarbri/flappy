/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "Modules/ExitOnEscape.hpp"
#include "Constants.h"
#include <cmath>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    mTimer = new ElapsedTime();
    mBird = new Bird();
    mBackground = Sprite::create("background.png");
    mBackground->setAnchorPoint(Vec2{0, 0});
    mBackground->getTexture()->setAliasTexParameters();
    mGround = Sprite::create("ground.png");
    mGround->setAnchorPoint(Vec2{0, 0});
    mGround->getTexture()->setAliasTexParameters();

    this->addChild(mBackground, 0);
    this->addChild(mGround, 50);
    this->addChild(mBird, 100);
    this->addChild(new Pipe(), 75);

    this->addComponent(new ExitOnEscape());
    this->addComponent(mTimer);
    scheduleUpdate();

    return true;
}

void HelloWorld::update(float dt)
{
  // Run parent update function
  Scene::update(dt);
  mBgScroll = (mBgScroll + BACKGROUND_SCROLL_SPEED * dt);
  mFloorScroll = (mFloorScroll + GROUND_SCROLL_SPEED * dt);

  // Update sprite positions
  mBackground->setPositionX(-mBgScroll);
  mGround->setPositionX(-mFloorScroll);

  // Determine if sprites should wrap back to the right
  if (mBgScroll >= BACKGROUND_LOOP_POINT)
  {
    mBgScroll = 0;
  }
  if (mFloorScroll >= DESIGN_WIDTH)
  {
    mFloorScroll = 0;
  }

  float elapsedTime = mTimer->getElapsedTime();
  if (elapsedTime > PIPE_SPAWN_DELAY_S)
  {
    addChild(new Pipe());
    mTimer->resetTimer();
  }
}
