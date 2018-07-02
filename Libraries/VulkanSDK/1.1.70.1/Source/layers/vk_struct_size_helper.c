// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See helper_file_generator.py for modifications


/***************************************************************************
 *
 * Copyright (c) 2015-2017 The Khronos Group Inc.
 * Copyright (c) 2015-2017 Valve Corporation
 * Copyright (c) 2015-2017 LunarG, Inc.
 * Copyright (c) 2015-2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Mark Lobodzinski <mark@lunarg.com>
 * Author: Courtney Goeltzenleuchter <courtneygo@google.com>
 * Author: Tobin Ehlis <tobine@google.com>
 * Author: Chris Forbes <chrisforbes@google.com>
 * Author: John Zulauf<jzulauf@lunarg.com>
 *
 ****************************************************************************/


#include "vk_struct_size_helper.h"
#include <string.h>
#include <assert.h>

#define ROUNDUP_TO_4(_len) ((((_len) + 3) >> 2) << 2)

// Function Definitions

size_t vk_size_vkapplicationinfo(const VkApplicationInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkApplicationInfo);
        struct_size += (struct_ptr->pApplicationName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pApplicationName))) : 0;
        struct_size += (struct_ptr->pEngineName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pEngineName))) : 0;
    }
    return struct_size;
}

size_t vk_size_vkinstancecreateinfo(const VkInstanceCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkInstanceCreateInfo);
        struct_size += vk_size_vkapplicationinfo(struct_ptr->pApplicationInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->enabledLayerCount; i++) {
            struct_size += (sizeof(char*) + ROUNDUP_TO_4((sizeof(char) * (1 + strlen(struct_ptr->ppEnabledLayerNames[i])))));
        }
        for (i = 0; i < struct_ptr->enabledExtensionCount; i++) {
            struct_size += (sizeof(char*) + ROUNDUP_TO_4((sizeof(char) * (1 + strlen(struct_ptr->ppEnabledExtensionNames[i])))));
        }
    }
    return struct_size;
}

size_t vk_size_vkallocationcallbacks(const VkAllocationCallbacks* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkAllocationCallbacks);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicefeatures(const VkPhysicalDeviceFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceFeatures);
    }
    return struct_size;
}

size_t vk_size_vkformatproperties(const VkFormatProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFormatProperties);
    }
    return struct_size;
}

size_t vk_size_vkextent3d(const VkExtent3D* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExtent3D);
    }
    return struct_size;
}

size_t vk_size_vkimageformatproperties(const VkImageFormatProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageFormatProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicelimits(const VkPhysicalDeviceLimits* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceLimits);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesparseproperties(const VkPhysicalDeviceSparseProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSparseProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceproperties(const VkPhysicalDeviceProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceProperties);
    }
    return struct_size;
}

size_t vk_size_vkqueuefamilyproperties(const VkQueueFamilyProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkQueueFamilyProperties);
    }
    return struct_size;
}

size_t vk_size_vkmemorytype(const VkMemoryType* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryType);
    }
    return struct_size;
}

size_t vk_size_vkmemoryheap(const VkMemoryHeap* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryHeap);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicememoryproperties(const VkPhysicalDeviceMemoryProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMemoryProperties);
    }
    return struct_size;
}

size_t vk_size_vkdevicequeuecreateinfo(const VkDeviceQueueCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceQueueCreateInfo);
        struct_size += (struct_ptr->queueCount ) * sizeof(float);
    }
    return struct_size;
}

size_t vk_size_vkdevicecreateinfo(const VkDeviceCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->queueCreateInfoCount; i++) {
            struct_size += vk_size_vkdevicequeuecreateinfo(&struct_ptr->pQueueCreateInfos[i]);
        }
        for (i = 0; i < struct_ptr->enabledLayerCount; i++) {
            struct_size += (sizeof(char*) + ROUNDUP_TO_4((sizeof(char) * (1 + strlen(struct_ptr->ppEnabledLayerNames[i])))));
        }
        for (i = 0; i < struct_ptr->enabledExtensionCount; i++) {
            struct_size += (sizeof(char*) + ROUNDUP_TO_4((sizeof(char) * (1 + strlen(struct_ptr->ppEnabledExtensionNames[i])))));
        }
        struct_size += vk_size_vkphysicaldevicefeatures(struct_ptr->pEnabledFeatures);
    }
    return struct_size;
}

size_t vk_size_vkextensionproperties(const VkExtensionProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExtensionProperties);
    }
    return struct_size;
}

size_t vk_size_vklayerproperties(const VkLayerProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkLayerProperties);
    }
    return struct_size;
}

size_t vk_size_vksubmitinfo(const VkSubmitInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSubmitInfo);
        struct_size += (struct_ptr->waitSemaphoreCount ) * sizeof(VkSemaphore);
        struct_size += (struct_ptr->waitSemaphoreCount ) * sizeof(VkPipelineStageFlags);
        struct_size += (struct_ptr->commandBufferCount ) * sizeof(VkCommandBuffer);
        struct_size += (struct_ptr->signalSemaphoreCount ) * sizeof(VkSemaphore);
    }
    return struct_size;
}

size_t vk_size_vkmemoryallocateinfo(const VkMemoryAllocateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryAllocateInfo);
    }
    return struct_size;
}

size_t vk_size_vkmappedmemoryrange(const VkMappedMemoryRange* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMappedMemoryRange);
    }
    return struct_size;
}

size_t vk_size_vkmemoryrequirements(const VkMemoryRequirements* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryRequirements);
    }
    return struct_size;
}

size_t vk_size_vksparseimageformatproperties(const VkSparseImageFormatProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageFormatProperties);
    }
    return struct_size;
}

size_t vk_size_vksparseimagememoryrequirements(const VkSparseImageMemoryRequirements* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageMemoryRequirements);
    }
    return struct_size;
}

size_t vk_size_vksparsememorybind(const VkSparseMemoryBind* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseMemoryBind);
    }
    return struct_size;
}

size_t vk_size_vksparsebuffermemorybindinfo(const VkSparseBufferMemoryBindInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseBufferMemoryBindInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->bindCount; i++) {
            struct_size += vk_size_vksparsememorybind(&struct_ptr->pBinds[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vksparseimageopaquememorybindinfo(const VkSparseImageOpaqueMemoryBindInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageOpaqueMemoryBindInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->bindCount; i++) {
            struct_size += vk_size_vksparsememorybind(&struct_ptr->pBinds[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkimagesubresource(const VkImageSubresource* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageSubresource);
    }
    return struct_size;
}

size_t vk_size_vkoffset3d(const VkOffset3D* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkOffset3D);
    }
    return struct_size;
}

size_t vk_size_vksparseimagememorybind(const VkSparseImageMemoryBind* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageMemoryBind);
    }
    return struct_size;
}

size_t vk_size_vksparseimagememorybindinfo(const VkSparseImageMemoryBindInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageMemoryBindInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->bindCount; i++) {
            struct_size += vk_size_vksparseimagememorybind(&struct_ptr->pBinds[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkbindsparseinfo(const VkBindSparseInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindSparseInfo);
        struct_size += (struct_ptr->waitSemaphoreCount ) * sizeof(VkSemaphore);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->bufferBindCount; i++) {
            struct_size += vk_size_vksparsebuffermemorybindinfo(&struct_ptr->pBufferBinds[i]);
        }
        for (i = 0; i < struct_ptr->imageOpaqueBindCount; i++) {
            struct_size += vk_size_vksparseimageopaquememorybindinfo(&struct_ptr->pImageOpaqueBinds[i]);
        }
        for (i = 0; i < struct_ptr->imageBindCount; i++) {
            struct_size += vk_size_vksparseimagememorybindinfo(&struct_ptr->pImageBinds[i]);
        }
        struct_size += (struct_ptr->signalSemaphoreCount ) * sizeof(VkSemaphore);
    }
    return struct_size;
}

size_t vk_size_vkfencecreateinfo(const VkFenceCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFenceCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vksemaphorecreateinfo(const VkSemaphoreCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSemaphoreCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkeventcreateinfo(const VkEventCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkEventCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkquerypoolcreateinfo(const VkQueryPoolCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkQueryPoolCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkbuffercreateinfo(const VkBufferCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferCreateInfo);
        struct_size += (struct_ptr->queueFamilyIndexCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkbufferviewcreateinfo(const VkBufferViewCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferViewCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkimagecreateinfo(const VkImageCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageCreateInfo);
        struct_size += (struct_ptr->queueFamilyIndexCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vksubresourcelayout(const VkSubresourceLayout* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSubresourceLayout);
    }
    return struct_size;
}

size_t vk_size_vkcomponentmapping(const VkComponentMapping* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkComponentMapping);
    }
    return struct_size;
}

size_t vk_size_vkimagesubresourcerange(const VkImageSubresourceRange* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageSubresourceRange);
    }
    return struct_size;
}

size_t vk_size_vkimageviewcreateinfo(const VkImageViewCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageViewCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkshadermodulecreateinfo(const VkShaderModuleCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkShaderModuleCreateInfo);
        struct_size += (struct_ptr->codeSize/4 ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkpipelinecachecreateinfo(const VkPipelineCacheCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineCacheCreateInfo);
        struct_size += (struct_ptr->initialDataSize ) * sizeof(void*);
    }
    return struct_size;
}

size_t vk_size_vkspecializationmapentry(const VkSpecializationMapEntry* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSpecializationMapEntry);
    }
    return struct_size;
}

size_t vk_size_vkspecializationinfo(const VkSpecializationInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSpecializationInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->mapEntryCount; i++) {
            struct_size += vk_size_vkspecializationmapentry(&struct_ptr->pMapEntries[i]);
        }
        struct_size += (struct_ptr->dataSize ) * sizeof(void*);
    }
    return struct_size;
}

size_t vk_size_vkpipelineshaderstagecreateinfo(const VkPipelineShaderStageCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineShaderStageCreateInfo);
        struct_size += (struct_ptr->pName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pName))) : 0;
        struct_size += vk_size_vkspecializationinfo(struct_ptr->pSpecializationInfo);
    }
    return struct_size;
}

size_t vk_size_vkvertexinputbindingdescription(const VkVertexInputBindingDescription* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkVertexInputBindingDescription);
    }
    return struct_size;
}

size_t vk_size_vkvertexinputattributedescription(const VkVertexInputAttributeDescription* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkVertexInputAttributeDescription);
    }
    return struct_size;
}

size_t vk_size_vkpipelinevertexinputstatecreateinfo(const VkPipelineVertexInputStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineVertexInputStateCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->vertexBindingDescriptionCount; i++) {
            struct_size += vk_size_vkvertexinputbindingdescription(&struct_ptr->pVertexBindingDescriptions[i]);
        }
        for (i = 0; i < struct_ptr->vertexAttributeDescriptionCount; i++) {
            struct_size += vk_size_vkvertexinputattributedescription(&struct_ptr->pVertexAttributeDescriptions[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkpipelineinputassemblystatecreateinfo(const VkPipelineInputAssemblyStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineInputAssemblyStateCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkpipelinetessellationstatecreateinfo(const VkPipelineTessellationStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineTessellationStateCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkviewport(const VkViewport* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkViewport);
    }
    return struct_size;
}

size_t vk_size_vkoffset2d(const VkOffset2D* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkOffset2D);
    }
    return struct_size;
}

size_t vk_size_vkextent2d(const VkExtent2D* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExtent2D);
    }
    return struct_size;
}

size_t vk_size_vkrect2d(const VkRect2D* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRect2D);
    }
    return struct_size;
}

size_t vk_size_vkpipelineviewportstatecreateinfo(const VkPipelineViewportStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineViewportStateCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->viewportCount; i++) {
            struct_size += vk_size_vkviewport(&struct_ptr->pViewports[i]);
        }
        for (i = 0; i < struct_ptr->scissorCount; i++) {
            struct_size += vk_size_vkrect2d(&struct_ptr->pScissors[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkpipelinerasterizationstatecreateinfo(const VkPipelineRasterizationStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineRasterizationStateCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkpipelinemultisamplestatecreateinfo(const VkPipelineMultisampleStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineMultisampleStateCreateInfo);
        struct_size += (struct_ptr->rasterizationSamples/32 + 1 ) * sizeof(VkSampleMask);
    }
    return struct_size;
}

size_t vk_size_vkstencilopstate(const VkStencilOpState* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkStencilOpState);
    }
    return struct_size;
}

size_t vk_size_vkpipelinedepthstencilstatecreateinfo(const VkPipelineDepthStencilStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineDepthStencilStateCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkpipelinecolorblendattachmentstate(const VkPipelineColorBlendAttachmentState* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineColorBlendAttachmentState);
    }
    return struct_size;
}

size_t vk_size_vkpipelinecolorblendstatecreateinfo(const VkPipelineColorBlendStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineColorBlendStateCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->attachmentCount; i++) {
            struct_size += vk_size_vkpipelinecolorblendattachmentstate(&struct_ptr->pAttachments[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkpipelinedynamicstatecreateinfo(const VkPipelineDynamicStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineDynamicStateCreateInfo);
        struct_size += (struct_ptr->dynamicStateCount ) * sizeof(VkDynamicState);
    }
    return struct_size;
}

size_t vk_size_vkgraphicspipelinecreateinfo(const VkGraphicsPipelineCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkGraphicsPipelineCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->stageCount; i++) {
            struct_size += vk_size_vkpipelineshaderstagecreateinfo(&struct_ptr->pStages[i]);
        }
        struct_size += vk_size_vkpipelinevertexinputstatecreateinfo(struct_ptr->pVertexInputState);
        struct_size += vk_size_vkpipelineinputassemblystatecreateinfo(struct_ptr->pInputAssemblyState);
        struct_size += vk_size_vkpipelinetessellationstatecreateinfo(struct_ptr->pTessellationState);
        struct_size += vk_size_vkpipelineviewportstatecreateinfo(struct_ptr->pViewportState);
        struct_size += vk_size_vkpipelinerasterizationstatecreateinfo(struct_ptr->pRasterizationState);
        struct_size += vk_size_vkpipelinemultisamplestatecreateinfo(struct_ptr->pMultisampleState);
        struct_size += vk_size_vkpipelinedepthstencilstatecreateinfo(struct_ptr->pDepthStencilState);
        struct_size += vk_size_vkpipelinecolorblendstatecreateinfo(struct_ptr->pColorBlendState);
        struct_size += vk_size_vkpipelinedynamicstatecreateinfo(struct_ptr->pDynamicState);
    }
    return struct_size;
}

