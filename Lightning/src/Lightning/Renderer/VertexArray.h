#pragma once

namespace Lightning {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray() = default;

		void SetVertexAttribute(unsigned int location, int size, bool normalized, int stride, void* offset);

		unsigned int GetId() { return id; }

		void Bind();
		void Unbind();
	private:
		bool bound = false;
		unsigned int id;
	};
}