#include "lnpch.h"
#include "Vector2.h"

namespace Lightning {
	Vector2::Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector2 Vector2::FromPixels(int x, int y) {
		return Vector2(0.0f, 0.0f); // finish
	}
}