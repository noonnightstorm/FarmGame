/*
 * TouchListener.h
 *
 *  Created on: Feb 13, 2014
 *      Author: C860
 */
#ifndef TOUCHLISTENER_H_
#define TOUCHLISTENER_H_

#include "cocos2d.h"

using namespace cocos2d;

class TouchListener : public cocos2d::CCLayer {
public:
	TouchListener();
	virtual ~TouchListener();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	CREATE_FUNC(TouchListener);

protected:
	CCSize winSize;
	CCPoint origin;
	CCPoint beginPoint;
	CCPoint endPoint;
};

#endif /* TOUCHLISTENER_H_ */
