/*
 * GameResources.h
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMERESOURCES_H_
#define GAMERESOURCES_H_

#include "cocos2d.h"

using namespace cocos2d;

class GameResources {
public:
	static GameResources* GetInstance();
	virtual ~GameResources();
	int getPosValue(int x, int y);
	void setPosValue(int x, int y, int value);
	CCLayer* getBuildingLayer();
	void setBuildingLayer(CCLayer* buildingLayer);
	CCLayer* getMapLayer();
	void setMapLayer(CCLayer* mapLayer);
	int getFood();
	void setFood(int food);
	int getMoney();
	void setMoney(int money);
	int getStudent();
	void setStudent(int student);
	int getWorker();
	void setWorker(int worker);
	int getPeople();
	void setWinHeight(float winHeight);
	float getWinHeight();
	void setWinWidth(float winWidth);
	float getWinWidth();
	void initMap();
	bool isUsed(int x,int y);
	int getRealHeight(int y);
	int getRealWidth(int x);
private:
	GameResources();
};

#endif /* GAMERESOURCES_H_ */
