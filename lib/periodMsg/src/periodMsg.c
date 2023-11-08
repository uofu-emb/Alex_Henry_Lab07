#include <zephyr.h>
#include <device.h>
#include <can/can_loopback.h>
#include "periodMsg.h"

void periodic_message(const struct device *dev){
    struct zcan_frame msg = {
        .id_type = CAN_STANDARD_IDENTIFIER,
        .rtr = CAN_DATAFRAME,
        .id = 0x123,
        .dlc = 8,
        .data = {1,2,3,4,5,6,7,8}
    };

    struct k_timer t;
    k_timer_init(&t, NULL, NULL);
    
    while(1){
        
        can_send(dev, &msg, K_MSEC(100), NULL, NULL);
        k_timer_start(&t, K_MSEC(1000), K_NO_WAIT);
        k_timer_status_sync(&t);
    }

}

void send_message(const struct device *dev, uint32_t id)
{
    struct zcan_frame msg = {
        .id_type = CAN_STANDARD_IDENTIFIER,
        .rtr = CAN_DATAFRAME,
        .id = id,
        .dlc = 8,
        .data = {1,2,3,4,5,6,7,8}
    };

    can_send(dev, &msg, K_MSEC(100), NULL, NULL);
}