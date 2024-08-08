#include <iostream>
#include <stdio.h>
#include <graphics.h>
#ifndef MENU_H
#define MENU_H
#pragma once
#define WIDTH 1500
#define HEIGHT 800
//����ʳ���Լ��ߵĴ�С
#define SIZE  10
using namespace std;

class Menu
{
private:
	IMAGE menu_bk, detail_bk, history_bk, control_bk, respect_bk;
	MOUSEMSG m;
public:
	int goon = 1;
	Menu();
	void window();
	void showmenu();
	void showhistory();
	void showdetail();
	void showcontrol();
	void showrespect();
	bool goback();
	void showreturn();
};

void Menu::window()
{
	initgraph(WIDTH, HEIGHT);
	// ȷ�����ڵĳ�ʼλ�ã�ʹ��λ����Ļ����
	int windowPosX = 0;
	int windowPosY = 0;

	// ��ȡ��ǰ���ھ��
	HWND hwnd = GetHWnd();

	// ���ô���λ��
	SetWindowPos(hwnd, HWND_TOP, windowPosX, windowPosY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

Menu::Menu()
{
	loadimage(&menu_bk, "menubk.png", WIDTH, HEIGHT);
	loadimage(&detail_bk, "detailbk.jpg", WIDTH, HEIGHT);
	loadimage(&history_bk, "historybk.jpg", WIDTH, HEIGHT);
	loadimage(&control_bk, "controlbk.jpg", WIDTH, HEIGHT);
}

void Menu::showmenu()
{
menubegin:
	window();
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
	fillrectangle(200, 500, 600, 520);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(250, 142, "��ʼ��Ϸ");//goto begin
	outtextxy(250, 202, "��ʷ�÷ְ�");//goto history
	outtextxy(250, 262, "����");//goto control
	outtextxy(250, 322, "��Ϸ˵��");//goto detail
	outtextxy(250, 382, "���ߺ�˧");//��ϲ�������������������
	outtextxy(250, 442, "���ߺó�");//��Ϸ����
	outtextxy(250, 502, "mamba out");//�˳���Ϸ
	settextcolor(WHITE);
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//�������λ�� �Ƿ���������
			setlinecolor(YELLOW);//����� �����µı߿�Ϊ��ɫ
			rectangle(190, 135, 610, 165);//���µı߿�
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
		else if (m.x >= 200 && m.x <= 600 && m.y >= 380 && m.y <= 400) {
			setlinecolor(YELLOW);
			rectangle(190, 375, 610, 405);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showrespect();
				goto menubegin;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 460) {
			setlinecolor(YELLOW);
			rectangle(190, 435, 610, 465);
			if (m.uMsg == WM_LBUTTONDOWN) {
				goon = 0;
				cout << "���Բ������ˣ�\n������ǿ쵶��\n�����ˣ�һ���������ʶ�����-_-"<<endl<<endl;
				break;
			}
		}
		else if (m.x >= 200 && m.x <= 600 && m.y >= 500 && m.y <= 520) {
			setlinecolor(YELLOW);
			rectangle(190, 495, 610, 525);
			if (m.uMsg == WM_LBUTTONDOWN) {
				goon = 0;
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
			rectangle(190, 495, 610, 525);
		}
	}
}

void Menu::showdetail()
{
	setbkcolor(WHITE);
	cleardevice();
	/*putimage(0, 0, &detail_bk);*/
	char line1[1000] = "��Ϸ˵��:";
	char line2[1000] = "1. ��Ϸѹ������û�в����ģ������ʹ�ã�������淢��bug����ת�����������˧���ˣ���ӭ��λת����ҡ�";
	char line3[1000] = "2. ����ǰ���������ͻ�ƣ�������������ࡣ";
	char line4[1000] = "3. ���;��о綾�ԣ�ҧ���Լ�������������";
	char line5[1000] = "4. �����ٶȺܿ죬����̫��ײǽ����������";
	char line6[1000] = "5. ��Ϸ�е�����Ӧ�������⣬�类�������1.5���ڿ�1���Ը����ʹ󣬴�ʱ�ʹ�����������ǰ����";
	char line7[1000] = "6. �������Ϸ̫�򵥣���h�����Ѷȣ��ѶȻ��ڳԵ���һ��ʳ���ˢ�¡�";
	char line8[1000] = "7. ��ϷΪ������������ӭת�ػ�������ҵ��Ϊ������ͷ������";
	char line9[1000] = "8. ��Ϸ�ﵽ81���вʵ�;";
	char line10[1000] ="9. ��Ϸ������������ƣ�3.0�汾��Ϊ�������汾������⣬�����ڴ�4.0�汾��";
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
		showreturn();
		if (goback()) break;
	}
}

void Menu::showhistory()
{
	setbkcolor(WHITE);
	cleardevice();
	/*putimage(0, 0, &history_bk);*/
	setfillcolor(WHITE);
	while (1) //�ļ����
	{
		showreturn();
		if (goback()) break;
	}
}

void Menu::showcontrol()
{
	setbkcolor(WHITE);
	cleardevice();
	/*putimage(0, 0, &control_bk);*/
	char line1[100] = "WASD : �������ң������Ӽ���";
	char line2[100] = "H : �����Ѷ�";
	char line3[100] = "��1 : �����δ�";
	char line4[100] = "�ո� : ��ͣ";
	char line5[100] = "�����Ϸ˵��";
	while (1)
	{
		outtextxy(200, 30, line1);
		outtextxy(200, 60, line2);
		outtextxy(200, 90, line3);
		outtextxy(200, 120, line4);
		outtextxy(200, 150, line5);
		showreturn();
		if (goback()) break;
	}
}

void Menu::showrespect()
{
	setbkcolor(WHITE);
	cleardevice();
	/*putimage(0, 0, &respect_bk);*/
	while (1)
	{
		char line1[100] = "��ϲ����˵�滰����>_<";
		outtextxy(200, 30, line1);
		showreturn();
		if (goback()) break;
	}
	cout << endl;
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

void Menu::showreturn()
{
	settextcolor(BLACK);
	outtextxy(900, 202, "��");
	outtextxy(900, 222, "��");
	outtextxy(900, 242, "��");
	outtextxy(900, 262, "��");
	outtextxy(900, 282, "��");
	outtextxy(900, 302, "��");
}
// 
// int main()
// {
// 	Menu m;
// 	m.showmenu();
// 	return 0;
// }


#endif