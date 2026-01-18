#pragma once
struct Vector2
{
    float x;
	float y;
};
class Command; // 前方宣言

class Player {
public:
    Player();

    // 更新処理
    void Update();

    // 描画
    void Draw() const;

    void Move(float x, float y);

private:
    Vector2 position_;
    float speed_;
    int width_;
    int height_;
};