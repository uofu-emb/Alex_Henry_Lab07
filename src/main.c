#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <can/can_loopback.h>
#include "periodMsg.h"
#include "receive_callback.h"

void main(void)
{
    const struct device *can_dev;
    can_dev = device_get_binding("CAN_1");

    if (!device_is_ready(can_dev))
        {
            printk("Device %s is not ready\n", can_dev->name);
            return;
        }
    
    // Set CAN mode
    can_set_mode(can_dev,CAN_LOOPBACK_MODE );

    struct zcan_filter filter = {
        .id_type = CAN_STANDARD_IDENTIFIER,
        .rtr = CAN_DATAFRAME,
        .id = 0x123,
        .rtr_mask = 1,
        .id_mask = CAN_STD_ID_MASK
    };

    can_attach_isr(can_dev, (can_rx_callback_t) rx_callback, NULL, &filter);

    periodic_message(can_dev);
}

