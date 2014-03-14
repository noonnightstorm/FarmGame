/*
 * People.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#include "People.h"
#include "GameResources.h"
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

People::People() {
	// TODO Auto-generated constructor stub
}

People::~People() {
	// TODO Auto-generated destructor stub
}

void People::setPosition(float new_x,float new_y){
	_x = new_x;
	_y = new_y;
	_toX = _x;
	_toY = _y;
	_armature->setPosition(_x,_y);
}


CCArmature* People::getArmature(){
	return _armature;
}

/*void People::moveTo(int type,float toX,float toY){
	_toX = toX;
	_toY = toY;
	this->removeAllChildren();
	this->addChild(_armature);
	//向前走
	if(type == GO_POSITIVE){
		this->schedule(schedule_selector(People::goForward),0.5);
		_armature->getAnimation()->play("positive");
	}
	else if(type == GO_NEGATIVE){
		this->schedule(schedule_selector(People::goBackward),0.5);
		_armature->getAnimation()->play("negative");
	}
	else if(type == GO_LEFT){
		this->schedule(schedule_selector(People::goLeft),0.5);
		_armature->getAnimation()->play("left");
	}
	else if(type == GO_RIGHT){
		this->schedule(schedule_selector(People::goRight),0.5);
		_armature->getAnimation()->play("right");
	}
}*/

void People::goForward(float dt){
	_armature->getAnimation()->play("positive");
	_y -= 1.5;
	_armature->setPosition(_x,_y);
}

void People::goBackward(float dt){
	_armature->getAnimation()->play("negative");
	_y += 1.5;
	_armature->setPosition(_x,_y);
}

void People::goLeft(float dt){
	_armature->getAnimation()->play("left");
	_x -= 1.5;
	_armature->setPosition(_x,_y);
}

void People::goRight(float dt){
	_armature->getAnimation()->play("right");
	_x += 1.5;
	_armature->setPosition(_x,_y);
}

void People::BFS(int FX,int FY,int TX,int TY){
	GameResources *resource = GameResources::GetInstance();
	//左,右,下,上 的坐标增减
	int dir[8] = {0,1,0,-1,1,0,-1,0};
	count = 0;
	//声明和初始化变量
	int head,tail,f_x,f_y,t_x,t_y;
	head = 0;
	tail = 1;
	pre[0] = -1;
	list[0].x = FX;
	list[0].y = FY;
	for(int i=0;i<33;++i)
	{
		for(int j=0;j<33;++j)
		{
			vis[i][j] = resource->getMapXY(i,j);
		}
	}
	for(int i = 0; i < 66; i++){
		dir_int[i] = -1;
	}

	while(head < tail){
		f_x = list[head].x;
		f_y = list[head].y;
		if(f_x == TX && f_y == TY){
			CCLog("Get the target!");
			findPath(head);
			move();
			return ;
		}
		for(int i = 0;i < 8;i += 2){
			t_x = f_x + dir[i];
			t_y = f_y + dir[i+1];
			//越界
			if(t_x < 0||t_x >= 33||t_y < 0||t_y >= 33){
				continue;
			}
			if(vis[t_x][t_y] == 0){
				vis[t_x][t_y] = 1;
				list[tail].x = t_x;
				list[tail].y = t_y;
				list[tail].dir = i;
				pre[tail] = head;
				tail++;
			}
		}
		head++;
	}
	return ;
}

void People::findPath(int x){
	int t;
	t = pre[x];
	if(t == 0){
		dir_int[count++] = list[x].dir;
		return ;
	}
	findPath(t);
	dir_int[count++] = list[x].dir;
}
void People::move(){
	const int RIGHT = 0;
	const int LEFT = 2;
	const int DOWN = 4;
	const int UP = 6;
	this->removeAllChildren();
	this->addChild(_armature);

	for(int i = 0;i < count;i++){
		switch(dir_int[i]){
			case LEFT :
				this->schedule(schedule_selector(People::goLeft),0.5,20,0.5*20*i);
				break;
			case RIGHT :
				this->schedule(schedule_selector(People::goRight),0.5,20,0.5*20*i);
				break;
			case DOWN :
				this->schedule(schedule_selector(People::goForward),0.5,20,0.5*20*i);
				break;
			case UP :
				this->schedule(schedule_selector(People::goBackward),0.5,20,0.5*20*i);
				break;
		}
	}
}
