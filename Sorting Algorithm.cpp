#include <iostream> 
#include <queue>
#define SWAP(X, Y, Z) (Z=X); (X=Y); (Y=Z);
#define INF 1000001
#define BUCKET 10
using namespace std;

inline void printArray(int * mArr, int mLength)
{
	for (int ii = 0; ii < mLength; ii++)
		cout << mArr[ii] << endl;

	cout << endl;
}

/* ���� ���� */
void selectionSort(int * mArr, int mLength)
{
	int mTemp = 0;
	int mIdx = 0;

	for (int ii = 0; ii < mLength - 1; ii++)
	{
		mIdx = ii;
		for (int jj = ii + 1; jj < mLength; jj++) /* �ּڰ� Ž�� �ݺ��� */
		{ 
			if (mArr[jj] < mArr[mIdx]) /* ���� ���� �� ���� */
				mIdx = jj;
		}

		SWAP(mArr[ii], mArr[mIdx], mTemp);
	} printArray(mArr, mLength);
}

/* ���� ���� */
void BubbleSort(int * mArr, int mLength)
{
	int mTemp = 0;

	for (int ii = 0; ii < mLength - 1; ii++)
	{
		for (int jj = 0; jj < (mLength - ii) - 1; jj++)
		{
			if (mArr[jj] > mArr[jj + 1])
				SWAP(mArr[jj], mArr[jj + 1], mTemp);
		}
	} printArray(mArr, mLength);
}

/* ���� ���� */
void insertSort(int * mArr, int mLength)
{
	int mTemp = 0;
	int mInsData = 0;

	for (int ii = 1, jj = 0; ii < mLength; ii++)
	{
		mInsData = mArr[ii];
		for (jj = ii - 1; jj >= 0; jj--)
		{
			if (mArr[jj] < mInsData) /* �����Ͱ� ���� �� ���� */
				mArr[jj + 1] = *(mArr + jj); /* �� ����� �� ĭ �ڷ� �б� */
			else  
				break; /* ������ġ�� ã�����Ƿ� Ż�� */
		}

		mArr[jj + 1] = mInsData;
	} printArray(mArr, mLength);
}

/* �պ� ���� */
void merger(int * mArr, int first, int mid, int last)
{
	/* ���� ������ �� ������ ù ��° ��ġ ������ ��� ���� */
	int fIdx = first; /* �迭�� ���� ������ ����Ű�� ���� */
	int rIdx = mid + 1; /* �迭�� ���� ������ ����Ű�� ���� */

	int sIdx = first;
	int ii = 0;

	/* ���� �� ����� ���� �迭�� �����Ѵ�. */
	int * mSumArr = new int[last + 1];

	/* ���� �� �� ������ �����͵��� ���Ͽ�, ���� ���� ��� �ӽ� ���� �� �迭�� �ϳ��� �Ű� ��´�. */
	while (fIdx <= mid && rIdx <= last) /* �迭�� ���� ��������, �迭�� ���� �������� ���� ����� �����ִ� ��Ȳ���� �ݺ������� '��'���� �ǹ��Ѵ�. */
	{
		if (mArr[fIdx] <= mArr[rIdx]) 
			mSumArr[sIdx] = mArr[fIdx++]; /* �迭�� �պκ��� ��� �ӽ� ���� �迭�� �Ű� ���ٸ� �迭�� �޺κп� ���� �����͵��� �״�� �ű��. */
		else 
			mSumArr[sIdx] = mArr[rIdx++]; /* �迭�� �޺κ��� ��� �ӽ� ���� �迭�� �Ű����ٸ� �迭�� �պκп� ���� �����͵��� �״�� �ű��. */

		sIdx++;
	}

	if (fIdx > mid) /* �迭�� �պκ��� ��� �ӽ� ���� �� �迭�� �Ű����ٸ�, �迭�� �޺κп� ���� �����͵��� �״�� �ű��. */
	{
		for (ii = rIdx; ii <= last; ii++, sIdx++)
			mSumArr[sIdx] = mArr[ii];
	}
	else /* �迭�� �޺κ��� ��� �ӽ� ���� �� �迭�� �״�� �Ű����ٸ�, �迭�� �պκп� ���� �����͵��� �״�� �ű��. */
	{
		for (ii = fIdx; ii <= mid; ii++, sIdx++)
			mSumArr[sIdx] = mArr[ii];
	}

	for (ii = first; ii <= last; ii++)
		mArr[ii] = mSumArr[ii];

	delete[] mSumArr;
}

