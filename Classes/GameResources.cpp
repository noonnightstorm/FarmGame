/*
 * GameResources.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#include "GameResources.h"
#include <cstddef>
#include "cocos2d.h"

using namespace cocos2d;

GameResources* instance = NULL;
static int _food;
static int _money;
static int _people;
static int _student;
static int _worker;
static float _winHeight;
static float _winWidth;
static int map[33][33];
static CCLayer* _mapLayer;

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
		_student = 0;
		_worker = 3;
	}
	return instance;
}

CCLayer* GameResources::getMapLayer()
{
	return _mapLayer;
}
void GameResources::setMapLayer(CCLayer* layer)
{
	_mapLayer = layer;
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
int GameResources::getStudent(){
	return _student;
}
void GameResources::setStudent(int student){
	_student = student;
}
int GameResources::getWorker(){
	return _student;
}
void GameResources::setWorker(int worker){
	_worker = worker;
}
int GameResources::getPeople(){
	return _student + _worker;
}
void GameResources::setWinHeight(float winHeight)
{
	_winHeight = winHeight;
}
float GameResources::getWinHeight()
{
	return _winHeight;
}
void GameResources::setWinWidth(float winWidth)
{
	_winWidth = winWidth;
}
float GameResources::getWinWidth()
{
	return _winWidth;
}
void GameResources::initMap()
{
	//初始化地图数组
	for(int i=0;i<33;++i)
	{
		for(int j=0;j<33;++j)
		{
			map[i][j] = 0;
		}
	}
}
int GameResources::getMapXY(int x, int y){
	return map[x][y];
}

bool GameResources::isUsed(int x,int y)
{
	if(map[x][y]==1) {
		return true;
	}
	else {
		return false;
	}
}
int GameResources::getRealHeight(int y)
{
	return y*30;
}
int GameResources::getRealWidth(int x)
{
	return x*30;
}
