#include <stdio.h>

void ft_foreach(int *tab, int length, void (*f)(int));

void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

int main(void)
{
	int arr[] = {1, 2, 3, 8, 9};
	ft_foreach(arr, 5, ft_putnbr);
}
