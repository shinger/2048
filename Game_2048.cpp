#include "Game_2048.h"

//���캯������ʼ������
GameFlame::GameFlame()
{
	srand(time(NULL));//�漴������
	initgraph(WIDTH, HEIGHT);
	setbkcolor(RGB(187, 173, 160));
	cleardevice();
	setfillcolor(RGB(205, 193, 180));
	setbkcolor(RGB(187, 173, 160));
	settextstyle(30, 20, "����");
	outtextxy(200, 650, "������   ");
}

//��Ϸ����
void GameFlame::GameStart()
{
	GameInit();
	test();
	while (1)
	{
		GameDraw();
		if (check())
		{
			//cout << "��������" << endl;
			if (IsGameOver())
			{
				test();
				cout << "��Ϸ����" << endl;
				HWND hnd = GetHWnd();
				char num[10];
				sprintf_s(num, "%d", score);
				char str[30] = "��ķ���Ϊ��";
				strcat_s(str, num);
				int is_ok = MessageBox(hnd, str, "��Ϸ����", MB_OK);
				score = 0;
				if (is_ok == IDOK)
				{
					for (int i = 0;i < 4;i++)
					{
						for (int j = 0;j < 4;j++)
						{
							map[i][j] = 0;
						}
					}
					GameInit();
					GameDraw();
				}
				else 
				{
					closegraph();
					exit(0);
				}
			}
		}
		KbControl();
		Sleep(20);
	}
}

void GameFlame::GameInit()
{
	score = 0;//��ʼ������Ϊ0

	//��ʼ��ÿ������Ϊ0
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			map[i][j] = 0;
		}
	}

	//��ʼ�����ֻ�������
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			drawCoor[i][j] = { drawRect[i]+35,drawRect[j]+25};
		}
	}

	//��ʼ����������2
	for (int i = 0;i < 2;i++)
	{
		Coor randCoor = GetRandCoor();
		map[randCoor.x][randCoor.y] = GetRandNum();
	}
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			solidroundrect(drawRect[j], drawRect[i], drawRect[j] + 150, drawRect[i] + 150, 30, 30);
		}
	}
}

void GameFlame::GameDraw()
{
	BeginBatchDraw();
	char num[10];

	//��ԭ�������ָ��ǵ�
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			setfillcolor(RGB(205, 193, 180));
			solidroundrect(drawRect[j], drawRect[i], drawRect[j] + 150, drawRect[i] + 150, 30, 30);
		}
	}

	//���»�������
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (map[i][j] != 0)
			{
				if (map[i][j] == 2) setfillcolor(RGB(238, 228, 218));
				if (map[i][j] == 4) setfillcolor(RGB(237, 224, 200));
				if (map[i][j] == 8) setfillcolor(RGB(242, 177, 121));
				if (map[i][j] == 16) setfillcolor(RGB(245, 149, 99));
				if (map[i][j] == 32) setfillcolor(RGB(246, 124, 95));
				if (map[i][j] == 64) setfillcolor(RGB(246, 94, 59));
				if (map[i][j] == 128) setfillcolor(RGB(237, 207, 114));
				if (map[i][j] == 256) setfillcolor(RGB(237, 204, 97));
				if (map[i][j] == 512) setfillcolor(RGB(237, 200, 80));
				if (map[i][j] == 1024) setfillcolor(RGB(237, 197, 63));
				if (map[i][j] == 2048) setfillcolor(RGB(237, 194, 46));
				solidroundrect(drawRect[j], drawRect[i], drawRect[j] + 150, drawRect[i] + 150, 30, 30);
				setbkmode(TRANSPARENT);
				settextstyle(50, 30, "����");
				sprintf_s(num, "%d", map[i][j]);
				if (num == "86" || num == "44" || num == "26"||num=="82") cout << "appear" << endl;
				outtextxy(drawRect[j]+35, drawRect[i]+25, num);
			}
		}
	}
	setbkcolor(RGB(187, 173, 160));
	setbkmode(OPAQUE);
	settextstyle(30, 20, "����");
	sprintf_s(num, "%d", score);
	outtextxy(300, 650, num);
	EndBatchDraw();
}

//���̲���
void GameFlame::KbControl()
{
	ExMessage KB;
	peekmessage(&KB, EM_KEY);
	Coor randCoor;
	switch (KB.message)
	{
	case WM_KEYDOWN:
		switch (KB.vkcode)
		{
		case VK_UP:
			UpMove();
			//Music();
			randCoor = GetRandCoor();
			map[randCoor.x][randCoor.y] = GetRandNum();
			test();
			break;
		case VK_DOWN:
			DownMove();
			//Music();
			randCoor = GetRandCoor();
			map[randCoor.x][randCoor.y] = GetRandNum();
			test();
			break;
		case VK_LEFT:
			LeftMove();
			//Music();
			randCoor = GetRandCoor();
			map[randCoor.x][randCoor.y] = GetRandNum();
			test();
			break;
		case VK_RIGHT:
			RightMove();
			//Music();
			randCoor = GetRandCoor();
			map[randCoor.x][randCoor.y] = GetRandNum();
			test();
			break;
		}
	}
	
}


