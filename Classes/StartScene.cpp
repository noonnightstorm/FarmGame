/*
 * StartScene.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#include "StartScene.h"
#include "GameScene.h"
#include "cocos-ext.h"


using namespace cocos2d;
using namespace cocos2d::extension;

StartScene::StartScene() {
	// TODO Auto-generated constructor stub

}

StartScene::~StartScene() {
	// TODO Auto-generated destructor stub
}

bool StartScene::init()
{

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	// run the super init()
	CCScene::init();

	// add a background layer to scene
	CCLayerGradient* bglayer = CCLayerGradient::create();
	ccColor4B s_color = {187,255,255,255};
	ccColor4B e_color = {255,255,255,255};
	bglayer->initWithColor(s_color,e_color);
	this->addChild(bglayer,0);

	// add a start layer to scene
	CCLayer* startlayer = CCLayer::create();
	CCLabelTTF* startgametitle = CCLabelTTF::create("Farm Game", "Marker Felt", 36);

	ccColor3B textcolor = {142,229,238};
	startgametitle->setColor(textcolor);

	startgametitle->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 + 50));
	startlayer->addChild(startgametitle,0);

	CCMenuItemImage* startbtn = CCMenuItemImage::create("startgamebtn.png",
			"quitgamebtn.png",
			startlayer,
			menu_selector(StartScene::menustartcallback));
	startbtn->setPosition(ccp(origin.x + visibleSize.width/2 - startbtn->getContentSize().width/2,origin.y + visibleSize.height/2 - 40));

	CCMenuItemImage* quitbtn = CCMenuItemImage::create("quitgamebtn.png",
			"startgamebtn.png",
			startlayer,
			menu_selector(StartScene::menuquitcallback));
	quitbtn->setPosition(ccp(origin.x + visibleSize.width/2 + quitbtn->getContentSize().width/2,origin.y + visibleSize.height/2 - 40));

	CCMenu* startmenu = CCMenu::create(startbtn,quitbtn,NULL);
	startmenu->setPosition(CCPointZero);
	startlayer->addChild(startmenu,1);

	this->addChild(startlayer,1);

	//添加动画
	//从导出文件异步加载动画
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("EnemyAnimation0.png","EnemyAnimation0.plist","tauren.ExportJson");

	//根据动画名称创建动画精灵
	CCArmature *armature = CCArmature::create("tauren");

	//播放指定动作
	armature->getAnimation()->playByIndex(0);

	//修改属性
	armature->setScale(0.5f);

	//设置动画精灵位置
	armature->setPosition(200,300);
	//添加到当前页面
	this->addChild(armature,2);
	return true;
}
void StartScene::menustartcallback(CCObject* pSender)
{
	CCScene* gameScene = GameScene::create();
	//变换的时候可以加一些效果，可以迟点再修改
	CCDirector::sharedDirector()->replaceScene(gameScene);
}
void StartScene::menuquitcallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}
