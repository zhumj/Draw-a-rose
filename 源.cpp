#include <graphics.h>
#include <conio.h>//_getch();
#include "rose.h"
#include <mmsystem.h>//mci库头文件
#pragma comment(lib,"winmm.lib")

#include <iostream>
using namespace std;

void sayToYou();	//打印情书的内容

int main()
{
	initgraph(930, 530);

	//爱情背景音乐
	mciSendString(_T("open 往后余生-马良.mp3 alias love"), 0, 0, 0);
	mciSendString(_T("play love repeat"), 0, 0, 0);//重复播放

	sayToYou();
	drawRose();

	_getch();

	return 0;
}

//打印情书的内容
void sayToYou()
{
	int x = 550, y = 40;
	TCHAR story[17][100] = {
		_T("我一直认为山是水的故事"),
		_T("云是风的故事"),
		_T("你是我的故事"),
		_T("和你在一起"),
		_T("我宁愿让天空所有的星光全部陨落"),
		_T("因为你的眼睛"),
		_T("是我生命里最亮的光芒"),
		_T("往后的余生"),
		_T("风雪是你"),
		_T("平淡是你"),
		_T("清贫是你"),
		_T("荣华是你"),
		_T("心底温柔是你"),
		_T("目光所致"),
		_T("也是你"),
		_T(""),
		_T(" 亲爱的，生日快乐！")
	};

	for (int i = 0; i < 17; i++)
	{
		int length = (lstrlen(story[i]) * sizeof(TCHAR)) / 2;
		cout << length << endl;
		for (int k = 0; k < length; k++)
		{
			if (i >= 16)
			{
				settextstyle(36, 0, _T("Matura MT Script Capitals"));
				settextcolor(RED);
				outtextxy(x + k * 36, y + i * 25, story[i][k]);
				Sleep(500);
			}
			else
			{
				//浪漫字体
				settextstyle(23, 0, _T("Matura MT Script Capitals"));//字号，字宽，字体
				//浪漫字体颜色（粉色）
				settextcolor(RGB(0xdb, 0x70, 0x93));
				outtextxy(x + k * 23, y + i * 25, story[i][k]);
				Sleep(300);
			}
		}
	}
}