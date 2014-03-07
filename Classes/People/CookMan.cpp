/*
 * CookMan.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: noonnightstorm
 */

#include "/home/noonnightstorm/tool/cocos2d-x-2.2.2/samples/Cpp/farmgame/Classes/People/CookMan.h"

CookMan::CookMan() {
	// TODO Auto-generated constructor stub

}

CookMan::~CookMan() {
	// TODO Auto-generated destructor stub
}

bool CookMan::init() {
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("cook/man/man0.png","cook/man/man0.plist","cook/man/man.ExportJson");
	_armature = CCArmature::create("man");
	return true;
}


