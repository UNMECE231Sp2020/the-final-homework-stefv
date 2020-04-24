#include <iostream>
#include <string>
#include "GeneralStack.hpp"
#include "GeneralQueue.hpp"

int main() {
	std::cout << "Creation of a highest to lowest stack" << std::endl;

	Stack<double> s;
	if(s.empty()) {
		std::cout << "The list is empty!" << std::endl;
	}

	s.push(0.45);
	s.push(2.91);
	s.push(5.78);
	s.push(8.03);
	s.push(9.12);

	std::cout << std::endl << s << std::endl;
	std::cout << "Top of the stack: " << s.top() << std::endl;

	Stack<double> s2(s);
	s2.pop();
	s2.push(14.98);
	std::cout << "Size of s2: " << s2.size() << std::endl;

	Stack<std::string> s3;
	s3.push("pie");
	s3.push("love");
	s3.push("I");
	s3.print();
 	std::cout << std::endl;

	std::cout << "Creating queues!" << std::endl;
	Queue<int> que;
	que.enqueue(5);
	que.enqueue(8);
	que.enqueue(24);
	que.print();

	Queue<int> quoi(que);
	quoi.dequeue();
	quoi.enqueue(12);
	quoi.enqueue(21);
	std::cout << "Front of queue: " << quoi.front();
	std::cout << ", back of queue: " << quoi.back() << std::endl;
	std::cout << quoi << std::endl;

	int search_term = 24;
	if(quoi.search(search_term)) {
		std::cout << search_term << " is in the queue" << std::endl;
	}
	else {
		std::cout << search_term << " is not in the queue" << std::endl;
	}

	return 0;
}