size_t vk_size_vkcomputepipelinecreateinfo(const VkComputePipelineCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkComputePipelineCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkpushconstantrange(const VkPushConstantRange* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPushConstantRange);
    }
    return struct_size;
}

size_t vk_size_vkpipelinelayoutcreateinfo(const VkPipelineLayoutCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineLayoutCreateInfo);
        struct_size += (struct_ptr->setLayoutCount ) * sizeof(VkDescriptorSetLayout);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->pushConstantRangeCount; i++) {
            struct_size += vk_size_vkpushconstantrange(&struct_ptr->pPushConstantRanges[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vksamplercreateinfo(const VkSamplerCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorsetlayoutbinding(const VkDescriptorSetLayoutBinding* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorSetLayoutBinding);
        struct_size += (struct_ptr->descriptorCount ) * sizeof(VkSampler);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorsetlayoutcreateinfo(const VkDescriptorSetLayoutCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorSetLayoutCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->bindingCount; i++) {
            struct_size += vk_size_vkdescriptorsetlayoutbinding(&struct_ptr->pBindings[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkdescriptorpoolsize(const VkDescriptorPoolSize* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorPoolSize);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorpoolcreateinfo(const VkDescriptorPoolCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorPoolCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->poolSizeCount; i++) {
            struct_size += vk_size_vkdescriptorpoolsize(&struct_ptr->pPoolSizes[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkdescriptorsetallocateinfo(const VkDescriptorSetAllocateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorSetAllocateInfo);
        struct_size += (struct_ptr->descriptorSetCount ) * sizeof(VkDescriptorSetLayout);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorimageinfo(const VkDescriptorImageInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorImageInfo);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorbufferinfo(const VkDescriptorBufferInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorBufferInfo);
    }
    return struct_size;
}

size_t vk_size_vkwritedescriptorset(const VkWriteDescriptorSet* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkWriteDescriptorSet);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->descriptorCount; i++) {
            struct_size += vk_size_vkdescriptorimageinfo(&struct_ptr->pImageInfo[i]);
        }
        for (i = 0; i < struct_ptr->descriptorCount; i++) {
            struct_size += vk_size_vkdescriptorbufferinfo(&struct_ptr->pBufferInfo[i]);
        }
        struct_size += (struct_ptr->descriptorCount ) * sizeof(VkBufferView);
    }
    return struct_size;
}

size_t vk_size_vkcopydescriptorset(const VkCopyDescriptorSet* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCopyDescriptorSet);
    }
    return struct_size;
}

size_t vk_size_vkframebuffercreateinfo(const VkFramebufferCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFramebufferCreateInfo);
        struct_size += (struct_ptr->attachmentCount ) * sizeof(VkImageView);
    }
    return struct_size;
}

size_t vk_size_vkattachmentdescription(const VkAttachmentDescription* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkAttachmentDescription);
    }
    return struct_size;
}

size_t vk_size_vkattachmentreference(const VkAttachmentReference* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkAttachmentReference);
    }
    return struct_size;
}

size_t vk_size_vksubpassdescription(const VkSubpassDescription* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSubpassDescription);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->inputAttachmentCount; i++) {
            struct_size += vk_size_vkattachmentreference(&struct_ptr->pInputAttachments[i]);
        }
        for (i = 0; i < struct_ptr->colorAttachmentCount; i++) {
            struct_size += vk_size_vkattachmentreference(&struct_ptr->pColorAttachments[i]);
        }
        for (i = 0; i < struct_ptr->colorAttachmentCount; i++) {
            struct_size += vk_size_vkattachmentreference(&struct_ptr->pResolveAttachments[i]);
        }
        struct_size += vk_size_vkattachmentreference(struct_ptr->pDepthStencilAttachment);
        struct_size += (struct_ptr->preserveAttachmentCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vksubpassdependency(const VkSubpassDependency* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSubpassDependency);
    }
    return struct_size;
}

size_t vk_size_vkrenderpasscreateinfo(const VkRenderPassCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->attachmentCount; i++) {
            struct_size += vk_size_vkattachmentdescription(&struct_ptr->pAttachments[i]);
        }
        for (i = 0; i < struct_ptr->subpassCount; i++) {
            struct_size += vk_size_vksubpassdescription(&struct_ptr->pSubpasses[i]);
        }
        for (i = 0; i < struct_ptr->dependencyCount; i++) {
            struct_size += vk_size_vksubpassdependency(&struct_ptr->pDependencies[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkcommandpoolcreateinfo(const VkCommandPoolCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCommandPoolCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkcommandbufferallocateinfo(const VkCommandBufferAllocateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCommandBufferAllocateInfo);
    }
    return struct_size;
}

size_t vk_size_vkcommandbufferinheritanceinfo(const VkCommandBufferInheritanceInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCommandBufferInheritanceInfo);
    }
    return struct_size;
}

size_t vk_size_vkcommandbufferbegininfo(const VkCommandBufferBeginInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCommandBufferBeginInfo);
        struct_size += vk_size_vkcommandbufferinheritanceinfo(struct_ptr->pInheritanceInfo);
    }
    return struct_size;
}

size_t vk_size_vkbuffercopy(const VkBufferCopy* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferCopy);
    }
    return struct_size;
}

size_t vk_size_vkimagesubresourcelayers(const VkImageSubresourceLayers* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageSubresourceLayers);
    }
    return struct_size;
}

size_t vk_size_vkimagecopy(const VkImageCopy* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageCopy);
    }
    return struct_size;
}

size_t vk_size_vkimageblit(const VkImageBlit* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageBlit);
    }
    return struct_size;
}

size_t vk_size_vkbufferimagecopy(const VkBufferImageCopy* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferImageCopy);
    }
    return struct_size;
}

size_t vk_size_vkclearcolorvalue(const VkClearColorValue* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkClearColorValue);
    }
    return struct_size;
}

size_t vk_size_vkcleardepthstencilvalue(const VkClearDepthStencilValue* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkClearDepthStencilValue);
    }
    return struct_size;
}

size_t vk_size_vkclearvalue(const VkClearValue* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkClearValue);
    }
    return struct_size;
}

size_t vk_size_vkclearattachment(const VkClearAttachment* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkClearAttachment);
    }
    return struct_size;
}

size_t vk_size_vkclearrect(const VkClearRect* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkClearRect);
    }
    return struct_size;
}

size_t vk_size_vkimageresolve(const VkImageResolve* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageResolve);
    }
    return struct_size;
}

size_t vk_size_vkmemorybarrier(const VkMemoryBarrier* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryBarrier);
    }
    return struct_size;
}

size_t vk_size_vkbuffermemorybarrier(const VkBufferMemoryBarrier* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferMemoryBarrier);
    }
    return struct_size;
}

size_t vk_size_vkimagememorybarrier(const VkImageMemoryBarrier* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageMemoryBarrier);
    }
    return struct_size;
}

size_t vk_size_vkrenderpassbegininfo(const VkRenderPassBeginInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassBeginInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->clearValueCount; i++) {
            struct_size += vk_size_vkclearvalue(&struct_ptr->pClearValues[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkdispatchindirectcommand(const VkDispatchIndirectCommand* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDispatchIndirectCommand);
    }
    return struct_size;
}

size_t vk_size_vkdrawindexedindirectcommand(const VkDrawIndexedIndirectCommand* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDrawIndexedIndirectCommand);
    }
    return struct_size;
}

size_t vk_size_vkdrawindirectcommand(const VkDrawIndirectCommand* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDrawIndirectCommand);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesubgroupproperties(const VkPhysicalDeviceSubgroupProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSubgroupProperties);
    }
    return struct_size;
}

size_t vk_size_vkbindbuffermemoryinfo(const VkBindBufferMemoryInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindBufferMemoryInfo);
    }
    return struct_size;
}

size_t vk_size_vkbindimagememoryinfo(const VkBindImageMemoryInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImageMemoryInfo);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevice16bitstoragefeatures(const VkPhysicalDevice16BitStorageFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDevice16BitStorageFeatures);
    }
    return struct_size;
}

size_t vk_size_vkmemorydedicatedrequirements(const VkMemoryDedicatedRequirements* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryDedicatedRequirements);
    }
    return struct_size;
}

size_t vk_size_vkmemorydedicatedallocateinfo(const VkMemoryDedicatedAllocateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryDedicatedAllocateInfo);
    }
    return struct_size;
}

size_t vk_size_vkmemoryallocateflagsinfo(const VkMemoryAllocateFlagsInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryAllocateFlagsInfo);
    }
    return struct_size;
}

size_t vk_size_vkdevicegrouprenderpassbegininfo(const VkDeviceGroupRenderPassBeginInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupRenderPassBeginInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->deviceRenderAreaCount; i++) {
            struct_size += vk_size_vkrect2d(&struct_ptr->pDeviceRenderAreas[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupcommandbufferbegininfo(const VkDeviceGroupCommandBufferBeginInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupCommandBufferBeginInfo);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupsubmitinfo(const VkDeviceGroupSubmitInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupSubmitInfo);
        struct_size += (struct_ptr->waitSemaphoreCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->commandBufferCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->signalSemaphoreCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupbindsparseinfo(const VkDeviceGroupBindSparseInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupBindSparseInfo);
    }
    return struct_size;
}

size_t vk_size_vkbindbuffermemorydevicegroupinfo(const VkBindBufferMemoryDeviceGroupInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindBufferMemoryDeviceGroupInfo);
        struct_size += (struct_ptr->deviceIndexCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkbindimagememorydevicegroupinfo(const VkBindImageMemoryDeviceGroupInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImageMemoryDeviceGroupInfo);
        struct_size += (struct_ptr->deviceIndexCount ) * sizeof(uint32_t);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->splitInstanceBindRegionCount; i++) {
            struct_size += vk_size_vkrect2d(&struct_ptr->pSplitInstanceBindRegions[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicegroupproperties(const VkPhysicalDeviceGroupProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceGroupProperties);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupdevicecreateinfo(const VkDeviceGroupDeviceCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupDeviceCreateInfo);
        struct_size += (struct_ptr->physicalDeviceCount ) * sizeof(VkPhysicalDevice);
    }
    return struct_size;
}

size_t vk_size_vkbuffermemoryrequirementsinfo2(const VkBufferMemoryRequirementsInfo2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferMemoryRequirementsInfo2);
    }
    return struct_size;
}

size_t vk_size_vkimagememoryrequirementsinfo2(const VkImageMemoryRequirementsInfo2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageMemoryRequirementsInfo2);
    }
    return struct_size;
}

size_t vk_size_vkimagesparsememoryrequirementsinfo2(const VkImageSparseMemoryRequirementsInfo2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageSparseMemoryRequirementsInfo2);
    }
    return struct_size;
}

size_t vk_size_vkmemoryrequirements2(const VkMemoryRequirements2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryRequirements2);
    }
    return struct_size;
}

size_t vk_size_vksparseimagememoryrequirements2(const VkSparseImageMemoryRequirements2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageMemoryRequirements2);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicefeatures2(const VkPhysicalDeviceFeatures2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceFeatures2);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceproperties2(const VkPhysicalDeviceProperties2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceProperties2);
    }
    return struct_size;
}

size_t vk_size_vkformatproperties2(const VkFormatProperties2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFormatProperties2);
    }
    return struct_size;
}

size_t vk_size_vkimageformatproperties2(const VkImageFormatProperties2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageFormatProperties2);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceimageformatinfo2(const VkPhysicalDeviceImageFormatInfo2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceImageFormatInfo2);
    }
    return struct_size;
}

size_t vk_size_vkqueuefamilyproperties2(const VkQueueFamilyProperties2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkQueueFamilyProperties2);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicememoryproperties2(const VkPhysicalDeviceMemoryProperties2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMemoryProperties2);
    }
    return struct_size;
}

size_t vk_size_vksparseimageformatproperties2(const VkSparseImageFormatProperties2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageFormatProperties2);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesparseimageformatinfo2(const VkPhysicalDeviceSparseImageFormatInfo2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSparseImageFormatInfo2);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicepointclippingproperties(const VkPhysicalDevicePointClippingProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDevicePointClippingProperties);
    }
    return struct_size;
}

size_t vk_size_vkinputattachmentaspectreference(const VkInputAttachmentAspectReference* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkInputAttachmentAspectReference);
    }
    return struct_size;
}

size_t vk_size_vkrenderpassinputattachmentaspectcreateinfo(const VkRenderPassInputAttachmentAspectCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassInputAttachmentAspectCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->aspectReferenceCount; i++) {
            struct_size += vk_size_vkinputattachmentaspectreference(&struct_ptr->pAspectReferences[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkimageviewusagecreateinfo(const VkImageViewUsageCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageViewUsageCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkpipelinetessellationdomainoriginstatecreateinfo(const VkPipelineTessellationDomainOriginStateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineTessellationDomainOriginStateCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkrenderpassmultiviewcreateinfo(const VkRenderPassMultiviewCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassMultiviewCreateInfo);
        struct_size += (struct_ptr->subpassCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->dependencyCount ) * sizeof(int32_t);
        struct_size += (struct_ptr->correlationMaskCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemultiviewfeatures(const VkPhysicalDeviceMultiviewFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMultiviewFeatures);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemultiviewproperties(const VkPhysicalDeviceMultiviewProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMultiviewProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicevariablepointerfeatures(const VkPhysicalDeviceVariablePointerFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceVariablePointerFeatures);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceprotectedmemoryfeatures(const VkPhysicalDeviceProtectedMemoryFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceProtectedMemoryFeatures);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceprotectedmemoryproperties(const VkPhysicalDeviceProtectedMemoryProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceProtectedMemoryProperties);
    }
    return struct_size;
}

size_t vk_size_vkdevicequeueinfo2(const VkDeviceQueueInfo2* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceQueueInfo2);
    }
    return struct_size;
}

size_t vk_size_vkprotectedsubmitinfo(const VkProtectedSubmitInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkProtectedSubmitInfo);
    }
    return struct_size;
}

size_t vk_size_vksamplerycbcrconversioncreateinfo(const VkSamplerYcbcrConversionCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerYcbcrConversionCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vksamplerycbcrconversioninfo(const VkSamplerYcbcrConversionInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerYcbcrConversionInfo);
    }
    return struct_size;
}

