/*
 * PeopleMoveObject.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: noonnightstorm
 */

#include "PeopleMoveObject.h"


PeopleMoveObject::PeopleMoveObject() {
	// TODO Auto-generated constructor stub

}

PeopleMoveObject::~PeopleMoveObject() {
	// TODO Auto-generated destructor stub
}


void PeopleMoveObject::setInfo(string info,int buildingIndex){
	_info = info;
	_buildingIndex = buildingIndex;
}

string PeopleMoveObject::getWorkInfo(){
	return _info;
}

int PeopleMoveObject::getBuildingIndex(){
	return _buildingIndex;
}
