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
	static GameResources* getInstance();
	virtual ~GameResources();
private:
	GameResources();
	static GameResources* instance;
	static int food;
	static int money;
};

#endif /* GAMERESOURCES_H_ */
