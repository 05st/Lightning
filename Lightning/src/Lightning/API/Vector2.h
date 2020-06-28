#pragma once

namespace Lightning {
	class LN_API Vector2 {
	public:
		Vector2(float x, float y);
		~Vector2() = default;

		Vector2 FromPixels(int x, int y);

		float x, y;
	};
}