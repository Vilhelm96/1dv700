#include "RouletteWheel.h"

RouletteWheel::RouletteWheel()
{
	_number = 0;	//Initialize  first wheel value.
}

RouletteWheel::~RouletteWheel() = default;

int RouletteWheel::spin()
{
	return rand() % 36 + 1;
}