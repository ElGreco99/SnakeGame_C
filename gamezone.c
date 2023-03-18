#include <unistd.h>


void displaying_gamezone(int width, int height)
{
	int i;
	int j;

	for (i = 0; i <= height; ++i)
	{
		for (j = 0; j <= width; ++j)
		{
			if (i == 0 || i == height)
			{
				write(1,"_",1);
			} else {
				if (j == 0 || j == width) 
					{
						write(1,"|",1);
					} else {
						write(1," ",1);
					}
			}
		}
	write(1,"\n",1);
	}
}


int main(void)
{
	displaying_gamezone(40,20);
	return 0;
}
