#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <can/can_loopback.h>

void main(void)
{
    const struct device *can_dev;
    // Set CAN mode
    can_set_mode(can_dev,CAN_LOOPBACK_MODE );


}

