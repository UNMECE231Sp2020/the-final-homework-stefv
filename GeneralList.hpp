#include <iostream>

template <class Data>
class List {
	private:
		struct _list {
			Data value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
				if(ptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
				}
			}
	public:
		List() {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list) {
			_front = nullptr;
			_back = nullptr;
			_size = 0;
			reccopy(list._front);
		}
		
		List &operator=(const List &list) {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
				pop_front();
			}
		}

		Data &front() const {
			return _front->value;
		}

		Data &back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		void push_front(const Data data) {
			Dlist *newNode = new Dlist;  
			newNode->value = data;       
			newNode->prev = nullptr;     

			if(_front==nullptr) {        
				newNode->next = nullptr;   
				_back = newNode;           
			}
			else {
				newNode->next = _front;    
				_front->prev = newNode;  
			}

			_front = newNode;              
			_size++;                     
		}

		void push_back(const Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next = nullptr;

			if(_back != nullptr) {
				_back->next = newNode;
				newNode->prev = _back;
			}

			if(_front == nullptr) {
				_front = newNode;
				newNode->prev = nullptr;
			}

			_back = newNode;
			_size += 1;
		}

		void pop_front() {
			Dlist *front_to_delete = _front;
			_front = _front->next;

			if(_front == nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size -= 1;
		}

		//CONVERT THIS FUNCTION
		void pop_back() {
			Dlist *back_to_remove = _back;
			_back = _back->prev;

			if(_back == nullptr) {
				_front = nullptr;
			}

			else {
				_back = _back->prev;
				_back->next = nullptr;
			}

			delete back_to_remove;
			_size -= 1;
		}

		// leave this alone
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}

		//Modify this
		void print() {
			Dlist *temp;
			for(temp = _front; temp != nullptr; temp = temp->next) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}

		void print_back() {
			Dlist *temp;
			for(temp =_back; temp != nullptr; temp = temp->prev) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}

		bool search (Data search_value) {
			Dlist *temp;
			for (temp = _front; temp != nullptr; temp = temp->next) {
				if (temp->value == search_value) {
		 			return true;
				}
			}
			return false;
		}
		
		template <typename V> friend bool operator !=(const List <V> &a, const List <V> &b);
		template <typename V> friend bool operator ==(const List <V> &a, const List <V> &b);
		template <class V> friend std::ostream &operator <<(std::ostream &o, const List<V> &list);
};

template <typename V> bool operator != (const List <V> &a, const List <V> &b) {
	auto i = a._front, j = b._front;

	if (a._size == b._size) {
		for (int x = 0; x < a.size(); x++) {
			if (i->value == j->value) {
				return false;
			}
			else {
				return true;
			}

			i = i->next;
			j = j->next;
		}
	}
	else {
		return true;
	}
}

template <typename V> bool operator == (const List <V> &a, const List <V> &b) {
	auto i = a._front, j = b._front;

	if (a._size == b._size) {
		for (int x = 0; x < a.size(); x++) {
			if (i->value == j->value) {
				return true;
			}
			else {
				return false;
			}

			i = i->next;
			j = j->next;
		}
	}
	else {
		return false;
	}
}

template <class V>
	std::ostream &operator << (std::ostream &o, const List<V> &list) {
		for (auto *i = list._front; i != nullptr; i = i->next) {
			o << i->value << " ";
		}
		return o;
	}
	
