#include "queue.h"

queue::queue():front(0), rear(0), q_size(0) {}

queue::~queue() {}


int queue::size() {
  return q_size;
}

bool queue::empty() {
  return q_size == 0;
}

void queue::push(int number) {

  list *temp = new list;
  temp->value = number;

  if(front == 0) front = temp;
  if(rear != 0) rear->next = temp;
  rear = temp;

  q_size++;
}

int queue::pop() {
 if (q_size == 0) return 0;
  q_size--;

  int temp_value = front->value;
  list *temp_list = front;

  front = temp_list->next;
  delete temp_list;

  return temp_value;
}



