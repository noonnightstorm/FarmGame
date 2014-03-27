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
#include "AddBuildingLayer.h"
#include <string>

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

class GameMenuLayer: public cocos2d::CCLayer {
public:
	GameMenuLayer();
	virtual ~GameMenuLayer();
	bool init();
	/*virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);*/
	/*virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);*/
	virtual void foodConsume(float dt);
	virtual void showMenu(CCObject *pSender, TouchEventType type);
	virtual void closeMenu(CCObject *pSender, TouchEventType type);
	virtual void addBuilding();
	virtual void showConfirmMenu(CCObject *pSender, TouchEventType type);
	void confirmAddBuilding();
	void cancelAddBuilding();
	void getNewPosition(CCObject* obj);
	void finishBuild(CCObject* obj);
	void closeTips();
	void initConfirmMenu(string about, string price, string wood, string maxPeople, TouchGroup* menu);
	CREATE_FUNC(GameMenuLayer);

private:
	TouchGroup* ul;
	TouchGroup* menu;
	UIWidget* widget;
	UIWidget* m_widget;
	UIImageView* menuBtn;
	UILabelAtlas* food_num_label;
	UILabelAtlas* money_num_label;
	UILabelAtlas* student_free_num_label;
	UILabelAtlas* worker_free_num_label;
	UILabelAtlas* student_total_num_label;
	UILabelAtlas* worker_total_num_label;
	UIButton* menu_btn;
	UIButton* m_backBtn;
	UIButton* m_b1;
	UIButton* m_b2;
	UIButton* m_b3;
	UIButton* m_b4;
	AddBuildingLayer* temp;
	CCSize winSize;
	CCPoint origin;
	string bType;
};

#endif /* GAMEMENULAYER_H_ */
