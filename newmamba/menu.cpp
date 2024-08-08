#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include "menu.h"
#define WIDTH 1500
#define HEIGHT 800
//定义食物以及蛇的大小
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
	outtextxy(250, 142, "开始游戏");//goto begin
	outtextxy(250, 202, "历史得分榜");//goto history
	outtextxy(250, 262, "操作");//goto control
	outtextxy(250, 322, "游戏说明");//goto detail
	outtextxy(250, 382, "作者好帅");//就喜欢你这种有眼力的玩家
	outtextxy(250, 442, "作者好丑");//游戏崩溃
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 140 && m.y <= 160) {//检测鼠标的位置 是否满足条件
			setlinecolor(YELLOW);//满足后 设置新的边框为红色
			rectangle(190, 135, 610, 165);//画新的边框
			//如果点击了1
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
				cout << "谎言不会伤人，\n真相才是快刀。\n别玩了，一点人情世故都不懂-_-";
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
	char line1[1000] = "游戏说明:";
	char line2[1000] = "\n1。 游戏压缩包包没有病毒的，请放心下载，如果游玩发现bug，奖励5块人民币，期待大家的建言献策。";
	char line3[1000] = "\n2。 长按前进方向加速突破，反向减速慢节奏。";
	char line4[1000] = "\n3。 曼巴具有剧毒性，咬到自己会马上死亡。";
	char line5[1000] = "\n4。 曼巴速度很快，动能太大，撞墙马上死亡。";
	char line6[1000] = "\n5。 游戏中的肘子应尽量避免，如被肘击，在1.5秒内扣1可以复活劳大，此时劳大会艰难爬起来前进。";
	char line7[1000] = "\n6。 如果闲游戏太简单，按h增加难度，难度会在吃到下一个食物后呈现。";
	char line8[1000] = "\n7。 游戏音频为本人录制，不能转载或用于商业行为。（神头鬼脸）";
	char line9[1000] = "\n8。 游戏达到81分有彩蛋;";
	char line10[1000] = "\n9。 游戏后续会更新完善，2.0版本仅为第二代版本，望理解，敬请期待3.0版本。";
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
	char line1[100] = "WASD:上下左右，长按加减速";
	char line2[100] = "H:增加难度";
	char line3[100] = "扣1:复活牢大";
	char line4[100] = " 空格暂停";
	char line5[100] = "详见游戏说明";
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
	cout << "就喜欢爱说真话的人>_<"<< endl;
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

