/*
 * CookMan.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: noonnightstorm
 */

#include "CookMan.h"

CookMan::CookMan() {
	// TODO Auto-generated constructor stub

}

CookMan::~CookMan() {
	// TODO Auto-generated destructor stub
}

bool CookMan::init() {
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("People/cook/man/man0.png","People/cook/man/man0.plist","People/cook/man/man.ExportJson");
	_armature = CCArmature::create("man");
	return true;
}


