#include <iostream>
#include <easyx.h>
#include<time.h>
#include <stdlib.h>
#include <vector>
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
using namespace std;


//���峡����С
#define WIDTH 1500
#define HEIGHT 800
//����ʳ���Լ��ߵĴ�С
#define SIZE  10
//�����ߵĳ���
#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2
int speed = 175;		//�ߵ��ٶ�(����˯�ߺ�������)
#define MAXLEN 1600             //�ߵ���󳤶�
typedef struct {
	int x;
	int y;
}SnakeNode;

//�����ߵ���
class Snake
{
	friend class Food;          //�ߵ���ԪΪʳ��
	friend class Block;
public:
	Snake():wuditime(0)//��ʼ��
	{
		this->dirt = RIGHT;
		this->length = 3;
		score = 0;
		two = three = 0;
		//�±���0��λ��Ϊ�ߵ�ͷ��
		for (int i = 0; i < length; i++) {
			this->node[i].x = 70 - ((i + 1) * 2 * SIZE);
			this->node[i].y = SIZE;
		}
		loadimage(&bk, "bk.png", WIDTH, HEIGHT, 1);
	};					
	void Move();				//�ƶ�
	void Draw();				//������
	int Eat(Food& food);	    //��ʳ��
	bool Defeat(Block& block);				//ʧ���ж�
	int wuditime;//�޵�֡
private:
	int dirt;					//����
	int length;					//����
	int score; //�ܵ÷�
	int two;//���������
	int three;//���������
	SnakeNode node[MAXLEN];		//�ߵĽ��     
	IMAGE bk;
};

//����ʳ�����
class Food
{
	friend class Snake;         //ʳ�����ԪΪ��
	friend class Block;
public:
	Food(Snake& snake,Block& block);			//ʳ���ʼ��
	void Draw();				//����ʳ��
	bool coli(float x0, float y0)//��ײ�ж�
	{
		if (x0 == x && y0 == y) return true;
		if (x0 == x + 2*SIZE && y0 == y) return true;
		if (x0 == x + 4 * SIZE && y0 == y) return true;
		if (x0 == x && y0 == y + 2 * SIZE) return true;
		if (x0 == x && y0 == y + 4 * SIZE) return true;
		if (x0 == x + 2 * SIZE && y0 == y + 2 * SIZE) return true;
		if (x0 == x + 4 * SIZE && y0 == y + 2 * SIZE) return true;
		if (x0 == x + 2 * SIZE && y0 == y + 4 * SIZE) return true;
		if (x0 == x + 4 * SIZE && y0 == y + 4 * SIZE) return true;
		return false;
	}
private:
	int x, y;					//����
	int score;					//����
	int type;
	IMAGE ima1, ima2, ima3, ima4;
};

