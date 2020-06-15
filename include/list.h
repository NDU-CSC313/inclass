template <typename Object>
class Node
{
public:
    Object data;
    Node *prev;
    Node *next;

    Node( const Object & d=Object (), Node *p=NULL,
         Node *n=NULL)
    :data(d),prev(p),next(n){}
};


template  <typename Object>
class List{

private:
int   theSize;
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
      friend class List<Object>;
  };
   
    List();
    List(const List &rhs);
    ~List();
    List & operator=(const List &);
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
Object & List<Object>::iterator::operator*(){
    return current->data;
}

template<typename Object>
typename List<Object>::iterator & List<Object>::iterator::operator++(){
    current=current->next;
    return *this;
}
template <typename Object>
typename List<Object>::iterator & List<Object>::iterator::operator++(int in){
    current=current->next;
    return *this;
}
template<typename Object>
typename List<Object>::iterator & List<Object>::iterator::operator--(){
    current=current->prev;
    return *this;
}
template<typename Object>
typename List<Object>::iterator & List<Object>::iterator::operator--(int in){
    current=current->prev;
    return *this;
}
template<typename Object>
bool List<Object>::iterator::operator==(const typename List<Object>::iterator & rhs)  {
    return current==rhs.current;
}

template<typename Object>
bool List<Object>::iterator::operator!=(const typename List<Object>::iterator & rhs)  {
    return (current!=rhs.current);
    
}

//the list class

template<typename Object>
void List<Object>::init()
{
    theSize=0;
    head=new Node<Object>;
    tail=new Node<Object>;
    head->next=tail;
    head->prev=NULL;
    tail->prev=head;
    tail->next=NULL;
}


template<typename Object>
List<Object>::List()
{ init(); }

template<typename Object>
List<Object>::~List()
{
    clear();
    delete head;
    delete tail;
}



template<typename Object>
typename List<Object>::iterator List<Object>::begin() const
{ return iterator(head->next);}

template<typename Object>
typename List<Object>::iterator List<Object>::end() const
{ return iterator(tail);}

template<typename Object>
int List<Object>::size()
{ return theSize;}

template<typename Object>
bool List<Object>::empty()
{return size()==0;}

template <typename Object>
void List<Object>::clear(){
    while(!empty())
        erase(begin());
}
template<typename Object>
void List<Object>::push_front(const Object & x){
    insert( begin( ), x );
}
template<typename Object>
void List<Object>::push_back(const Object & x){
    insert( end( ), x );
}

template<typename Object>
void List<Object>::pop_front(){
    erase( begin() );
}
template<typename Object>
void List<Object>::pop_back(){
    erase( --end() );
}
template<typename Object>
List<Object>::List(const List<Object> &rhs)
{  init();
    for( List<Object>::iterator itr=rhs.begin();itr!=rhs.end();++itr)
        push_back(*itr);
}

template<typename Object>
List<Object> & List<Object>::operator=(const List<Object> &rhs)
{
    if(this==&rhs)
        return *this;
    clear();
    for(typename List<Object>::iterator itr=rhs.begin();itr!=rhs.end();++itr)
	       push_back(*itr);
    return *this;
}
template<typename Object>
   typename List<Object>::iterator List<Object>::insert( typename List<Object>::iterator itr,const Object & x)
{
    Node<Object> *p=itr.current;
    theSize++;
    Node<Object> *newNode=new Node<Object>(x,p->prev,p);
    p->prev->next=newNode;
    p->prev=newNode;
    return iterator(newNode);
}

template<typename Object>
 typename List<Object>::iterator List<Object>::erase( typename List<Object>::iterator itr){
    Node<Object> *p=itr.current;
    iterator ret(p->next);
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
    theSize--;
    return ret;

}

template<typename Object>
Node<Object> * List<Object>::rreverse(Node<Object> *t){
    if(t==NULL) return NULL;
    if(t->next==NULL) return t;// a list with one element is its OWN reverse
    // second represents the "tail" list
    Node<Object> *second=t->next;
    t->next=NULL;
    //  rsecond represents the reverse of "tail"
    Node<Object> *rsecond=rreverse(second);
    //concatenate or "glue" the two lists together
    rsecond->prev=NULL;
    second->next=t;
    t->prev=second;
    return rsecond;
}


template<typename Object>
void List<Object>::reverse(){
    Node<Object> *current;
    Node<Object> *t;
    current=head;
    
    while(current!=NULL){
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


