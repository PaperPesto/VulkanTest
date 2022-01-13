#include <vulkan/vulkan.h>

void CreateDeviceAndComputeQueue(void);
void CreateCommandPool(void);
void DestroyCommandPoolAndLogicalDevice(void);

extern VkDevice LogicalDevice;
extern VkQueue ComputingQueue;
extern VkCommandPool ComputeCmdPool;