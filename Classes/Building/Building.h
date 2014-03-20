/*
 * Building.h
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#ifndef BUILDING_H_
#define BUILDING_H_

#include "cocos2d.h"

using namespace cocos2d;

class Building : public CCSprite, public CCTouchDelegate {
public:
	Building();
	virtual ~Building();
	bool init();
	static Building* create(const char *filename);

	CCRect getRect();

	void setMapIndex(int x,int y);
	void setBuildingIndex(int index);

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//拖动
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开

    virtual void onEnter();
    virtual void onExit();

    virtual void onClick();

	void doBuilding();

private:
	CCPoint buildingMap;
	int buildingIndex;
};

#endif /* BUILDING_H_ */
