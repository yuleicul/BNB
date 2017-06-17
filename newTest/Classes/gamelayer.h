#pragma once
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SceneManager.h"
#include "Figure.h"
#include "Bomb.h"
#include "TiledMap.h"
#include "countDownBar.h"
//#include "mainLayer.h"
USING_NS_CC_EXT;
USING_NS_CC;
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4

#define MAP1 1
#define MAP2 2
#define MAP3 3
#define MAP4 4

#define FULL_TIME 180.0

#define BombOther 1
#define BombJust 2
#define WaitBomb 3
class Figure;
class countDownBar;
class TiledMap;
class Bomb;

class gamelayer :public Layer
{
public:
	CREATE_FUNC(gamelayer);
	virtual bool init();
	void menucallback(Ref *psender);
	void gamelayerInit();

public:
	int playerOne = 1;
	int playerSe = 0;
	int playerAi = 0;
	int allBombNum = 0;
	int mapType = MAP1;
	float timeLeft = FULL_TIME;
	bool isClient;
	bool aiAllDie;
	bool isDraw=false;
	TiledMap* myMap;

	countDownBar* CountDownBar;
	SceneManager *tsm;
	//Switch* mySwitch;

	std::map<int, int> figureTeam = { { 0,RED },{ 1,BLUE } };
	std::list<Bomb*> allBombs;
	std::vector<Figure*> players;
	std::vector<Figure*> winPlayers;
	std::vector<Figure*> red;
	std::vector<Figure*> green;
	std::vector<Figure*> blue;
	std::vector<Figure*> yellow;
	std::vector<Figure*> user;
	std::vector<Figure*> ai;

public:
	void loadFigure();
	void loadMap();
	void loadBar();
	void teamInitForAi(int figureNum);
	//�����ƶ���
	void figureMove(int tag, int direction);
	//��ײ��⣺
	bool moveifBomb(int tag,int direction);//���ڵ��ϰ�������true;
	bool ksPlayer(int doerTag);//�ƶ�ʱ������ң��������Ǳ������ˣ���ִ��kill�������Ǳ������ѣ���ִ��save��
	bool moveifPlayer(int tag);
	void bombifPlayer(std::vector<Point>&vec);//���ը���Ƿ�ը��������
	int bombifBomb(std::vector<Point>&vec,int& bombTag);//���ը���Ƿ���Ҫ��ը���ը��
	void bombBomb(std::vector<Point>&vec,  int& bombTag);//����ը��
	//����ը����
	void putBomb(int playerTag, Point position);
	bool canBomb(Point mP);
	
	//�е��߾ͼ���ߣ�û���߾����ˣ�
	void getTool(int tag, Point position);

	//ʵʱ���£������Ϸ�Ƿ������
	void myUpdate(float dt);

	//�򵥵�д��һ��gameover�ĺ����������������
	void gameOver(float dt);

	void finishGame(float dt);

	void addSwitch();
	void change(Object* pSender, Control::EventType event);

	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	//forAi
	bool ifMove(int tag, int direction);
	bool ifDanger(Point position);
};