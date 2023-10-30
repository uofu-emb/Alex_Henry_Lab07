#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <can/can_loopback.h>
#include "periodMsg.h"
#include "receive_callback.h"
#include "priority_msg.h"

typedef struct k_thread k_thread_t;

#define STACKSIZE 2000

K_THREAD_STACK_DEFINE(transmit_stack, STACKSIZE);

void main(void)
{
    const struct device *can_dev;
    can_dev = device_get_binding("CAN_1");
    led_setup();

    if (!device_is_ready(can_dev))
        {
            printk("Device %s is not ready\n", can_dev->name);
            return;
        }
    
    // Set CAN mode
    #if defined (ACTIVITY0 ) || defined(ACTIVITY1)
    can_set_mode(can_dev, CAN_LOOPBACK_MODE);
    #endif
    
    #if defined (ACTIVITY2) || defined (ACTIVITY3)
    can_set_mode(can_dev, CAN_NORMAL_MODE);
    #endif
    
    struct zcan_filter filter = {
        .id_type = CAN_STANDARD_IDENTIFIER,
        .rtr = CAN_DATAFRAME,
        .id = 0x123,
        .rtr_mask = 1, 
        .id_mask = CAN_STD_ID_MASK
    };

    can_attach_isr(can_dev, (can_rx_callback_t) rx_callback, NULL, &filter);
    #ifdef ACTIVITY0
    k_thread_t transmit_thread;
    k_thread_create(&transmit_thread,
                    transmit_stack,
                    STACKSIZE,
                    (k_thread_entry_t) periodic_message,
                    (void *) can_dev,
                    NULL,
                    NULL,
                    K_PRIO_PREEMPT(7),
                    0,
                    K_NO_WAIT);
    // periodic_message(can_dev);
    k_sleep(K_FOREVER);

    #endif
    #ifdef ACTIVITY1

    while (1)
    {
        send_message(can_dev, 0x123);

        k_sleep(K_MSEC(250));

        send_message(can_dev, 0x170);

        k_sleep(K_MSEC(250));
    }
    #endif

    #ifdef ACTIVITY3
    while(1){
        // send_hiprio_message_cont(can_dev);
        send_loprio_message_periodic(can_dev, 1000);
    }

    #endif 
}

