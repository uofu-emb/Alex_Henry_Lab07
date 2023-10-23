#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <can/can_loopback.h>
#include "periodMsg.h"

void main(void)
{
    const struct device *can_dev;
    can_dev = device_get_binding("CAN_0");
    
    // Set CAN mode
    can_set_mode(can_dev,CAN_LOOPBACK_MODE );

    periodic_message(can_dev);
}

