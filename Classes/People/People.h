/*
 * People.h
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

class People: public cocos2d::CCNode {
public:
	People();
	virtual ~People();
	//bool init();
	void setPosition(float new_x,float new_y);
/*	float getX();
	float getY();*/
	CCArmature* getArmature();
	//移动函数
	void moveTo(float toX,float toY);
	virtual void goForward(float dt);
	/*virtual void goBackward(float dt);
	virtual void goLeft(float dt);
	virtual void goRight(float dt);*/
	//CREATE_FUNC(People);

protected:
	//当前位置
	float _x;
	float _y;
	//移动的位置
	float _toX;
	float _toY;
	//动画变量
	CCArmature* _armature;
};

#endif /* PEOPLE_H_ */
