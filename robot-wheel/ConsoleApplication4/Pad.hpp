#pragma once

#include <cinttypes>

// �K���ȃR���g���[���[�N���X
class Pad {
public:
	/// �X�e�B�b�N�̌X���擾(-255 ~ 255)
	int16_t getLeftAxisX() { return 0; }
	int16_t getLeftAxisY() { return 100; }
	int16_t getRightAxisX() { return 0; }
};
