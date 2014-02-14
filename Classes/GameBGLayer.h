/*
 * GameBGLayer.h
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMEBGLAYER_H_
#define GAMEBGLAYER_H_

#include "cocos2d.h"
#include "TouchListener.h"

using namespace cocos2d;

class GameBGLayer: public TouchListener {
public:
	GameBGLayer();
	virtual ~GameBGLayer();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	CREATE_FUNC(GameBGLayer);

private:
	CCSprite* bGSprite;
};

#endif /* GAMEBGLAYER_H_ */
