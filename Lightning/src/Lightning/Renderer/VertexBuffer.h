#pragma once

namespace Lightning {
	class VertexBuffer {
	public:
		VertexBuffer(std::vector<float> data);
		VertexBuffer(std::vector<unsigned int> data);
		~VertexBuffer() = default;

		unsigned int GetId() { return id; }
	private:
		unsigned int id;
	};
}