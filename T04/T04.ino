// Задание 4. Blink с ускорением

#define PIN_LED 2

// Коэф. угасания времени периода. (Уменьшение на 20% - это умножение на 0.8)
#define PERIOD_K (1.0 - 0.2)

// Изначальный период - 1000 мс, значит полупериод - половина
int current_half_period = 1000 / 2;


void setup() {
	pinMode(PIN_LED, OUTPUT);
	
	/*
	Объект последовательного порта Serial.
	Позволяет осуществлять двухстронную связь между платой Arduino и Компьютером по USB
	
	Основные методы Serial	
		- begin(int baudrate) - Инициализировать порт со скоростью 9600 бод (стандартная)
		- print(int num, int base=10) - вывод числа (система счисления (base) по умолчанию 10)
		- print(String &str) - вывод строки
		- println() - как print, только ещё и переносит строку.
		- end() - Закрыть порт.
	*/
	Serial.begin(9600);
}


void loop() {
	// Мигаем светодиодом с текущей длительностью периода
	digitalWrite(PIN_LED, HIGH);
	delay(current_half_period);
	digitalWrite(PIN_LED, LOW);
	delay(current_half_period);
	
	// Уменьшаем длительность периода на 20%
	current_half_period *= PERIOD_K;
}
