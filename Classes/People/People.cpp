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
#include "People/PeopleMoveObject.h"

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

void  People::go(float dt){
	if(frame_count % 15 == 0){
		frame_count = 0;
		_armature->getAnimation()->stop();
		switch(dir_int[frame_index]){
			case LEFT :
				_armature->getAnimation()->play("left");
				break;
			case RIGHT :
				_armature->getAnimation()->play("right");
				break;
			case DOWN :
				_armature->getAnimation()->play("positive");
				break;
			case UP :
				_armature->getAnimation()->play("negative");
				break;
		}
		frame_index++;
		//结束条件
		if(frame_index == count + 1){
			moveEnded();
			return ;
		}
	}
	switch(dir_int[frame_index-1]){
		case LEFT :
			goLeft(dt);
			break;
		case RIGHT :
			goRight(dt);
			break;
		case DOWN :
			goForward(dt);
			break;
		case UP :
			goBackward(dt);
			break;
	}
	frame_count++;
}

void People::goForward(float dt){
	_y -= 3;
	_armature->setPosition(_x,_y);
}

void People::goBackward(float dt){
	_y += 3;
	_armature->setPosition(_x,_y);
}

void People::goLeft(float dt){
	_x -= 3;
	_armature->setPosition(_x,_y);
}

void People::goRight(float dt){
	_x += 3;
	_armature->setPosition(_x,_y);
}

void People::BFS(int FX,int FY,int TX,int TY,int index,string info){
	workInfo = info;
	buildingIndex = index;
	GameResources *resource = GameResources::GetInstance();
	//上，下，右，左 的坐标增减
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
			vis[i][j] = resource->getPosValue(i,j);
		}
	}
	for(int i = 0; i < 66; i++){
		dir_int[i] = -1;
	}

	while(head < tail){
		f_x = list[head].x;
		f_y = list[head].y;
		//CCLog("%d %d | %d %d | %d",f_x,f_y,TX,TY,head);
		if(f_x == TX && f_y == TY){
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
	this->removeAllChildren();
	this->addChild(_armature);
	frame_index = 0;
	frame_count = 0;
	/*for(int i = 0;i < count; i++){
		CCLog("index : %d",dir_int[i]);
	}*/
	this->schedule(schedule_selector(People::go),0.5);
}

void People::moveEnded(){
	this->unscheduleAllSelectors();

	//根据人物的info来进行消息的广播
	if(workInfo.compare("beginToBuilding") == 0){
		//开始工作
		PeopleMoveObject* obj = new PeopleMoveObject();
		obj->setInfo(workInfo,buildingIndex);
		CCNotificationCenter::sharedNotificationCenter()->postNotification("beginToBuilding",obj);
		//人物消失
		GameResources* res = GameResources::GetInstance();
		res->getBuildingLayer()->removeChild(this,true);
	}
	else if(workInfo.compare("moveBack") == 0){
		GameResources* res = GameResources::GetInstance();
		res->getBuildingLayer()->removeChild(this,true);
	}
}
