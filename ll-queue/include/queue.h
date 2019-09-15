#ifndef QUEUE_H
#define QUEUE_H


class queue
{
  private:
    class list {
      public:
        int value;
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
    void push(int number);
    int pop();

};

#endif // QUEUE_H
