#include "lnpch.h"
#include "Renderer.h"

#include "Shader.h"

namespace Lightning {
	Renderer::Renderer() {

	}
	
	void Renderer::Prepare() {
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}