#include <graphics.h>
#include <conio.h>//_getch();
#include "rose.h"

#include <mmsystem.h>//mci��ͷ�ļ�
#pragma comment(lib,"winmm.lib")

 

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
		_T("  �װ��ģ����տ��֣�")
	};

	//����������ɫ����ɫ��
	settextcolor(RGB(0xdb, 0x70, 0x93));
	//settextcolor(RGB(219,112,147));

	//��������
	settextstyle(23, 0, _T("Matura MT Script Capitals"));//�ֺţ��ֿ�����


	//���鱳������
	//mciSendString(_T("open background_warm_love.mp3 alias love"), 0, 0, 0);
	//mciSendString(_T("play love repeat"), 0, 0, 0);//�ظ�����

	for (int i = 0; i < 17; i++)
	{
		if (i >= 16)
		{
			settextstyle(30, 0, _T("Matura MT Script Capitals"));
			settextcolor(RED);
			//settextcolor(RGB(255,0,0));

			outtextxy(x, y, story[i]);
			y += 25;
			continue;//��������ѭ��
		}
		outtextxy(x, y, story[i]);
		y += 25;
		Sleep(1500);
	}
}