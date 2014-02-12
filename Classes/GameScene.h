/*
 * GameScene.h
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"

class GameScene: public cocos2d::CCScene {
public:
	GameScene();
	virtual ~GameScene();

	bool init();

	CREATE_FUNC(GameScene);
};

#endif /* GAMESCENE_H_ */
