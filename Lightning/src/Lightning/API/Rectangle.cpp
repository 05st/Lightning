#include "lnpch.h"
#include "Rectangle.h"

#include "Lightning/Renderer/VertexArray.h"
#include "Lightning/Renderer/VertexBuffer.h"

namespace Lightning {
    Rectangle::Rectangle(Vector2* size, Vector2* position, Color* color, Renderer* renderer) {
        LN_INFO("Creating rectangle ({0}, {1}) ({2}, {3}) [R: {4}, G: {5}, B: {6}, A: {7}]", size->x, size->y, position->x, position->y, color->red, color->green, color->blue, color->alpha);

        std::vector<float> vertices = {
            -1.0f + (position->x*2) + (size->x*2), 1.0f - (position->y*2), 0.0f,  // top right
            -1.0f + (position->x*2) + (size->x*2), 1.0f - (position->y*2) - (size->y*2), 0.0f,  // bottom right
            -1.0f + (position->x*2), 1.0f - (position->y*2) - (size->y*2) , 0.0f,  // bottom left
            -1.0f + (position->x*2), 1.0f - (position->y*2), 0.0f   // top left 
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