#include <iostream>
#include <assert.h>
using namespace std;


template <class K>
class Heap
{
public:
	Heap(int capacity)
		:_size(0)
		,_data(new K[capacity])
		,_capacity(capacity)
	{
		memset(_data,0,sizeof(K)*capacity);
		for(int i = (_capacity-2)/2; i >= 0;i--){
			AdjustDown(i);
		}
	}

	Heap(int *a,int capacity)
		:_size(0)
		,_data(new K[capacity])
		,_capacity(capacity)
	{
		for(size_t i = 0; i < capacity;i++){
			_data[i] = a[i];
		}	
		for(int i = (_capacity-2)/2; i >= 0;i--){
			AdjustDown(i);
		}
	}
	
	void Insert(int key){
		_data[_capacity] = key;
		AdjustUp(_capacity++);	
	}

	void Delete(){
		swap(_data[0],_data[--_capacity]);
		AdjustDown(0);
	}

	void AdjustUp(int child){
		if(child > _capacity){
			cout<<"child value wrong"<<endl;
			return;
		}

		int parent = (child-1)/2;
		while(parent >= 0){
			if(child + 1 < _capacity && _data[child+1] < _data[child])
				child++;
			if(_data[parent] > _data[child]){
				swap(_data[parent],_data[child]);
				child = parent;
				parent = (child - 1)/2;	
			}
			else 
				break;
		}
	}

	void AdjustDown(int parent){
		if(parent > _capacity){
			cout<<"parent value wrong"<<endl;
			return;
		}

		int child = parent*2+1;

		while(child < _capacity){
			if(child+1 < _capacity && _data[child+1] < _data[child])
				child++;

			if(_data[parent] > _data[child]){
				swap(_data[child],_data[parent]);
				parent = child;
				child = parent*2 + 1;
			}
			else 
				break;
		}
	}

	void InOrderHeap(){
		for(int i = 0;i < _capacity;i++){
			cout<<_data[i]<<" ";	
		}
		cout<<endl;
	}
protected:
	K* _data;
	size_t _size;
	size_t _capacity;	
};


int main()
{
	int a[] = {8,5,10,9,6,3,7,4,1};
	Heap<int> hp(a,sizeof(a)/sizeof(a[0]));	
	hp.InOrderHeap();
	hp.Insert(2);
	hp.InOrderHeap();
	hp.Delete();
	hp.InOrderHeap();
	
	return 0;		
}
















