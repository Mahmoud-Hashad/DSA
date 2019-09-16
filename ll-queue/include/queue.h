#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class queue
{
  private:
    class list {
      public:
        T value;
        list *next;
        list ():next(0) {}
    };

    list *front, *rear;
    int q_size;

  public:
    queue();
    ~queue();

    int size();
    bool empty();
    void push(T value);
    T pop();

};


template <typename T>
queue<T>::queue():front(0), rear(0), q_size(0) {}
template <typename T>
queue<T>::~queue() {}

template <typename T>
int queue<T>::size() {
  return q_size;
}

template <typename T>
bool queue<T>::empty() {
  return q_size == 0;
}

template <typename T>
void queue<T>::push(T value) {

  list *temp = new list;
  temp->value = value;

  if(front == 0) front = temp;
  if(rear != 0) rear->next = temp;
  rear = temp;

  q_size++;
}

template <typename T>
T queue<T>::pop() {
 if (q_size == 0) return 0;
  q_size--;

  T temp_value = front->value;
  list *temp_list = front;

  front = temp_list->next;
  delete temp_list;

  return temp_value;
}

#endif // QUEUE_H
