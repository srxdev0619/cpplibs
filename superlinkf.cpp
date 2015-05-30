#include<iostream>
#include<new>
#include<cstdlib>
#include"linkedlist.h"
#define GOOD 31001
#define BAD -31001

using namespace std;

void insert(node** start, int number, int index);
void insertsort(node** start, int number);
int treverse(node** start);
void sortll(node** start,int length);
int partition(node** start, int pivot, int length);
int getelement(node** start,int index);
int remove(node** start, int index);
int length(node** start);
node* getptr(node** start, int index);
node* getptr1(node** start,int index);

node* first = NULL;


void insert(node** start,int number, int index)
{
  if((number >= GOOD) || (number <= BAD))
  {
    return;
  }
  if((*start) == NULL)
    {
      node* temp = new node;
      temp->next = NULL;
      temp->n = number; 
      (*start) = temp;
      return;
    }
  else if(index < 0)
    {
      node* temp = new node;
      node* nptr = (*start);
      node* pptr = NULL;
      while(nptr != NULL)
	{
	  pptr = nptr;
	  nptr = nptr->next;
	}
      temp->n = number;
      temp->next = NULL;
      pptr->next = temp;
    }
  else
    {
      node* temp = new node;
      node* nptr = (*start);
      node* pptr = NULL;
      node* ptptr = NULL;
      int counter = 0;
      while( nptr != NULL)
	{
	  ptptr = pptr;
	  pptr = nptr;
	  nptr = nptr->next;
	  if (counter == index)
	    {
	      if(ptptr == NULL)
		{
		  node* temp = new node;
		  temp->n = number;
		  temp->next = (*start);
		  (*start) = temp;
		}
	      else
		{
		  node* temp = new node;
		  temp->n = number;
		  temp->next = pptr;
		  ptptr->next = temp;
		}
	      return;
		
	    }
	  counter++;
	}
      temp->next = NULL;
      temp->n = number;
      pptr->next = temp;
      return;
    }
}

void insertsort(node** start, int number)
{
  if( (number >= GOOD) || (number <= BAD))
    {
      return;
    }
  if((*start) == NULL)
    {
      node* temp = new node;
      temp->next = NULL;
      temp->n = number;
      (*start) = temp;
      return;
    }
  else
    {
      node* temp = new node;
      node* nptr = (*start);
      node* pptr = NULL;
      node* ptptr = NULL;
      while(nptr != NULL)
	{
	  ptptr = pptr;
	  pptr = nptr;
	  if ((pptr->n) > number)
	    {
	      if (ptptr == NULL)
		{
		  temp->n = number;
		  temp->next = pptr;
		  (*start) = temp;
		  return;
		}
	      else
		{
		  temp->n = number;
		  temp->next = pptr;
		  ptptr->next = temp;
		  return;
		}
	      
	    }
	  nptr = nptr->next;
	}
       temp->n = number;
       temp->next = NULL;
       pptr->next = temp;
       return;
    }
}

int treverse(node** start)
{
  if((*start) == NULL)
    {
      cout<<"List is empty!";
      return 1;
    }
  else
    {
      node* nptr = (*start);
      node* pptr = NULL;
      while(nptr != NULL)
	{
	  pptr = nptr;
	  cout<<pptr->n<<"-";
	  nptr = nptr->next;
	}
    }
  return 0;
}

////////////////////////////////////////////////////////////////////////

int remove(node** start, int index)
{
  if((*start) == NULL)
    {
      return BAD;
    }
  else
    {
      int ind = 0;
      node* nptr = (*start);
      node* pptr = NULL;
      node* cptr = NULL;
      while(nptr != NULL)
	{
	  cptr = pptr;
	  pptr = nptr;
	  nptr = nptr->next;
	  if(ind == index)
	    {
	      if(cptr == NULL)
		{
		  int temp = pptr->n;
		  (*start) = pptr->next;
		  return temp;
		}
	      else
		{
		  int temp = pptr->n;
		  cptr->next = pptr->next;
		  return temp;
		}
	    }
	  ind++;
	}
      
    }
}

int partition(node** start, int pivot, int length)
{
  if((*start) == NULL)
    {
      return BAD;
    }
  else
    {
      int npivot = getelement(start,pivot);
      int ppivot = pivot;
      int i =0;
      while ( i < length)
	{
	  int temp = getelement(start,i);
	  if((temp > npivot) && (i < pivot))
	    {
	      remove(start,i);
	      pivot = pivot - 1;
	      insert(start,temp,pivot+1);
	    }
	  else if((temp <= npivot) && (i > pivot))
	    {
	      remove(start,i);
	      if(pivot == 0)
		{
		  insert(start,temp,0);
		}
	      else
		{
		  insert(start,temp,pivot-1);
		}
	      pivot = pivot + 1;
	    }
	  else
	    {
	      i++;
	    }
	}
      return pivot;
    }
}

void sortll(node** start,int length)
{
  if((*start) == NULL)
    {
      return;
    }
  else if(length == 1 || length <= 0)
    {
      return;
    }
  else
    {
      int lent = length;
      if (lent == 1 || lent == 0)
	{
	  return;
	}
      else
	{
	  int pivot = rand()%lent;
	  pivot = partition(start,pivot,length);
	  int lent1 = length - pivot -1;
	  node* temp = getptr(start,pivot);
	  node* temp1 = getptr1(start,pivot);
	  sortll(start,pivot);
	  sortll(&temp,lent1);
	  temp1->next = temp;
	}
    }
}

int length(node** start)
{
  if((*start) == NULL)
    {
      return 0;
    }
  else
    {
      int n = 0;
      node* nptr= (*start);
      node* pptr = NULL;
      while(nptr != NULL)
	{
	  pptr = nptr;
	  nptr = nptr->next;
	  n++;
	}
      return n;
    }
}

int getelement(node** start, int index)
{
  if((*start) == NULL)
    {
      cout<<"The list is empty\n";
      return BAD;
    }
  else
    {
      node* nptr = (*start);
      node* pptr  = NULL;
      int ind = 0;
      while(nptr != NULL)
	{
	  pptr = nptr;
	  nptr = nptr->next;
	  if(ind == index)
	    {
	      return pptr->n;
	    }
	  ind++;
	}
      return BAD;
    }
}

node* getptr(node** start, int index)
{
  if((*start) == NULL)
    {
      cout<<"The list is empty\n";
      return NULL;
    }
  else
    {
      node* nptr = (*start);
      node* pptr  = NULL;
      int ind = 0;
      while(nptr != NULL)
	{
	  pptr = nptr;
	  nptr = nptr->next;
	  if(ind == index)
	    {
	      return pptr->next;
	    }
	  ind++;
	}
      return NULL;
    }
}

node* getptr1(node** start, int index)
{
  if((*start) == NULL)
    {
      cout<<"The list is empty\n";
      return NULL;
    }
  else
    {
      node* nptr = (*start);
      node* pptr  = NULL;
      node* cptr = NULL;
      int ind = 0;
      while(nptr != NULL)
	{
	  cptr = pptr;
	  pptr = nptr;
	  nptr = nptr->next;
	  if(ind == index)
	    {
	      if(ind == 0)
		{
		  return (*start);
		}
	      else
		{
		  return cptr->next;
		}
	    }
	  ind++;
	}
      return NULL;
    }
}




