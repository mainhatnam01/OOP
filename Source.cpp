//Ten: Mai Nhật Nam - MSSV: 22120219
//Bài 05: Cài đặt lớp queue với các yêu cầu sau
//Dùng mảng 1 chiều hoặc DSLK để minh họa queue.
//- Thêm phần tử vào queue.
//- Xóa phần tử khỏi queue.
//- Lấy phần tử đầu queue.
//- Kiểm tra queue rỗng.
//- Lấy kích thước queue.

#include<iostream>
#include<vector>
using namespace std;

class queue {
private:
	int* a;
	int capacity;
	int size;
	int front;
	int rear;
public:
	queue(int Size);
	void push(int element);
	void pop();
	int top();
	bool isEmpty();
	int GetSize();
};
int main() {
	queue q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << "Top element: " << q.top(); // should be  1.
	q.pop();
	cout << endl;
	cout << "Top element: " << q.top() << endl; // should be 2.
	if (q.isEmpty()) {
		cout << "Queue is emty ";
	}
	else {
		cout << "Current Size: " << q.GetSize(); // should be 3
	}
}

queue::queue(int Size) {
	capacity = Size;
	a = new int[capacity];
	size = 0;
	front = 0;
	rear = -1;
}
void queue::push(int element) {
	if (size < capacity) {
		rear = (rear + 1) % capacity; 
		a[rear] = element;
		size++;
	}
	else {
		cout << "Queue is Full" << endl;
	}
}

void queue::pop() {
	if (size > 0) {
		front = (front + 1) % capacity; 
		size--;
	}
	else {
		cout << "Queue is empty" << endl;
	}
}

int queue::top() {
	if (size == 0) {
		cout << "Queue is empty" << endl;
		return -1; 
	}
	return a[front];
}

bool queue::isEmpty() {
	return size == 0;
}

int queue::GetSize() {
	return size;
}