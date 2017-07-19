#pragma once

#include <stdlib.h>

using namespace std;

/*
	��������
*/
void quickSort(int *a, int low, int high)
{
	if (low >= high) {
		return;
	}

	int left = low;
	int right = high;
	int key = a[left];

	while (left < right) {
		while (left < right && a[right] >= key)
			right--;
		a[left] = a[right];
		while (left < right && a[left] <= key)
			left++;
		a[right] = a[left];
	}

	a[left] = key;

	quickSort(a, low, left - 1);
	quickSort(a, left + 1, high);
}

/*
	�뾶Ϊn��������ֵ�˲�
*/
void medianFilter(int *a, int size, int n)
{
	int k = n / 2;
	int *tmp = (int*)malloc(sizeof(int) * n);

	// �ϱ�Ե����
	for (int i = 0; i < k; i++) {
		int t = 0;
		for (int j = 0; j < i + k; j++) {
			tmp[t++] = a[j];
		}
		for (int j = i + k; j < n; j++) {
			tmp[t++] = a[i];
		}
		quickSort(tmp, 0, n);
		a[i] = tmp[i];
	}

	// �м�����
	for (int i = k; i < size - k; i++) {
		int t = 0;
		for (int j = i - k; j < i + k; j++) {
			tmp[t++] = a[j];
		}
		quickSort(tmp, 0, n);
		a[i] = tmp[i];
	}

	// �±�Ե����
	for (int i = size - k; i < size; i++) {
		int t = 0;
		for (int j = i - k; j < size; j++) {
			tmp[t++] = a[j];
		}
		for (int j = size; j < i + k; j++) {
			tmp[t++] = a[i];
		}
		quickSort(tmp, 0, n);
		a[i] = tmp[i];
	}
}

/*
    �뾶Ϊn��������ֵ�˲�
*/
void meanFilter(int *a, int size, int n)
{
	int k = n / 2;

	// �ϱ�Ե����
	for (int i = 0; i < k; i++) {
		int sum = 0;
		int t = 0;
		for (int j = 0; j < i + k; j++) {
			sum += a[j];
		}
		for (int j = i + k; j < n; j++) {
			sum += a[i];
		}
		a[i] = sum / n;
	}

	// �м�����
	for (int i = k; i < size - k; i++) {
		int sum = 0;
		for (int j = i - k; j < i + k; j++) {
			sum += a[j];
		}
		a[i] = sum / n;
	}

	// �±�Ե����
	for (int i = size - k; i < size; i++) {
		int sum = 0;
		int t = 0;
		for (int j = i - k; j < size; j++) {
			sum += a[j];
		}
		for (int j = size; j < i + k; j++) {
			sum += a[i];
		}
		a[i] = sum / n;
	}
}