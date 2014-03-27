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
#include "People/PeopleMoveObject.h"

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
	this->initWithFile("building.png");
	GameResources* res = GameResources::GetInstance();
	worker = 0;
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
	//注册触摸方法，为调试方便暂时放在这里实现
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

void Building::building(int MapX,int MapY){
	CCPoint* point = new CCPoint();
	point->setPoint(MapX*45,MapY*45);
	this->setPosition(*point);
	buildingMap.x = MapX;
	buildingMap.y = MapY;
	buildingIndex = res->getBuildingIndex();
	res->addBuildingIndex();

	refreshView();

}

void Building::doBuilding(int MapX,int MapY){
	//添加地基
	CCPoint* point = new CCPoint();
	point->setPoint(MapX*45,MapY*45);
	this->setPosition(*point);
	buildingMap.x = MapX;
	buildingMap.y = MapY;
	buildingIndex = res->getBuildingIndex();
	res->addBuildingIndex();

	//人物移动
	moveToBuilding();
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(Building::beginToBuilding),"beginToBuilding",NULL);
}

void Building::moveToBuilding(){
	CCPoint tmpPoint = res->getCastleMap();
	Worker* worker = Worker::create();
	worker->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
	res->getBuildingLayer()->addChild(worker,4);
	worker->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y,buildingIndex,"beginToBuilding");
	res->setPosValue(buildingMap.x, buildingMap.y, 1);
}
void Building::moveBack(){
	CCPoint tmpPoint = res->getCastleMap();
	Worker* worker = Worker::create();
	worker->setPosition(buildingMap.x * 45,buildingMap.y * 45);
	res->getBuildingLayer()->addChild(worker,4);
	worker->BFS((int)buildingMap.x,(int)buildingMap.y,(int)tmpPoint.x,(int)tmpPoint.y,0,"moveBack");
}

void Building::beginToBuilding(CCObject* obj){
	PeopleMoveObject* pobj = (PeopleMoveObject*)obj;
	if(pobj->getBuildingIndex() == buildingIndex){
		//开始播放修建动画
		GameResources* res = GameResources::GetInstance();
		this->initWithFile("blank.png");
		CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Building/Building0.png","Building/Building0.plist","Building/Building.ExportJson");
		_armature = CCArmature::create("Building");
		_armature->setPosition(buildingMap.x*45,buildingMap.y*45);
		_armature->getAnimation()->playByIndex(0);
		res->getBuildingLayer()->addChild(_armature,6);
		//定时60秒就会完成
		this->scheduleOnce(schedule_selector(Building::finishBuilding),5);
	}
}

void Building::finishBuilding(){
	res->getBuildingLayer()->removeChild(_armature);
	refreshView();
	moveBack();
}

void Building::showInfoMenu()
{
	menu = TouchGroup::create();
	menu->addWidget(GUIReader::shareReader()->widgetFromJsonFile("FixMenu/FixMenu.json"));

	res->getMenuLayer()->addChild(menu,6,20);

	widget = static_cast<UIWidget*>(menu->getWidgetByName("Panel_1"));

	buildingView = static_cast<UIImageView*>(widget->getChildByName("building"));
	sub_btn = static_cast<UIButton*>(widget->getChildByName("sub"));
	add_btn = static_cast<UIButton*>(widget->getChildByName("plus"));

	//分派到各个子类初始化
	infoMenuInit();

	UIButton* okBtn = static_cast<UIButton*>(widget->getChildByName("choose"));
	okBtn->setTouchEnabled(true);
	okBtn->addTouchEventListener(this,toucheventselector(Building::closeInfoMenu));
}

void Building::closeInfoMenu()
{
	res->getMenuLayer()->removeChildByTag(20);
}
void Building::infoMenuInit()
{

}
void Building::setInfoMenu(string about, string price, string wood, string maxPeople, string currentPeople)
{
	UILabel* l_about = static_cast<UILabel*>(menu->getWidgetByName("introduce"));
	UILabel* l_price = static_cast<UILabel*>(menu->getWidgetByName("price"));
	UILabel* l_wood = static_cast<UILabel*>(menu->getWidgetByName("wood"));
	UILabel* l_maxPeople = static_cast<UILabel*>(menu->getWidgetByName("maxPeople"));

	l_about->setText(about);
	l_price->setText(price);
	l_wood->setText(wood);
	l_maxPeople->setText(maxPeople);

	setPeople(currentPeople);
}
void Building::setPeople(string num)
{
	UILabel* peopleNum = static_cast<UILabel*>(menu->getWidgetByName("peopleNum"));
	peopleNum->setText(num);
}
void Building::refreshView()
{

}
void Building::goToWork()
{

}
void Building::goBackToCastle()
{

}
