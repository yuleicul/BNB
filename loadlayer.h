#pragma once
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;
class loadlayer :public Layer
{
public:
	CREATE_FUNC(loadlayer);
	virtual bool init();
	void menucallback(Ref *psender);

public:
	SceneManager *tsm;
};