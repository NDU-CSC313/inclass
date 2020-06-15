template <typename Object>
class Node
{
public:
    Object data;
    Node *prev;
    Node *next;

    Node( const Object & d=Object (), Node *p=nullptr,
         Node *n=nullptr)
    :data(d),prev(p),next(n){}
};


template  <typename Object>
class list{

private:
int   _size;
  Node<Object> *head;
  Node<Object> *tail;
  void init();
public:
  class iterator{
  protected:
    Node<Object> *current;
  public:
    iterator(){}
  iterator(Node<Object> *p):current(p){}

      Object & operator*();
      iterator & operator++();
      iterator & operator++(int in);
      iterator & operator--();
      iterator & operator--(int in);
      bool operator==(const iterator & rhs) ;
      //the operator != is typically used in
      // a for loop as itr!=list.end()
      //since end and begin return a temp value
      //then != should take a constant argument
      bool operator!=(const iterator &rhs) ;
      friend class list<Object>;
  };
   
    list();
    list(const list &rhs);
    ~list();
    list & operator=(const list &);
    iterator begin() const;//it is used by constant lists, for example in copy constructor
    iterator end() const;// same as above
    int size()  ;
    bool empty();
    void clear();
   
    void push_front( const Object & x );//const so it can be used with literals
    void push_back(const  Object & x );//const so it can be used with literals
    void pop_front( );
    void pop_back( );
    iterator insert( iterator itr, const Object & x ) ;//const so it can be used with literals
    iterator erase( iterator );
    Node<Object> * rreverse(Node<Object> *);
    void reverse();
};

//implementation
//First the iterator class
template<typename Object>
Object & list<Object>::iterator::operator*(){
    return current->data;
}

template<typename Object>
typename list<Object>::iterator & list<Object>::iterator::operator++(){
    current=current->next;
    return *this;
}
template <typename Object>
typename list<Object>::iterator & list<Object>::iterator::operator++(int in){
    current=current->next;
    return *this;
}
template<typename Object>
typename list<Object>::iterator & list<Object>::iterator::operator--(){
    current=current->prev;
    return *this;
}
template<typename Object>
typename list<Object>::iterator & list<Object>::iterator::operator--(int in){
    current=current->prev;
    return *this;
}
template<typename Object>
bool list<Object>::iterator::operator==(const typename list<Object>::iterator & rhs)  {
    return current==rhs.current;
}

template<typename Object>
bool list<Object>::iterator::operator!=(const typename list<Object>::iterator & rhs)  {
    return (current!=rhs.current);
    
}

//the list class

template<typename Object>
void list<Object>::init()
{
    _size=0;
    head = new Node<Object>{};
    tail = new Node<Object>{};
    head->next=tail;
    head->prev=nullptr;
    tail->prev=head;
    tail->next=nullptr;
}


template<typename Object>
list<Object>::list()
{ init(); }

template<typename Object>
list<Object>::~list()
{
    clear();
    delete head;
    delete tail;
}



template<typename Object>
typename list<Object>::iterator list<Object>::begin() const
{ return iterator(head->next);}

template<typename Object>
typename list<Object>::iterator list<Object>::end() const
{ return iterator(tail);}

template<typename Object>
int list<Object>::size()
{ return _size;}

template<typename Object>
bool list<Object>::empty()
{return size()==0;}

template <typename Object>
void list<Object>::clear(){
    while(!empty())
        erase(begin());
}
template<typename Object>
void list<Object>::push_front(const Object & x){
    insert( begin( ), x );
}
template<typename Object>
void list<Object>::push_back(const Object & x){
    insert( end( ), x );
}

template<typename Object>
void list<Object>::pop_front(){
    erase( begin() );
}
template<typename Object>
void list<Object>::pop_back(){
    erase( --end() );
}
template<typename Object>
list<Object>::list(const list<Object> &rhs)
{  init();
    for( list<Object>::iterator itr=rhs.begin();itr!=rhs.end();++itr)
        push_back(*itr);
}

template<typename Object>
list<Object> & list<Object>::operator=(const list<Object> &rhs)
{
    if(this==&rhs)
        return *this;
    clear();
    for(typename list<Object>::iterator itr=rhs.begin();itr!=rhs.end();++itr)
	       push_back(*itr);
    return *this;
}
template<typename Object>
   typename list<Object>::iterator list<Object>::insert( typename list<Object>::iterator itr,const Object & x)
{
    Node<Object> *p=itr.current;
    _size++;
    Node<Object> *newNode=new Node<Object>(x,p->prev,p);
    p->prev->next=newNode;
    p->prev=newNode;
    return iterator(newNode);
}

template<typename Object>
 typename list<Object>::iterator list<Object>::erase( typename list<Object>::iterator itr){
    Node<Object> *p=itr.current;
    iterator ret(p->next);
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
    _size--;
    return ret;

}

template<typename Object>
Node<Object> * list<Object>::rreverse(Node<Object> *t){
    if(t==nullptr) return nullptr;
    if(t->next==nullptr) return t;// a list with one element is its OWN reverse
    // second represents the "tail" list
    Node<Object> *second=t->next;
    t->next=nullptr;
    //  rsecond represents the reverse of "tail"
    Node<Object> *rsecond=rreverse(second);
    //concatenate or "glue" the two lists together
    rsecond->prev=nullptr;
    second->next=t;
    t->prev=second;
    return rsecond;
}


template<typename Object>
void list<Object>::reverse(){
    Node<Object> *current;
    Node<Object> *t;
    current=head;
    
    while(current!=nullptr){
        t=current->prev;
        current->prev=current->next;
        current->next=t;
        current=current->prev;
    }
    
    t=head;
    head=tail;
    tail=t;
    return;
}


