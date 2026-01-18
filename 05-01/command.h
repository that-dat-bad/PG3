#pragma once
#include "Player.h"

class Command {
public:
    virtual ~Command() {}
    virtual void Execute(Player& actor) = 0;
};

// 右移動
class MoveRightCommand : public Command {
public:
    void Execute(Player& actor) override;
};

// 左移動
class MoveLeftCommand : public Command {
public:
    void Execute(Player& actor) override;
};