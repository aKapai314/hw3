#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  T const & at(int idx);



private:
  /// Add whatever helper functions and data members you need below
	//void trickleDown();
	//void trickleUp();
	int findBestChildLoc(size_t idx);
	void heapify(size_t idx);
	std::vector<T> data;
	PComparator comp;
	int m_;
};

// HEAP AT FUNCTION
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::at(int idx)
{
  return data.at(idx);
}



// HEAP CONSTRUCTOR
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
	m_ = m;
	comp = c;
}


// HEAP DESTRUCTOR
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
	//delete dynamically allocated stuff if any
}


// PUSH FUNCTION
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
    size_t index = data.size() - 1;
    while (index != 0) {
        size_t parent_index = (index - 1) / m_;
        T& current = data[index];
        T& parent = data[parent_index];
        if (!comp(current, parent)) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
}
}

// TOP FUNCTION
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty())
	{
    throw std::underflow_error("List is empty");
		//return;
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	else
	{
		return data.at(0);
	}
}




// POP FUNCTION
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
	{
    throw std::underflow_error("List is empty");
		return;
  }
	else
	{
		T& best = data[0];
    T& worst = data[data.size() - 1];
    std::swap(best, worst);
    //remove last node
    data.pop_back();
		heapify(0); 
	}

}


// HEAPIFY
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx)
{
if(m_*idx + 1 >= data.size()) 
    return;

size_t start = m_*idx + 1;
size_t bestChildLoc = findBestChildLoc(start);

if(comp(data[bestChildLoc], data[idx])){
    std::swap(data[idx], data[bestChildLoc]);
    heapify(bestChildLoc);
}

}


// FIND BEST CHILD LOC
template <typename T, typename PComparator>
int Heap<T,PComparator>::findBestChildLoc(size_t idx)
{
	T bestChild = data.at(idx);
	size_t bestChildIdx = idx;
	size_t last;

	if(idx + m_ > data.size())
		last = data.size();
	else
		last = idx + m_;

	for(size_t i = idx; i < last; i++)
	{
		if(comp(data.at(i), bestChild))
		{
			bestChild = data.at(i);
			bestChildIdx = i;
		}
			
	}

	return bestChildIdx;

}


// EMPTY 
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return (size() == 0);
}



// SIZE
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}


#endif

