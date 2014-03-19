/*
 * Building.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

/*
 * AddBuildingLayer.cpp
 *
 *  Created on: Feb 26, 2014
 *      Author: C860
 */

#include "Building.h"
#include "GameResources.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

Building::Building() {
	// TODO Auto-generated constructor stub

}

Building::~Building() {
	// TODO Auto-generated destructor stub
}

Building* Building::create(const char *filename)
{
	Building* pobSprite = new Building();
	if(pobSprite && pobSprite->initWithFile(filename))
	{
		pobSprite->autorelease();
		return pobSprite;
	}
	CC_SAFE_DELETE(pobSprite);
	return NULL;
}

bool Building::init() {
	if (!CCSprite::init() )
	{
		return false;
	}

	return true;
}