size_t vk_size_vkbindimageplanememoryinfo(const VkBindImagePlaneMemoryInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImagePlaneMemoryInfo);
    }
    return struct_size;
}

size_t vk_size_vkimageplanememoryrequirementsinfo(const VkImagePlaneMemoryRequirementsInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImagePlaneMemoryRequirementsInfo);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesamplerycbcrconversionfeatures(const VkPhysicalDeviceSamplerYcbcrConversionFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures);
    }
    return struct_size;
}

size_t vk_size_vksamplerycbcrconversionimageformatproperties(const VkSamplerYcbcrConversionImageFormatProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerYcbcrConversionImageFormatProperties);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorupdatetemplateentry(const VkDescriptorUpdateTemplateEntry* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorUpdateTemplateEntry);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorupdatetemplatecreateinfo(const VkDescriptorUpdateTemplateCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorUpdateTemplateCreateInfo);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->descriptorUpdateEntryCount; i++) {
            struct_size += vk_size_vkdescriptorupdatetemplateentry(&struct_ptr->pDescriptorUpdateEntries[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkexternalmemoryproperties(const VkExternalMemoryProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalimageformatinfo(const VkPhysicalDeviceExternalImageFormatInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalImageFormatInfo);
    }
    return struct_size;
}

size_t vk_size_vkexternalimageformatproperties(const VkExternalImageFormatProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalImageFormatProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalbufferinfo(const VkPhysicalDeviceExternalBufferInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalBufferInfo);
    }
    return struct_size;
}

size_t vk_size_vkexternalbufferproperties(const VkExternalBufferProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalBufferProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceidproperties(const VkPhysicalDeviceIDProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceIDProperties);
    }
    return struct_size;
}

size_t vk_size_vkexternalmemoryimagecreateinfo(const VkExternalMemoryImageCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryImageCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkexternalmemorybuffercreateinfo(const VkExternalMemoryBufferCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryBufferCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkexportmemoryallocateinfo(const VkExportMemoryAllocateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportMemoryAllocateInfo);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalfenceinfo(const VkPhysicalDeviceExternalFenceInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalFenceInfo);
    }
    return struct_size;
}

size_t vk_size_vkexternalfenceproperties(const VkExternalFenceProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalFenceProperties);
    }
    return struct_size;
}

size_t vk_size_vkexportfencecreateinfo(const VkExportFenceCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportFenceCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkexportsemaphorecreateinfo(const VkExportSemaphoreCreateInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportSemaphoreCreateInfo);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalsemaphoreinfo(const VkPhysicalDeviceExternalSemaphoreInfo* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalSemaphoreInfo);
    }
    return struct_size;
}

size_t vk_size_vkexternalsemaphoreproperties(const VkExternalSemaphoreProperties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalSemaphoreProperties);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemaintenance3properties(const VkPhysicalDeviceMaintenance3Properties* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMaintenance3Properties);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorsetlayoutsupport(const VkDescriptorSetLayoutSupport* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorSetLayoutSupport);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceshaderdrawparameterfeatures(const VkPhysicalDeviceShaderDrawParameterFeatures* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceShaderDrawParameterFeatures);
    }
    return struct_size;
}

size_t vk_size_vksurfacecapabilitieskhr(const VkSurfaceCapabilitiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSurfaceCapabilitiesKHR);
    }
    return struct_size;
}

size_t vk_size_vksurfaceformatkhr(const VkSurfaceFormatKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSurfaceFormatKHR);
    }
    return struct_size;
}

size_t vk_size_vkswapchaincreateinfokhr(const VkSwapchainCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSwapchainCreateInfoKHR);
        struct_size += (struct_ptr->queueFamilyIndexCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkpresentinfokhr(const VkPresentInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPresentInfoKHR);
        struct_size += (struct_ptr->waitSemaphoreCount ) * sizeof(VkSemaphore);
        struct_size += (struct_ptr->swapchainCount ) * sizeof(VkSwapchainKHR);
        struct_size += (struct_ptr->swapchainCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->swapchainCount ) * sizeof(VkResult);
    }
    return struct_size;
}

size_t vk_size_vkimageswapchaincreateinfokhr(const VkImageSwapchainCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageSwapchainCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkbindimagememoryswapchaininfokhr(const VkBindImageMemorySwapchainInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImageMemorySwapchainInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkacquirenextimageinfokhr(const VkAcquireNextImageInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkAcquireNextImageInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegrouppresentcapabilitieskhr(const VkDeviceGroupPresentCapabilitiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupPresentCapabilitiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegrouppresentinfokhr(const VkDeviceGroupPresentInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupPresentInfoKHR);
        struct_size += (struct_ptr->swapchainCount ) * sizeof(uint32_t);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupswapchaincreateinfokhr(const VkDeviceGroupSwapchainCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupSwapchainCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplaypropertieskhr(const VkDisplayPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayPropertiesKHR);
        struct_size += (struct_ptr->displayName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->displayName))) : 0;
    }
    return struct_size;
}

size_t vk_size_vkdisplaymodeparameterskhr(const VkDisplayModeParametersKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayModeParametersKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplaymodepropertieskhr(const VkDisplayModePropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayModePropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplaymodecreateinfokhr(const VkDisplayModeCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayModeCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplayplanecapabilitieskhr(const VkDisplayPlaneCapabilitiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayPlaneCapabilitiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplayplanepropertieskhr(const VkDisplayPlanePropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayPlanePropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplaysurfacecreateinfokhr(const VkDisplaySurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplaySurfaceCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdisplaypresentinfokhr(const VkDisplayPresentInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayPresentInfoKHR);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
size_t vk_size_vkxlibsurfacecreateinfokhr(const VkXlibSurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkXlibSurfaceCreateInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR
size_t vk_size_vkxcbsurfacecreateinfokhr(const VkXcbSurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkXcbSurfaceCreateInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
size_t vk_size_vkwaylandsurfacecreateinfokhr(const VkWaylandSurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkWaylandSurfaceCreateInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_MIR_KHR
size_t vk_size_vkmirsurfacecreateinfokhr(const VkMirSurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMirSurfaceCreateInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_MIR_KHR

#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t vk_size_vkandroidsurfacecreateinfokhr(const VkAndroidSurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkAndroidSurfaceCreateInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkwin32surfacecreateinfokhr(const VkWin32SurfaceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkWin32SurfaceCreateInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

size_t vk_size_vkrenderpassmultiviewcreateinfokhr(const VkRenderPassMultiviewCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassMultiviewCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemultiviewfeatureskhr(const VkPhysicalDeviceMultiviewFeaturesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMultiviewFeaturesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemultiviewpropertieskhr(const VkPhysicalDeviceMultiviewPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMultiviewPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicefeatures2khr(const VkPhysicalDeviceFeatures2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceFeatures2KHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceproperties2khr(const VkPhysicalDeviceProperties2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceProperties2KHR);
    }
    return struct_size;
}

size_t vk_size_vkformatproperties2khr(const VkFormatProperties2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFormatProperties2KHR);
    }
    return struct_size;
}

size_t vk_size_vkimageformatproperties2khr(const VkImageFormatProperties2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageFormatProperties2KHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceimageformatinfo2khr(const VkPhysicalDeviceImageFormatInfo2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceImageFormatInfo2KHR);
    }
    return struct_size;
}

size_t vk_size_vkqueuefamilyproperties2khr(const VkQueueFamilyProperties2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkQueueFamilyProperties2KHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicememoryproperties2khr(const VkPhysicalDeviceMemoryProperties2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMemoryProperties2KHR);
    }
    return struct_size;
}

size_t vk_size_vksparseimageformatproperties2khr(const VkSparseImageFormatProperties2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageFormatProperties2KHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesparseimageformatinfo2khr(const VkPhysicalDeviceSparseImageFormatInfo2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSparseImageFormatInfo2KHR);
    }
    return struct_size;
}

size_t vk_size_vkmemoryallocateflagsinfokhr(const VkMemoryAllocateFlagsInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryAllocateFlagsInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegrouprenderpassbegininfokhr(const VkDeviceGroupRenderPassBeginInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupRenderPassBeginInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupcommandbufferbegininfokhr(const VkDeviceGroupCommandBufferBeginInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupCommandBufferBeginInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupsubmitinfokhr(const VkDeviceGroupSubmitInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupSubmitInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupbindsparseinfokhr(const VkDeviceGroupBindSparseInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupBindSparseInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkbindbuffermemorydevicegroupinfokhr(const VkBindBufferMemoryDeviceGroupInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindBufferMemoryDeviceGroupInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkbindimagememorydevicegroupinfokhr(const VkBindImageMemoryDeviceGroupInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImageMemoryDeviceGroupInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicegrouppropertieskhr(const VkPhysicalDeviceGroupPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceGroupPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkdevicegroupdevicecreateinfokhr(const VkDeviceGroupDeviceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGroupDeviceCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalmemorypropertieskhr(const VkExternalMemoryPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalimageformatinfokhr(const VkPhysicalDeviceExternalImageFormatInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalImageFormatInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalimageformatpropertieskhr(const VkExternalImageFormatPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalImageFormatPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalbufferinfokhr(const VkPhysicalDeviceExternalBufferInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalBufferInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalbufferpropertieskhr(const VkExternalBufferPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalBufferPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceidpropertieskhr(const VkPhysicalDeviceIDPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceIDPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalmemoryimagecreateinfokhr(const VkExternalMemoryImageCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryImageCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalmemorybuffercreateinfokhr(const VkExternalMemoryBufferCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryBufferCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexportmemoryallocateinfokhr(const VkExportMemoryAllocateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportMemoryAllocateInfoKHR);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkimportmemorywin32handleinfokhr(const VkImportMemoryWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportMemoryWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkexportmemorywin32handleinfokhr(const VkExportMemoryWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportMemoryWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkmemorywin32handlepropertieskhr(const VkMemoryWin32HandlePropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryWin32HandlePropertiesKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkmemorygetwin32handleinfokhr(const VkMemoryGetWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryGetWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

size_t vk_size_vkimportmemoryfdinfokhr(const VkImportMemoryFdInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportMemoryFdInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkmemoryfdpropertieskhr(const VkMemoryFdPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryFdPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkmemorygetfdinfokhr(const VkMemoryGetFdInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryGetFdInfoKHR);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkwin32keyedmutexacquirereleaseinfokhr(const VkWin32KeyedMutexAcquireReleaseInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkWin32KeyedMutexAcquireReleaseInfoKHR);
        struct_size += (struct_ptr->acquireCount ) * sizeof(VkDeviceMemory);
        struct_size += (struct_ptr->acquireCount ) * sizeof(uint64_t);
        struct_size += (struct_ptr->acquireCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->releaseCount ) * sizeof(VkDeviceMemory);
        struct_size += (struct_ptr->releaseCount ) * sizeof(uint64_t);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

size_t vk_size_vkphysicaldeviceexternalsemaphoreinfokhr(const VkPhysicalDeviceExternalSemaphoreInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalSemaphoreInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalsemaphorepropertieskhr(const VkExternalSemaphorePropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalSemaphorePropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkexportsemaphorecreateinfokhr(const VkExportSemaphoreCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportSemaphoreCreateInfoKHR);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkimportsemaphorewin32handleinfokhr(const VkImportSemaphoreWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportSemaphoreWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkexportsemaphorewin32handleinfokhr(const VkExportSemaphoreWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportSemaphoreWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkd3d12fencesubmitinfokhr(const VkD3D12FenceSubmitInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkD3D12FenceSubmitInfoKHR);
        struct_size += (struct_ptr->waitSemaphoreValuesCount ) * sizeof(uint64_t);
        struct_size += (struct_ptr->signalSemaphoreValuesCount ) * sizeof(uint64_t);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vksemaphoregetwin32handleinfokhr(const VkSemaphoreGetWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSemaphoreGetWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

size_t vk_size_vkimportsemaphorefdinfokhr(const VkImportSemaphoreFdInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportSemaphoreFdInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vksemaphoregetfdinfokhr(const VkSemaphoreGetFdInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSemaphoreGetFdInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicepushdescriptorpropertieskhr(const VkPhysicalDevicePushDescriptorPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDevicePushDescriptorPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevice16bitstoragefeatureskhr(const VkPhysicalDevice16BitStorageFeaturesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDevice16BitStorageFeaturesKHR);
    }
    return struct_size;
}

size_t vk_size_vkrectlayerkhr(const VkRectLayerKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRectLayerKHR);
    }
    return struct_size;
}

size_t vk_size_vkpresentregionkhr(const VkPresentRegionKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPresentRegionKHR);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->rectangleCount; i++) {
            struct_size += vk_size_vkrectlayerkhr(&struct_ptr->pRectangles[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkpresentregionskhr(const VkPresentRegionsKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPresentRegionsKHR);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->swapchainCount; i++) {
            struct_size += vk_size_vkpresentregionkhr(&struct_ptr->pRegions[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkdescriptorupdatetemplateentrykhr(const VkDescriptorUpdateTemplateEntryKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorUpdateTemplateEntryKHR);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorupdatetemplatecreateinfokhr(const VkDescriptorUpdateTemplateCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorUpdateTemplateCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vksharedpresentsurfacecapabilitieskhr(const VkSharedPresentSurfaceCapabilitiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSharedPresentSurfaceCapabilitiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalfenceinfokhr(const VkPhysicalDeviceExternalFenceInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalFenceInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkexternalfencepropertieskhr(const VkExternalFencePropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalFencePropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkexportfencecreateinfokhr(const VkExportFenceCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportFenceCreateInfoKHR);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkimportfencewin32handleinfokhr(const VkImportFenceWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportFenceWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkexportfencewin32handleinfokhr(const VkExportFenceWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportFenceWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkfencegetwin32handleinfokhr(const VkFenceGetWin32HandleInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFenceGetWin32HandleInfoKHR);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

size_t vk_size_vkimportfencefdinfokhr(const VkImportFenceFdInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportFenceFdInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkfencegetfdinfokhr(const VkFenceGetFdInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkFenceGetFdInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicepointclippingpropertieskhr(const VkPhysicalDevicePointClippingPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDevicePointClippingPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkrenderpassinputattachmentaspectcreateinfokhr(const VkRenderPassInputAttachmentAspectCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassInputAttachmentAspectCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkinputattachmentaspectreferencekhr(const VkInputAttachmentAspectReferenceKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkInputAttachmentAspectReferenceKHR);
    }
    return struct_size;
}

size_t vk_size_vkimageviewusagecreateinfokhr(const VkImageViewUsageCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageViewUsageCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkpipelinetessellationdomainoriginstatecreateinfokhr(const VkPipelineTessellationDomainOriginStateCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineTessellationDomainOriginStateCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesurfaceinfo2khr(const VkPhysicalDeviceSurfaceInfo2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSurfaceInfo2KHR);
    }
    return struct_size;
}

size_t vk_size_vksurfacecapabilities2khr(const VkSurfaceCapabilities2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSurfaceCapabilities2KHR);
    }
    return struct_size;
}

size_t vk_size_vksurfaceformat2khr(const VkSurfaceFormat2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSurfaceFormat2KHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicevariablepointerfeatureskhr(const VkPhysicalDeviceVariablePointerFeaturesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceVariablePointerFeaturesKHR);
    }
    return struct_size;
}

size_t vk_size_vkmemorydedicatedrequirementskhr(const VkMemoryDedicatedRequirementsKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryDedicatedRequirementsKHR);
    }
    return struct_size;
}

size_t vk_size_vkmemorydedicatedallocateinfokhr(const VkMemoryDedicatedAllocateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryDedicatedAllocateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkbuffermemoryrequirementsinfo2khr(const VkBufferMemoryRequirementsInfo2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBufferMemoryRequirementsInfo2KHR);
    }
    return struct_size;
}

size_t vk_size_vkimagememoryrequirementsinfo2khr(const VkImageMemoryRequirementsInfo2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageMemoryRequirementsInfo2KHR);
    }
    return struct_size;
}

size_t vk_size_vkimagesparsememoryrequirementsinfo2khr(const VkImageSparseMemoryRequirementsInfo2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageSparseMemoryRequirementsInfo2KHR);
    }
    return struct_size;
}

size_t vk_size_vkmemoryrequirements2khr(const VkMemoryRequirements2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryRequirements2KHR);
    }
    return struct_size;
}

size_t vk_size_vksparseimagememoryrequirements2khr(const VkSparseImageMemoryRequirements2KHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSparseImageMemoryRequirements2KHR);
    }
    return struct_size;
}

size_t vk_size_vkimageformatlistcreateinfokhr(const VkImageFormatListCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImageFormatListCreateInfoKHR);
        struct_size += (struct_ptr->viewFormatCount ) * sizeof(VkFormat);
    }
    return struct_size;
}

size_t vk_size_vksamplerycbcrconversioncreateinfokhr(const VkSamplerYcbcrConversionCreateInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerYcbcrConversionCreateInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vksamplerycbcrconversioninfokhr(const VkSamplerYcbcrConversionInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerYcbcrConversionInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkbindimageplanememoryinfokhr(const VkBindImagePlaneMemoryInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImagePlaneMemoryInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkimageplanememoryrequirementsinfokhr(const VkImagePlaneMemoryRequirementsInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImagePlaneMemoryRequirementsInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesamplerycbcrconversionfeatureskhr(const VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR);
    }
    return struct_size;
}

size_t vk_size_vksamplerycbcrconversionimageformatpropertieskhr(const VkSamplerYcbcrConversionImageFormatPropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerYcbcrConversionImageFormatPropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkbindbuffermemoryinfokhr(const VkBindBufferMemoryInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindBufferMemoryInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkbindimagememoryinfokhr(const VkBindImageMemoryInfoKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkBindImageMemoryInfoKHR);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemaintenance3propertieskhr(const VkPhysicalDeviceMaintenance3PropertiesKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMaintenance3PropertiesKHR);
    }
    return struct_size;
}

size_t vk_size_vkdescriptorsetlayoutsupportkhr(const VkDescriptorSetLayoutSupportKHR* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDescriptorSetLayoutSupportKHR);
    }
    return struct_size;
}

size_t vk_size_vkdebugreportcallbackcreateinfoext(const VkDebugReportCallbackCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugReportCallbackCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkpipelinerasterizationstaterasterizationorderamd(const VkPipelineRasterizationStateRasterizationOrderAMD* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineRasterizationStateRasterizationOrderAMD);
    }
    return struct_size;
}

size_t vk_size_vkdebugmarkerobjectnameinfoext(const VkDebugMarkerObjectNameInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugMarkerObjectNameInfoEXT);
        struct_size += (struct_ptr->pObjectName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pObjectName))) : 0;
    }
    return struct_size;
}

size_t vk_size_vkdebugmarkerobjecttaginfoext(const VkDebugMarkerObjectTagInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugMarkerObjectTagInfoEXT);
        struct_size += (struct_ptr->tagSize ) * sizeof(void*);
    }
    return struct_size;
}

size_t vk_size_vkdebugmarkermarkerinfoext(const VkDebugMarkerMarkerInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugMarkerMarkerInfoEXT);
        struct_size += (struct_ptr->pMarkerName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pMarkerName))) : 0;
    }
    return struct_size;
}

size_t vk_size_vkdedicatedallocationimagecreateinfonv(const VkDedicatedAllocationImageCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDedicatedAllocationImageCreateInfoNV);
    }
    return struct_size;
}

size_t vk_size_vkdedicatedallocationbuffercreateinfonv(const VkDedicatedAllocationBufferCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDedicatedAllocationBufferCreateInfoNV);
    }
    return struct_size;
}

size_t vk_size_vkdedicatedallocationmemoryallocateinfonv(const VkDedicatedAllocationMemoryAllocateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDedicatedAllocationMemoryAllocateInfoNV);
    }
    return struct_size;
}

size_t vk_size_vktexturelodgatherformatpropertiesamd(const VkTextureLODGatherFormatPropertiesAMD* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkTextureLODGatherFormatPropertiesAMD);
    }
    return struct_size;
}

size_t vk_size_vkshaderresourceusageamd(const VkShaderResourceUsageAMD* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkShaderResourceUsageAMD);
    }
    return struct_size;
}

size_t vk_size_vkshaderstatisticsinfoamd(const VkShaderStatisticsInfoAMD* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkShaderStatisticsInfoAMD);
    }
    return struct_size;
}

size_t vk_size_vkexternalimageformatpropertiesnv(const VkExternalImageFormatPropertiesNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalImageFormatPropertiesNV);
    }
    return struct_size;
}

size_t vk_size_vkexternalmemoryimagecreateinfonv(const VkExternalMemoryImageCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExternalMemoryImageCreateInfoNV);
    }
    return struct_size;
}

size_t vk_size_vkexportmemoryallocateinfonv(const VkExportMemoryAllocateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportMemoryAllocateInfoNV);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkimportmemorywin32handleinfonv(const VkImportMemoryWin32HandleInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportMemoryWin32HandleInfoNV);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkexportmemorywin32handleinfonv(const VkExportMemoryWin32HandleInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkExportMemoryWin32HandleInfoNV);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t vk_size_vkwin32keyedmutexacquirereleaseinfonv(const VkWin32KeyedMutexAcquireReleaseInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkWin32KeyedMutexAcquireReleaseInfoNV);
        struct_size += (struct_ptr->acquireCount ) * sizeof(VkDeviceMemory);
        struct_size += (struct_ptr->acquireCount ) * sizeof(uint64_t);
        struct_size += (struct_ptr->acquireCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->releaseCount ) * sizeof(VkDeviceMemory);
        struct_size += (struct_ptr->releaseCount ) * sizeof(uint64_t);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_WIN32_KHR

size_t vk_size_vkvalidationflagsext(const VkValidationFlagsEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkValidationFlagsEXT);
        struct_size += (struct_ptr->disabledValidationCheckCount ) * sizeof(VkValidationCheckEXT);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_VI_NN
size_t vk_size_vkvisurfacecreateinfonn(const VkViSurfaceCreateInfoNN* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkViSurfaceCreateInfoNN);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_VI_NN

size_t vk_size_vkdevicegeneratedcommandsfeaturesnvx(const VkDeviceGeneratedCommandsFeaturesNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGeneratedCommandsFeaturesNVX);
    }
    return struct_size;
}

size_t vk_size_vkdevicegeneratedcommandslimitsnvx(const VkDeviceGeneratedCommandsLimitsNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceGeneratedCommandsLimitsNVX);
    }
    return struct_size;
}

