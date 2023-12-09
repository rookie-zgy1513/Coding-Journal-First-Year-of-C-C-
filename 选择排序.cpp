void Swap(int *a,int *b) //交换两个数
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectSort(int*a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int min_i = left, max_i = right;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[min_i])
				min_i = i;
			if (a[i] > a[max_i])
				max_i = i;
		}
		if(min_i!=left)
			Swap(&a[left], &a[min_i]);
		if (max_i != right)
		{
			if (left == max_i)
				max_i = min_i;
			Swap(&a[right], &a[max_i]);
		}
		left++;
		right--;
	}
}