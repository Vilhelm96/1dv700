#ifndef ROULETTEWHEEL_H
#define ROULETTEWHEEL_H
#include <cstdlib>

class RouletteWheel
{
public:
	RouletteWheel();
	~RouletteWheel();
	int spin();

private:
	int _number;
};

#endif 