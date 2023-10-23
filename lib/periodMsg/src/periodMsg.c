#include "periodMsg.h"

void periodic_message(const struct device *dev){
    struct k_timer t;
    k_timer_init(&t, NULL, NULL);
    while(1){
        can_send(dev, msg, K_MSEC(100), NULL, NULL);
        k_timer_start(&t, K_MSEC(1000), K_NO_WAIT);
        k_timer_status_sync(&t);
    }

}