/*
 * StudentGirl.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: noonnightstorm
 */

#include "/home/noonnightstorm/tool/cocos2d-x-2.2.2/samples/Cpp/farmgame/Classes/StudentGirl.h"

Student_Girl::Student_Girl() {
	// TODO Auto-generated constructor stub
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl_Positive_Animation/Girl_Positive_Animation0.png","girl/Girl_Positive_Animation/Girl_Positive_Animation0.plist","girl/Girl_Positive_Animation/Girl_Positive_Animation.ExportJson");
	_armature = CCArmature::create("Girl_Positive_Animation");
	_armature->getAnimation()->stop();

}

Student_Girl::~Student_Girl() {
	// TODO Auto-generated destructor stub
}

void Student_Girl::setPosition(float new_x,float new_y){
	_x = new_x;
	_y = new_y;
	_toX = _x;
	_toY = _y;
	_armature->setPosition(new_x,new_y);
}

CCArmature* Student_Girl::getArmature(){
	return _armature;
}

void Student_Girl::moveTo(CCNode* obj,float toX,float toY){
	_toX = toX;
	_toY = toY;
	//向前走
	_armature->getAnimation()->playByIndex(0);
	//obj->schedule(schedule_selector(Student_Girl::goForward),3);
}

void Student_Girl::goForward(float dt){
	CCLog("move: %f",_y);
	_y += 5;
	_armature->setPosition(_x,_y);
}
