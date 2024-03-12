//Ten: Mai Nhật Nam - MSSV: 22120219
//Bài 04: Cài đặt lớp stack với các yêu cầu sau
//Dùng mảng 1 chiều hoặc DSLK để minh họa stack.
//- Thêm phần tử vào stack.
//- Xóa phần tử khỏi stack.
//- Lấy phần tử đầu stack.
//- Kiểm tra stack rỗng.
//- Lấy kích thước stack.

#include<iostream>
#include<vector>
using namespace std;

// Minh hoa stack bang mang 1 chieu.
class stack {
private:
	int* a;
	int capacity; // Luu size hien tai co trong 1 Stack
	int size; // Luu so phan tu co the o trong 1 Stack.
public:
	stack(int size);
	void push(int element);
	void pop();
	int Top();
	bool isEmpty();
	int GetSize();

};

int main() {
	stack a(5);
	a.push(5);
	a.push(10);
	a.push(15);
	a.push(25);
	cout << "Top element: " << a.Top() << endl;
	a.pop();
	cout << "Top element after a pop : " << a.Top();
	cout << endl;
	cout << "Current size: " << a.GetSize();
		 
}

stack::stack(int Size) {
	size = Size;
	a = new int[size];
	capacity = -1; 
}

void stack::push(int element) {
	if (capacity >= size - 1) {
		cout << "Stack overflow" << endl;
	}
	else {
		a[++capacity] = element;
	}
}

void stack:: pop() {
	if (capacity < 0) {
		cout << "Stack dang rong" << endl;
	}
	else {
		capacity--;
	}
	
}

int stack::Top() {
	return a[capacity];
}

bool stack::isEmpty() {
	return capacity == -1;
}

int stack::GetSize() {
	return capacity + 1; 
}
