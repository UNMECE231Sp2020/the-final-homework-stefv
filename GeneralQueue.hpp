#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;
	public:
		//Default constructor
		Queue() {
			_size = 0;
		}

		//Copy constructor
		Queue(const List<Q> &q) {
			_data = q._data;
			_size = q.size();
		}

		//Getters
		size_t size() const {
			return _size;
		}

		Q front() const {
			return _data.front();
		}

		Q back() const {
			return _data.back();
		}

		//Push to queue
		void enqueue(Q value) {
			_data.push_front(value);
			_size = _data.size();
		}

		//Pop from queue
		void dequeue() {
			_data.pop_back();
			_size = _data.size();
		}

		void print() {
			_data.print();
		}

		bool search(Q value) {
			return _data.search(value);
		}

		bool empty() {
			return _data.empty;
		}

		Queue<Q> operator=(const Queue<Q> q) {
			_data = q._data;
			_size = _data.size();
			return *this;
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};

template <class U>
	std::ostream &operator<<(std::ostream &out, const Queue<U> &q) {
		out << q._data;
		return out;
	}

template <class U>
	bool operator==(const Queue<U> &left_queue, const Queue<U> &right_queue) {
		if( left_queue.size() != right_queue.size() ) {
			return false;
		}
		
		for(int i = 0; i < left_queue.size(); i++) {
			if( *(left_queue._data+i) != *(right_queue._data+i) ) {
				return false;
			}
		}
	return true;
}

template <class U>
		bool operator!=(const Queue<U> &left_queue, const Queue<U> &right_queue) {
		if( left_queue.size() == right_queue.size() ) {
			return false;
		}
		
		for(int i = 0; i < left_queue.size(); i++) {
			if( *(left_queue._data+i) == *(right_queue._data+i) ) {
				return false;
			}
		}
	return true;
}

