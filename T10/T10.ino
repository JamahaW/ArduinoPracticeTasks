// Задание 10*. Мигание тремя светодиодами без delay()

#define PIN_LED_A 2
#define PIN_LED_B 3
#define PIN_LED_C 4

#define LED_A_HALF_PERIOD (1000 / 2)
#define LED_B_HALF_PERIOD (1000 / 3 / 2)
#define LED_C_HALF_PERIOD (1000 / 5 / 2)

bool led_a_state, led_b_state, led_c_state;

/*
	Библиотека Arduino.h автоматически подключает и библиотеку cstdint.
	Значит есть возможность использовать типы фиксированной длины.
*/

// uint32_t - синоним unsigned long, просто запись короче.
uint32_t next_led_a_change = millis();
uint32_t next_led_b_change = millis();
uint32_t next_led_c_change = millis();


void setup() {
	pinMode(PIN_LED_A, OUTPUT);
	pinMode(PIN_LED_B, OUTPUT);
	pinMode(PIN_LED_C, OUTPUT);
}

void loop() {
	
	// Аналогично заданию 9.
	if (millis() >= next_led_a_change) {
		next_led_a_change += LED_A_HALF_PERIOD;
		digitalWrite(PIN_LED_A, led_a_state);
		
		/*
			Оператор ^ - побитовое исключающее или (xor)
			
			Можно использовать для лаконичной записи переключения bool переменной в противоположное значение.
			
			Таблица истинности xor
			A	B	(A^B)
			1	1	0
			0	1	1
			1	0	1
			0	0	0
		*/
		led_a_state ^= 1;
	}
	
	// аналогичный код для двух остальных светодиодов
	
	if (millis() >= next_led_b_change) {
		next_led_b_change += LED_B_HALF_PERIOD;
		digitalWrite(PIN_LED_B, led_b_state);
		led_b_state ^= 1;
	}
	
	if (millis() >= next_led_c_change) {
		next_led_c_change += LED_C_HALF_PERIOD;
		digitalWrite(PIN_LED_C, led_c_state);
		led_c_state ^= 1;
	}
}
