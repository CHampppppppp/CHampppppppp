#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include "menu.h"
#define WIDTH 1500
#define HEIGHT 800
//����ʳ���Լ��ߵĴ�С
#define SIZE  10

Menu::Menu()
{
	loadimage(&menu_bk, "menubk.jpg", WIDTH, HEIGHT);
	loadimage(&detail_bk, "detailbk.jpg", WIDTH, HEIGHT);
	loadimage(&history_bk, "historybk.jpg", WIDTH, HEIGHT);
	loadimage(&control_bk, "controlbk.jpg", WIDTH, HEIGHT);
}

void Menu::showmenu()
{
menubegin:
	initgraph(WIDTH, HEIGHT);
	setbkcolor(WHITE);
	cleardevice();
	putimage(0, 0, &menu_bk);
	setfillcolor(WHITE);
	fillrectangle(200, 140, 600, 160);
	fillrectangle(200, 200, 600, 220);
	fillrectangle(200, 260, 600, 280);
	fillrectangle(200, 320, 600, 340);
	fillrectangle(200, 380, 600, 400);
	fillrectangle(200, 440, 600, 460);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(250, 142, "��ʼ��Ϸ");//goto begin
	outtextxy(250, 202, "��ʷ�÷ְ�");//goto history
	outtextxy(250, 262, "����");//goto control
	outtextxy(250, 322, "��Ϸ˵��");//goto detail
	outtextxy(250, 382, "���ߺ�˧");//��ϲ�������������������
	outtextxy(250, 442, "���ߺó�");//��Ϸ����
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//�������λ�� �Ƿ���������
			setlinecolor(YELLOW);//����� �����µı߿�Ϊ��ɫ
			rectangle(190, 135, 610, 165);//���µı߿�
			//��������1
			if (m.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 200 && m.y <= 220) {
			setlinecolor(YELLOW);
			rectangle(190, 195, 610, 225);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showhistory();
				goto menubegin;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 260 && m.y <= 280) {
			setlinecolor(YELLOW);
			rectangle(190, 255, 610, 285);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showcontrol();
				goto menubegin;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 320 && m.y <= 340) {
			setlinecolor(YELLOW);
			rectangle(190, 315, 610, 345);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showdetail();
				goto menubegin;
			}
		}
		//
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {//
			setlinecolor(YELLOW);
			rectangle(190, 375, 610, 405);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showrespect();
				goto menubegin;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 460) {//
			setlinecolor(YELLOW);
			rectangle(190, 435, 610, 465);
			if (m.uMsg == WM_LBUTTONDOWN) {
				goon = 0;
				cout << "���Բ������ˣ�\n������ǿ쵶��\n�����ˣ�һ���������ʶ�����-_-";
				break;
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 135, 610, 165);
			rectangle(190, 195, 610, 225);
			rectangle(190, 255, 610, 285);
			rectangle(190, 315, 610, 345);
			rectangle(190, 375, 610, 405);
			rectangle(190, 435, 610, 465);
		}
	}
}

void Menu::showdetail()
{
	setbkcolor(WHITE);
	cleardevice();
	putimage(0, 0, &detail_bk);
	char line1[1000] = "��Ϸ˵��:";
	char line2[1000] = "\n1�� ��Ϸѹ������û�в����ģ���������أ�������淢��bug������5������ң��ڴ���ҵĽ����ײߡ�";
	char line3[1000] = "\n2�� ����ǰ���������ͻ�ƣ�������������ࡣ";
	char line4[1000] = "\n3�� ���;��о綾�ԣ�ҧ���Լ�������������";
	char line5[1000] = "\n4�� �����ٶȺܿ죬����̫��ײǽ����������";
	char line6[1000] = "\n5�� ��Ϸ�е�����Ӧ�������⣬�类�������1.5���ڿ�1���Ը����ʹ󣬴�ʱ�ʹ�����������ǰ����";
	char line7[1000] = "\n6�� �������Ϸ̫�򵥣���h�����Ѷȣ��ѶȻ��ڳԵ���һ��ʳ�����֡�";
	char line8[1000] = "\n7�� ��Ϸ��ƵΪ����¼�ƣ�����ת�ػ�������ҵ��Ϊ������ͷ������";
	char line9[1000] = "\n8�� ��Ϸ�ﵽ81���вʵ�;";
	char line10[1000] = "\n9�� ��Ϸ������������ƣ�2.0�汾��Ϊ�ڶ����汾������⣬�����ڴ�3.0�汾��";
	while (1)
	{
		outtextxy(100, 50, line1);
		outtextxy(100, 80, line2);
		outtextxy(100, 110, line3);
		outtextxy(100, 140, line4);
		outtextxy(100, 170, line5);
		outtextxy(100, 200, line6);
		outtextxy(100, 230, line7);
		outtextxy(100, 260, line8);
		outtextxy(100, 290, line9);
		outtextxy(100, 320, line10);
		if (goback()) break;
	}
}

void Menu::showhistory()
{
	initgraph(WIDTH, HEIGHT);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(WHITE);
	while (1)
	{
		putimage(0, 0, &history_bk);
		if (goback()) break;
	}
}

void Menu::showcontrol()
{
	setbkcolor(WHITE);
	cleardevice();
	putimage(0, 0, &control_bk);
	char line1[100] = "WASD:�������ң������Ӽ���";
	char line2[100] = "H:�����Ѷ�";
	char line3[100] = "��1:�����δ�";
	char line4[100] = " �ո���ͣ";
	char line5[100] = "�����Ϸ˵��";
	while (1)
	{
		outtextxy(100, 10, line1);
		outtextxy(100, 30, line2);
		outtextxy(100, 50, line3);
		outtextxy(100, 70, line4);
		outtextxy(100, 90, line5);
		if (goback()) break;
	}
}

void Menu::showrespect()
{
	putimage(0, 0, &respect_bk);
	while (1)
	{
		if (goback()) break;
	}
	cout << "��ϲ����˵�滰����>_<"<< endl;
}


bool Menu::goback()
{
	m = GetMouseMsg();
	if (m.x >= 0 && m.x <= 1800 && m.y >= 0 && m.y <= 800)
		if (m.uMsg == WM_RBUTTONDOWN) {
			return 1;
		}
	return 0;
}

int main()
{
	Menu m;
	m.showmenu();
	return 0;
}

