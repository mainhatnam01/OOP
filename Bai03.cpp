//Ten: Mai Nhật Nam - MSSV: 22120219
// Bài 03: Viết chương trình tạo ra mảng động (dùng con trỏ) các số nguyên.
//- Viết 1 phương thức khởi tạo của mảng.
//- Viết phương thức thêm phần tử vào mảng.
//- Viết phương thức xóa phần tử đầu tiên trong mảng.
//- Viết phương thức tìm phần tử lớn thứ “nhì” trong mảng.

#include<iostream>
#include<vector>
using namespace std;

class Array {
private:
	int* a;
	int size;
public:
	Array(int Size);
	void addElement(int element);
	void RemoveFirstElement();
	int findSecondLargest();
	void printArray();

};

int main() {
	Array a(3);
	a.addElement(4);
	cout << "Array after added an element: " << endl;
	a.printArray();
	a.addElement(5);
	cout << "Array after added an element: " << endl;
	a.printArray();
	a.RemoveFirstElement();
	cout << "Array after Remove the first element: " << endl;
	a.printArray();
	cout << "Second largest element: " << a.findSecondLargest();


}

Array::Array(int Size) {
	size = Size;
	a = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
}

void Array::printArray() {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void Array::addElement(int element) {
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; ++i) {
		newArray[i] = a[i];
	}
	delete[] a;
	a = newArray;
	a[size++] = element;
}

void Array::RemoveFirstElement() {
	if (size == 0) return;
	for (int i = 1; i < size; ++i) {
		a[i - 1] = a[i];
	}
	size--;
}

int Array::findSecondLargest() {
	if (size < 2) return -1;

	int max = INT_MIN;
	int secondLargest = INT_MIN;
	for (int i = 0; i < size; ++i) {
		if (a[i] > max) {
			secondLargest = max;
			max = a[i];
		}
		else if (a[i] > secondLargest && a[i] < max) {
			secondLargest = a[i];
		}
	}
	return secondLargest;
}
