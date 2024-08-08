#include <iostream>
#include <stdio.h>
#include <graphics.h>
#ifndef BLOCK_H
#define BLOCK_H
#pragma once
#define WIDTH 1500
#define HEIGHT 800
//����ʳ���Լ��ߵĴ�С
#define SIZE  10
using namespace std;

class Block
{
	friend class Snake;
	friend class Food;
private:
	vector<vector<int>> vc;//��vector�����������ϰ��������
	int x, y;
	int count;
	int difficulty;//�Ѷ�Խ�ߣ��ϰ�������Խ��
	IMAGE b, bv;//�ϰ����ͼ��
public:
	Block(); //��ʼ��8���ϰ���
	void Draw(int num);//�����ϰ�����صĻ滭
	bool coli(int x0, int y0);//��ײ�ж�
	bool onblock(int x, int y);//�ж�һ�������Ƿ����ϰ����ص�
	void modify(int num);//�ı��ϰ�������
	void diff();//�ı���ʾ�Ѷ�
};

Block::Block():vc(100, vector<int>(2)), count(8), difficulty(1)
{
	srand(time(0));//�ı����������
	for (int i = 0; i < 100; i++)
	{
		do
		{
			x = rand() % (WIDTH / SIZE);
			y = rand() % (HEIGHT / SIZE);
		} while (x % 2 == 0 || y % 2 == 0 || x >= WIDTH / 10 - 5 || y >= HEIGHT / 10 - 5);
		x *= 10;
		y *= 10;
		vc[i][0] = x;
		vc[i][1] = y;
	}
	loadimage(&b, "block.png", 5 * SIZE, 5 * SIZE);//��ʼ��ͼ��
	loadimage(&bv, "blockrv.png", 5 * SIZE, 5 * SIZE);
}

void Block::Draw(int num)
{
	char difficultystr[10];
	settextcolor(BLACK);
	sprintf_s(difficultystr, "�Ѷ�:%2d", difficulty);
	outtextxy(900, 20, difficultystr);
	for (int i = 0; i < num; i++)
	{
		putimage(vc[i][0], vc[i][1], &bv, SRCAND);
		putimage(vc[i][0], vc[i][1], &b, SRCPAINT);
	}
}

bool Block::coli(int x0,int y0)
{
	for (int i = 0; i < count; i++)
	{
		int x = vc[i][0];
		int y = vc[i][1];//ѭ��ÿ���ϰ���ж���ͷ����x0��y0�Ƿ������ϰ���
		if (x0 == x && y0 == y) return true;
		if (x0 == x + 2 * SIZE && y0 == y) return true;
		if (x0 == x + 4 * SIZE && y0 == y) return true;
		if (x0 == x && y0 == y + 2 * SIZE) return true;
		if (x0 == x && y0 == y + 4 * SIZE) return true;
		if (x0 == x + 2 * SIZE && y0 == y + 2 * SIZE) return true;
		if (x0 == x + 4 * SIZE && y0 == y + 2 * SIZE) return true;
		if (x0 == x + 2 * SIZE && y0 == y + 4 * SIZE) return true;
		if (x0 == x + 4 * SIZE && y0 == y + 4 * SIZE) return true;
	}
	return false;
}

bool Block::onblock(int x,int y)
{
	x *= 10;
	y *= 10;
	for (int i = 0; i < count; i++)
	{
		if (x >= vc[i][0] && x <= vc[i][0] + 4 * SIZE && y >= vc[i][1] && y <= vc[i][1] + 4 * SIZE) return true;
	}return false;
}

void Block::modify(int num)
{
	count = num;
}

void Block::diff()
{
	difficulty++;
}

#endif