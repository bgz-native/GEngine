#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace GEngine
{
	RendererAPI* RenderCommand::s_rendererApi = new OpenGLRendererAPI;
}