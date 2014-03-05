/*
 * People.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#include "People.h"

People::People() {
	// TODO Auto-generated constructor stub
}

People::~People() {
	// TODO Auto-generated destructor stub
}

void People::setPosition(float new_x,float new_y){
	_x = new_x;
	_y = new_y;
	_toX = _x;
	_toY = _y;
	_armature_positive->setPosition(_x,_y);
	_armature_negative->setPosition(_x,_y);
	_armature_left->setPosition(_x,_y);
	_armature_right->setPosition(_x,_y);
}

CCArmature* People::getPositiveArmature(){
	return _armature_positive;
}
CCArmature* People::getNegativeArmature(){
	return _armature_negative;
}
CCArmature* People::getLeftArmature(){
	return _armature_left;
}
CCArmature* People::getRightArmature(){
	return _armature_right;
}

void People::moveTo(int type,float toX,float toY){
	_toX = toX;
	_toY = toY;
	//向前走
	if(type == GO_POSITIVE){
		this->removeAllChildren();
		this->addChild(_armature_positive);
		this->schedule(schedule_selector(People::goForward),0.5);
		_armature_positive->getAnimation()->playByIndex(0);
	}
	else if(type == GO_NEGATIVE){
		this->removeAllChildren();
		this->addChild(_armature_negative);
		this->schedule(schedule_selector(People::goBackward),0.5);
		_armature_negative->getAnimation()->playByIndex(0);
	}
	else if(type == GO_LEFT){
		this->removeAllChildren();
		this->addChild(_armature_left);
		this->schedule(schedule_selector(People::goLeft),0.5);
		_armature_left->getAnimation()->playByIndex(0);
	}
	else if(type == GO_RIGHT){
		this->removeAllChildren();
		this->addChild(_armature_right);
		this->schedule(schedule_selector(People::goRight),0.5);
		_armature_right->getAnimation()->playByIndex(0);
	}
}

void People::goForward(float dt){
	_y -= 1.5;
	_armature_positive->setPosition(_x,_y);
}

void People::goBackward(float dt){
	_y += 1.5;
	_armature_negative->setPosition(_x,_y);
}

void People::goLeft(float dt){
	_x -= 1.5;
	_armature_left->setPosition(_x,_y);
}

void People::goRight(float dt){
	_x += 1.5;
	_armature_right->setPosition(_x,_y);
}
