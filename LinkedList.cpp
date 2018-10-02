// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "pch.h"
#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL), listsize(0), listsum(0)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
	listsize = other.listsize;
	listsum = other.listsum;
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}
	this->listsize = other.listsize;
	this->listsum = other.listsum;

	return *this;
}

bool List::operator==(const List &rhs){
    if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->first_;
    Node * rptr = rhs.first_;
		double lEntry = lptr->entry_;
    double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}

  return true;
}



bool List::empty() const
{
	return first_ == NULL;
}

int List::size() const
{
	return listsize;
}

double List::sum()
{
	return listsum;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
	listsize+=1;
	listsum += x;
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	listsize--;
	listsum -= item;
	return item;
}

void List::instertAsLast(double x)
{
	if (!empty())
	{
		Node * temp = first_->next_;
		while (temp->next_ != NULL)
		{
			temp = temp->next_;
		}
		temp->next_ = new Node(x);
	}
	else if (empty())
	{

	}
	listsum += x;
	listsize++;

}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


// Recursive version of clone.
// This version handles two cases, a linked structure with
//   no Nodes, and a linked structure with one or more
//   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
