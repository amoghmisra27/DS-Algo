#include<iostream> 
using namespace std; 
struct Boxes 
{ 
	int left; 
	int ht;  
	int right;  
}; 

class Strip 
{ 
	int left; 
	int ht; 
public: 
	Strip(int l=0, int h=0) 
	{ 
		left = l; 
		ht = h; 
	} 
	friend class Crates; 
}; 
class Crates 
{ 
	Strip *arr; 
	int capacity; 
	int n;
public: 
	~Crates() { delete[] arr; } 
	int count() { return n; } 
	Crates* Merge(Crates *other); 
	Crates(int cap) 
	{ 
		capacity = cap; 
		arr = new Strip[cap]; 
		n = 0; 
	} 
	void append(Strip *st) 
	{ 
		if (n>0 && arr[n-1].ht == st->ht) 
			return; 
		if (n>0 && arr[n-1].left == st->left) 
		{ 
			arr[n-1].ht = max(arr[n-1].ht, st->ht); 
			return; 
		} 

		arr[n] = *st; 
		n++; 
	} 
	void print() 
	{ 
		for (int i=0; i<n; i++) 
		{ 
			cout << " (" << arr[i].left << ", "
				<< arr[i].ht << "), "; 
		} 
	} 
}; 

Crates *findCrates(Boxes arr[], int l, int h) 
{ 
	if (l == h) 
	{ 
		Crates *res = new Crates(2); 
		res->append(new Strip(arr[l].left, arr[l].ht)); 
		res->append(new Strip(arr[l].right, 0)); 
		return res; 
	} 

	int mid = (l + h)/2; 
	Crates *sl = findCrates(arr, l, mid); 
	Crates *sr = findCrates(arr, mid+1, h); 
	Crates *res = sl->Merge(sr); 
	delete sl; 
	delete sr; 
	return res; 
} 

Crates *Crates::Merge(Crates *other) 
{ 
	
	Crates *res = new Crates(this->n + other->n); 

	
	int h1 = 0, h2 = 0;  
	int i = 0, j = 0; 
	while (i < this->n && j < other->n) 
	{ 
	
		if (this->arr[i].left < other->arr[j].left) 
		{ 
			int x1 = this->arr[i].left; 
			h1 = this->arr[i].ht; 
			int maxh = max(h1, h2); 

			res->append(new Strip(x1, maxh)); 
			i++; 
		} 
		else
		{ 
			int x2 = other->arr[j].left; 
			h2 = other->arr[j].ht; 
			int maxh = max(h1, h2); 
			res->append(new Strip(x2, maxh)); 
			j++; 
		} 
	} 
	while (i < this->n) 
	{ 
		res->append(&arr[i]); 
		i++; 
	} 
	while (j < other->n) 
	{ 
		res->append(&other->arr[j]); 
		j++; 
	} 
	return res; 
} 

// drive program 
int main() 
{ 
	Boxes arr[] = {{1, 11, 5}, {2, 6, 7}, {3, 13, 9}, 
					{12, 7, 16}, {14, 3, 25}, {19, 18, 22}, 
					{23, 13, 29}, {24, 4, 28}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	Crates *ptr = findCrates(arr, 0, n-1); 
	cout << " Crates Viewed as \n"; 
	ptr->print(); 
    cout<<endl;
	return 0; 
} 
