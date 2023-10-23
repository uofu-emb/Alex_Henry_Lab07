#include <zephyr.h>
#include <device.h>
#include <devicetree.h>

void main(void)
{
    const struct device *can_dev;
    // Set CAN mode
    can_set_mode(can_dev,can_mode.CAN_LOOPBACK_MODE )
}
