// Задание 6. Циклический Blink с ускорением

#define PIN_LED 2

// Изначальный период
#define INIT_HALF_PERIOD (1000 / 2)

// Шаг изменения длительности периода 20% / 2
#define HALF_PERIOD_STEP (1000 * 0.2 / 2)

int current_half_period = INIT_HALF_PERIOD;


void setup() {
	pinMode(PIN_LED, OUTPUT);
}


void loop() {
	// Мигаем светодиодом
	digitalWrite(PIN_LED, HIGH);
	delay(current_half_period);
	digitalWrite(PIN_LED, LOW);
	delay(current_half_period);
	
	// Уменьшаем длительность полупериода на шаг
	current_half_period -= HALF_PERIOD_STEP;
	
	/*
		Условный оператор if

		Синтаксис 
		` if ( expression ) { statements } `, где
		* expression - выражение, результатом которого будет логический тип (bool), 
			или тип, имеющий возможность приведения к логическому типу
		
		* statements - код, который будет выполнен, если значение expression true
	*/
	
	// Если текущая длительность полупериода меньше или равна 0,
	if (current_half_period <= 0) {
		// то выполнить этот блок кода.
		
		current_half_period = INIT_HALF_PERIOD;
	}
}
