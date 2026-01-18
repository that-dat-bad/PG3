#include "Player.h"
#include "Novice.h"
#include "Command.h"

void MoveRightCommand::Execute(Player& actor) {
	actor.Move(1.0f, 0.0f);
}

void MoveLeftCommand::Execute(Player& actor) {
	actor.Move(-1.0f, 0.0f);
}

Player::Player()
	: position_{ 640.0f, 360.0f }, speed_(4.0f), width_(48), height_(48) {
}

void Player::Update() {
	if (position_.x < width_ / 2) {
		position_.x = (float)width_ / 2;
	}
	if (position_.x > 1280 - width_ / 2) {
		position_.x = 1280 - (float)width_ / 2;
	}
}

void Player::Move(float dirX, float dirY) {
	position_.x += dirX * speed_;
	position_.y += dirY * speed_;
}

void Player::Draw() const {
	int left = static_cast<int>(position_.x - width_ / 2);
	int top = static_cast<int>(position_.y - height_ / 2);
	Novice::DrawBox(left, top, width_, height_, 0, 0xFFFFFFFF, kFillModeSolid);
}