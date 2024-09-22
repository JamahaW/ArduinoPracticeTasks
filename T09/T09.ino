#define PIN_LED 2

// Период изменения состояния светодиода
#define BLINK_HALF_PERIOD (1000 / 2)

// состояние светодиода, которое будем менять и выводить на пин.
bool led_state = LOW;

// время изменения состояния светодиода
unsigned long next_state_change = millis() + BLINK_HALF_PERIOD;

void setup() {
	pinMode(PIN_LED, OUTPUT);
}

void loop() {
	if (millis() >= next_state_change) {
		next_state_change += BLINK_HALF_PERIOD;
		
		digitalWrite(PIN_LED, led_state);
		
		// меняем состояние светодиода на противоположное
		led_state = !led_state;
	}
}