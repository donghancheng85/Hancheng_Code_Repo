// hashInfo.cpp 
#include <iostream>
#include <unordered_set>
using namespace std;

void getInfo(const unordered_set<int>& hash){
  cout << "hash.bucket_count(): " << hash.bucket_count();
  cout << "hash.load_factor(): " << hash.load_factor();
}

int main(){

  // Create an unoredered set and initialize it with the array
	// Set will contain only random elements
  int arr[100];
  for(int i=0; i<100; i++)
    arr[i] = (rand() % 100) + 1; 
  unordered_set<int> hash(arr, arr + sizeof(arr) / sizeof(int));
  cout << "hash.max_load_factor():\t" << hash.max_load_factor() << endl; // hash.max_load_factor():	1

  getInfo(hash);
  //hash.bucket_count(): 103hash.load_factor(): 0.660194
  cout<<endl;

  hash.insert(500);
  cout << "hash.bucket(500):\t" << hash.bucket(500) << endl; // 88

  getInfo(hash);
  cout<<endl;
  //hash.bucket_count(): 103hash.load_factor(): 0.669903

  hash.rehash(500);

  getInfo(hash);
  //hash.bucket_count(): 503hash.load_factor(): 0.137177500
  
  cout << endl << "hash.bucket(500):\t" << hash.bucket(500); //hash.bucket(500):	500

  return 0;
}