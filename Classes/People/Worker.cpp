/*
 * Worker.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: noonnightstorm
 */

#include "Worker.h"

Worker::Worker() {
	// TODO Auto-generated constructor stub

}

Worker::~Worker() {
	// TODO Auto-generated destructor stub
}

bool Worker::init() {
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("People/worker/Worker0.png","People/worker/Worker0.plist","People/worker/Worker.ExportJson");
	_armature = CCArmature::create("Worker");
	return true;
}

