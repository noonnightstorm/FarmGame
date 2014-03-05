/*
 * StudentGirl.h
 *
 *  Created on: Mar 4, 2014
 *      Author: noonnightstorm
 */

#ifndef STUDENTGIRL_H_
#define STUDENTGIRL_H_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

class Student_Girl {
public:
	Student_Girl();
	virtual ~Student_Girl();
	void setPosition(float new_x,float new_y);
	CCArmature* getArmature();
	//移动函数
	void moveTo(CCNode* obj,float toX,float toY);
	virtual void goForward(float dt);
	/*virtual void goBackward(float dt);
	virtual void goLeft(float dt);
	virtual void goRight(float dt);*/

private:
	//当前位置
	float _x;
	float _y;
	//移动的位置
	float _toX;
	float _toY;
	//动画变量
	CCArmature* _armature;
};

#endif /* STUDENTGIRL_H_ */
