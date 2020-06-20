#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>
//#include <execution>
#include "vector.h"
class check {
    int _x;
public:
    check(int x) :_x(x) {}
    bool operator()(int val) {
        if (val == _x)return true;
        else return false;
    }
};
int main()
{

    /* exercise 1 */
    /* we can declare vectors of any type */
    /* typical usage is to APPEND to the vector */
    /* using the push_back() method */

    /* {

      std::vector<int> v;
      std::vector<std::string> sv;
      v.push_back(1);
      v.push_back(2);
      sv.push_back("one");
      sv.push_back("two");
      for (int i = 0; i < sv.size(); ++i)
          std::cout << sv[i] << ",";
      std::cout << "\n";
      for (int& x : v)
          x = 17;
       for (int& x : v)
           std::cout << x <<",";
       std::cout << "\n";
      }*/


    /* exercise 2: illustration of dynamically */
    /* resizing the interal storage of a vector */

      /* {

           int size = 2;
           int* p = new int[2];
           for (int i = 0; i < 10; ++i) {
               if (i == size) {
                   std::cout << "copying\n";
                   int* old = p;
                   p = new int[size + 1];
                   for (int j = 0; j < size; ++j)
                       p[j] = old[j];
                   size++;
               }
               p[i] = i;

           }
           std::cout << "------content-------\n";
           for (int i = 0; i < size; ++i)
               std::cout << p[i] << ",";
           std::cout << "\n";
       }*/

    /* exercise 3: a more efficient way of reallocation */
    /* doubling the size instead of increasing by one every time */
       /*{
           int size = 2;
           int* p = new int[2];
           for (int i = 0; i < 10; ++i) {
               if (i == size) {
                   std::cout << "copying\n";
                   int* old = p;
                   p = new int[2*size];
                   for (int j = 0; j < size; ++j)
                       p[j] = old[j];
                   size*=2;
               }
               p[i] = i;

           }
           std::cout << "------content-------\n";
           for (int i = 0; i < size; ++i)
               std::cout << p[i] << ",";
           std::cout << "\n";
       }*/

    /* exercise 4: we need to values to keep track of */
    /* elements. The capacity and the size */

       //{
       //     int capacity = 2;
       //     int size = 0;
       //     int* p = new int[capacity];
       //     for (int i = 0; i < 10; ++i) {
       //         if (capacity == size) {
       //             std::cout << "copying\n";
       //             int* old = p;
       //             p = new int[2 * capacity];
       //             for (int j = 0; j < size; ++j)
       //                 p[j] = old[j];
       //             capacity *= 2;
       //         }
       //         p[i] = i;
       //         size++;

       //     }
       //     std::cout << "------content-------\n";
       //     for (int i = 0; i < size; ++i)
       //         std::cout << p[i] << ",";
       //     std::cout << "\n";
       // }

    /* exercise 5: illustration of the growth of the */
    /* capacity of a vector in the STL */
        /*{   std::vector<int> v;
             for (int i = 0; i < 100; i++) {
            std::cout << "i= " << i << ", capacity=" << v.capacity() << std::endl;
            v.push_back(i);
              }
        }*/

    /* exercise 6: using a pointer instead of index to iterate */
    /* over the elements of a container */
        /* int* p = new int[10];
         int* begin = p;
         int* end = p + 10;
         int i = 0;
         for (int* q = begin; q != end; ++q) {
             *q = i++;
         }
         for (int i = 0; i < 10; i++)
             std::cout << p[i] << ",";
         std::cout << "\n";
         */

        //exercise 7: an iterator is a generalization of pointer 

         /* {
              Container c(10);

          for (Container::Iterator itr = c.begin(); itr != c.end(); ++itr)
              std::cout << *itr << ",";
          }*/

   /* exercise 8: using an iterator with std::vector*/
          //{
          //std::vector<int> v;
          //v.push_back(1); v.push_back(2); v.push_back(3);
          //for (auto itr = v.begin(); itr != v.end(); ++itr)
          //    std::cout << *itr << ",";
          //std::cout << "\n";
          //}

    /*exercise 9: storing a user defined type
    which illustrates the call for ctor and dtors*/
         /* {
              std::vector<TestClass<0>> v;
              TestClass<0> a(1, 2);
              TestClass<0> b(3, 4);
              v.push_back(a);
              v.push_back(b);

          }*/

  /*  exercise 10: using array-like indices with vectors*/

          /* {
           std::vector<TestClass<0>> v(3);
           TestClass<0> a(1, 2);
           TestClass<0> b(3, 4);
           v[0] = a;
           v[1] = b;
           std::cout << "size= " << v.size() << std::endl;
           std::cout << "----------------\n";

           }*/

      /*  exercise 11: reseving space ahead of time*/
           /*   {
              std::vector<TestClass<0>> v;
              v.reserve(2);
              TestClass<0> a(1, 2);
              TestClass<0> b(3, 4);
              v.push_back(a);
              v.push_back(b);
              std::cout << "size= " << v.size() << std::endl;
              std::cout << "----------------\n";
              }*/

  /*  exercise 12: removing elements from a vector*/
             /* {
              std::vector<TestClass<0>> v;
              v.push_back(TestClass<0>(1, 2));
              v.push_back(TestClass<0>(3, 4));
              std::cout << v.size() << std::endl;
              v.pop_back();
              std::cout << v.size() << std::endl;

              }*/


  /*     exercise 13: inserting at arbitrary positions*/
               //{
               //std::vector<TestClass<0>> v;
               //v.reserve(4);
               //TestClass<0> a(1, 2);
               //TestClass<0> b(3, 4);
               //TestClass<0> c(5, 6);
               //TestClass<0> d(7, 8);

               //v.push_back(a);// begin()
               //v.push_back(b);// begin+1
               //v.push_back(c);//begin+2
               //auto itr=v.insert(v.begin()+1,d);
               //std::cout << "listing elements\n";
               //for (auto i = v.begin(); i != v.end(); ++i) {
               //    if (i == itr)std::cout << "element inserted here: ";
               //    std::cout << i->x() << "," << i->y() << std::endl;

               //}
               //}

  /*  exercise 14: deleting at arbitrary positions*/

               //{
               //std::vector<TestClass<0>> v(5);
               //TestClass<0> a(1, 2);
               //TestClass<0> b(3, 4);
               //v[0] = a;
               //v[1] = b;
               //std::cout << "size= " << v.size() << std::endl;
               //std::cout << "----------------\n";
               //v.erase(v.begin());
               //std::cout << "-------done----\n";
               //}

    /* exercise 15: deleting certain values from a vector */
            /* {
             std::vector<TestClass<0>> v;
             v.reserve(4);
             TestClass<0> a(1, 2);
             TestClass<0> b(3, 4);
             TestClass<0> c(5, 2);
             TestClass<0> d(5, 6);
             v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
             std::cout << "---searching--\n";
             for (auto itr = v.begin(); itr != v.end();) {
                 if (itr->y() == 2) {
                     itr=v.erase(itr);
                 }
                 else itr++;
             }
             std::cout << "----done searching\n";
               }

    //exercise 16: using the more efficient remove/erase idiom
             {
                 std::vector<TestClass<0>> v;
                 v.reserve(4);
                 TestClass<0> a(1, 2);
                 TestClass<0> b(3, 4);
                 TestClass<0> c(5, 2);
                 TestClass<0> d(5, 6);
                 v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
                 std::cout << "---searching--\n";
                 auto itr=std::remove_if(v.begin(), v.end(), [](auto& t) { return t.y() == 2; });
                 v.erase(itr, v.end());
                 std::cout << "----done searching\n";
             }*/


                /* {
                 std::vector<TestClass<1>> u;
                 u.reserve(4);
                 u.emplace_back(1, 2); u.emplace_back(3, 4); u.emplace_back(5, 2); u.emplace_back(5, 6);
                 std::vector<TestClass<1>> v;
                 v.resize(u.size());
                 std::transform(u.begin(), u.end(), v.begin(), [](auto& t) {
                     int tmp = t.x();
                     t.x() = t.y();
                     t.y() = tmp;
                     return t; }
                     );
                 for (auto& a : v)
                     std::cout << a.x() << "," << a.y() << std::endl;
                 }*/

                 /* {
                  int n = 20;
                  std::random_device e;
                  std::uniform_int_distribution<> dist(1, 10);
                  std::vector<int> v;
                  v.resize(n);
                  std::generate(v.begin(), v.end(), [&]() {return  dist(e); });
                  for (auto& x : v)
                      std::cout << x << ",";
                  int m = dist(e);
                  std::cout << "\n The number of " << m << " is " << std::count(v.begin(), v.end(), m);
                  }*/

                  /*{
                      int n = 20;
                      std::random_device e;
                      std::uniform_int_distribution<> dist(1, 10);
                      std::vector<int> v;
                      v.resize(n);
                      std::generate(v.begin(), v.end(), [&]() {return  dist(e); });
                      for (auto& x : v)
                          std::cout << x << ",";
                      int m = dist(e);
                      std::cout << "\n The # evens is  "
                          << std::count_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; })<<std::endl;
                      std::cout << "min element is " << *std::min_element(v.begin(), v.end())<<std::endl;
                      std::cout << "max element is " << *std::max_element(v.begin(), v.end())<<std::endl;


                  }*/
                  /* {
                   std::vector<int> v;
                   std::back_insert_iterator itr(v);
                   *itr = 1;
                   *itr = 2;
                   *itr = 3;
                   for (auto& x : v)
                       std::cout << x << ",";
                   std::cout << std::endl;
                   }*/

                   /*{
                       int n = 20;
                       std::random_device e;
                       std::uniform_int_distribution<> dist(1, 10);
                       std::vector<int> v;
                       v.resize(n);
                       std::generate(v.begin(), v.end(), [&]() {return  dist(e); });
                       std::vector<int> d;
                       std::copy_if(v.begin(), v.end(), std::back_insert_iterator(d),
                           [](int i) { return i % 2 ==0; });
                       for(auto& x:d)
                           std::cout << x << ",";
                       std::cout << std::endl;
                   }*/

                   /*{
                   int n = 20;
                   std::random_device e;
                   std::uniform_int_distribution<> dist(1, 10);
                   std::vector<int> v;
                   v.resize(n);
                   std::generate(v.begin(), v.end(), [&]() {return  dist(e); });
                   std::vector<int> d;
                   d.resize(n);
                   std::copy_if(std::execution::par,v.begin(), v.end(), d.begin(),
                       [](int i) { return i % 2 == 0; });
                   for (auto& x : d)
                       std::cout << x << ",";
                   std::cout << std::endl;
                      }*/

				/*  {
					vector<int> v;
					v.push_back(1); v.push_back(2); v.push_back(3);
					for (int i = 0; i < v.size(); i++)
						std::cout << v[i] << ",";
					std::cout << std::endl;
					std::cout << "----------------\n";
					vector<int>::iterator itr;
					for (itr = v.begin(); itr != v.end(); ++itr)
						std::cout << *itr << ",";
					std::cout << std::endl;
					vector<TestClass<0>> t;
					t.push_back(TestClass<0>(1, 2));
					vector<TestClass<0>>::iterator j = t.begin();
					std::cout << j->x() << std::endl;
                        }*/

    /*{
    std::random_device e;
    std::uniform_int_distribution<> dist(1, 10);
    const int n = 10;
    std::vector<int> v(n);
    std::generate(v.begin(), v.end(), [&]() {return dist(e); });
    for (auto& x : v)
        std::cout << x << ",";
    std::cout << std::endl;
    std::vector<int>::iterator  pivot = std::partition(v.begin(), v.end(), [](int n) {return n % 2 == 0; });
    const int odd = std::accumulate(v.begin(), pivot,0);
    const int even = std::accumulate(pivot, v.end(),0);
    std::cout << "even sum = " << odd << std::endl;
    std::cout << "odd sum= " << even << std::endl;
    
    }*/

    //{
    //    std::random_device e;
    //    std::uniform_int_distribution<> dist(1, 10);
    //    const int n = 10;
    //    std::vector<int> v(n);
    //    std::generate(v.begin(), v.end(), [&]() {return dist(e); });
    //    for (auto& x : v)
    //        std::cout << x << ",";
    //    std::cout << std::endl;
    //   // 1,2,3,4,5,6
    //    const auto result = std::accumulate(v.begin(), v.end(), std::make_pair(0, 0),
    //        [](std::pair<int,int> sum,int n) {
    //            n % 2 == 1?sum.first += n:sum.second += n;
    //            return sum;
    //        });
    //    auto [x, y] = result;
    //    std::cout << x << "," << y << std::endl;

    //}


    //{
    //    std::string s{ "    " };
    //    std::vector<std::string> vs{ "hi","  ","there","hello","  ","welcome","  ","end"};
    //    auto filter = [](auto c) {return c == ' ' ? true : false; };
    //    auto res = [&](auto& x) {return std::find_if_not(x.begin(), x.end(), filter); };
    //    /*if (res(s) == s.end()) {
    //        std::cout <<"("<< s <<")"<< std::endl;
    //    }*/
    //    for (auto& c : vs)
    //        std::cout << c << ",";
    //    std::cout << std::endl;
    //    std::remove_if(vs.begin(), vs.end(), [&](auto& is) { return res(is)== is.end(); });
    //  
    //    for (auto& c : vs)
    //        std::cout << c << ",";
    //    std::cout<<std::endl;
    //}


   /* {
    std::vector<int>  v{ 7,2,3,8,19,23,4,2,2,2,4,44,54,2,8,95,2,27 };
   
    v.erase(std::remove_if(v.begin(), v.end(), check{ 7 }), v.end());
    for (auto x : v)
        std::cout << x << ",";
    std::cout << std::endl;

    }*/

  /*  {
    std::vector<int>  v{ 7,2,3 };
    int res = std::accumulate(v.begin(), v.end(),0);

    std::cout << res << std::endl;
    }*/

    /*{vector v;
    v.push_back(1);
    v.push_back(2);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << ",";
    std::cout << std::endl;
    }*/

  /*  {
    std::vector<int > v{ 1,2,3,4 ,5,4,2,6,1};
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::cout << "size= " << v.size() << std::endl;
    for (auto& x : v)
        std::cout << x << ",";
    std::cout << std::endl;
    }*/

    //{
    //    const int n = 10;
    //    std::random_device e;
    //    std::uniform_int_distribution<> dist(1, 20);
    //    ::vector<int> v(10);
    //    std::generate(v.begin(), v.end(), [&]() {return dist(e); });
    //    //v.insert(v.begin() + 2, 6);
    //    for (auto itr = v.begin(); itr != v.end(); ++itr)
    //        std::cout << *itr << ",";
    //    std::cout << std::endl;
    //   
    //    ::vector<int> d;
    //    std::copy_if(v.begin(), v.end(), std::back_insert_iterator(d),
    //        [](int i) { return i % 2 == 0; });

    //    for (auto itr = d.begin(); itr != d.end(); ++itr)
    //        std::cout << *itr<<",";
    //}

    //{
    //    ::vector<TestClass<0>> v;
    //    v.push_back(TestClass<0>(1, 2));
    //    for (auto itr = v.begin(); itr != v.end(); itr++)
    //        std::cout << itr->x() << std::endl;
    //   // v.begin();
    //}
   /* {
    std::vector<TestClass<0>> u;
    u.push_back(TestClass<0>(1, 2)); u.push_back(TestClass<0>(3, 4));
    u.insert(u.begin(), TestClass<0>(5, 6));
    std::cout << "----list------\n";*/
    /*std::list<TestClass<0>> v;
    v.push_back(TestClass<0>(1, 2)); v.push_back(TestClass<0>(3, 4));
    v.insert(v.begin(), TestClass<0>(5, 6));


    }*/
   /* {
    
        ::vector<int> u,v,t;
        u.push_back(1); u.push_back(2); u.push_back(3);
        t=v = u;
        ::vector<int> w = v;
        u[0] = 11;
        for (auto& x : v)
            std::cout << x << ",";
        std::cout << std::endl;
        for (auto& x : w)
            std::cout << x << ",";
        std::cout << std::endl;
        std::cout << "done\n";

    }*/
    {

      /*  ::vector<TestClass<0>> v;
        v.push_back(TestClass<0>(3, 4));
        v.emplace_back(1, 2);
        v.push_back(TestClass<0>(5, 6));
        v.emplace_back(7, 8);
        v.emplace_back(9, 10);
        v.emplace_back(11, 12);
        v.emplace_back(13, 14);*/
        //::vector<TestClass<0>> u(5);
       std::vector<TestClass<0>> u,v;

        u.emplace_back(1, 2);

        u.emplace_back(3, 4);
        u.emplace_back(5, 6);
        u.emplace_back(7, 8);
        u.emplace_back(9, 10);
        v = u;
        std::cout << "----------\n";
        //std::vector<TestClass<0>> v = u;

        //std::vector<TestClass<0>> v(5);

        /*std::vector<TestClass<0>> u;
        u.push_back(TestClass<0>(3, 4));
        u.emplace_back(1, 2);
        u.push_back(TestClass<0>(5, 6));
        u.emplace_back(7, 8);
        std::cout << "\n-------------\n";*/
        /*::vector<TestClass<0>>::iterator itr;
        for (itr = v.begin(); itr != v.end(); ++itr)
            std::cout << itr->x() <<","<<itr->y()<< std::endl;*/
       /* for (auto&&  e : v) {
            std::cout << e.x() << ","<<e.y()<<std::endl;
        }*/
    }
    std::cout << "\n-------------------\n";
    return 0;
}
