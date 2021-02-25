// vulkan_engine.cpp : Defines the entry point for the application.
//

#include <vector>
#include "Renderer.hpp"

using namespace std;
using namespace vulkanapi::engine;

int main()
{
	std::shared_ptr<Renderer> renderer = Renderer::getInstance();

	return 0;
}