void mergerSort(int * mArr, int first, int last)
{
	int middle;

	if (first < last) /* First�� �۴ٴ� Last���� ���� ���� �� ������ �� �� �ִٴ� ���̴�. */
	{
		middle = (first + last) / 2; /* �߰� ������ ����Ѵ�. */

		/* �ѷ� ������ ������ �����Ѵ�. */
		mergerSort(mArr, first, middle); /* First ~ Middle�� ��ġ�� ������ ���� */
		mergerSort(mArr, middle + 1, last); /* Middle+1 ~ Last�� ��ġ�� ������ ���� */
		
		/* ���ĵ� �� �迭�� �����Ѵ�. */
		merger(mArr, first, middle, last); /* ���� �� �� �迭�� �����Ѵ�. */
	}
}

/* �� ���� */
void QuickSort(int * mArr, int left, int right)
{
	int pivot = mArr[(left + right) / 2]; /* �߽��� */
	int mLeft = left; /* ���� ����� ���� ���� ���� */
	int mRight = right; /* ���� ����� ���� ������ ���� */
	int mTemp = 0;

	while (mLeft <= mRight) /* mLeft�� mRight�� �������� ���� �� ������ �ݺ��Ѵ�. */
	{
		while (mArr[mLeft] > pivot) { ++mLeft; } /* pivot ���� ū ���� ã�� ��� */
		while (mArr[mRight] < pivot) { --mRight; } /* pivot ���� ���� ���� ã�� ��� */

		if (mLeft <= mRight) /* mLeft ���� mRight�� ���� ũ�ų� ���� ��� */
		{
			SWAP(mArr[mLeft], mArr[mRight], mTemp); /* mLeft�� mRight ���� ��ȯ�Ѵ�. */
			++mLeft, --mRight; /* mLeft ����, mRight ���� */
		}
	}

	if (left < mRight) { QuickSort(mArr, left, mRight); }
	if (mLeft < right) { QuickSort(mArr, mLeft, right); }
}

/* ��� ���� */
void RadixSort(int * mArr, int num, int mMaxLength)
{
	queue<int> mQueue[BUCKET];

	int divfac = 1;
	int radix = 0;

	/* ���� �� �������� ���̸�ŭ �ݺ� */
	for (int pos = 0; pos < mMaxLength; pos++)
	{
		/* ���Ĵ���� �� ��ŭ �ݺ� */
		for (int di = 0; di < num; di++)
		{
			/* N��° �ڸ��� ���� ���� */
			radix = (mArr[di] / divfac) % 10;
			
			/* ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ���� */
			mQueue[radix].push(mArr[di]);
		}

		/* ��Ŷ �� ��ŭ �ݺ� */
		for (int bi = 0, di = 0; bi < BUCKET; bi++)
		{
			/* ��Ŷ�� ����� �� ������� �� ������ �ٽ� Arr�� ���� */
			while (mQueue[bi].empty() == false)
			{
				mArr[di++] = mQueue[bi].front();
				mQueue[bi].pop();
			}
		}

		/* N��° �ڸ��� ���� ������ ���� �������� ���� */
		divfac *= 10;
	}

	printArray(mArr, num);
}

int main(void)
{
	int mArr[10] = { 3, 5, 6, 1, 2, 4, 7, 8, 10, 9 };
	int mSize = sizeof(mArr) / sizeof(int);

	/* ���� ���� (Selection Sort) */
	cout << ":::: Selection Sort ::::" << endl;
	selectionSort(mArr, mSize);

	/* ���� ���� (Insert Sort) */
	cout << ":::: Insert Sort ::::" << endl;
	insertSort(mArr, mSize);

	/* ���� ���� (Bubble Sort) */
	cout << ":::: Bubble Sort ::::" << endl;
	BubbleSort(mArr, mSize);

	/* �� ���� (Quick Sort) */
	cout << ":::: Quick Sort ::::" << endl;
	QuickSort(mArr, 0, mSize - 1);
	printArray(mArr, mSize);

	/* ��� ���� (Radix Sort) */
	cout << ":::: Radix Sort ::::" << endl;
	RadixSort(mArr, mSize, 2);

	/* �պ� ���� (Meger Sort) */
	cout << ":::: Metger Sort ::::" << endl;
	mergerSort(mArr, 0, mSize - 1);
	printArray(mArr, mSize);

	return 0;
}