size_t vk_size_vkindirectcommandstokennvx(const VkIndirectCommandsTokenNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkIndirectCommandsTokenNVX);
    }
    return struct_size;
}

size_t vk_size_vkindirectcommandslayouttokennvx(const VkIndirectCommandsLayoutTokenNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkIndirectCommandsLayoutTokenNVX);
    }
    return struct_size;
}

size_t vk_size_vkindirectcommandslayoutcreateinfonvx(const VkIndirectCommandsLayoutCreateInfoNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkIndirectCommandsLayoutCreateInfoNVX);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->tokenCount; i++) {
            struct_size += vk_size_vkindirectcommandslayouttokennvx(&struct_ptr->pTokens[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkcmdprocesscommandsinfonvx(const VkCmdProcessCommandsInfoNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCmdProcessCommandsInfoNVX);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->indirectCommandsTokenCount; i++) {
            struct_size += vk_size_vkindirectcommandstokennvx(&struct_ptr->pIndirectCommandsTokens[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkcmdreservespaceforcommandsinfonvx(const VkCmdReserveSpaceForCommandsInfoNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkCmdReserveSpaceForCommandsInfoNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttablecreateinfonvx(const VkObjectTableCreateInfoNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTableCreateInfoNVX);
        struct_size += (struct_ptr->objectCount ) * sizeof(VkObjectEntryTypeNVX);
        struct_size += (struct_ptr->objectCount ) * sizeof(uint32_t);
        struct_size += (struct_ptr->objectCount ) * sizeof(VkObjectEntryUsageFlagsNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttableentrynvx(const VkObjectTableEntryNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTableEntryNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttablepipelineentrynvx(const VkObjectTablePipelineEntryNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTablePipelineEntryNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttabledescriptorsetentrynvx(const VkObjectTableDescriptorSetEntryNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTableDescriptorSetEntryNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttablevertexbufferentrynvx(const VkObjectTableVertexBufferEntryNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTableVertexBufferEntryNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttableindexbufferentrynvx(const VkObjectTableIndexBufferEntryNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTableIndexBufferEntryNVX);
    }
    return struct_size;
}

size_t vk_size_vkobjecttablepushconstantentrynvx(const VkObjectTablePushConstantEntryNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkObjectTablePushConstantEntryNVX);
    }
    return struct_size;
}

size_t vk_size_vkviewportwscalingnv(const VkViewportWScalingNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkViewportWScalingNV);
    }
    return struct_size;
}

size_t vk_size_vkpipelineviewportwscalingstatecreateinfonv(const VkPipelineViewportWScalingStateCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineViewportWScalingStateCreateInfoNV);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->viewportCount; i++) {
            struct_size += vk_size_vkviewportwscalingnv(&struct_ptr->pViewportWScalings[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vksurfacecapabilities2ext(const VkSurfaceCapabilities2EXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSurfaceCapabilities2EXT);
    }
    return struct_size;
}

size_t vk_size_vkdisplaypowerinfoext(const VkDisplayPowerInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayPowerInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkdeviceeventinfoext(const VkDeviceEventInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceEventInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkdisplayeventinfoext(const VkDisplayEventInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDisplayEventInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkswapchaincountercreateinfoext(const VkSwapchainCounterCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSwapchainCounterCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkrefreshcycledurationgoogle(const VkRefreshCycleDurationGOOGLE* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRefreshCycleDurationGOOGLE);
    }
    return struct_size;
}

size_t vk_size_vkpastpresentationtiminggoogle(const VkPastPresentationTimingGOOGLE* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPastPresentationTimingGOOGLE);
    }
    return struct_size;
}

size_t vk_size_vkpresenttimegoogle(const VkPresentTimeGOOGLE* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPresentTimeGOOGLE);
    }
    return struct_size;
}

size_t vk_size_vkpresenttimesinfogoogle(const VkPresentTimesInfoGOOGLE* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPresentTimesInfoGOOGLE);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->swapchainCount; i++) {
            struct_size += vk_size_vkpresenttimegoogle(&struct_ptr->pTimes[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicemultiviewperviewattributespropertiesnvx(const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);
    }
    return struct_size;
}

size_t vk_size_vkviewportswizzlenv(const VkViewportSwizzleNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkViewportSwizzleNV);
    }
    return struct_size;
}

size_t vk_size_vkpipelineviewportswizzlestatecreateinfonv(const VkPipelineViewportSwizzleStateCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineViewportSwizzleStateCreateInfoNV);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->viewportCount; i++) {
            struct_size += vk_size_vkviewportswizzlenv(&struct_ptr->pViewportSwizzles[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicediscardrectanglepropertiesext(const VkPhysicalDeviceDiscardRectanglePropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkpipelinediscardrectanglestatecreateinfoext(const VkPipelineDiscardRectangleStateCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineDiscardRectangleStateCreateInfoEXT);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->discardRectangleCount; i++) {
            struct_size += vk_size_vkrect2d(&struct_ptr->pDiscardRectangles[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceconservativerasterizationpropertiesext(const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkpipelinerasterizationconservativestatecreateinfoext(const VkPipelineRasterizationConservativeStateCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineRasterizationConservativeStateCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkxycolorext(const VkXYColorEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkXYColorEXT);
    }
    return struct_size;
}

size_t vk_size_vkhdrmetadataext(const VkHdrMetadataEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkHdrMetadataEXT);
    }
    return struct_size;
}

#ifdef VK_USE_PLATFORM_IOS_MVK
size_t vk_size_vkiossurfacecreateinfomvk(const VkIOSSurfaceCreateInfoMVK* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkIOSSurfaceCreateInfoMVK);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_IOS_MVK

#ifdef VK_USE_PLATFORM_MACOS_MVK
size_t vk_size_vkmacossurfacecreateinfomvk(const VkMacOSSurfaceCreateInfoMVK* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMacOSSurfaceCreateInfoMVK);
    }
    return struct_size;
}
#endif // VK_USE_PLATFORM_MACOS_MVK

size_t vk_size_vkdebugutilsobjectnameinfoext(const VkDebugUtilsObjectNameInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugUtilsObjectNameInfoEXT);
        struct_size += (struct_ptr->pObjectName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pObjectName))) : 0;
    }
    return struct_size;
}

