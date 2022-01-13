#include "compute.h"
#include "instance.h"
#include "device.h"

int main(int ac, char **av) {

    CreateInstance();
    GetPhysicalDevice();                    // enumerate garphic cards
    CreateDeviceAndComputeQueue();          // open device
    CreateCommandPool();                    // allocate queue
    PrepareCommandBuffer();                 // 
    Compute();                              // execute it
    DestroyCommandPoolAndLogicalDevice();
    

    return 0;
}