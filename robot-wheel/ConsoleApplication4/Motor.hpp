#pragma once

#include <cinttypes>
#include <utility>

#define OUTPUT 1
void pinMode(...) {}
void digitalWrite(...) {}
void analogWrite(...) {}

/// @brief モーター制御クラス
class Motor {
	const uint8_t pinA;
	const uint8_t pinB;
	const uint8_t pinP;
	const bool direction;  // 回転方向
public:

	Motor(uint8_t pinA, uint8_t pinB, uint8_t pinP, bool direction)
		: pinA(pinA)
		, pinB(pinB)
		, pinP(pinP)
		, direction(direction)
	{
		pinMode(pinA, OUTPUT);
		pinMode(pinB, OUTPUT);
	}
	void move(int16_t power) const {
		if (direction)
		{
			digitalWrite(pinA, power >= 0);
			digitalWrite(pinB, power <= 0);
		}
		else
		{
			digitalWrite(pinA, power <= 0);
			digitalWrite(pinB, power >= 0);
		}
		analogWrite(pinP, std::abs(power));
	}
};