#include "compute.h"
#include "instance.h"
#include "device.h"
#include "pipeline.h"

int main(int ac, char **av) {

    CreateInstance();
    GetPhysicalDevice();                    // enumerate garphic cards
    CreateDeviceAndComputeQueue();          // open device
    CreatePipeline();
    CreateCommandPool();                    // allocate queue
    PrepareCommandBuffer();                 // 
    Compute();                              // execute it
    DestroyPipeline();
    DestroyCommandPoolAndLogicalDevice();
    

    return 0;
}