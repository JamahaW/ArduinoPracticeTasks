// Задание 3. Светофор

// Псевдонимы для пинов светофора
#define PIN_LED_GREEN 2
#define PIN_LED_YELLOW 3
#define PIN_LED_RED 4


// Настройка пинов как выход
void setup() {
	pinMode(PIN_LED_GREEN, OUTPUT);
	pinMode(PIN_LED_YELLOW, OUTPUT);
	pinMode(PIN_LED_RED, OUTPUT);
}


// Поочередно мигаем светодиодами светофора
void loop() {
	
	// Мигаем зеленым на 1 секунду
	digitalWrite(PIN_LED_GREEN, HIGH);
	delay(1000);
	digitalWrite(PIN_LED_GREEN, LOW);
	
	// Аналогично, желтым
	digitalWrite(PIN_LED_YELLOW, HIGH);
	delay(1000);
	digitalWrite(PIN_LED_YELLOW, LOW);
	
	// .. И красным.
	digitalWrite(PIN_LED_RED, HIGH);
	delay(1000);
	digitalWrite(PIN_LED_RED, LOW);
}