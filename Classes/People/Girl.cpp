/*
 * Girl.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#include "/home/noonnightstorm/tool/cocos2d-x-2.2.2/samples/Cpp/farmgame/Classes/People/Girl.h"

Girl::Girl() {
	// TODO Auto-generated constructor stub

}

Girl::~Girl() {
	// TODO Auto-generated destructor stub
}

bool Girl::init() {
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl_Positive_Animation/Girl_Positive_Animation0.png","girl/Girl_Positive_Animation/Girl_Positive_Animation0.plist","girl/Girl_Positive_Animation/Girl_Positive_Animation.ExportJson");
	_armature = CCArmature::create("Girl_Positive_Animation");
	this->addChild(_armature);
	_armature->getAnimation()->stop();
	return true;
}

