#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <graphics.h>
#include<mmsystem.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

typedef struct node//����ṹ��
{
	int x;
	int y;
}Coor;


class GameFlame
{
public:
	GameFlame();						//���캯��

	void GameStart();					//��ʼ��Ϸ

	void GameInit();					//��Ϸ��ʼ��

	void GameDraw();					//��Ϸ����

	Coor GetRandCoor();					//��ȡ�������

	void KbControl();					//��ȡ���̲���

	void RightMove();					//��������

	void LeftMove();					//��������

	void UpMove();						//��������

	void DownMove();					//��������

	void test();						//����

	bool IsGameOver();					//�ж���Ϸ�Ƿ����

	bool check();						//����Ƿ����������

	int GetRandNum();					//��ȡ�����4��2

	void Music();						//�����ƶ���Ч

public:
	//��Ϸ����
	int WIDTH = 650;
	int HEIGHT = 700;
	int drawRect[4] = { 10,170,330,490 };//������ʼ��
	int score;//����
	int Direct;//�ƶ�����
	int map[4][4];//ÿ�������ϵ�����
	Coor drawCoor[4][4];//ÿ�����ӻ������ֵ�����
};