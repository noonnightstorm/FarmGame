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
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("People/girl/Girl0.png","People/girl/Girl0.plist","People/girl/Girl.ExportJson");
	_armature = CCArmature::create("Girl");
	return true;
}