size_t vk_size_vkdebugutilsobjecttaginfoext(const VkDebugUtilsObjectTagInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugUtilsObjectTagInfoEXT);
        struct_size += (struct_ptr->tagSize ) * sizeof(void*);
    }
    return struct_size;
}

size_t vk_size_vkdebugutilslabelext(const VkDebugUtilsLabelEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugUtilsLabelEXT);
        struct_size += (struct_ptr->pLabelName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pLabelName))) : 0;
    }
    return struct_size;
}

size_t vk_size_vkdebugutilsmessengercallbackdataext(const VkDebugUtilsMessengerCallbackDataEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugUtilsMessengerCallbackDataEXT);
        struct_size += (struct_ptr->pMessageIdName != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pMessageIdName))) : 0;
        struct_size += (struct_ptr->pMessage != NULL) ? ROUNDUP_TO_4(sizeof(char)*(1+strlen(struct_ptr->pMessage))) : 0;
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->queueLabelCount; i++) {
            struct_size += vk_size_vkdebugutilslabelext(&struct_ptr->pQueueLabels[i]);
        }
        for (i = 0; i < struct_ptr->cmdBufLabelCount; i++) {
            struct_size += vk_size_vkdebugutilslabelext(&struct_ptr->pCmdBufLabels[i]);
        }
        for (i = 0; i < struct_ptr->objectCount; i++) {
            struct_size += vk_size_vkdebugutilsobjectnameinfoext(&struct_ptr->pObjects[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkdebugutilsmessengercreateinfoext(const VkDebugUtilsMessengerCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDebugUtilsMessengerCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vksamplerreductionmodecreateinfoext(const VkSamplerReductionModeCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSamplerReductionModeCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesamplerfilterminmaxpropertiesext(const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vksamplelocationext(const VkSampleLocationEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSampleLocationEXT);
    }
    return struct_size;
}

size_t vk_size_vksamplelocationsinfoext(const VkSampleLocationsInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSampleLocationsInfoEXT);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->sampleLocationsCount; i++) {
            struct_size += vk_size_vksamplelocationext(&struct_ptr->pSampleLocations[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkattachmentsamplelocationsext(const VkAttachmentSampleLocationsEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkAttachmentSampleLocationsEXT);
    }
    return struct_size;
}

size_t vk_size_vksubpasssamplelocationsext(const VkSubpassSampleLocationsEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkSubpassSampleLocationsEXT);
    }
    return struct_size;
}

size_t vk_size_vkrenderpasssamplelocationsbegininfoext(const VkRenderPassSampleLocationsBeginInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkRenderPassSampleLocationsBeginInfoEXT);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->attachmentInitialSampleLocationsCount; i++) {
            struct_size += vk_size_vkattachmentsamplelocationsext(&struct_ptr->pAttachmentInitialSampleLocations[i]);
        }
        for (i = 0; i < struct_ptr->postSubpassSampleLocationsCount; i++) {
            struct_size += vk_size_vksubpasssamplelocationsext(&struct_ptr->pPostSubpassSampleLocations[i]);
        }
    }
    return struct_size;
}

size_t vk_size_vkpipelinesamplelocationsstatecreateinfoext(const VkPipelineSampleLocationsStateCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineSampleLocationsStateCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicesamplelocationspropertiesext(const VkPhysicalDeviceSampleLocationsPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkmultisamplepropertiesext(const VkMultisamplePropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMultisamplePropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceblendoperationadvancedfeaturesext(const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceblendoperationadvancedpropertiesext(const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkpipelinecolorblendadvancedstatecreateinfoext(const VkPipelineColorBlendAdvancedStateCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineColorBlendAdvancedStateCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkpipelinecoveragetocolorstatecreateinfonv(const VkPipelineCoverageToColorStateCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineCoverageToColorStateCreateInfoNV);
    }
    return struct_size;
}

size_t vk_size_vkpipelinecoveragemodulationstatecreateinfonv(const VkPipelineCoverageModulationStateCreateInfoNV* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineCoverageModulationStateCreateInfoNV);
        struct_size += (struct_ptr->coverageModulationTableCount ) * sizeof(float);
    }
    return struct_size;
}

size_t vk_size_vkvalidationcachecreateinfoext(const VkValidationCacheCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkValidationCacheCreateInfoEXT);
        struct_size += (struct_ptr->initialDataSize ) * sizeof(void*);
    }
    return struct_size;
}

size_t vk_size_vkshadermodulevalidationcachecreateinfoext(const VkShaderModuleValidationCacheCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkShaderModuleValidationCacheCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkdevicequeueglobalprioritycreateinfoext(const VkDeviceQueueGlobalPriorityCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkDeviceQueueGlobalPriorityCreateInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkimportmemoryhostpointerinfoext(const VkImportMemoryHostPointerInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkImportMemoryHostPointerInfoEXT);
    }
    return struct_size;
}

size_t vk_size_vkmemoryhostpointerpropertiesext(const VkMemoryHostPointerPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkMemoryHostPointerPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldeviceexternalmemoryhostpropertiesext(const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkphysicaldevicevertexattributedivisorpropertiesext(const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT);
    }
    return struct_size;
}

size_t vk_size_vkvertexinputbindingdivisordescriptionext(const VkVertexInputBindingDivisorDescriptionEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkVertexInputBindingDivisorDescriptionEXT);
    }
    return struct_size;
}

size_t vk_size_vkpipelinevertexinputdivisorstatecreateinfoext(const VkPipelineVertexInputDivisorStateCreateInfoEXT* struct_ptr) { 
    size_t struct_size = 0;
    if (struct_ptr) {
        struct_size = sizeof(VkPipelineVertexInputDivisorStateCreateInfoEXT);
        uint32_t i = 0;
        for (i = 0; i < struct_ptr->vertexBindingDivisorCount; i++) {
            struct_size += vk_size_vkvertexinputbindingdivisordescriptionext(&struct_ptr->pVertexBindingDivisors[i]);
        }
    }
    return struct_size;
}

