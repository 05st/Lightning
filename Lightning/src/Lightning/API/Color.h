#pragma once

namespace Lightning {
	class LN_API Color {
	public:
		Color(float red, float green, float blue, float alpha);
		~Color() = default;

		float red, green, blue, alpha;
	};
}