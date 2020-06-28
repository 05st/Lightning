#pragma once

#include "Lightning/API/GameObject.h"
#include "Vector2.h"
#include "Color.h"

namespace Lightning {
	class LN_API Rectangle : public GameObject {
	public:
		Rectangle(Vector2* size, Vector2* position, Color* color, Renderer* renderer);
		~Rectangle() = default;

		Vector2 GetSize() { return Vector2(size->x, size->y); }
		Vector2 GetPosition() { return Vector2(position->x, position->y); }
	private:
		Vector2* size;
		Vector2* position;
		Color* color;
		Renderer* renderer;
	};
}