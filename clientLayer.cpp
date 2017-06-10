#include "clientLayer.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace cocos2d;
bool clientLayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();

	auto sprite = Sprite::create("BeginScene2.png");

	sprite->setPosition(Vec2(winSize.width *0.5, winSize.height*0.5));
	this->addChild(sprite, 0);

	MenuItemLabel *menuItem = MenuItemLabel::create(Label::createWithSystemFont("Single", "", 30), CC_CALLBACK_1(clientLayer::menucallback, this));
	menuItem->setColor(Color3B(0, 0, 0));
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winSize.width *0.8, winSize.height*0.3));

	MenuItemLabel *menuItem_2 = MenuItemLabel::create(Label::createWithSystemFont("Double", "", 30), CC_CALLBACK_1(clientLayer::menucallback, this));
	menuItem_2->setColor(Color3B(0, 0, 0));
	menuItem_2->setTag(102);
	menuItem_2->setPosition(Vec2(winSize.width *0.8, winSize.height*0.2));

	MenuItemLabel *menuItem_3 = MenuItemLabel::create(Label::createWithSystemFont("Return", "", 30), CC_CALLBACK_1(clientLayer::menucallback, this));
	menuItem_3->setColor(Color3B(0, 0, 0));
	menuItem_3->setTag(103);
	menuItem_3->setPosition(Vec2(winSize.width *0.8, winSize.height*0.1));

	auto menu = Menu::create(menuItem, menuItem_2, menuItem_3, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);


	return true;
}
void clientLayer::menucallback(Ref *psender)
{
	switch (((MenuItem *)psender)->getTag())
	{
	case 101:
	{
		tsm->gochoosescene();
	}
	break;
	case 102:
	{
		tsm->gochoosescene(2,true);
	}
	break;
	case 103:
	{
		tsm->goLoadScene();
	}
	break;
	default:
		break;
	}
}