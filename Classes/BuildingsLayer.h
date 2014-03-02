/*
 * BuildingsLayer.h
 *
 *  Created on: Feb 13, 2014
 *      Author: c860
 */
#ifndef BUILDINGSLAYER_H_
#define BUILDINGSLAYER_H_

#include "cocos2d.h"

using namespace cocos2d;

class BuildingsLayer: public cocos2d::CCLayer {
public:
	BuildingsLayer();
	virtual ~BuildingsLayer();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	CREATE_FUNC(BuildingsLayer);

private:
	CCPoint beginPoint;
	CCPoint endPoint;
};

#endif /* BUILDINGSLAYER_H_ */