//����
void GameFlame::test()
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//��������
void GameFlame::LeftMove()
{
	for (int i = 0;i < 4;i++)
	{
		int k = 0, j = 1;
		while (j < 4)
		{
			if (map[i][k] == 0)
			{
				if (map[i][j] != 0)
				{
					map[i][k] = map[i][j];
					map[i][j] = 0;
				}
				j++;
			}
			else
			{
				if (map[i][j] != 0)
				{
					if (map[i][k] == map[i][j])
					{
						map[i][k] *= 2;
						score += map[i][k];
						map[i][j] = 0;
						k++;
						j = k + 1;
					}
					else
					{
						if (k + 1 != j)
						{
							map[i][k + 1] = map[i][j];
							map[i][j] = 0;
						}
						k++;
						j++;
					}
				}
				else j++;
			}
		}
	}
	
}

//��������
void GameFlame::RightMove()
{
	for (int i = 0;i < 4;i++)
	{
		int k = 3, j = 2;
		while (j >= 0)
		{
			if (map[i][k] == 0)
			{
				if (map[i][j] != 0)
				{
					map[i][k] = map[i][j];
					map[i][j] = 0;
				}
				j--;
			}
			else
			{
				if (map[i][j] != 0)
				{
					if (map[i][k] == map[i][j])
					{
						map[i][k] *= 2;
						score += map[i][k];
						map[i][j] = 0;
						k--;
						j = k - 1;
					}
					else
					{
						if (k - 1 != j)
						{
							map[i][k - 1] = map[i][j];
							map[i][j] = 0;
						}
						k--;
						j--;
					}
				}
				else j--;
			}
		}
	}
}

//��������
void GameFlame::DownMove()
{
	for (int i = 3;i >= 0;i--)
	{
		int k = 3, j = 2;
		while (j >= 0)
		{
			if (map[k][i] == 0)
			{
				if (map[j][i] != 0)
				{
					map[k][i] = map[j][i];
					map[j][i] = 0;
				}
				j--;
			}
			else
			{
				if (map[j][i] != 0)
				{
					if (map[k][i] == map[j][i])
					{
						map[k][i] *= 2;
						score += map[k][i];
						map[j][i] = 0;
						k--;
						j = k - 1;
					}
					else
					{
						if (k - 1 != j)
						{
							map[k - 1][i] = map[j][i];
							map[j][i] = 0;
						}
						k--;
						j--;
					}
				}
				else j--;
			}
		}
	}
}

//��������
void GameFlame::UpMove()
{
	for (int i = 0;i < 4;i++)
	{
		int k = 0, j = 1;
		while (j < 4)
		{
			if (map[k][i] == 0)
			{
				if (map[j][i] != 0)
				{
					map[k][i] = map[j][i];
					map[j][i] = 0;
				}
				j++;
			}
			else
			{
				if (map[j][i] != 0)
				{
					if (map[k][i] == map[j][i])
					{
						map[k][i] *= 2;
						score += map[k][i];
						map[j][i] = 0;
						k++;
						j = k + 1;
					}
					else
					{
						if (k + 1 != j)
						{
							map[k + 1][i] = map[j][i];
							map[j][i] = 0;
						}
						k++;
						j++;
					}
				}
				else j++;
			}
		}
	}
}

bool GameFlame::check()
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

bool GameFlame::IsGameOver()
{
	int x;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			x = map[i][j];
			if (i - 1 >= 0 && i - 1 < 4)
				if (map[i - 1][j] == x) return false;
			if (j - 1 >= 0 && j - 1 < 4)
				if (map[i][j - 1] == x) return false;
			if (j + 1 >= 0 && j + 1 < 4)
				if (map[i][j + 1] == x) return false;
			if (i + 1 >= 0 && i + 1 < 4)
				if (map[i + 1][j] == x) return false;
		}
	}
	return true;
}

//��ȡ�������
Coor GameFlame::GetRandCoor()
{
	int randX, randY;
	while (1)
	{
		randX = rand() % 4;
		randY = rand() % 4;
		if (map[randX][randY] == 0) break;
	}
	
	Coor randCoor = { randX,randY };
	return randCoor;
}

//��ȡ�����4��2
int GameFlame::GetRandNum()
{
	int t = rand() % 11;
	if (t >= 0 && t <= 7) return 2;
	if (t >= 8 && t <= 10) return 4;
}

void GameFlame::Music()
{
	mciSendString("open ./move.wav alias move", 0, 0, 0);
	mciSendString("play move", 0, 0, 0);
	mciSendString("close move", 0, 0, 0);
}