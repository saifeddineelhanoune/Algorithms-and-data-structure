#include <unistd.h>

int	is_prime(int nb)
{
	int i = 3;

	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 && nb > 2)
		return 0;
	while ((i += 2) < (nb / 2))
		if(nb % i == 0)
			return 0;
	return 1;
}