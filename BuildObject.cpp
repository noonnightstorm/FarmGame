/*
 * BuildObject.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "BuildObject.h"

BuildObject::BuildObject() {
	// TODO Auto-generated constructor stub

}

BuildObject::~BuildObject() {
	// TODO Auto-generated destructor stub
}

void BuildObject::setPosition(CCPoint point){
	BuildingPoint = point;
}

CCPoint BuildObject::getPosition(){
	return BuildingPoint;
}

void BuildObject::setBuildingStr(string name){
	BuildingName = name;
}

string BuildObject::getBuildingStr(){
	return BuildingName;
}

void BuildObject::setTag(int tag){
	BuildingTag = tag;
}

int BuildObject::getTag(){
	return BuildingTag;
}
