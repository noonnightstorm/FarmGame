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

void Building::building(int MapX,int MapY,string type){
	CCPoint* point = new CCPoint();
	point->setPoint(MapX*45,MapY*45);
	this->setPosition(*point);
	buildingMap.x = MapX;
	buildingMap.y = MapY;
	buildingType = type;
	buildingIndex = res->getBuildingIndex();
	res->addBuildingIndex();

	if(type.compare("Castle") == 0){
		this->initWithFile("castle.png");
	}
	else if(type.compare("Canteen") == 0){
		this->initWithFile("canteen.png");
	}
	else if(type.compare("ClassRoom") == 0){
		this->initWithFile("teachBuilding.png");
	}
	else if(type.compare("DormitoryStu") == 0){
		this->initWithFile("dormitory_stu.png");
	}
	else if(type.compare("DormitoryWrk") == 0){
		this->initWithFile("dormitory_worker.png");
	}
}

void Building::doBuilding(int MapX,int MapY,string type){
	//添加地基
	CCPoint* point = new CCPoint();
	point->setPoint(MapX*45,MapY*45);
	this->setPosition(*point);
	buildingMap.x = MapX;
	buildingMap.y = MapY;
	buildingType = type;
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
	if(buildingType.compare("Castle") == 0){
		this->initWithFile("castle.png");
	}
	else if(buildingType.compare("Canteen") == 0){
		this->initWithFile("canteen.png");
	}
	else if(buildingType.compare("ClassRoom") == 0){
		this->initWithFile("teachBuilding.png");
	}
	else if(buildingType.compare("DormitoryStu") == 0){
		this->initWithFile("dormitory_stu.png");
	}
	else if(buildingType.compare("DormitoryWrk") == 0){
		this->initWithFile("dormitory_worker.png");
	}

	moveBack();
}

void Building::showInfoMenu()
{
	menu = TouchGroup::create();
	menu->addWidget(GUIReader::shareReader()->widgetFromJsonFile("FixMenu/FixMenu.json"));

	res->getMenuLayer()->addChild(menu,6,20);

	widget = static_cast<UIWidget*>(menu->getWidgetByName("Panel_1"));

	UIImageView* buildingView = static_cast<UIImageView*>(widget->getChildByName("building"));

	if(buildingType.compare("Castle") == 0){
		buildingView->loadTexture("castle.png");
	}
	else if(buildingType.compare("Canteen") == 0){
		buildingView->loadTexture("canteen.png");
	}
	else if(buildingType.compare("ClassRoom") == 0){
		buildingView->loadTexture("teachBuilding.png");
	}
	else if(buildingType.compare("DormitoryStu") == 0){
		buildingView->loadTexture("dormitory_stu.png");
	}
	else if(buildingType.compare("DormitoryWrk") == 0){
		buildingView->loadTexture("dormitory_worker.png");
	}

	UIButton* cancelBtn = static_cast<UIButton*>(widget->getChildByName("choose"));
	cancelBtn->setTouchEnabled(true);
	cancelBtn->addTouchEventListener(this,toucheventselector(Building::closeInfoMenu));
}

void Building::closeInfoMenu()
{
	res->getMenuLayer()->removeChildByTag(20);
}
