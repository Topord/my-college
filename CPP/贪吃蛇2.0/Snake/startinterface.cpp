#include "startinterface.h"
#include <windows.h>
#include<iostream>

//�ߴ���߳��ֵ���ȫ���ֵĹ���
void StartInterface::PrintFirst()
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}
//�ߴ��������ƶ��Ĺ���
void StartInterface::PrintSecond()
{
    for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();  //���������е�һ������Ԫ��   ��ӡͷ
        startsnake.front().Clear(); //�������������һ������Ԫ��   ���β
        startsnake.pop_front();     //ɾ�������е�һ��Ԫ��
        Sleep(speed);
    }
}
//�ߴӽӴ��ұߵ���ʧ�Ĺ���
void StartInterface::PrintThird()
{
    //deque.empty ��������Ƿ�Ϊ��  �� -> true, ���� -> false
    while (!startsnake.empty() || textsnake.back().GetX() < 33) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake.empty()) //����߻�û��ʧ�������ƶ�
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//�����������
        PrintText();//���Ƹ���λ�ú������
        Sleep(speed);
    }
}
//��ӡSnake����
void StartInterface::PrintText()
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}
//����ұߵ�����
void StartInterface::ClearText()
{
    for (auto& point : textsnake) //�����ͬʱ���������������ƶ�һ��
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }

}
//��ӡ���м��snake(������ѡ�������)
void StartInterface::MidSnake()
{
    for (auto& point : endsnake)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}
//������
void StartInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}