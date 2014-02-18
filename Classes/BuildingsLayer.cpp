/*
 * BuildingsLayer.h
 *
 *  Created on: Feb 13, 2014
 *      Author: c860
 */
#include "BuildingsLayer.h"
#include "TouchListener.h"


using namespace cocos2d;


BuildingsLayer::BuildingsLayer() {
	// TODO Auto-generated constructor stub

}

BuildingsLayer::~BuildingsLayer() {
	// TODO Auto-generated destructor stub
}

bool BuildingsLayer::init(){
	TouchListener::init();
	winSize = CCDirector::sharedDirector()->getVisibleSize();
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSprite* canteen = CCSprite::create("canteen.png");
	canteen->setPosition( ccp(origin.x + winSize.width/2, origin.y + winSize.height/2) );
	this->addChild(canteen);

	CCSprite* building = CCSprite::create("isBuilding.png");
	building->setPosition( ccp(origin.x + winSize.width/2 + 60, origin.y + winSize.height/2 + 60));
	this->addChild(building);

	CCSprite* building2 = CCSprite::create("isBuilding.png");
	building2->setPosition( ccp(origin.x + winSize.width/2 - 120, origin.y + winSize.height/2 + 20));
	this->addChild(building2);

	CCSprite* tree = CCSprite::create("tree.png");
	tree->setPosition( ccp(origin.x + winSize.width/2 - 80, origin.y + winSize.height/2 - 80));
	this->addChild(tree);
	CCSprite* tree2 = CCSprite::create("tree.png");
	tree2->setPosition( ccp(origin.x + winSize.width/2 - 85, origin.y + winSize.height/2 - 85));
	this->addChild(tree2);
	CCSprite* tree5 = CCSprite::create("tree.png");
	tree5->setPosition( ccp(origin.x + winSize.width/2 - 85, origin.y + winSize.height/2 - 85));
	this->addChild(tree5);
	CCSprite* tree6 = CCSprite::create("tree.png");
	tree6->setPosition( ccp(origin.x + winSize.width/2 - 75, origin.y + winSize.height/2 - 90));
	this->addChild(tree6);
	CCSprite* tree3 = CCSprite::create("tree.png");
	tree3->setPosition( ccp(origin.x + winSize.width/2 - 45, origin.y + winSize.height/2 - 45));
	this->addChild(tree3);
	CCSprite* tree4 = CCSprite::create("tree.png");
	tree4->setPosition( ccp(origin.x + winSize.width/2 - 60, origin.y + winSize.height/2 - 60));
	this->addChild(tree4);
	CCSprite* tree7 = CCSprite::create("tree.png");
	tree7->setPosition( ccp(origin.x + winSize.width/2 - 55, origin.y + winSize.height/2 + 45));
	this->addChild(tree7);
	CCSprite* tree8 = CCSprite::create("tree.png");
	tree8->setPosition( ccp(origin.x + winSize.width/2 - 45, origin.y + winSize.height/2 + 60));
	this->addChild(tree8);


	CCSprite* people = CCSprite::create("man_building.png");
	people->setPosition( ccp(origin.x + winSize.width/2 + 85, origin.y + winSize.height/2 + 60));
	this->addChild(people);

	CCSprite* people3 = CCSprite::create("man_building.png");
	people3->setPosition( ccp(origin.x + winSize.width/2 - 105, origin.y + winSize.height/2 + 10));
	this->addChild(people3);

	CCSprite* people2 = CCSprite::create("man_canteen.png");
	people2->setPosition( ccp(origin.x + winSize.width/2 + 30, origin.y + winSize.height/2 - 30));
	this->addChild(people2);

	CCSprite* teachBuilding = CCSprite::create("teachBuilding.png");
	teachBuilding->setPosition( ccp(origin.x + winSize.width/2 + 150, origin.y + winSize.height/2 - 60));
	this->addChild(teachBuilding);

	return true;
}
void BuildingsLayer::registerWithTouchDispatcher()
{
	TouchListener::registerWithTouchDispatcher();
}


bool BuildingsLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchBegan(touch,event);
	return true;
}

void BuildingsLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void BuildingsLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);
}
