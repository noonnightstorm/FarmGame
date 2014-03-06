/*
 * Girl.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#include "Girl.h"

Girl::Girl() {
	// TODO Auto-generated constructor stub

}

Girl::~Girl() {
	// TODO Auto-generated destructor stub
}

bool Girl::init() {
	/*CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl_Positive_Animation/Girl_Positive_Animation0.png","girl/Girl_Positive_Animation/Girl_Positive_Animation0.plist","girl/Girl_Positive_Animation/Girl_Positive_Animation.ExportJson");
	_armature_positive = CCArmature::create("Girl_Positive_Animation");
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl_Negative_Animation/Girl_Negative_Animation0.png","girl/Girl_Negative_Animation/Girl_Negative_Animation0.plist","girl/Girl_Negative_Animation/Girl_Negative_Animation.ExportJson");
	_armature_negative = CCArmature::create("Girl_Negative_Animation");
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl_Left_Animation/Girl_Left_Animation0.png","girl/Girl_Left_Animation/Girl_Left_Animation0.plist","girl/Girl_Left_Animation/Girl_Left_Animation.ExportJson");
	_armature_left = CCArmature::create("Girl_Left_Animation");
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl_Right_Animation/Girl_Right_Animation0.png","girl/Girl_Right_Animation/Girl_Right_Animation0.plist","girl/Girl_Right_Animation/Girl_Right_Animation.ExportJson");
	_armature_right = CCArmature::create("Girl_Right_Animation");*/
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl/Girl0.png","girl/Girl0.plist","girl/Girl.ExportJson");
	_armature = CCArmature::create("Girl");
	return true;
}

