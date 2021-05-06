#include <iostream>
using std::cout;
using std::endl;
template <class T>
class Node{ // simple unit 
	public:
		T data; 
		Node *pNext; 
		Node(T data = T(), Node *pNext = nullptr){
			this->data = data;
			this->pNext = pNext;
		}
	};

template <class T>
class List{
	public:
		List();
		~List();

		void pop_front();
		void pop();
		void push_back(T data);
		int GetSize() {return size;} 
		T& operator[](const int index);
	private:
		int size; // list size 
		Node<T> *head;

};

template <class T>
List<T>::List(){
	//empty list
	size = 0;
	head = nullptr;

}

template <class T>
List<T>::~List(){

}

template <class T>
void List<T>::pop_front(){
}


template <class T>
void List<T>::pop(){
	if (head == nullptr) return;
	if (head->pNext == nullptr){
		delete head;
		head = nullptr; 
		return; 
	}
	Node<T> *current = this->head;
	while (current->pNext->pNext != nullptr){
		current = current->pNext;
	}

	delete current->pNext;
	current->pNext = nullptr;

}
template <class T> 
void List<T>::push_back(T data){
	if (head == nullptr){
		head = new Node<T>(data);
	}	
	else{
		Node <T> *current = this->head; 
		while (current->pNext != nullptr){
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	size++;
}

template <class T>
T &List<T>::operator[](const int index){
	Node<T> *current = this->head;
	int counter = 0;
	while (current != nullptr){
		if (counter == index)
			return current->data;
		current = current -> pNext;
		++counter;
	}
}

int main(void){
	List<int> lst;
	lst.push_back(5); 
	lst.push_back(8); 
	lst.push_back(1); 
	lst.push_back(2); 
	std::cout << lst[2] << '\n'; 
	return 0;
}
