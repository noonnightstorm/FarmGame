/*
 * Worker.h
 *
 *  Created on: Mar 9, 2014
 *      Author: noonnightstorm
 */

#ifndef WORKER_H_
#define WORKER_H_

#include "People.h"

class Worker: public People {
public:
	Worker();
	virtual ~Worker();
	bool init();
	CREATE_FUNC(Worker);
};

#endif /* WORKER_H_ */
