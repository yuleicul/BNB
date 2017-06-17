#ifndef _FIGURE_H_INCLUDED
#define _FIGURE_H_INCLUDED
#include "cocos2d.h"
#include "Bomb.h"
#include "gamelayer.h"
class gamelayer;
#define NO_DIRECTION 0		//��Ҷ�������
#define LEFT 1			
#define RIGHT 2
#define UP 3
#define DOWN 4

#define USER 1			//��������
#define COMPUTER 2

#define RED 1			//�������
#define GREEN 2
#define BLUE 3
#define YELLOW 4

#define STATE_FREE 0	//����״̬
#define STATE_BOXED 1
#define STATE_DIED 2

#define TOOL_SHOE 1		//��������
#define TOOL_BOMB 2
#define TOOL_LIQUID 3
#define TOOL_COIN 4
#define TOOL_STRAW 5
#define TOOL_BANANA 6

USING_NS_CC;
//����
class Figure:public Layer
{
public:
	Figure();
	~Figure();
	int type;//��������
	int team;//����
	int direction;//���﷽����4��
	Point position;//��������
	Sprite* sprite;//��ʾ����
	int tag;//������gamelayer���ڵ�players[tag]
	Sprite* Portrait;
	bool win=false;

	float speed=10;//�ٶ�
	int killNum=0;//ɱ����
	int saveNum=0;//������
	int state=STATE_FREE;//״̬
	int score=0;//����
	int bombNum=1;//ը������
	int bombNum_avail=1;//ʣ��ը������
	int bombPower=1;//ը������
	gamelayer* myGamelayer;//���ڵ���Ϸ��
	LabelTTF* labelScore;
	LabelTTF* labelBombNum_avail;
	LabelTTF* labelKill;
	LabelTTF* labelSave;
	LabelTTF* labelTag;
	
	static Figure* createFigureSprite(Point position, int direction,int type, int team,int tag);//��������
	void figureInit(Point position, int direction, int type, int team,int tag);//��ʼ������
	Animate* createAnimate(int direction, int team, const char*action, int num,int time);//��������

	void Move(int myDirection, bool i);
	void DoStand();
	void CollectTool(unsigned int i);
	void BeBoxed();
	void BeSaved();
	void Die(float dt);
	void Win();
	void Delete();

	void labelInit(int tag);
	void updateLabel();
	void stopAllSchedules();
	void gameover();

	virtual bool init();
	CREATE_FUNC(Figure);
};
#endif // !_FIGURE_H_INCLUDED