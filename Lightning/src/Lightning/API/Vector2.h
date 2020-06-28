#pragma once

namespace Lightning {
	class LN_API Vector2 {
	public:
		Vector2(float x, float y);
		~Vector2() = default;

		float x, y;
	};
}