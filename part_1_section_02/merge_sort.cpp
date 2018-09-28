#include <iostream>

void merge_sort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);
int main(int argc, char const *argv[])
{
	int A[6] = {1,3,5,2,4,6};
	merge_sort(A, 0, 5);
	for (int i = 0; i < 6; ++i)
	{
		std::cout<<A[i];
	}
	return 0;
}
void merge_sort(int A[], int p, int r){
	if (p < r)
	{
		int q = (p + r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}
void merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int * L = new int(n1 + 1);
	int * R = new int(n2 + 1);
	int i, j;
	for (i = 0; i < n1; ++i)
	{
		L[i] = A[p + i];
	}
	L[n1] = 1000;
	for (j = 0; j < n2; ++j)
	{
		R[j] = A[q + j + 1];
	}
	R[n2] = 1000;
	i = 0;
	j = 0;
	for (int k = p; k < r; ++k)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			++i;
		}else{
			A[k] = R[j];
			++j;
		}
	}
}