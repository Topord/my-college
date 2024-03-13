#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "point.h"

class StartInterface
{
public:
    StartInterface() : speed(35) {
        startsnake.emplace_back(Point(0, 14)); // 开始时运动的蛇
        startsnake.emplace_back(Point(1, 14));
        startsnake.emplace_back(Point(2, 15));
        startsnake.emplace_back(Point(3, 16));
        startsnake.emplace_back(Point(4, 17));
        startsnake.emplace_back(Point(5, 18));
        startsnake.emplace_back(Point(6, 17));
        startsnake.emplace_back(Point(7, 16));
        startsnake.emplace_back(Point(8, 15));
        startsnake.emplace_back(Point(9, 14));

        textsnake.emplace_back(Point(-26, 14));//S
        textsnake.emplace_back(Point(-25, 14));
        textsnake.emplace_back(Point(-27, 15));
        textsnake.emplace_back(Point(-26, 16));
        textsnake.emplace_back(Point(-25, 17));
        textsnake.emplace_back(Point(-27, 18));
        textsnake.emplace_back(Point(-26, 18));

        textsnake.emplace_back(Point(-23, 14));//N
        textsnake.emplace_back(Point(-23, 15));
        textsnake.emplace_back(Point(-23, 16));
        textsnake.emplace_back(Point(-23, 17));
        textsnake.emplace_back(Point(-23, 18));
        textsnake.emplace_back(Point(-22, 15));
        textsnake.emplace_back(Point(-21, 16));
        textsnake.emplace_back(Point(-20, 17));
        textsnake.emplace_back(Point(-19, 14));
        textsnake.emplace_back(Point(-19, 15));
        textsnake.emplace_back(Point(-19, 16));
        textsnake.emplace_back(Point(-19, 17));
        textsnake.emplace_back(Point(-19, 18));

        textsnake.emplace_back(Point(-17, 18));//A
        textsnake.emplace_back(Point(-16, 17));
        textsnake.emplace_back(Point(-15, 16));
        textsnake.emplace_back(Point(-14, 15));
        textsnake.emplace_back(Point(-14, 16));
        textsnake.emplace_back(Point(-13, 14));
        textsnake.emplace_back(Point(-13, 16));
        textsnake.emplace_back(Point(-12, 15));
        textsnake.emplace_back(Point(-12, 16));
        textsnake.emplace_back(Point(-11, 16));
        textsnake.emplace_back(Point(-10, 17));
        textsnake.emplace_back(Point(-9, 18));

        textsnake.emplace_back(Point(-7, 14));//K
        textsnake.emplace_back(Point(-7, 15));
        textsnake.emplace_back(Point(-7, 16));
        textsnake.emplace_back(Point(-7, 17));
        textsnake.emplace_back(Point(-7, 18));
        textsnake.emplace_back(Point(-6, 16));
        textsnake.emplace_back(Point(-5, 15));
        textsnake.emplace_back(Point(-5, 17));
        textsnake.emplace_back(Point(-4, 14));
        textsnake.emplace_back(Point(-4, 18));

        textsnake.emplace_back(Point(-2, 14));//E
        textsnake.emplace_back(Point(-2, 15));
        textsnake.emplace_back(Point(-2, 16));
        textsnake.emplace_back(Point(-2, 17));
        textsnake.emplace_back(Point(-2, 18));
        textsnake.emplace_back(Point(-1, 14));
        textsnake.emplace_back(Point(-1, 16));
        textsnake.emplace_back(Point(-1, 18));
        textsnake.emplace_back(Point(0, 14));
        textsnake.emplace_back(Point(0, 16));
        textsnake.emplace_back(Point(0, 18));

        //
        endsnake.emplace_back(Point(9, 14));//S
        endsnake.emplace_back(Point(10, 14));
        endsnake.emplace_back(Point(8, 15));
        endsnake.emplace_back(Point(9, 16));
        endsnake.emplace_back(Point(10, 17));
        endsnake.emplace_back(Point(8, 18));
        endsnake.emplace_back(Point(9, 18));

        endsnake.emplace_back(Point(12, 14));//N
        endsnake.emplace_back(Point(12, 15));
        endsnake.emplace_back(Point(12, 16));
        endsnake.emplace_back(Point(12, 17));
        endsnake.emplace_back(Point(12, 18));
        endsnake.emplace_back(Point(13, 15));
        endsnake.emplace_back(Point(14, 16));
        endsnake.emplace_back(Point(15, 17));
        endsnake.emplace_back(Point(16, 14));
        endsnake.emplace_back(Point(16, 15));
        endsnake.emplace_back(Point(16, 16));
        endsnake.emplace_back(Point(16, 17));
        endsnake.emplace_back(Point(16, 18));

        endsnake.emplace_back(Point(18, 18));//A
        endsnake.emplace_back(Point(19, 17));
        endsnake.emplace_back(Point(20, 16));
        endsnake.emplace_back(Point(21, 15));
        endsnake.emplace_back(Point(21, 16));
        endsnake.emplace_back(Point(22, 14));
        endsnake.emplace_back(Point(22, 16));
        endsnake.emplace_back(Point(23, 15));
        endsnake.emplace_back(Point(23, 16));
        endsnake.emplace_back(Point(24, 16));
        endsnake.emplace_back(Point(25, 17));
        endsnake.emplace_back(Point(26, 18));

        endsnake.emplace_back(Point(28, 14));//K
        endsnake.emplace_back(Point(28, 15));
        endsnake.emplace_back(Point(28, 16));
        endsnake.emplace_back(Point(28, 17));
        endsnake.emplace_back(Point(28, 18));
        endsnake.emplace_back(Point(29, 16));
        endsnake.emplace_back(Point(30, 15));
        endsnake.emplace_back(Point(30, 17));
        endsnake.emplace_back(Point(31, 14));
        endsnake.emplace_back(Point(31, 18));

        endsnake.emplace_back(Point(33, 14));//E
        endsnake.emplace_back(Point(33, 15));
        endsnake.emplace_back(Point(33, 16));
        endsnake.emplace_back(Point(33, 17));
        endsnake.emplace_back(Point(33, 18));
        endsnake.emplace_back(Point(34, 14));
        endsnake.emplace_back(Point(34, 16));
        endsnake.emplace_back(Point(34, 18));
        endsnake.emplace_back(Point(35, 14));
        endsnake.emplace_back(Point(35, 16));
        endsnake.emplace_back(Point(35, 18));

    }
    void PrintFirst();
    void PrintSecond();
    void PrintThird();
    void PrintText();
    void ClearText();
    void Action();
    void MidSnake();
private:
    std::deque<Point> startsnake;//开始动画中的蛇
    std::vector<Point> textsnake;//开始动画中的文字
    //最后的snake
    std::vector<Point> endsnake;
    int speed;//动画的速度
};
#endif // STRATINTERFACE_H