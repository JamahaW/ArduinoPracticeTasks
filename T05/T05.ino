// Задание 5. Blink с ускорением и вывод периода в порт

#define PIN_LED 2
#define PERIOD_K (1.0 - 0.2)

int current_half_period = 1000 / 2;


void setup() {
	pinMode(PIN_LED, OUTPUT);
	Serial.begin(9600);
}


void loop() {
	// Основной цикл как в задании 4.
	digitalWrite(PIN_LED, HIGH);
	delay(current_half_period);
	digitalWrite(PIN_LED, LOW);
	delay(current_half_period);
	current_half_period *= PERIOD_K;
	
	/*
		В стандартной библиотеке Arduino
		Интерфейс, который использует Serial (Stream) не имеет метода printf, потому форматированный вывод нужно реализовывать вручную
	*/
	
	// выводом `d = `
	Serial.print("d = ");
	
	// Дописываем значение периода и переносим строку
	Serial.println(2 * current_half_period);
}
