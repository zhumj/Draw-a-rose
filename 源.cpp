#include <graphics.h>
#include <conio.h>//_getch();
#include "rose.h"
#include <mmsystem.h>//mci��ͷ�ļ�
#pragma comment(lib,"winmm.lib")

#include <iostream>
using namespace std;

void sayToYou();	//��ӡ���������

int main()
{
	initgraph(930, 530);

	//���鱳������
	mciSendString(_T("open ��������-����.mp3 alias love"), 0, 0, 0);
	mciSendString(_T("play love repeat"), 0, 0, 0);//�ظ�����

	sayToYou();
	drawRose();

	_getch();

	return 0;
}

//��ӡ���������
void sayToYou()
{
	int x = 550, y = 40;
	TCHAR story[17][100] = {
		_T("��һֱ��Ϊɽ��ˮ�Ĺ���"),
		_T("���Ƿ�Ĺ���"),
		_T("�����ҵĹ���"),
		_T("������һ��"),
		_T("����Ը��������е��ǹ�ȫ������"),
		_T("��Ϊ����۾�"),
		_T("���������������Ĺ�â"),
		_T("���������"),
		_T("��ѩ����"),
		_T("ƽ������"),
		_T("��ƶ����"),
		_T("�ٻ�����"),
		_T("�ĵ���������"),
		_T("Ŀ������"),
		_T("Ҳ����"),
		_T(""),
		_T(" �װ��ģ����տ��֣�")
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
				//��������
				settextstyle(23, 0, _T("Matura MT Script Capitals"));//�ֺţ��ֿ�����
				//����������ɫ����ɫ��
				settextcolor(RGB(0xdb, 0x70, 0x93));
				outtextxy(x + k * 23, y + i * 25, story[i][k]);
				Sleep(300);
			}
		}
	}
}