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
#include "People/Girl.h"
#include "People/CookMan.h"
#include "People/Worker.h"

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



	/*CookMan* cookMan = CookMan::create();
	cookMan->setPosition(200,100);
	this->addChild(cookMan,4);
	cookMan->moveTo(0,200,300);

	CookMan* cookMan1 = CookMan::create();
	cookMan1->setPosition(200,100);
	this->addChild(cookMan1,4);
	cookMan1->moveTo(1,200,300);

	CookMan* cookMan2 = CookMan::create();
	cookMan2->setPosition(200,100);
	this->addChild(cookMan2,4);
	cookMan2->moveTo(2,200,300);

	CookMan* cookMan3 = CookMan::create();
	cookMan3->setPosition(200,100);
	this->addChild(cookMan3,4);
	cookMan3->moveTo(3,200,300);

	//girl 动画
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

	//worker 动画
	Worker* worker = Worker::create();
	worker->setPosition(300,200);
	this->addChild(worker,4);
	worker->moveTo(0,200,300);

	Worker* worker1 = Worker::create();
	worker1->setPosition(300,200);
	this->addChild(worker1,4);
	worker1->moveTo(1,200,300);

	Worker* worker2 = Worker::create();
	worker2->setPosition(300,200);
	this->addChild(worker2,4);
	worker2->moveTo(2,200,300);

	Worker* worker3 = Worker::create();
	worker3->setPosition(300,200);
	this->addChild(worker3,4);
	worker3->moveTo(3,200,300);*/

	Girl* girl4 = Girl::create();
	girl4->setPosition(200,200);
	this->addChild(girl4,4);
	girl4->BFS(0,0,2,2);

	return true;
}

/*void GameScene::test(float dt){
	CCLog("test");
}*/

