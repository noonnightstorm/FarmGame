/*
 * People.h
 *
 *  Created on: Mar 5, 2014
 *      Author: noonnightstorm
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

class People: public cocos2d::CCNode {
public:
	People();
	virtual ~People();
	void setPosition(float new_x,float new_y);
	CCArmature* getArmature();

	//移动函数
	//void moveTo(int type,float toX,float toY);
	virtual void goForward(float dt);
	virtual void goBackward(float dt);
	virtual void goLeft(float dt);
	virtual void goRight(float dt);
	virtual void go(float dt);

	//BFS
	void BFS(int FX,int FY,int TX,int TY,int index,string info);
	void findPath(int head);
	void move();
	void moveEnded();
	//CREATE_FUNC(People);

protected:
	//当前位置
	float _x;
	float _y;
	//移动的位置
	float _toX;
	float _toY;
	//动画变量
	CCArmature* _armature;

private:
	const static int UP = 0;
	const static int DOWN = 2;
	const static int RIGHT = 4;
	const static int LEFT = 6;
	struct local{
		int x;
		int y;
		int dir;
	}list[1100];
	int vis[33][33],pre[1100],dir_int[67],count;
	int frame_count,frame_index;
	string workInfo;
	int buildingIndex;
};

#endif /* PEOPLE_H_ */
