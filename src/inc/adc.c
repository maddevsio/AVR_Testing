#include "adc.h"
#include <avr/io.h>
void adcInit(){
    ADMUX = (1<<REFS0); //Ион АЦП=питание
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1); // Включаем АЦП и устанавлием делитель на 64 (125000 сэмплов/с.)
}

uint16_t adcRead(uint8_t ch)
{
  ch &= 0b00000111;  // Маска для регистра ADMUX чтобы выбрать вход мультиплексора
  ADMUX = (ADMUX & 0xF8)|ch; 
  ADCSRA |= (1<<ADSC);// Начинаем преобразование
  while(ADCSRA & (1<<ADSC));// Ждем завершения преобразования
  return (ADC);
}
