/*
 * GameScene.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#include "GameScene.h"
#include "GameBGLayer.h"
#include "GameMenuLayer.h"

using namespace cocos2d;

GameScene::GameScene() {
	// TODO Auto-generated constructor stub

}

GameScene::~GameScene() {
	// TODO Auto-generated destructor stub
}

bool GameScene::init()
{

	//run the super init()
	CCScene::init();
	CCLayer* bGLayer = GameBGLayer::create();
	this->addChild(bGLayer,0);
	CCLayer* menuLayer = GameMenuLayer::create();
	this->addChild(menuLayer,1);
	return true;
}



