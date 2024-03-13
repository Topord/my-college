#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <vector>
#include "point.h"
#include "food.h"

class Food;
class Terrain;
class Snake
{ 
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };

    Snake() {
        snake.emplace_back(16, 6);
        snake.emplace_back(17, 6);
        snake.emplace_back(18, 6);
        direction = Direction::RIGHT;
    }
    void InitSnake();
    void Move();
    void NormalMove();
    bool HitItself();
    bool HitTer(Terrain&);
    bool ChangeDirection();
    bool GetFood(const Food&);
    bool GetBigFood(Food&);
private:
    std::deque<Point> snake;
    std::vector<Point> edgemap;
    Direction direction;
    friend class Food;//将Food类置为友元，以便访问其私有元素
    friend class Terrain;
};
#endif // SNAKE_H