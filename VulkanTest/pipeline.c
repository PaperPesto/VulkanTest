#include "pipeline.h"
#include <string.h>
#include <stdio.h>
#include "device.h"

VkPipeline Pipeline = VK_NULL_HANDLE;

VkShaderModule CreateComputeShader(void) {
	uint8_t shaderData[20000];

	FILE* f = fopen("comp.spv", "rb");
	if (f == NULL) {
		printf("Failed to open the shader file.\n");
		return VK_NULL_HANDLE;
	}

	size_t size = fread(shaderData, 1, sizeof(shaderData), f);
	fclose(f);

	VkShaderModuleCreateInfo createInfo;
	memset(&createInfo, 0, sizeOf(createInfo));

	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = size;
	createInfo.pCode = shaderData;

	VkShaderModule handle;

	if (vkCreateShaderModule(LogicalDevice, &createInfo, NULL, handle) != VK_SUCCESS) {
		printf("Failed to create the shader module.\n");
		return VK_NULL_HANDLE;
	}

	return handle;
}

void CreatePipeline(void) {
	VkComputePipelineCreateInfo createPipeline;
	memset(&createPipeline, 0, sizeof(createPipeline));
	createPipeline.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
	createPipeline.layout = Layout;
	createPipeline.basePipelineIndex = -1;
	createPipeline.stage.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	createPipeline.stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
	createPipeline.stage.pName = "main";
	createPipeline.stage.module = CreateComputeShader();

	if (vkCreateComputePipelines(LogicalDevice, VK_NULL_HANDLE, 1, &createPipeline, NULL, &Pipeline) != VK_SUCCESS) {
		printf("Failed to create a pipeline\n");
		return;
	}
}