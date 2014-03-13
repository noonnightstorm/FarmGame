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
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

class GameMenuLayer: public TouchListener {
public:
	GameMenuLayer();
	virtual ~GameMenuLayer();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	virtual void foodConsume(float dt);
	virtual void addTeachBuilding(CCObject *pSender, TouchEventType type);
	virtual void addCanteenBuilding(CCObject *pSender, TouchEventType type);
	virtual void closeMenu(CCObject *pSender, TouchEventType type);
	CREATE_FUNC(GameMenuLayer);

private:
	TouchGroup* ul;
	UIWidget* widget;
	UIImageView* menuBtn;
	UILabelAtlas* food_num_label;
	UILabelAtlas* money_num_label;
	UILabelAtlas* student_num_label;
	UILabelAtlas* worker_num_label;
};

#endif /* GAMEMENULAYER_H_ */
