# Alex and Henry Lab 7

## Activity 0

We added a setup for LED0 to change state when the callback is called.

We also added a method within a thread to send a message

## Activity 1

We added a new send_message call that takes an ID and sends using that id and the callback takes a mask to prevent any id except the correct one from having a good callback.

## Activity 2

After connecting boards together, we observed how communication occurred between board and transceiver and the communication on the actual bus line. Communication was very quick across the lines with some weird voltage fluctuations when a line was high.

## Activity 3

Henry set his board to send messages constantly without waiting for responses and Alex set his board to send a lower priority message every so often. We observed that the lower priority sender would interrupt sending when a message was known on the receiving line. It prevented even one message from getting through.