size_t get_struct_chain_size(const void* struct_ptr) {
    // Use VkApplicationInfo as struct until actual type is resolved
    VkApplicationInfo* pNext = (VkApplicationInfo*)struct_ptr;
    size_t struct_size = 0;
    while (pNext) {
        switch (pNext->sType) {
            case VK_STRUCTURE_TYPE_APPLICATION_INFO: {
                struct_size += vk_size_vkapplicationinfo((VkApplicationInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: {
                struct_size += vk_size_vkinstancecreateinfo((VkInstanceCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: {
                struct_size += vk_size_vkdevicequeuecreateinfo((VkDeviceQueueCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: {
                struct_size += vk_size_vkdevicecreateinfo((VkDeviceCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SUBMIT_INFO: {
                struct_size += vk_size_vksubmitinfo((VkSubmitInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: {
                struct_size += vk_size_vkmemoryallocateinfo((VkMemoryAllocateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: {
                struct_size += vk_size_vkmappedmemoryrange((VkMappedMemoryRange*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: {
                struct_size += vk_size_vkbindsparseinfo((VkBindSparseInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: {
                struct_size += vk_size_vkfencecreateinfo((VkFenceCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: {
                struct_size += vk_size_vksemaphorecreateinfo((VkSemaphoreCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: {
                struct_size += vk_size_vkeventcreateinfo((VkEventCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: {
                struct_size += vk_size_vkquerypoolcreateinfo((VkQueryPoolCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: {
                struct_size += vk_size_vkbuffercreateinfo((VkBufferCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: {
                struct_size += vk_size_vkbufferviewcreateinfo((VkBufferViewCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: {
                struct_size += vk_size_vkimagecreateinfo((VkImageCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: {
                struct_size += vk_size_vkimageviewcreateinfo((VkImageViewCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: {
                struct_size += vk_size_vkshadermodulecreateinfo((VkShaderModuleCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinecachecreateinfo((VkPipelineCacheCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: {
                struct_size += vk_size_vkpipelineshaderstagecreateinfo((VkPipelineShaderStageCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinevertexinputstatecreateinfo((VkPipelineVertexInputStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelineinputassemblystatecreateinfo((VkPipelineInputAssemblyStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinetessellationstatecreateinfo((VkPipelineTessellationStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelineviewportstatecreateinfo((VkPipelineViewportStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinerasterizationstatecreateinfo((VkPipelineRasterizationStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinemultisamplestatecreateinfo((VkPipelineMultisampleStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinedepthstencilstatecreateinfo((VkPipelineDepthStencilStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinecolorblendstatecreateinfo((VkPipelineColorBlendStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinedynamicstatecreateinfo((VkPipelineDynamicStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: {
                struct_size += vk_size_vkgraphicspipelinecreateinfo((VkGraphicsPipelineCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: {
                struct_size += vk_size_vkcomputepipelinecreateinfo((VkComputePipelineCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
                struct_size += vk_size_vkpipelinelayoutcreateinfo((VkPipelineLayoutCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: {
                struct_size += vk_size_vksamplercreateinfo((VkSamplerCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: {
                struct_size += vk_size_vkdescriptorsetlayoutcreateinfo((VkDescriptorSetLayoutCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: {
                struct_size += vk_size_vkdescriptorpoolcreateinfo((VkDescriptorPoolCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: {
                struct_size += vk_size_vkdescriptorsetallocateinfo((VkDescriptorSetAllocateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: {
                struct_size += vk_size_vkwritedescriptorset((VkWriteDescriptorSet*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: {
                struct_size += vk_size_vkcopydescriptorset((VkCopyDescriptorSet*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: {
                struct_size += vk_size_vkframebuffercreateinfo((VkFramebufferCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: {
                struct_size += vk_size_vkrenderpasscreateinfo((VkRenderPassCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: {
                struct_size += vk_size_vkcommandpoolcreateinfo((VkCommandPoolCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: {
                struct_size += vk_size_vkcommandbufferallocateinfo((VkCommandBufferAllocateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: {
                struct_size += vk_size_vkcommandbufferinheritanceinfo((VkCommandBufferInheritanceInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: {
                struct_size += vk_size_vkcommandbufferbegininfo((VkCommandBufferBeginInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER: {
                struct_size += vk_size_vkmemorybarrier((VkMemoryBarrier*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: {
                struct_size += vk_size_vkbuffermemorybarrier((VkBufferMemoryBarrier*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: {
                struct_size += vk_size_vkimagememorybarrier((VkImageMemoryBarrier*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: {
                struct_size += vk_size_vkrenderpassbegininfo((VkRenderPassBeginInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: {
                struct_size += vk_size_vkphysicaldevicesubgroupproperties((VkPhysicalDeviceSubgroupProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO: {
                struct_size += vk_size_vkbindbuffermemoryinfo((VkBindBufferMemoryInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO: {
                struct_size += vk_size_vkbindimagememoryinfo((VkBindImageMemoryInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: {
                struct_size += vk_size_vkphysicaldevice16bitstoragefeatures((VkPhysicalDevice16BitStorageFeatures*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: {
                struct_size += vk_size_vkmemorydedicatedrequirements((VkMemoryDedicatedRequirements*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: {
                struct_size += vk_size_vkmemorydedicatedallocateinfo((VkMemoryDedicatedAllocateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: {
                struct_size += vk_size_vkmemoryallocateflagsinfo((VkMemoryAllocateFlagsInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {
                struct_size += vk_size_vkdevicegrouprenderpassbegininfo((VkDeviceGroupRenderPassBeginInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: {
                struct_size += vk_size_vkdevicegroupcommandbufferbegininfo((VkDeviceGroupCommandBufferBeginInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: {
                struct_size += vk_size_vkdevicegroupsubmitinfo((VkDeviceGroupSubmitInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: {
                struct_size += vk_size_vkdevicegroupbindsparseinfo((VkDeviceGroupBindSparseInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: {
                struct_size += vk_size_vkbindbuffermemorydevicegroupinfo((VkBindBufferMemoryDeviceGroupInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: {
                struct_size += vk_size_vkbindimagememorydevicegroupinfo((VkBindImageMemoryDeviceGroupInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES: {
                struct_size += vk_size_vkphysicaldevicegroupproperties((VkPhysicalDeviceGroupProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: {
                struct_size += vk_size_vkdevicegroupdevicecreateinfo((VkDeviceGroupDeviceCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2: {
                struct_size += vk_size_vkbuffermemoryrequirementsinfo2((VkBufferMemoryRequirementsInfo2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2: {
                struct_size += vk_size_vkimagememoryrequirementsinfo2((VkImageMemoryRequirementsInfo2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2: {
                struct_size += vk_size_vkimagesparsememoryrequirementsinfo2((VkImageSparseMemoryRequirementsInfo2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2: {
                struct_size += vk_size_vkmemoryrequirements2((VkMemoryRequirements2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2: {
                struct_size += vk_size_vksparseimagememoryrequirements2((VkSparseImageMemoryRequirements2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: {
                struct_size += vk_size_vkphysicaldevicefeatures2((VkPhysicalDeviceFeatures2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2: {
                struct_size += vk_size_vkphysicaldeviceproperties2((VkPhysicalDeviceProperties2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2: {
                struct_size += vk_size_vkformatproperties2((VkFormatProperties2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2: {
                struct_size += vk_size_vkimageformatproperties2((VkImageFormatProperties2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2: {
                struct_size += vk_size_vkphysicaldeviceimageformatinfo2((VkPhysicalDeviceImageFormatInfo2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2: {
                struct_size += vk_size_vkqueuefamilyproperties2((VkQueueFamilyProperties2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2: {
                struct_size += vk_size_vkphysicaldevicememoryproperties2((VkPhysicalDeviceMemoryProperties2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2: {
                struct_size += vk_size_vksparseimageformatproperties2((VkSparseImageFormatProperties2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2: {
                struct_size += vk_size_vkphysicaldevicesparseimageformatinfo2((VkPhysicalDeviceSparseImageFormatInfo2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: {
                struct_size += vk_size_vkphysicaldevicepointclippingproperties((VkPhysicalDevicePointClippingProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: {
                struct_size += vk_size_vkrenderpassinputattachmentaspectcreateinfo((VkRenderPassInputAttachmentAspectCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: {
                struct_size += vk_size_vkimageviewusagecreateinfo((VkImageViewUsageCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: {
                struct_size += vk_size_vkpipelinetessellationdomainoriginstatecreateinfo((VkPipelineTessellationDomainOriginStateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: {
                struct_size += vk_size_vkrenderpassmultiviewcreateinfo((VkRenderPassMultiviewCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: {
                struct_size += vk_size_vkphysicaldevicemultiviewfeatures((VkPhysicalDeviceMultiviewFeatures*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: {
                struct_size += vk_size_vkphysicaldevicemultiviewproperties((VkPhysicalDeviceMultiviewProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES: {
                struct_size += vk_size_vkphysicaldevicevariablepointerfeatures((VkPhysicalDeviceVariablePointerFeatures*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: {
                struct_size += vk_size_vkphysicaldeviceprotectedmemoryfeatures((VkPhysicalDeviceProtectedMemoryFeatures*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: {
                struct_size += vk_size_vkphysicaldeviceprotectedmemoryproperties((VkPhysicalDeviceProtectedMemoryProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2: {
                struct_size += vk_size_vkdevicequeueinfo2((VkDeviceQueueInfo2*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: {
                struct_size += vk_size_vkprotectedsubmitinfo((VkProtectedSubmitInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO: {
                struct_size += vk_size_vksamplerycbcrconversioncreateinfo((VkSamplerYcbcrConversionCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: {
                struct_size += vk_size_vksamplerycbcrconversioninfo((VkSamplerYcbcrConversionInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: {
                struct_size += vk_size_vkbindimageplanememoryinfo((VkBindImagePlaneMemoryInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: {
                struct_size += vk_size_vkimageplanememoryrequirementsinfo((VkImagePlaneMemoryRequirementsInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: {
                struct_size += vk_size_vkphysicaldevicesamplerycbcrconversionfeatures((VkPhysicalDeviceSamplerYcbcrConversionFeatures*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: {
                struct_size += vk_size_vksamplerycbcrconversionimageformatproperties((VkSamplerYcbcrConversionImageFormatProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO: {
                struct_size += vk_size_vkdescriptorupdatetemplatecreateinfo((VkDescriptorUpdateTemplateCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: {
                struct_size += vk_size_vkphysicaldeviceexternalimageformatinfo((VkPhysicalDeviceExternalImageFormatInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: {
                struct_size += vk_size_vkexternalimageformatproperties((VkExternalImageFormatProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO: {
                struct_size += vk_size_vkphysicaldeviceexternalbufferinfo((VkPhysicalDeviceExternalBufferInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES: {
                struct_size += vk_size_vkexternalbufferproperties((VkExternalBufferProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: {
                struct_size += vk_size_vkphysicaldeviceidproperties((VkPhysicalDeviceIDProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: {
                struct_size += vk_size_vkexternalmemoryimagecreateinfo((VkExternalMemoryImageCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: {
                struct_size += vk_size_vkexternalmemorybuffercreateinfo((VkExternalMemoryBufferCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: {
                struct_size += vk_size_vkexportmemoryallocateinfo((VkExportMemoryAllocateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO: {
                struct_size += vk_size_vkphysicaldeviceexternalfenceinfo((VkPhysicalDeviceExternalFenceInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES: {
                struct_size += vk_size_vkexternalfenceproperties((VkExternalFenceProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: {
                struct_size += vk_size_vkexportfencecreateinfo((VkExportFenceCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: {
                struct_size += vk_size_vkexportsemaphorecreateinfo((VkExportSemaphoreCreateInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO: {
                struct_size += vk_size_vkphysicaldeviceexternalsemaphoreinfo((VkPhysicalDeviceExternalSemaphoreInfo*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES: {
                struct_size += vk_size_vkexternalsemaphoreproperties((VkExternalSemaphoreProperties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: {
                struct_size += vk_size_vkphysicaldevicemaintenance3properties((VkPhysicalDeviceMaintenance3Properties*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT: {
                struct_size += vk_size_vkdescriptorsetlayoutsupport((VkDescriptorSetLayoutSupport*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES: {
                struct_size += vk_size_vkphysicaldeviceshaderdrawparameterfeatures((VkPhysicalDeviceShaderDrawParameterFeatures*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: {
                struct_size += vk_size_vkswapchaincreateinfokhr((VkSwapchainCreateInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: {
                struct_size += vk_size_vkpresentinfokhr((VkPresentInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: {
                struct_size += vk_size_vkimageswapchaincreateinfokhr((VkImageSwapchainCreateInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: {
                struct_size += vk_size_vkbindimagememoryswapchaininfokhr((VkBindImageMemorySwapchainInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: {
                struct_size += vk_size_vkacquirenextimageinfokhr((VkAcquireNextImageInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: {
                struct_size += vk_size_vkdevicegrouppresentcapabilitieskhr((VkDeviceGroupPresentCapabilitiesKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: {
                struct_size += vk_size_vkdevicegrouppresentinfokhr((VkDeviceGroupPresentInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: {
                struct_size += vk_size_vkdevicegroupswapchaincreateinfokhr((VkDeviceGroupSwapchainCreateInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkdisplaymodecreateinfokhr((VkDisplayModeCreateInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkdisplaysurfacecreateinfokhr((VkDisplaySurfaceCreateInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: {
                struct_size += vk_size_vkdisplaypresentinfokhr((VkDisplayPresentInfoKHR*)pNext);
                break;
            }
#ifdef VK_USE_PLATFORM_XLIB_KHR
            case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkxlibsurfacecreateinfokhr((VkXlibSurfaceCreateInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
            case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkxcbsurfacecreateinfokhr((VkXcbSurfaceCreateInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
            case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkwaylandsurfacecreateinfokhr((VkWaylandSurfaceCreateInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_MIR_KHR
            case VK_STRUCTURE_TYPE_MIR_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkmirsurfacecreateinfokhr((VkMirSurfaceCreateInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_MIR_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
            case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkandroidsurfacecreateinfokhr((VkAndroidSurfaceCreateInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR: {
                struct_size += vk_size_vkwin32surfacecreateinfokhr((VkWin32SurfaceCreateInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkimportmemorywin32handleinfokhr((VkImportMemoryWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkexportmemorywin32handleinfokhr((VkExportMemoryWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR: {
                struct_size += vk_size_vkmemorywin32handlepropertieskhr((VkMemoryWin32HandlePropertiesKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkmemorygetwin32handleinfokhr((VkMemoryGetWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: {
                struct_size += vk_size_vkimportmemoryfdinfokhr((VkImportMemoryFdInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR: {
                struct_size += vk_size_vkmemoryfdpropertieskhr((VkMemoryFdPropertiesKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR: {
                struct_size += vk_size_vkmemorygetfdinfokhr((VkMemoryGetFdInfoKHR*)pNext);
                break;
            }
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: {
                struct_size += vk_size_vkwin32keyedmutexacquirereleaseinfokhr((VkWin32KeyedMutexAcquireReleaseInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkimportsemaphorewin32handleinfokhr((VkImportSemaphoreWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkexportsemaphorewin32handleinfokhr((VkExportSemaphoreWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: {
                struct_size += vk_size_vkd3d12fencesubmitinfokhr((VkD3D12FenceSubmitInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vksemaphoregetwin32handleinfokhr((VkSemaphoreGetWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR: {
                struct_size += vk_size_vkimportsemaphorefdinfokhr((VkImportSemaphoreFdInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR: {
                struct_size += vk_size_vksemaphoregetfdinfokhr((VkSemaphoreGetFdInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR: {
                struct_size += vk_size_vkphysicaldevicepushdescriptorpropertieskhr((VkPhysicalDevicePushDescriptorPropertiesKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: {
                struct_size += vk_size_vkpresentregionskhr((VkPresentRegionsKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: {
                struct_size += vk_size_vksharedpresentsurfacecapabilitieskhr((VkSharedPresentSurfaceCapabilitiesKHR*)pNext);
                break;
            }
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkimportfencewin32handleinfokhr((VkImportFenceWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkexportfencewin32handleinfokhr((VkExportFenceWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR: {
                struct_size += vk_size_vkfencegetwin32handleinfokhr((VkFenceGetWin32HandleInfoKHR*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR: {
                struct_size += vk_size_vkimportfencefdinfokhr((VkImportFenceFdInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR: {
                struct_size += vk_size_vkfencegetfdinfokhr((VkFenceGetFdInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR: {
                struct_size += vk_size_vkphysicaldevicesurfaceinfo2khr((VkPhysicalDeviceSurfaceInfo2KHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR: {
                struct_size += vk_size_vksurfacecapabilities2khr((VkSurfaceCapabilities2KHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR: {
                struct_size += vk_size_vksurfaceformat2khr((VkSurfaceFormat2KHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR: {
                struct_size += vk_size_vkimageformatlistcreateinfokhr((VkImageFormatListCreateInfoKHR*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: {
                struct_size += vk_size_vkdebugreportcallbackcreateinfoext((VkDebugReportCallbackCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: {
                struct_size += vk_size_vkpipelinerasterizationstaterasterizationorderamd((VkPipelineRasterizationStateRasterizationOrderAMD*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT: {
                struct_size += vk_size_vkdebugmarkerobjectnameinfoext((VkDebugMarkerObjectNameInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT: {
                struct_size += vk_size_vkdebugmarkerobjecttaginfoext((VkDebugMarkerObjectTagInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT: {
                struct_size += vk_size_vkdebugmarkermarkerinfoext((VkDebugMarkerMarkerInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: {
                struct_size += vk_size_vkdedicatedallocationimagecreateinfonv((VkDedicatedAllocationImageCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: {
                struct_size += vk_size_vkdedicatedallocationbuffercreateinfonv((VkDedicatedAllocationBufferCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: {
                struct_size += vk_size_vkdedicatedallocationmemoryallocateinfonv((VkDedicatedAllocationMemoryAllocateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: {
                struct_size += vk_size_vktexturelodgatherformatpropertiesamd((VkTextureLODGatherFormatPropertiesAMD*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: {
                struct_size += vk_size_vkexternalmemoryimagecreateinfonv((VkExternalMemoryImageCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: {
                struct_size += vk_size_vkexportmemoryallocateinfonv((VkExportMemoryAllocateInfoNV*)pNext);
                break;
            }
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                struct_size += vk_size_vkimportmemorywin32handleinfonv((VkImportMemoryWin32HandleInfoNV*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                struct_size += vk_size_vkexportmemorywin32handleinfonv((VkExportMemoryWin32HandleInfoNV*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: {
                struct_size += vk_size_vkwin32keyedmutexacquirereleaseinfonv((VkWin32KeyedMutexAcquireReleaseInfoNV*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_WIN32_KHR
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: {
                struct_size += vk_size_vkvalidationflagsext((VkValidationFlagsEXT*)pNext);
                break;
            }
#ifdef VK_USE_PLATFORM_VI_NN
            case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN: {
                struct_size += vk_size_vkvisurfacecreateinfonn((VkViSurfaceCreateInfoNN*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_VI_NN
            case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX: {
                struct_size += vk_size_vkdevicegeneratedcommandsfeaturesnvx((VkDeviceGeneratedCommandsFeaturesNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX: {
                struct_size += vk_size_vkdevicegeneratedcommandslimitsnvx((VkDeviceGeneratedCommandsLimitsNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX: {
                struct_size += vk_size_vkindirectcommandslayoutcreateinfonvx((VkIndirectCommandsLayoutCreateInfoNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX: {
                struct_size += vk_size_vkcmdprocesscommandsinfonvx((VkCmdProcessCommandsInfoNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX: {
                struct_size += vk_size_vkcmdreservespaceforcommandsinfonvx((VkCmdReserveSpaceForCommandsInfoNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX: {
                struct_size += vk_size_vkobjecttablecreateinfonvx((VkObjectTableCreateInfoNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: {
                struct_size += vk_size_vkpipelineviewportwscalingstatecreateinfonv((VkPipelineViewportWScalingStateCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT: {
                struct_size += vk_size_vksurfacecapabilities2ext((VkSurfaceCapabilities2EXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT: {
                struct_size += vk_size_vkdisplaypowerinfoext((VkDisplayPowerInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT: {
                struct_size += vk_size_vkdeviceeventinfoext((VkDeviceEventInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT: {
                struct_size += vk_size_vkdisplayeventinfoext((VkDisplayEventInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: {
                struct_size += vk_size_vkswapchaincountercreateinfoext((VkSwapchainCounterCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: {
                struct_size += vk_size_vkpresenttimesinfogoogle((VkPresentTimesInfoGOOGLE*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: {
                struct_size += vk_size_vkphysicaldevicemultiviewperviewattributespropertiesnvx((VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: {
                struct_size += vk_size_vkpipelineviewportswizzlestatecreateinfonv((VkPipelineViewportSwizzleStateCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldevicediscardrectanglepropertiesext((VkPhysicalDeviceDiscardRectanglePropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkpipelinediscardrectanglestatecreateinfoext((VkPipelineDiscardRectangleStateCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldeviceconservativerasterizationpropertiesext((VkPhysicalDeviceConservativeRasterizationPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkpipelinerasterizationconservativestatecreateinfoext((VkPipelineRasterizationConservativeStateCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_HDR_METADATA_EXT: {
                struct_size += vk_size_vkhdrmetadataext((VkHdrMetadataEXT*)pNext);
                break;
            }
#ifdef VK_USE_PLATFORM_IOS_MVK
            case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK: {
                struct_size += vk_size_vkiossurfacecreateinfomvk((VkIOSSurfaceCreateInfoMVK*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
            case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK: {
                struct_size += vk_size_vkmacossurfacecreateinfomvk((VkMacOSSurfaceCreateInfoMVK*)pNext);
                break;
            }
#endif // VK_USE_PLATFORM_MACOS_MVK
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: {
                struct_size += vk_size_vkdebugutilsobjectnameinfoext((VkDebugUtilsObjectNameInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT: {
                struct_size += vk_size_vkdebugutilsobjecttaginfoext((VkDebugUtilsObjectTagInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT: {
                struct_size += vk_size_vkdebugutilslabelext((VkDebugUtilsLabelEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT: {
                struct_size += vk_size_vkdebugutilsmessengercallbackdataext((VkDebugUtilsMessengerCallbackDataEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: {
                struct_size += vk_size_vkdebugutilsmessengercreateinfoext((VkDebugUtilsMessengerCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT: {
                struct_size += vk_size_vksamplerreductionmodecreateinfoext((VkSamplerReductionModeCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldevicesamplerfilterminmaxpropertiesext((VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
                struct_size += vk_size_vksamplelocationsinfoext((VkSampleLocationsInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {
                struct_size += vk_size_vkrenderpasssamplelocationsbegininfoext((VkRenderPassSampleLocationsBeginInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkpipelinesamplelocationsstatecreateinfoext((VkPipelineSampleLocationsStateCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldevicesamplelocationspropertiesext((VkPhysicalDeviceSampleLocationsPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT: {
                struct_size += vk_size_vkmultisamplepropertiesext((VkMultisamplePropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: {
                struct_size += vk_size_vkphysicaldeviceblendoperationadvancedfeaturesext((VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldeviceblendoperationadvancedpropertiesext((VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkpipelinecolorblendadvancedstatecreateinfoext((VkPipelineColorBlendAdvancedStateCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: {
                struct_size += vk_size_vkpipelinecoveragetocolorstatecreateinfonv((VkPipelineCoverageToColorStateCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: {
                struct_size += vk_size_vkpipelinecoveragemodulationstatecreateinfonv((VkPipelineCoverageModulationStateCreateInfoNV*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkvalidationcachecreateinfoext((VkValidationCacheCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkshadermodulevalidationcachecreateinfoext((VkShaderModuleValidationCacheCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT: {
                struct_size += vk_size_vkdevicequeueglobalprioritycreateinfoext((VkDeviceQueueGlobalPriorityCreateInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: {
                struct_size += vk_size_vkimportmemoryhostpointerinfoext((VkImportMemoryHostPointerInfoEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT: {
                struct_size += vk_size_vkmemoryhostpointerpropertiesext((VkMemoryHostPointerPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldeviceexternalmemoryhostpropertiesext((VkPhysicalDeviceExternalMemoryHostPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: {
                struct_size += vk_size_vkphysicaldevicevertexattributedivisorpropertiesext((VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*)pNext);
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: {
                struct_size += vk_size_vkpipelinevertexinputdivisorstatecreateinfoext((VkPipelineVertexInputDivisorStateCreateInfoEXT*)pNext);
                break;
            }
            default:
                struct_size += 0;
                break;        }
        pNext = (VkApplicationInfo*)pNext->pNext;
    }
    return struct_size;
}

size_t get_struct_size(const void* struct_ptr) {
    switch (((VkApplicationInfo*)struct_ptr)->sType) {
    case VK_STRUCTURE_TYPE_APPLICATION_INFO: 
        return vk_size_vkapplicationinfo((VkApplicationInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: 
        return vk_size_vkinstancecreateinfo((VkInstanceCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: 
        return vk_size_vkdevicequeuecreateinfo((VkDeviceQueueCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: 
        return vk_size_vkdevicecreateinfo((VkDeviceCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_SUBMIT_INFO: 
        return vk_size_vksubmitinfo((VkSubmitInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: 
        return vk_size_vkmemoryallocateinfo((VkMemoryAllocateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: 
        return vk_size_vkmappedmemoryrange((VkMappedMemoryRange*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: 
        return vk_size_vkbindsparseinfo((VkBindSparseInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: 
        return vk_size_vkfencecreateinfo((VkFenceCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: 
        return vk_size_vksemaphorecreateinfo((VkSemaphoreCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: 
        return vk_size_vkeventcreateinfo((VkEventCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: 
        return vk_size_vkquerypoolcreateinfo((VkQueryPoolCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: 
        return vk_size_vkbuffercreateinfo((VkBufferCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: 
        return vk_size_vkbufferviewcreateinfo((VkBufferViewCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: 
        return vk_size_vkimagecreateinfo((VkImageCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: 
        return vk_size_vkimageviewcreateinfo((VkImageViewCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: 
        return vk_size_vkshadermodulecreateinfo((VkShaderModuleCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: 
        return vk_size_vkpipelinecachecreateinfo((VkPipelineCacheCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: 
        return vk_size_vkpipelineshaderstagecreateinfo((VkPipelineShaderStageCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: 
        return vk_size_vkpipelinevertexinputstatecreateinfo((VkPipelineVertexInputStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: 
        return vk_size_vkpipelineinputassemblystatecreateinfo((VkPipelineInputAssemblyStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: 
        return vk_size_vkpipelinetessellationstatecreateinfo((VkPipelineTessellationStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: 
        return vk_size_vkpipelineviewportstatecreateinfo((VkPipelineViewportStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: 
        return vk_size_vkpipelinerasterizationstatecreateinfo((VkPipelineRasterizationStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: 
        return vk_size_vkpipelinemultisamplestatecreateinfo((VkPipelineMultisampleStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: 
        return vk_size_vkpipelinedepthstencilstatecreateinfo((VkPipelineDepthStencilStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: 
        return vk_size_vkpipelinecolorblendstatecreateinfo((VkPipelineColorBlendStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: 
        return vk_size_vkpipelinedynamicstatecreateinfo((VkPipelineDynamicStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: 
        return vk_size_vkgraphicspipelinecreateinfo((VkGraphicsPipelineCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: 
        return vk_size_vkcomputepipelinecreateinfo((VkComputePipelineCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: 
        return vk_size_vkpipelinelayoutcreateinfo((VkPipelineLayoutCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: 
        return vk_size_vksamplercreateinfo((VkSamplerCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: 
        return vk_size_vkdescriptorsetlayoutcreateinfo((VkDescriptorSetLayoutCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: 
        return vk_size_vkdescriptorpoolcreateinfo((VkDescriptorPoolCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: 
        return vk_size_vkdescriptorsetallocateinfo((VkDescriptorSetAllocateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: 
        return vk_size_vkwritedescriptorset((VkWriteDescriptorSet*)struct_ptr);
    case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: 
        return vk_size_vkcopydescriptorset((VkCopyDescriptorSet*)struct_ptr);
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: 
        return vk_size_vkframebuffercreateinfo((VkFramebufferCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: 
        return vk_size_vkrenderpasscreateinfo((VkRenderPassCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: 
        return vk_size_vkcommandpoolcreateinfo((VkCommandPoolCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: 
        return vk_size_vkcommandbufferallocateinfo((VkCommandBufferAllocateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: 
        return vk_size_vkcommandbufferinheritanceinfo((VkCommandBufferInheritanceInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: 
        return vk_size_vkcommandbufferbegininfo((VkCommandBufferBeginInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER: 
        return vk_size_vkmemorybarrier((VkMemoryBarrier*)struct_ptr);
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: 
        return vk_size_vkbuffermemorybarrier((VkBufferMemoryBarrier*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: 
        return vk_size_vkimagememorybarrier((VkImageMemoryBarrier*)struct_ptr);
    case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: 
        return vk_size_vkrenderpassbegininfo((VkRenderPassBeginInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: 
        return vk_size_vkphysicaldevicesubgroupproperties((VkPhysicalDeviceSubgroupProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO: 
        return vk_size_vkbindbuffermemoryinfo((VkBindBufferMemoryInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO: 
        return vk_size_vkbindimagememoryinfo((VkBindImageMemoryInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: 
        return vk_size_vkphysicaldevice16bitstoragefeatures((VkPhysicalDevice16BitStorageFeatures*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: 
        return vk_size_vkmemorydedicatedrequirements((VkMemoryDedicatedRequirements*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: 
        return vk_size_vkmemorydedicatedallocateinfo((VkMemoryDedicatedAllocateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: 
        return vk_size_vkmemoryallocateflagsinfo((VkMemoryAllocateFlagsInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: 
        return vk_size_vkdevicegrouprenderpassbegininfo((VkDeviceGroupRenderPassBeginInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: 
        return vk_size_vkdevicegroupcommandbufferbegininfo((VkDeviceGroupCommandBufferBeginInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: 
        return vk_size_vkdevicegroupsubmitinfo((VkDeviceGroupSubmitInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: 
        return vk_size_vkdevicegroupbindsparseinfo((VkDeviceGroupBindSparseInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: 
        return vk_size_vkbindbuffermemorydevicegroupinfo((VkBindBufferMemoryDeviceGroupInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: 
        return vk_size_vkbindimagememorydevicegroupinfo((VkBindImageMemoryDeviceGroupInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES: 
        return vk_size_vkphysicaldevicegroupproperties((VkPhysicalDeviceGroupProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: 
        return vk_size_vkdevicegroupdevicecreateinfo((VkDeviceGroupDeviceCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2: 
        return vk_size_vkbuffermemoryrequirementsinfo2((VkBufferMemoryRequirementsInfo2*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2: 
        return vk_size_vkimagememoryrequirementsinfo2((VkImageMemoryRequirementsInfo2*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2: 
        return vk_size_vkimagesparsememoryrequirementsinfo2((VkImageSparseMemoryRequirementsInfo2*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2: 
        return vk_size_vkmemoryrequirements2((VkMemoryRequirements2*)struct_ptr);
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2: 
        return vk_size_vksparseimagememoryrequirements2((VkSparseImageMemoryRequirements2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: 
        return vk_size_vkphysicaldevicefeatures2((VkPhysicalDeviceFeatures2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2: 
        return vk_size_vkphysicaldeviceproperties2((VkPhysicalDeviceProperties2*)struct_ptr);
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2: 
        return vk_size_vkformatproperties2((VkFormatProperties2*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2: 
        return vk_size_vkimageformatproperties2((VkImageFormatProperties2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2: 
        return vk_size_vkphysicaldeviceimageformatinfo2((VkPhysicalDeviceImageFormatInfo2*)struct_ptr);
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2: 
        return vk_size_vkqueuefamilyproperties2((VkQueueFamilyProperties2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2: 
        return vk_size_vkphysicaldevicememoryproperties2((VkPhysicalDeviceMemoryProperties2*)struct_ptr);
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2: 
        return vk_size_vksparseimageformatproperties2((VkSparseImageFormatProperties2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2: 
        return vk_size_vkphysicaldevicesparseimageformatinfo2((VkPhysicalDeviceSparseImageFormatInfo2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: 
        return vk_size_vkphysicaldevicepointclippingproperties((VkPhysicalDevicePointClippingProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: 
        return vk_size_vkrenderpassinputattachmentaspectcreateinfo((VkRenderPassInputAttachmentAspectCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: 
        return vk_size_vkimageviewusagecreateinfo((VkImageViewUsageCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: 
        return vk_size_vkpipelinetessellationdomainoriginstatecreateinfo((VkPipelineTessellationDomainOriginStateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: 
        return vk_size_vkrenderpassmultiviewcreateinfo((VkRenderPassMultiviewCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: 
        return vk_size_vkphysicaldevicemultiviewfeatures((VkPhysicalDeviceMultiviewFeatures*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: 
        return vk_size_vkphysicaldevicemultiviewproperties((VkPhysicalDeviceMultiviewProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES: 
        return vk_size_vkphysicaldevicevariablepointerfeatures((VkPhysicalDeviceVariablePointerFeatures*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: 
        return vk_size_vkphysicaldeviceprotectedmemoryfeatures((VkPhysicalDeviceProtectedMemoryFeatures*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: 
        return vk_size_vkphysicaldeviceprotectedmemoryproperties((VkPhysicalDeviceProtectedMemoryProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2: 
        return vk_size_vkdevicequeueinfo2((VkDeviceQueueInfo2*)struct_ptr);
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: 
        return vk_size_vkprotectedsubmitinfo((VkProtectedSubmitInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO: 
        return vk_size_vksamplerycbcrconversioncreateinfo((VkSamplerYcbcrConversionCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: 
        return vk_size_vksamplerycbcrconversioninfo((VkSamplerYcbcrConversionInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: 
        return vk_size_vkbindimageplanememoryinfo((VkBindImagePlaneMemoryInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: 
        return vk_size_vkimageplanememoryrequirementsinfo((VkImagePlaneMemoryRequirementsInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: 
        return vk_size_vkphysicaldevicesamplerycbcrconversionfeatures((VkPhysicalDeviceSamplerYcbcrConversionFeatures*)struct_ptr);
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: 
        return vk_size_vksamplerycbcrconversionimageformatproperties((VkSamplerYcbcrConversionImageFormatProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO: 
        return vk_size_vkdescriptorupdatetemplatecreateinfo((VkDescriptorUpdateTemplateCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: 
        return vk_size_vkphysicaldeviceexternalimageformatinfo((VkPhysicalDeviceExternalImageFormatInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: 
        return vk_size_vkexternalimageformatproperties((VkExternalImageFormatProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO: 
        return vk_size_vkphysicaldeviceexternalbufferinfo((VkPhysicalDeviceExternalBufferInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES: 
        return vk_size_vkexternalbufferproperties((VkExternalBufferProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: 
        return vk_size_vkphysicaldeviceidproperties((VkPhysicalDeviceIDProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: 
        return vk_size_vkexternalmemoryimagecreateinfo((VkExternalMemoryImageCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: 
        return vk_size_vkexternalmemorybuffercreateinfo((VkExternalMemoryBufferCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: 
        return vk_size_vkexportmemoryallocateinfo((VkExportMemoryAllocateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO: 
        return vk_size_vkphysicaldeviceexternalfenceinfo((VkPhysicalDeviceExternalFenceInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES: 
        return vk_size_vkexternalfenceproperties((VkExternalFenceProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: 
        return vk_size_vkexportfencecreateinfo((VkExportFenceCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: 
        return vk_size_vkexportsemaphorecreateinfo((VkExportSemaphoreCreateInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO: 
        return vk_size_vkphysicaldeviceexternalsemaphoreinfo((VkPhysicalDeviceExternalSemaphoreInfo*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES: 
        return vk_size_vkexternalsemaphoreproperties((VkExternalSemaphoreProperties*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: 
        return vk_size_vkphysicaldevicemaintenance3properties((VkPhysicalDeviceMaintenance3Properties*)struct_ptr);
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT: 
        return vk_size_vkdescriptorsetlayoutsupport((VkDescriptorSetLayoutSupport*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES: 
        return vk_size_vkphysicaldeviceshaderdrawparameterfeatures((VkPhysicalDeviceShaderDrawParameterFeatures*)struct_ptr);
    case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: 
        return vk_size_vkswapchaincreateinfokhr((VkSwapchainCreateInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: 
        return vk_size_vkpresentinfokhr((VkPresentInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: 
        return vk_size_vkimageswapchaincreateinfokhr((VkImageSwapchainCreateInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: 
        return vk_size_vkbindimagememoryswapchaininfokhr((VkBindImageMemorySwapchainInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: 
        return vk_size_vkacquirenextimageinfokhr((VkAcquireNextImageInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: 
        return vk_size_vkdevicegrouppresentcapabilitieskhr((VkDeviceGroupPresentCapabilitiesKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: 
        return vk_size_vkdevicegrouppresentinfokhr((VkDeviceGroupPresentInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: 
        return vk_size_vkdevicegroupswapchaincreateinfokhr((VkDeviceGroupSwapchainCreateInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR: 
        return vk_size_vkdisplaymodecreateinfokhr((VkDisplayModeCreateInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkdisplaysurfacecreateinfokhr((VkDisplaySurfaceCreateInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: 
        return vk_size_vkdisplaypresentinfokhr((VkDisplayPresentInfoKHR*)struct_ptr);
#ifdef VK_USE_PLATFORM_XLIB_KHR
    case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkxlibsurfacecreateinfokhr((VkXlibSurfaceCreateInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkxcbsurfacecreateinfokhr((VkXcbSurfaceCreateInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkwaylandsurfacecreateinfokhr((VkWaylandSurfaceCreateInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_MIR_KHR
    case VK_STRUCTURE_TYPE_MIR_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkmirsurfacecreateinfokhr((VkMirSurfaceCreateInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_MIR_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkandroidsurfacecreateinfokhr((VkAndroidSurfaceCreateInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR: 
        return vk_size_vkwin32surfacecreateinfokhr((VkWin32SurfaceCreateInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkimportmemorywin32handleinfokhr((VkImportMemoryWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkexportmemorywin32handleinfokhr((VkExportMemoryWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR: 
        return vk_size_vkmemorywin32handlepropertieskhr((VkMemoryWin32HandlePropertiesKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkmemorygetwin32handleinfokhr((VkMemoryGetWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: 
        return vk_size_vkimportmemoryfdinfokhr((VkImportMemoryFdInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR: 
        return vk_size_vkmemoryfdpropertieskhr((VkMemoryFdPropertiesKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR: 
        return vk_size_vkmemorygetfdinfokhr((VkMemoryGetFdInfoKHR*)struct_ptr);
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: 
        return vk_size_vkwin32keyedmutexacquirereleaseinfokhr((VkWin32KeyedMutexAcquireReleaseInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkimportsemaphorewin32handleinfokhr((VkImportSemaphoreWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkexportsemaphorewin32handleinfokhr((VkExportSemaphoreWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: 
        return vk_size_vkd3d12fencesubmitinfokhr((VkD3D12FenceSubmitInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vksemaphoregetwin32handleinfokhr((VkSemaphoreGetWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR: 
        return vk_size_vkimportsemaphorefdinfokhr((VkImportSemaphoreFdInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR: 
        return vk_size_vksemaphoregetfdinfokhr((VkSemaphoreGetFdInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR: 
        return vk_size_vkphysicaldevicepushdescriptorpropertieskhr((VkPhysicalDevicePushDescriptorPropertiesKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: 
        return vk_size_vkpresentregionskhr((VkPresentRegionsKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: 
        return vk_size_vksharedpresentsurfacecapabilitieskhr((VkSharedPresentSurfaceCapabilitiesKHR*)struct_ptr);
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkimportfencewin32handleinfokhr((VkImportFenceWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkexportfencewin32handleinfokhr((VkExportFenceWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR: 
        return vk_size_vkfencegetwin32handleinfokhr((VkFenceGetWin32HandleInfoKHR*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR: 
        return vk_size_vkimportfencefdinfokhr((VkImportFenceFdInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR: 
        return vk_size_vkfencegetfdinfokhr((VkFenceGetFdInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR: 
        return vk_size_vkphysicaldevicesurfaceinfo2khr((VkPhysicalDeviceSurfaceInfo2KHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR: 
        return vk_size_vksurfacecapabilities2khr((VkSurfaceCapabilities2KHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR: 
        return vk_size_vksurfaceformat2khr((VkSurfaceFormat2KHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR: 
        return vk_size_vkimageformatlistcreateinfokhr((VkImageFormatListCreateInfoKHR*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: 
        return vk_size_vkdebugreportcallbackcreateinfoext((VkDebugReportCallbackCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: 
        return vk_size_vkpipelinerasterizationstaterasterizationorderamd((VkPipelineRasterizationStateRasterizationOrderAMD*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT: 
        return vk_size_vkdebugmarkerobjectnameinfoext((VkDebugMarkerObjectNameInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT: 
        return vk_size_vkdebugmarkerobjecttaginfoext((VkDebugMarkerObjectTagInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT: 
        return vk_size_vkdebugmarkermarkerinfoext((VkDebugMarkerMarkerInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: 
        return vk_size_vkdedicatedallocationimagecreateinfonv((VkDedicatedAllocationImageCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: 
        return vk_size_vkdedicatedallocationbuffercreateinfonv((VkDedicatedAllocationBufferCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: 
        return vk_size_vkdedicatedallocationmemoryallocateinfonv((VkDedicatedAllocationMemoryAllocateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: 
        return vk_size_vktexturelodgatherformatpropertiesamd((VkTextureLODGatherFormatPropertiesAMD*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: 
        return vk_size_vkexternalmemoryimagecreateinfonv((VkExternalMemoryImageCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: 
        return vk_size_vkexportmemoryallocateinfonv((VkExportMemoryAllocateInfoNV*)struct_ptr);
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: 
        return vk_size_vkimportmemorywin32handleinfonv((VkImportMemoryWin32HandleInfoNV*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: 
        return vk_size_vkexportmemorywin32handleinfonv((VkExportMemoryWin32HandleInfoNV*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: 
        return vk_size_vkwin32keyedmutexacquirereleaseinfonv((VkWin32KeyedMutexAcquireReleaseInfoNV*)struct_ptr);
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: 
        return vk_size_vkvalidationflagsext((VkValidationFlagsEXT*)struct_ptr);
#ifdef VK_USE_PLATFORM_VI_NN
    case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN: 
        return vk_size_vkvisurfacecreateinfonn((VkViSurfaceCreateInfoNN*)struct_ptr);
#endif // VK_USE_PLATFORM_VI_NN
    case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX: 
        return vk_size_vkdevicegeneratedcommandsfeaturesnvx((VkDeviceGeneratedCommandsFeaturesNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX: 
        return vk_size_vkdevicegeneratedcommandslimitsnvx((VkDeviceGeneratedCommandsLimitsNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX: 
        return vk_size_vkindirectcommandslayoutcreateinfonvx((VkIndirectCommandsLayoutCreateInfoNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX: 
        return vk_size_vkcmdprocesscommandsinfonvx((VkCmdProcessCommandsInfoNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX: 
        return vk_size_vkcmdreservespaceforcommandsinfonvx((VkCmdReserveSpaceForCommandsInfoNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX: 
        return vk_size_vkobjecttablecreateinfonvx((VkObjectTableCreateInfoNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: 
        return vk_size_vkpipelineviewportwscalingstatecreateinfonv((VkPipelineViewportWScalingStateCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT: 
        return vk_size_vksurfacecapabilities2ext((VkSurfaceCapabilities2EXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT: 
        return vk_size_vkdisplaypowerinfoext((VkDisplayPowerInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT: 
        return vk_size_vkdeviceeventinfoext((VkDeviceEventInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT: 
        return vk_size_vkdisplayeventinfoext((VkDisplayEventInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: 
        return vk_size_vkswapchaincountercreateinfoext((VkSwapchainCounterCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: 
        return vk_size_vkpresenttimesinfogoogle((VkPresentTimesInfoGOOGLE*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: 
        return vk_size_vkphysicaldevicemultiviewperviewattributespropertiesnvx((VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: 
        return vk_size_vkpipelineviewportswizzlestatecreateinfonv((VkPipelineViewportSwizzleStateCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: 
        return vk_size_vkphysicaldevicediscardrectanglepropertiesext((VkPhysicalDeviceDiscardRectanglePropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: 
        return vk_size_vkpipelinediscardrectanglestatecreateinfoext((VkPipelineDiscardRectangleStateCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: 
        return vk_size_vkphysicaldeviceconservativerasterizationpropertiesext((VkPhysicalDeviceConservativeRasterizationPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: 
        return vk_size_vkpipelinerasterizationconservativestatecreateinfoext((VkPipelineRasterizationConservativeStateCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_HDR_METADATA_EXT: 
        return vk_size_vkhdrmetadataext((VkHdrMetadataEXT*)struct_ptr);
#ifdef VK_USE_PLATFORM_IOS_MVK
    case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK: 
        return vk_size_vkiossurfacecreateinfomvk((VkIOSSurfaceCreateInfoMVK*)struct_ptr);
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
    case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK: 
        return vk_size_vkmacossurfacecreateinfomvk((VkMacOSSurfaceCreateInfoMVK*)struct_ptr);
#endif // VK_USE_PLATFORM_MACOS_MVK
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: 
        return vk_size_vkdebugutilsobjectnameinfoext((VkDebugUtilsObjectNameInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT: 
        return vk_size_vkdebugutilsobjecttaginfoext((VkDebugUtilsObjectTagInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT: 
        return vk_size_vkdebugutilslabelext((VkDebugUtilsLabelEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT: 
        return vk_size_vkdebugutilsmessengercallbackdataext((VkDebugUtilsMessengerCallbackDataEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: 
        return vk_size_vkdebugutilsmessengercreateinfoext((VkDebugUtilsMessengerCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT: 
        return vk_size_vksamplerreductionmodecreateinfoext((VkSamplerReductionModeCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT: 
        return vk_size_vkphysicaldevicesamplerfilterminmaxpropertiesext((VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: 
        return vk_size_vksamplelocationsinfoext((VkSampleLocationsInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: 
        return vk_size_vkrenderpasssamplelocationsbegininfoext((VkRenderPassSampleLocationsBeginInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: 
        return vk_size_vkpipelinesamplelocationsstatecreateinfoext((VkPipelineSampleLocationsStateCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: 
        return vk_size_vkphysicaldevicesamplelocationspropertiesext((VkPhysicalDeviceSampleLocationsPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT: 
        return vk_size_vkmultisamplepropertiesext((VkMultisamplePropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: 
        return vk_size_vkphysicaldeviceblendoperationadvancedfeaturesext((VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: 
        return vk_size_vkphysicaldeviceblendoperationadvancedpropertiesext((VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: 
        return vk_size_vkpipelinecolorblendadvancedstatecreateinfoext((VkPipelineColorBlendAdvancedStateCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: 
        return vk_size_vkpipelinecoveragetocolorstatecreateinfonv((VkPipelineCoverageToColorStateCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: 
        return vk_size_vkpipelinecoveragemodulationstatecreateinfonv((VkPipelineCoverageModulationStateCreateInfoNV*)struct_ptr);
    case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT: 
        return vk_size_vkvalidationcachecreateinfoext((VkValidationCacheCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: 
        return vk_size_vkshadermodulevalidationcachecreateinfoext((VkShaderModuleValidationCacheCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT: 
        return vk_size_vkdevicequeueglobalprioritycreateinfoext((VkDeviceQueueGlobalPriorityCreateInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: 
        return vk_size_vkimportmemoryhostpointerinfoext((VkImportMemoryHostPointerInfoEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT: 
        return vk_size_vkmemoryhostpointerpropertiesext((VkMemoryHostPointerPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: 
        return vk_size_vkphysicaldeviceexternalmemoryhostpropertiesext((VkPhysicalDeviceExternalMemoryHostPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: 
        return vk_size_vkphysicaldevicevertexattributedivisorpropertiesext((VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*)struct_ptr);
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: 
        return vk_size_vkpipelinevertexinputdivisorstatecreateinfoext((VkPipelineVertexInputDivisorStateCreateInfoEXT*)struct_ptr);
    default:
        return(0);
    }
}
