#pragma once

#include <cinttypes>

// 適当なコントローラークラス
class Pad {
public:
	/// スティックの傾き取得(-255 ~ 255)
	int16_t getLeftAxisX() { return 0; }
	int16_t getLeftAxisY() { return 100; }
	int16_t getRightAxisX() { return 0; }
};
