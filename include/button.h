#include "freertos/queue.h"
#include "driver/gpio.h"

#define PIN_BIT(x) (1ULL<<x)

#define BUTTON_DOWN (1)
#define BUTTON_UP (2)
#define BUTTON_HELD (3)

typedef struct {
  uint8_t pin;
    uint8_t event;
} button_event_t;

typedef struct {
    uint64_t pin_select;
    uint8_t pull_mode;
    uint8_t long_down_enabled;
} button_config_t;

QueueHandle_t button_init(button_config_t config);
