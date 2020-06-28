#include "lnpch.h"
#include "VertexArray.h"

namespace Lightning {
	VertexArray::VertexArray() {
		glCreateVertexArrays(1, &id);
	}

	void VertexArray::SetVertexAttribute(unsigned int location, int size, bool normalized, int stride, void* offset) {
		if (bound) {
			glVertexAttribPointer(location, size, GL_FLOAT, normalized, stride * sizeof(float), (void*)offset);
			glEnableVertexAttribArray(location);
		}
	}

	void VertexArray::Bind() {
		bound = true;
		glBindVertexArray(id);
	}

	void VertexArray::Unbind() {
		bound = false;
		glBindVertexArray(0);
	}
}