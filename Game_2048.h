#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <graphics.h>
#include<mmsystem.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

typedef struct node//坐标结构体
{
	int x;
	int y;
}Coor;


class GameFlame
{
public:
	GameFlame();						//构造函数

	void GameStart();					//开始游戏

	void GameInit();					//游戏初始化

	void GameDraw();					//游戏绘制

	Coor GetRandCoor();					//获取随机坐标

	void KbControl();					//获取键盘操作

	void RightMove();					//数字右移

	void LeftMove();					//数字左移

	void UpMove();						//数字上移

	void DownMove();					//数字下移

	void test();						//测试

	bool IsGameOver();					//判断游戏是否结束

	bool check();						//检查是否格子填满了

	int GetRandNum();					//获取随机数4或2

	void Music();						//数字移动音效

public:
	//游戏参数
	int WIDTH = 650;
	int HEIGHT = 700;
	int drawRect[4] = { 10,170,330,490 };//方格起始点
	int score;//分数
	int Direct;//移动方向
	int map[4][4];//每个格子上的数字
	Coor drawCoor[4][4];//每个格子绘制数字的坐标
};