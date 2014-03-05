/*
 * People.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#include "/home/noonnightstorm/tool/cocos2d-x-2.2.2/samples/Cpp/farmgame/Classes/People/People.h"

People::People() {
	// TODO Auto-generated constructor stub
}

People::~People() {
	// TODO Auto-generated destructor stub
}

/*
bool People::init() {
	return true;
}
*/

void People::setPosition(float new_x,float new_y){
	_x = new_x;
	_y = new_y;
	_toX = _x;
	_toY = _y;
	_armature->setPosition(new_x,new_y);
}

/*float People::getX(){
	return _x;
}

float People::getY(){
	return _y;
}*/

CCArmature* People::getArmature(){
	return _armature;
}

void People::moveTo(float toX,float toY){
	_toX = toX;
	_toY = toY;
	_armature->getAnimation()->playByIndex(0);
	//向前走
	this->schedule(schedule_selector(People::goForward),0.5);
}

void People::goForward(float dt){
	_y -= 1.5;
	_armature->setPosition(_x,_y);
}

