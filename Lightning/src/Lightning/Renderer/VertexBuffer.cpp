#include "lnpch.h"
#include "VertexBuffer.h"

namespace Lightning {
	VertexBuffer::VertexBuffer(std::vector<float> data) {
		glCreateBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * data.size()), &data[0], GL_STATIC_DRAW);
	}

	VertexBuffer::VertexBuffer(std::vector<unsigned int> data) {
		glCreateBuffers(1, &id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(float) * data.size()), &data[0], GL_STATIC_DRAW);
	}
}