#define PIN_LED 2

// Объявление граничных значений полупериодов
#define MAX_HALF_PERIOD (1000 / 2)
#define MIN_HALF_PERIOD (10 / 2)

// Абсолютное значение шага изменения полупериода
#define HALF_PERIOD_STEP (1000 * 0.2 / 2)

int current_half_period = MAX_HALF_PERIOD;

// Переменная шага периода, изначально период будет сокращаться
int half_period_step = -HALF_PERIOD_STEP;

void setup() {
	pinMode(PIN_LED, OUTPUT);
}

void loop() {
	digitalWrite(PIN_LED, HIGH);
	delay(current_half_period);
	digitalWrite(PIN_LED, LOW);
	delay(current_half_period);
	
	// Уменьшаем длительность полупериода на шаг
	current_half_period += half_period_step;
	
	// Если текущая длительность полупериода <= минимальной длительности,
	if (current_half_period <= MIN_HALF_PERIOD) {
		// то текущую длительность полупериода устанавливаем в минимальное значениe
		current_half_period = MIN_HALF_PERIOD;
		
		// шаг периода меняем на положительный, таким образом длительность периода будет возрастать.
		half_period_step = HALF_PERIOD_STEP;
	}
	
	// Если текущая длительность полупериода >= максимальной длительности,
	if (current_half_period >= MAX_HALF_PERIOD) {
		// то текущую длительность устанавливаем в максимальное значениe
		current_half_period = MAX_HALF_PERIOD;
		
		// шаг полупериода устанавливаем отрицательный, таким образом длительность периода будет сокращаться
		half_period_step = -HALF_PERIOD_STEP;
	}
}
