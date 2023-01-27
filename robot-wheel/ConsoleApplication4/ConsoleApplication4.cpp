#include "Omni.hpp"
#include "Motor.hpp"
#include "Pad.hpp"

#include <iostream>

int main() {

	// コントローラー
	Pad pad;

	// モーター
	Motor motor[] = {
		{  1,  2,  3, true },
		{  4,  5,  6, true },
		{  7,  8,  9, true },
		{ 10, 11, 12, true }
	};

	for (;;) {

		// 各モーター出力値計算
		const auto powers = Omni::GetOmniPowerFromScalar(pad.getLeftAxisX(), pad.getLeftAxisY(), pad.getRightAxisX(), 150);

		// モーターに出力
		for (int i = 0; i < 4; i++) {
			motor[i].move(powers[i]);
		}

		// コンソール表示
		for (auto&& it : powers) {
			std::cout << it << " ";
		}
		std::cout << std::endl;

	}

}
