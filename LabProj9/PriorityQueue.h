// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: Ian Clowes
// Section: CMPSCI122 - 002L
// Assignment: LabProj9 - Priority Queue
//


#pragma once
template <class T>
class PriorityQueue {
public:
	PriorityQueue();
	~PriorityQueue();
	PriorityQueue(const PriorityQueue<T>& org);
	PriorityQueue<T>& operator=(const PriorityQueue<T>& org);
	void enqueue(T item);
	T dequeue();
	bool IsEmpty();
	void Insert(T item, int priorityVal);
	void ChangePriority(T item, int priorityVal);
	T Pull();
	T Peek();

private:
	int qFront, qBack;
	T* arr;
	int capacity = 1024;
    int* priorities;
};
template <class T>
PriorityQueue<T>::PriorityQueue()
{
    qFront = 0;
    qBack = 0;
    arr = new T[capacity];
    priorities = new int[capacity];  
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] arr;   
    delete[] priorities;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& org)
{
    qFront = org.qFront;
    qBack = org.qBack;
    capacity = org.capacity;
    arr = new T[capacity];
    priorities = new int[capacity];  // New array for priorities
    for (int i = 0; i < qBack; ++i) {
        arr[i] = org.arr[i];
        priorities[i] = org.priorities[i];  // Copy the priorities as well
    }
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& org)
{
    if (this != &org) {
        delete[] arr;
        delete[] priorities;  // Don't forget to delete the old priorities array

        qFront = org.qFront;
        qBack = org.qBack;
        capacity = org.capacity;
        arr = new T[capacity];
        priorities = new int[capacity];  // New array for priorities

        for (int i = 0; i < qBack; ++i) {
            arr[i] = org.arr[i];
            priorities[i] = org.priorities[i];  // Copy the priorities
        }
    }
    return *this;
}

template <class T>
bool PriorityQueue<T>::IsEmpty() {
    return qBack == 0;
}

template <class T>
void PriorityQueue<T>::enqueue(T item) {
    if (qBack == capacity) {
        
    }
    arr[qBack] = item;
    priorities[qBack] = 0;  // Default priority (can be updated later)
    ++qBack;
}

template <class T>
T PriorityQueue<T>::dequeue()
{
    if (IsEmpty()) {
        cout << "Queue is empty";
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < qBack; ++i) {
        if (priorities[i] > priorities[highestPriorityIndex]) {  // Max-priority queue (higher priority value means higher priority)
            highestPriorityIndex = i;
        }
    }

    T item = arr[highestPriorityIndex];
    for (int i = highestPriorityIndex; i < qBack - 1; ++i) {
        arr[i] = arr[i + 1];
        priorities[i] = priorities[i + 1];
    }
    --qBack;
    return item;
}

template <class T>
void PriorityQueue<T>::Insert(T item, int priorityVal) {
    // Check for duplicates directly before inserting
    for (int i = 0; i < qBack; ++i) {
        if (arr[i] == item) {
            cout << "***Error: Trying to insert duplicated item!" << endl;
            return;  // Do nothing if item already exists in the queue
        }
    }

    if (qBack == capacity) {  // If array is full increase the capacity by 50%
        int newCapacity = capacity + (capacity / 2);
        T* newArr = new T[newCapacity];
        int* newPriorities = new int[newCapacity];

        for (int i = 0; i < qBack; ++i) {
            newArr[i] = arr[i];
            newPriorities[i] = priorities[i];
        }

        delete[] arr;
        delete[] priorities;

        arr = newArr;
        priorities = newPriorities;
        capacity = newCapacity;
    }

    arr[qBack] = item;
    priorities[qBack] = priorityVal;
    ++qBack;
}

template <class T>
void PriorityQueue<T>::ChangePriority(T item, int priorityVal) {
    for (int i = 0; i < qBack; ++i) {
        if (arr[i] == item) {
            priorities[i] = priorityVal;
            return;
        }
    }
}

template <class T>
T PriorityQueue<T>::Pull() {
     if (IsEmpty()) {
         cout << "Queue is empty";
    }

     int highestPriorityIndex = 0;
     for (int i = 1; i < qBack; ++i) {
         if (priorities[i] > priorities[highestPriorityIndex]) {  // Max-priority queue
             highestPriorityIndex = i;
         }
     }

    T item = arr[highestPriorityIndex];

    // Shift the remaining items to fill the gap
    for (int i = highestPriorityIndex; i < qBack - 1; ++i) {
        arr[i] = arr[i + 1];
        priorities[i] = priorities[i + 1];
    }
    --qBack;

    return item;
}


template <class T>
T PriorityQueue<T>::Peek() {
    if (IsEmpty()) {
        cout << "Queue is empty";
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < qBack; ++i) {
        if (priorities[i] > priorities[highestPriorityIndex]) {  // Max-priority queue
            highestPriorityIndex = i;
        }
    }

    return arr[highestPriorityIndex];
}

/*OUTPUT
Successfully created an empty priority queue for strings.
Insert string "Homework Due Today" to the priority queue with priority value 20.
Insert string "Play Games" to the priority queue with priority value 3.
Insert string "Prepare Dinner" to the priority queue with priority value 30.
Insert string "Exam" to the priority queue with priority value 70.
Insert string "Workout" to the priority queue with priority value 15.
Insert string "Homework Due Today" to the priority queue with priority value 45.
***Error: Trying to insert duplicated item!
Current item with the highest priority: Exam
Removing the highest priority item...
Current item with the highest priority: Prepare Dinner
Change the priority of item "Homework Due Today" to 50.
Current item with the highest priority: Homework Due Today
Removing the two highest priority item...
Current item with the highest priority: Workout*/
