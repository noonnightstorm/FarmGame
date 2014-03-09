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
	_armature->setPosition(_x,_y);
}

CCArmature* People::getArmature(){
	return _armature;
}

void People::moveTo(int type,float toX,float toY){
	_toX = toX;
	_toY = toY;
	this->removeAllChildren();
	this->addChild(_armature);
	//向前走
	if(type == GO_POSITIVE){
		this->schedule(schedule_selector(People::goForward),0.5,10,0);
		_armature->getAnimation()->play("positive");
	}
	else if(type == GO_NEGATIVE){
		this->schedule(schedule_selector(People::goBackward),0.5);
		_armature->getAnimation()->play("negative");
	}
	else if(type == GO_LEFT){
		this->schedule(schedule_selector(People::goLeft),0.5);
		_armature->getAnimation()->play("left");
	}
	else if(type == GO_RIGHT){
		this->schedule(schedule_selector(People::goRight),0.5);
		_armature->getAnimation()->play("right");
	}
}

void People::goForward(float dt){
	_y -= 1.5;
	_armature->setPosition(_x,_y);
}

void People::goBackward(float dt){
	_y += 1.5;
	_armature->setPosition(_x,_y);
}

void People::goLeft(float dt){
	_x -= 1.5;
	_armature->setPosition(_x,_y);
}

void People::goRight(float dt){
	_x += 1.5;
	_armature->setPosition(_x,_y);
}
