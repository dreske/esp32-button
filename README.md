# Button press detector

This implements a version of [THE ULTIMATE DEBOUNCER(TM) from hackaday](https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/
).

It can monitor multiple pins, and sends button events over a queue for your application to process.

## Available input GPIO pins

Only the following pins can be used as inputs on the ESP32:

0-19, 21-23, 25-27, 32-39


## Example Usage

```c
button_config_t button_config = 
{
    .pull_mode = GPIO_PULLUP_ONLY,
    .pin_select = PIN_BIT(BUTTON_1_PIN) | PIN_BIT(BUTTON_2_PIN) | PIN_BIT(BUTTON_3_PIN) | PIN_BIT(BUTTON_4_PIN),
    .long_down_enabled = 0
};
QueueHandle_t button_events = button_init(button_config);
while (true) {
    if (xQueueReceive(button_events, &ev, 1000/portTICK_PERIOD_MS)) {
        if ((ev.pin == BUTTON_1) && (ev.event == BUTTON_DOWN)) {
            // ...
        }
        if ((ev.pin == BUTTON_2) && (ev.event == BUTTON_DOWN)) {
            // ...
        }
    }
}
```

## Event Types

### BUTTON_DOWN

Triggered when the button is first considered pressed.

### BUTTON_UP

Triggered when the button is considered released. In most cases you can use either the UP or DOWN event for your application, and ignore the other.

### BUTTON_HELD

Triggered starting after 2 seconds of long holding a button and then every 50ms thereafter.
