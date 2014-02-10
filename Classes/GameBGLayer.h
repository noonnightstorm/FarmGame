/*
 * GameBGLayer.h
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMEBGLAYER_H_
#define GAMEBGLAYER_H_

#include "cocos2d.h"


class GameBGLayer: public cocos2d::CCLayer {
public:
	GameBGLayer();
	virtual ~GameBGLayer();
	bool init();
	CREATE_FUNC(GameBGLayer);
};

#endif /* GAMEBGLAYER_H_ */
