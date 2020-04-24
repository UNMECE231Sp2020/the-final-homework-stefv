#include <iostream>
#include "GeneralList.hpp"

template <class T>
class Stack {
	private:
		List<T> _data;
		size_t _size;
		
	public:
		//Default constructor
		Stack();

		//Default copy constructor
		Stack(const Stack &stack);

		//Getters
		T top() const;

		size_t size() const;

		//Adding data to the data structure
		void push(T value);

		//Removing data from the data structure
		void pop();

		bool search(T value) {
			return _data.search(value);
		}


		bool empty() const;

		void print();

		//This overloaded operator is empty, please implement
		Stack<T> operator=(const Stack<T> &stack) {
			;
		}

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};
