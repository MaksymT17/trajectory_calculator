#include "myMathDll.h"
#include <iostream>

int main(){
	std::cout << "started\n";
	CmyMathDll builder(true);
	builder.setObject(1, 1, 1);
	builder.setTarget(45, 11);
	builder.initialize();
	for (float i = 0; i < 15; ++i) {
		float x, y;
		builder.getPositionByTime(i, x, y);
		std::cout << "second:" << i << "x:" << x << "y:" << y << "\n";
	}
	return 0;
}