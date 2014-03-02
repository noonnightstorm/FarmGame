/*
 * GameResources.h
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#ifndef GAMERESOURCES_H_
#define GAMERESOURCES_H_

class GameResources {
public:
	static GameResources* GetInstance();
	virtual ~GameResources();
	int getFood();
	void setFood(int food);
	int getMoney();
	void setMoney(int money);
private:
	GameResources();
};

#endif /* GAMERESOURCES_H_ */
