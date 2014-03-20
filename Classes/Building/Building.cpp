/*
 * Building.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#include "Building.h"
#include "GameResources.h"
#include "cocos-ext.h"
#include "People/Worker.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

Building::Building() {
	// TODO Auto-generated constructor stub

}

Building::~Building() {
	// TODO Auto-generated destructor stub
}

Building* Building::create(const char *pszFileName)
{
	Building *pobSprite = new Building();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

bool Building::init() {
	if (!CCSprite::init() )
	{
		return false;
	}

	return true;
}

void Building::setMapIndex(int x,int y){
	buildingMap.x = x;
	buildingMap.y = y;
}

void Building::setBuildingIndex(int index){
	buildingIndex = index;
}

void Building::onEnter()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	//添加一个触摸委托给dispatcher的列表,委托对象this,
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
	CCSprite::onEnter();
}

void Building::onExit()
{
	//移除监听
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}

CCRect Building::getRect()
{
	return CCRectMake(getPositionX() - getContentSize().width * getAnchorPoint().x,
						  getPositionY() - getContentSize().height * getAnchorPoint().y,
						  getContentSize().width, getContentSize().height);
}

bool Building::ccTouchBegan(CCTouch* touch, CCEvent* event)
{

    CCPoint touchLocation = touch->getLocation(); // 返回GL坐标
    CCPoint localPos = convertToNodeSpace(touchLocation);
    CCRect rc = getRect();
    rc.origin = CCPointZero;
    bool isTouched = rc.containsPoint(localPos);
    if(isTouched)
    {
        onClick();
        return true;
    }
}
void Building::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
}
void Building::ccTouchEnded(CCTouch* pTouch, CCEvent* event)
{
}
void Building::onClick()
{

}

void Building::doBuilding(){
	GameResources* res = GameResources::GetInstance();
	CCPoint tmpPoint = res->getCastleMap();

	Worker* worker = Worker::create();
	worker->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
	res->getBuildingLayer()->addChild(worker,4);
	worker->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y);
}

