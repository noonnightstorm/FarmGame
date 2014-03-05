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
#include "People/Girl.h"

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

	//test 动画
	Girl* girl = Girl::create();
	girl->setPosition(200,200);
	this->addChild(girl,4);
	girl->moveTo(0,200,300);

	Girl* girl2 = Girl::create();
	girl2->setPosition(200,200);
	this->addChild(girl2,4);
	girl2->moveTo(1,200,300);

	Girl* girl3 = Girl::create();
	girl3->setPosition(200,200);
	this->addChild(girl3,4);
	girl3->moveTo(2,200,300);

	Girl* girl4 = Girl::create();
	girl4->setPosition(200,200);
	this->addChild(girl4,4);
	girl4->moveTo(3,200,300);

	return true;
}

/*void GameScene::test(float dt){
	CCLog("test");
}*/

