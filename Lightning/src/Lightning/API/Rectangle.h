#pragma once

#include "Vector2.h"
#include "Color.h"

namespace Lightning {
	class LN_API Rectangle {
	public:
		Rectangle(Vector2* size, Vector2* position, Color* color, Renderer* renderer);
		~Rectangle() = default;
	};
}