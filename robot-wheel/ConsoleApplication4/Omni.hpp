#pragma once

/// マイコンによってはSTL使えないです🥲😭
#include <array>    // std::array
#include <numeric>  // std::accumulate

namespace Omni
{

	/// @brief 方向スカラー、旋回スカラーから各オムニホイールの出力を算出する
	/// @param {x} x方向 (-255 ~ 255)
	/// @param {y} y方向 (-255 ~ 255)
	/// @param {t} 旋回  (-255 ~ 255)
	/// @param {powerLimit} 出力最大値
	/// @return 各オムニホイールの出力
	inline std::array<int16_t, 4> GetOmniPowerFromScalar(int16_t x, int16_t y, int16_t t, int16_t powerLimit)
	{

		// 4輪の場合スカラーを足すだけでOKです 
		// 3輪オムニを使うときは三角関数での行列計算が必要です
		// 矢印はモーター正転時の力の働く方向です
		// 
		//        前
		// [↗:0]      [↘:1]
		// 
		//        
		// 
		// [↖:3]      [↙:2]
		//        後
		//
		std::array<int16_t, 4> powers = {
			+x + y + t,  // 0
			+x - y + t,  // 1
			-x - y + t,  // 2
			-x + y + t   // 3
		};

		// 単純にスカラーを足しただけなので、出力値が 255*3 になってしまう場合が考えられます。
		// なので4輪のうち最大出力値をもとめ、最大値が {powerLimit} になるよう圧縮します。
		const int16_t max = std::accumulate(powers.begin(), powers.end(), 0, [](int16_t max, int16_t it) {
			return std::max(max, it);
			});

		//同義(上では、なるべく変数をconstにしたいため、C++STLのaccumulate関数を使って求めてます)
		//int16_t max = 0;
		//for (auto&& it : powers)
		//{
		//	max = std::max(max, it);
		//}


		// 出力値が {powerLimit} をオーバーしている
		if (max > powerLimit)
		{

			// 圧縮率
			const double ratio = static_cast<double>(powerLimit) / max;

			// 圧縮
			for (auto&& it : powers)
			{
				it = static_cast<int16_t>(it * ratio);
			}

		}

		return powers;

	}



};