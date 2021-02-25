// vulkan_engine.cpp : Defines the entry point for the application.
//

#include <vector>
#include "Renderer.hpp"

using namespace std;

int main()
{
	std::shared_ptr<Renderer> renderer = Renderer::getInstance();

	return 0;
}
