#include "priority_msg.h"


void send_hiprio_message_cont(const struct device *dev){

    struct zcan_frame msg = {
        .id_type = CAN_STANDARD_IDENTIFIER,
        .rtr = CAN_DATAFRAME,
        .id = 0x121,
        .dlc = 8,
        .data = {1,2,3,4,5,6,7,8}
    };

    
    while(1){
        can_send(dev, &msg, K_MSEC(100), NULL, NULL);
    }
}

void send_loprio_message_periodic(const struct device *dev){

    struct zcan_frame msg = {
        .id_type = CAN_STANDARD_IDENTIFIER,
        .rtr = CAN_DATAFRAME,
        .id = 0x129,
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

