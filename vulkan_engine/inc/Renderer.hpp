#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#define GLFW_INCLUDE_VULKAN

#include <iostream>
#include <GLFW/glfw3.h>

#include <vector>
#include <exception>

namespace vulkanapi
{
	namespace engine
	{
		class Renderer
		{
		private:
			VkInstance m_instance;

			static std::shared_ptr<Renderer> renderer_instance;

		public:
			~Renderer();

			static std::shared_ptr<Renderer> getInstance();

		private:
			Renderer();

			void createInstance();
			void choosePhysicalDevice();
		};
	} // namespace engine
} // namespace vulkanapi

#endif // __RENDERER_HPP__