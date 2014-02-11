/*
 * GameMenuLayer.h
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMEMENULAYER_H_
#define GAMEMENULAYER_H_

#include "cocos2d.h"

using namespace cocos2d;

class GameMenuLayer: public cocos2d::CCLayer {
public:
	GameMenuLayer();
	virtual ~GameMenuLayer();
	bool init();
	CREATE_FUNC(GameMenuLayer);
};

#endif /* GAMEMENULAYER_H_ */
