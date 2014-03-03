/*
 * GameScene.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#include "GameScene.h"
#include "GameBGLayer.h"

#include "BuildingsLayer.h"
#include "GameMenuLayer.h"
#include "AddBuildingLayer.h"

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

	//添加地图层（背景层）
	CCLayer* bGLayer = GameBGLayer::create();
	this->addChild(bGLayer,0);

	//添加建筑层
	CCLayer* BDLayer = BuildingsLayer::create();
	this->addChild(BDLayer,1);

	//添加菜单层
	CCLayer* MenuLayer = GameMenuLayer::create();
	this->addChild(MenuLayer,2);

	//添加操作层
	CCLayer* ABLayer = AddBuildingLayer::create();
	//this->addChild(ABLayer,3);

	return true;
}



