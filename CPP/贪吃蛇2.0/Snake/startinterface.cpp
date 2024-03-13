#include "startinterface.h"
#include <windows.h>
#include<iostream>

//蛇从左边出现到完全出现的过程
void StartInterface::PrintFirst()
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}
//蛇从左向右移动的过程
void StartInterface::PrintSecond()
{
    for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();  //返回容器中第一个数据元素   打印头
        startsnake.front().Clear(); //返回容器中最后一个数据元素   清除尾
        startsnake.pop_front();     //删除容器中第一个元素
        Sleep(speed);
    }
}
//蛇从接触右边到消失的过程
void StartInterface::PrintThird()
{
    //deque.empty 检查容器是否为空  是 -> true, 不是 -> false
    while (!startsnake.empty() || textsnake.back().GetX() < 33) //当蛇还没消失或文字没移动到指定位置
    {
        if (!startsnake.empty()) //如果蛇还没消失，继续移动
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//清除已有文字
        PrintText();//绘制更新位置后的文字
        Sleep(speed);
    }
}
//打印Snake文字
void StartInterface::PrintText()
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}
//清除右边的文字
void StartInterface::ClearText()
{
    for (auto& point : textsnake) //清除的同时将文字整体向右移动一格
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }

}
//打印在中间的snake(结束且选择继续后)
void StartInterface::MidSnake()
{
    for (auto& point : endsnake)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}
//整体打包
void StartInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}