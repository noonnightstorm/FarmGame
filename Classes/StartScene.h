/*
 * StartScene.h
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#ifndef STARTSCENE_H_
#define STARTSCENE_H_

#include "cocos2d.h"

class StartScene: public cocos2d::CCScene {
public:
	StartScene();
	virtual ~StartScene();
	bool init();

	//开始界面的两个按钮点击的回调方法
	void menustartcallback(CCObject* pSender);
	void menuquitcallback(CCObject* pSender);

	CREATE_FUNC(StartScene);
};

#endif /* STARTSCENE_H_ */
