#include "receive_callback.h"

void rx_callback(struct zcan_frame *frame, void *arg)
{
    printk("Data value 1 = %d", frame->data[0]);
}