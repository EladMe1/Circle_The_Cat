#include "Controller.h"


int main()
{
	
	int level = 1;
	bool back;
	while (true)
	{
		while (level >=1 && level <=3)
		{
			Controller game;
			game.run(back);
			if (back)
				break;
		 level++;
		}
		if (back)
			break;
	}
}
