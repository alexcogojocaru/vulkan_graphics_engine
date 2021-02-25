#include "Renderer.hpp"
#include "log.h"

std::shared_ptr<Renderer> Renderer::renderer_instance = nullptr;

Renderer::Renderer() 
	: m_instance(nullptr)
{
	createInstance();

	choosePhysicalDevice();
}

Renderer::~Renderer()
{
	vkDestroyInstance(m_instance, nullptr);
}

std::shared_ptr<Renderer> Renderer::getInstance()
{
	if (renderer_instance == nullptr)
	{
		renderer_instance = std::shared_ptr<Renderer>(new Renderer);
	}

	return renderer_instance;
}

void Renderer::createInstance()
{
	VkInstanceCreateInfo instanceCreateInfo{};
	VkApplicationInfo appInfo{};

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Vulkan Graphics Engine";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 1, 0);
	appInfo.pEngineName = "Vulkan Graphics Engine";
	appInfo.apiVersion = VK_VERSION_1_0;

	instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pApplicationInfo = &appInfo;

	if (vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create the instance");
	}

	LOG_TRACE("Vulkan instance successfully created");
}

void Renderer::choosePhysicalDevice()
{
	std::vector<VkPhysicalDevice> physicalDevices;
	VkPhysicalDevice physicalDevice{};
	VkPhysicalDeviceProperties phyDeviceProps{};
	uint32_t count = 0;

	vkEnumeratePhysicalDevices(m_instance, &count, nullptr);
	physicalDevices.resize(count);
	vkEnumeratePhysicalDevices(m_instance, &count, physicalDevices.data());

	if (count != 0)
	{
		physicalDevice = physicalDevices[0];

		vkGetPhysicalDeviceProperties(physicalDevice, &phyDeviceProps);
	}
}
