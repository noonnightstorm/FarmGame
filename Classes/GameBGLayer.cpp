/*
 * GameBGLayer.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#include "GameBGLayer.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

GameBGLayer::GameBGLayer() {
	// TODO Auto-generated constructor stub

}

GameBGLayer::~GameBGLayer() {
	// TODO Auto-generated destructor stub
}

bool GameBGLayer::init(){
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite* pSprite = CCSprite::create("background.png");
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
	this->addChild(pSprite, 0);
	return true;
}
