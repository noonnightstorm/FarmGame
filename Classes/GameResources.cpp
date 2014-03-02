/*
 * GameResources.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#include "GameResources.h"
#include <cstddef>

GameResources* instance = NULL;
static int _food;
static int _money;

GameResources::GameResources() {
	// TODO Auto-generated constructor stub

}

GameResources::~GameResources() {
	// TODO Auto-generated destructor stub
}

GameResources* GameResources::GetInstance() {

	if(instance == NULL){
		//init the resources
		instance = new GameResources();
		_food = 150;
		_money = 150;
	}
	return instance;
}

int GameResources::getFood(){
	return _food;
}
void GameResources::setFood(int food){
	_food = food;
}
int GameResources::getMoney(){
	return _money;
}
void GameResources::setMoney(int money){
	_money = money;
}



