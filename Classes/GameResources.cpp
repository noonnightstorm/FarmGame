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
static int map[22][22];
static CCLayer* _mapLayer;
static CCLayer* _buildingLayer;
static int _buildingIndex;

//城堡的位置
static CCPoint _castleMap;

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
		_buildingIndex = 0;
		_castleMap.x = 3;
		_castleMap.y = 4;
	}
	return instance;
}

CCLayer* GameResources::getBuildingLayer()
{
	return _buildingLayer;
}
void GameResources::setBuildingLayer(CCLayer* buildingLayer)
{
	_buildingLayer = buildingLayer;
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
	for(int i=0;i<22;++i)
	{
		for(int j=0;j<22;++j)
		{
			map[i][j] = 0;
		}
	}
}
int GameResources::getPosValue(int x, int y){
	return map[x][y];
}
void GameResources::setPosValue(int x, int y, int value)
{
	map[x][y] = value;
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
	return y*45;
}
int GameResources::getRealWidth(int x)
{
	return x*45;
}

void GameResources::addBuildingIndex(){
	_buildingIndex++;
}

int GameResources::getBuildingIndex(){
	return _buildingIndex;
}

CCPoint GameResources::getCastleMap(){
	return _castleMap;
}
