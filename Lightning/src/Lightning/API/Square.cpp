#include "lnpch.h"
#include "Square.h"

#include "Lightning/Renderer/VertexArray.h"
#include "Lightning/Renderer/VertexBuffer.h"

#include "Vector2.h"
#include "Color.h"

namespace Lightning {
	Square::Square(Renderer* renderer) {
        std::vector<float> vertices = {
             0.5f,  0.5f, 0.0f,  // top right
             0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left 
        };
        std::vector<unsigned int> indices = {
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
        };

        VertexArray* vao = new VertexArray();
        vao->Bind();
        VertexBuffer* vbo = new VertexBuffer(vertices);
        VertexBuffer* ebo = new VertexBuffer(indices);
        vao->SetVertexAttribute(0, 3, false, 3, 0);
        vao->Unbind();

        renderer->AddVertexArray(vao);
	}
}