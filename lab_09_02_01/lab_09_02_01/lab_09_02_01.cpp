#include "macros.h"

#define DEBUG_MODE

int main()
{
	int x, y, z, w;

	ENTER_VARIABLE("x", x);
	ENTER_VARIABLE("y", y);
	ENTER_VARIABLE("z", z);

	int xy = x * y;
	int yz = y * z;	
	int zx = z * x;
	
	if (IS_GREATER(z, 3))

	{
		w = MAX(POW((x - z), 2), x - y);
#ifdef DEBUG_MODE
		std::cout << "[DEBUG] z > 3 branch taken." << std::endl;
#endif
	}
	else
	{
		w = MAX(xy, yz) + MAX(zx, yz);
#ifdef DEBUG_MODE
		std::cout << "[DEBUG] z <= 3 branch taken." << std::endl;
#endif
	}

	PRINT_RESULT(w);
	return 0;
}