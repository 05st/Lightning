#include "lnpch.h"
#include "Color.h"

namespace Lightning {
	Color::Color(float red, float green, float blue, float alpha) {
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->alpha = alpha;
	}
}