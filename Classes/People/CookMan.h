/*
 * CookMan.h
 *
 *  Created on: Mar 6, 2014
 *      Author: noonnightstorm
 */

#ifndef COOKMAN_H_
#define COOKMAN_H_

#include "People.h"

class CookMan: public People {
public:
	CookMan();
	virtual ~CookMan();
	bool init();
	CREATE_FUNC(CookMan);
};

#endif /* COOKMAN_H_ */
