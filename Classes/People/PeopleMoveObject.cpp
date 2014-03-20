/*
 * PeopleMoveObject.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: noonnightstorm
 */

#include "PeopleMoveObject.h"

PeopleMoveObject::PeopleMoveObject() {
	// TODO Auto-generated constructor stub

}

PeopleMoveObject::~PeopleMoveObject() {
	// TODO Auto-generated destructor stub
}

void PeopleMoveObject::setPath(int fIndex,int fx,int fy,int tIndex,int tx,int ty,int peopleType){
	_fIndex = fIndex;
	_fy = fy;
	_fx = fx;
	_tIndex = tIndex;
	_ty = ty;
	_tx = tx;
	_peopleType = peopleType;
}
