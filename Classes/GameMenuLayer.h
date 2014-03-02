/*
 * GameMenuLayer.h
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMEMENULAYER_H_
#define GAMEMENULAYER_H_

#include "cocos2d.h"
#include "TouchListener.h"

using namespace cocos2d;

class GameMenuLayer: public TouchListener {
public:
	GameMenuLayer();
	virtual ~GameMenuLayer();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	virtual void test(CCObject *pSender);
	CREATE_FUNC(GameMenuLayer);
};

#endif /* GAMEMENULAYER_H_ */
