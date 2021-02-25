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
		/*
			The renderer class implements the creation of the vulkan instance and devices
			The class makes use of the singleton design pattern
		*/
		class Renderer
		{
		private:
			VkInstance m_instance;

			static std::shared_ptr<Renderer> renderer_instance;

		public:
			Renderer(const Renderer&) = delete;
			Renderer operator=(const Renderer&) = delete;

			~Renderer();

			static std::shared_ptr<Renderer> getInstance();

		private:
			Renderer();

			/*
				This method creates the vulkan instance and throws a runtime error
				if the creation process fails
			*/
			void createInstance();

			/*
				This method chooses the gpu or gpus installed in the pc 
			*/
			void choosePhysicalDevice();
		};
	} // namespace engine
} // namespace vulkanapi

#endif // __RENDERER_HPP__