class Block
{
	friend class Snake;
	friend class Food;
private:
	vector<vector<int>> vc;
	int x, y;
	int count;
	int difficulty;
	IMAGE b, bv;
public:
	Block() :vc(100, vector<int>(2)), count(8),difficulty(1) //��ʼ��8���ϰ���
	{
		srand(time(0));
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
		loadimage(&b, "block.png", 5 * SIZE, 5 * SIZE);
		loadimage(&bv, "blockrv.png", 5 * SIZE, 5 * SIZE);
	}
	void Draw(int num)
	{
		char difficultystr[10];
		settextcolor(BLACK);
		sprintf_s(difficultystr, "�Ѷ�:%2d", difficulty);
		outtextxy(1000, 20, difficultystr);
		for (int i = 0; i < num; i++)
		{
			putimage(vc[i][0], vc[i][1], &bv, SRCAND);
			putimage(vc[i][0], vc[i][1], &b, SRCPAINT);
		}
	}
	bool coli(int x0, int y0)
	{
		for (int i = 0; i < count; i++)
		{
			int x = vc[i][0];
			int y = vc[i][1];
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
	bool onblock(int x, int y)
	{
		x *= 10;
		y *= 10;
		for (int i = 0; i < count; i++)
		{
			if (x >= vc[i][0] && x <= vc[i][0] + 4 * SIZE && y >= vc[i][1] && y <= vc[i][1] + 4 * SIZE) return true;
		}return false;
	}
	void modify(int num)
	{
		count = num;
	}
	void diff()
	{
		difficulty++;
	}
};

class End
{
private:
	IMAGE kobe;
public:
	End()
	{
		loadimage(&kobe, "ending.jpg", WIDTH-10, HEIGHT-10,0);
	}
	void play()
	{
		cleardevice();
		putimage(0, 0, &kobe);
		mciSendString("close BGM1", 0, 0, 0);
		mciSendString("open mambaout.mp3 alias BGM3", 0, 0, 0);//hahaha what can i say ? mambaout!
		mciSendString("play BGM3", 0, 0, 0);
		Sleep(6000);
	}
};
SnakeNode tmp[MAXLEN];	//������һ���������洢��ԭ����λ��

//�ƶ�

void Snake::Move() {
	//��ԭ�����߽�㿽��һ��
	for (int i = 0; i < this->length; i++) {
		tmp[i].x = this->node[i].x;
		tmp[i].y = this->node[i].y;
	}
	int status = 0;//�����ж��Ƿ�����ת�򰴼�
	int flag = 0;
	if (this->dirt == RIGHT) {
		//�ж��Ƿ�ת��
		if (GetAsyncKeyState('W') && status == 0) {
			this->node[0].y -= 2*SIZE;
			this->dirt = UP;
			status = 1;
		}
		else if (GetAsyncKeyState('S') && status == 0) {
			this->node[0].y += 2*SIZE;
			this->dirt = DOWN;
			status = 1;
		}
		else {
			if (GetAsyncKeyState('A') && status == 0)
				flag -= 10;
			if (GetAsyncKeyState('D') && status == 0)
				flag += 10;
			this->node[0].x += 2*SIZE;
		}
	}
	else if (this->dirt == DOWN) {
		//�ж��Ƿ�ת��
		if (GetAsyncKeyState('A') && status == 0) {
			this->node[0].x -= 2*SIZE;
			this->dirt = LEFT;
			status = 1;
		}
		else if (GetAsyncKeyState('D') && status == 0) {
			this->node[0].x += 2*SIZE;
			this->dirt = RIGHT;
			status = 1;
		}
		else {
			if (GetAsyncKeyState('W') && status == 0)
				flag -= 10;
			if (GetAsyncKeyState('S') && status == 0)
				flag += 10;
			this->node[0].y += 2*SIZE;
		}
	}
	else if (this->dirt == LEFT) {
		//�ж��Ƿ�ת��
		if (GetAsyncKeyState('W') && status == 0) {
			this->node[0].y -= 2*SIZE;
			this->dirt = UP;
			status = 1;
		}
		else if (GetAsyncKeyState('S') && status == 0) {
			this->node[0].y += 2*SIZE;
			this->dirt = DOWN;
			status = 1;
		}
		else {
			if (GetAsyncKeyState('D') && status == 0)
				flag -= 10;
			if (GetAsyncKeyState('A') && status == 0)
				flag += 10;
			this->node[0].x -= 2*SIZE;
		}
	}
	else if (this->dirt == UP) {
		//�ж��Ƿ�ת��
		if (GetAsyncKeyState('A') && status == 0) {
			this->node[0].x -= 2*SIZE;
			this->dirt = LEFT;
			status = 1;
		}
		else if (GetAsyncKeyState('D') && status == 0) {
			this->node[0].x += 2*SIZE;
			this->dirt = RIGHT;
			status = 1;
		}
		else {
			if (GetAsyncKeyState('S') && status == 0)
				flag -= 10;
			if (GetAsyncKeyState('W') && status == 0)
				flag += 10;
			this->node[0].y -= 2*SIZE;
		}
	}
	//�ƶ�
	for (int i = 1; i < this->length; i++) {
		this->node[i].x = tmp[i - 1].x;
		this->node[i].y = tmp[i - 1].y;
	}
	Sleep(speed - flag*15);
}


//������
void Snake::Draw() {
	cleardevice();//���ԭ�ȵĻ�ͼ
	putimage(0, 0, &bk);
	settextcolor(BLACK);
	char str1[2000], str2[2000], scorestr[2000], twostr[1000], threestr[1000],str[8];
	sprintf_s(str1, "%2d", node[0].x);
	sprintf_s(str2, "%2d", node[0].y);
	sprintf_s(twostr, "������:%2d", two);
	sprintf_s(threestr, "������:%2d", three);
	sprintf_s(scorestr, "�ܵ÷�:%2d", score);
	outtextxy(1000, 110, str1);
	outtextxy(1000, 130, str2);
	outtextxy(1000, 90, scorestr);
	outtextxy(1000, 70, threestr);
	outtextxy(1000, 50, twostr);
	srand((unsigned)time(NULL));//�������������
	for (int i = 0; i < this->length; i++) {
		setfillcolor(BLACK);
		fillcircle(this->node[i].x, this->node[i].y,SIZE);
	}
	
}

//ʳ��ĳ�ʼ��
Food::Food(Snake& snake,Block &block)
{
	loadimage(&ima1, "basketball.png", 4 * SIZE, 4 * SIZE);
	loadimage(&ima2, "baskrv.png", 4 * SIZE, 4 * SIZE);
	loadimage(&ima3, "bhc.png", 4 * SIZE, 4 * SIZE);
	loadimage(&ima4, "rv.png", 4 * SIZE, 4 * SIZE);
table:
	srand((unsigned)time(0));
	do
	{
		x = (rand() % (WIDTH/ SIZE));
		y = (rand() % (HEIGHT/ SIZE));
	} while (x % 2 == 0 || y % 2 == 0||x>=WIDTH/10-4||y>=HEIGHT/10-4||block.onblock(x,y));
	this->x *= SIZE;
	this->y *= SIZE;
	this->type = rand() % 100;
	if (type >= 0 && type <= 80) {
		type = 1;
	}
	else {
		type = 2;
	}
	for (int i = 0; i < snake.length; i++) {
		if (snake.node[i].x== this->x && snake.node[i].y == this->y) {
			goto table;
		}
	}
}

//����ʳ��
void Food::Draw() {
	char str3[10], str4[10],difficulty[10];
	sprintf_s(str3, "%2d", x);
	sprintf_s(str4, "%2d", y);
	settextcolor(BLACK);
	outtextxy(1000, 150, str3);
	outtextxy(1000, 170, str4);
	if (type == 1)
	{
		putimage(this->x, this->y, &ima2, SRCAND);
		putimage(x, y, &ima1, SRCPAINT);
	}
	else if(type==2)
	{
		putimage(x, y, &ima4, SRCAND);
		putimage(x, y, &ima3, SRCPAINT);
	}
}

//��ʳ��
int Snake::Eat(Food& food) {
	if (food.coli(node[0].x,node[0].y)) {
		if (food.type == 1) {
			two++;
			score += 2;
		}
		else if (food.type == 2) {
			three++;
			score += 3;
		}
		if (this->node[length - 1].x - this->node[length - 2].x == 0 && this->node[length - 1].y - this->node[length - 2].y == -20) {
			this->length++;
			this->node[length - 1].x = this->node[length - 2].x;
			this->node[length - 1].y = this->node[length - 2].y - 2*SIZE;
		}
		if (this->node[length - 1].x - this->node[length - 2].x == 0 && this->node[length - 1].y - this->node[length - 2].y == 20) {
			this->length++;
			this->node[length - 1].x = this->node[length - 2].x;
			this->node[length - 1].y = this->node[length - 2].y + 2*SIZE;
		}
		if (this->node[length - 1].x - this->node[length - 2].x == 20 && this->node[length - 1].y - this->node[length - 2].y == 0) {
			this->length++;
			this->node[length - 1].x = this->node[length - 2].x + 2*SIZE;
			this->node[length - 1].y = this->node[length - 2].y;
		}
		if (this->node[length - 1].x - this->node[length - 2].x == -20 && this->node[length - 1].y - this->node[length - 2].y == 0) {
			this->length++;
			this->node[length - 1].x = this->node[length - 2].x - 2*SIZE;
			this->node[length - 1].y = this->node[length - 2].y;
		}

		return true;
	}
	return false;
}

//ʧ���ж�
bool Snake::Defeat(Block& block) {
	//1.�����߽�
	if (this->node[0].x < 0 || this->node[0].x >= WIDTH || this->node[0].y < 0 || this->node[0].y >= HEIGHT) {
		return true;
	}
	//2.�����Լ�������
	for (int i = 1; i < this->length; i++) {
		if (this->node[0].x == this->node[i].x && this->node[0].y == this->node[i].y) {
			return true;
		}
	}
	//3.�����
	if (block.coli(node[0].x, node[0].y))
	{
		Sleep(1500);
		if (GetAsyncKeyState('1')) {
			wuditime = 3;
			return false;
		}
		return true;
	}
	return false;
}

int main() {
	End ending;
begin:
	initgraph(WIDTH, HEIGHT);
	setbkcolor(WHITE);
	cleardevice();
	mciSendString("open seeyouagain.mp3 alias BGM1", 0, 0, 0);//see you again���ٰ�
	mciSendString("play BGM1 repeat", 0, 0, 0);
	Block block;
	Snake snake;
	int num = 8;
	int newnum=8;
	int eat = 0;
table:
	Food food(snake,block);
	while (1) {
		BeginBatchDraw();
		FlushBatchDraw();
		snake.Draw();
		if (eat)
		{
			block.modify(newnum);
			block.Draw(newnum);
			num = newnum;
		}
		else block.Draw(num);
		if (GetAsyncKeyState('H'))
		{
			newnum += 16;
			block.diff();
		}
		if (GetAsyncKeyState(' '))
			system("Pause");
		food.Draw();
		FlushBatchDraw();
		EndBatchDraw();//˫���壬��ֹ��Ļһ��һ����
		if (snake.Eat(food)) {
			eat = 1;
			snake.wuditime = 5;//�޵�֡
			goto table;
		}
		if (snake.Defeat(block)&&snake.wuditime<=0) {
			mciSendString("close BGM1", 0, 0, 0);
			mciSendString("open ah.mp3 alias BGM2", 0, 0, 0);//����
			mciSendString("play BGM2", 0, 0, 0);
			break;
		}
		snake.Move();
		snake.wuditime--;
		eat = 0;
	}
	HWND window = GetHWnd();
	SetWindowText(window, "����");
	int end=MessageBox(window, "mambaout,see you again?", "��ʾ", MB_OKCANCEL);
	if (end == IDOK) goto begin;
	else if (IDCANCEL==end)
	{
		ending.play();
	}
over:
	return 0;
}
