#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>

int main(){

  std::cout << std::endl;

  long long home = 497074123456;
  long long mobile = 4916046123356;

  // constructor
  std::unordered_multimap<std::string, long long> multiMap{{"grimm", home}, {"grimm", mobile}, {"jaud-grimm", home}};
  std::unordered_map<std::string, int> uniqMap{{"bin", 1}, {"root", 0}, {"nobody", 65834}, {"rainer", 1000}};

  // ctor - set and unordered_set=======================================================
  std::unordered_multiset<std::string> multiset{"grimm", "grimm", "jaud-grimm"};
  std::unordered_set<std::string> uniqSet{"bin", "root", "nobody", "rainer"};

  // show the unordered maps
  std::cout << "multiMap: ";
  for(auto m : multiMap) std::cout << '{' << m.first << ", " << m.second << '}';

  std::cout << std::endl;

  std::cout << "uniqMap: ";
  for(auto u : uniqMap) std::cout << '{' << u.first << ", " << u.second << '}';
  std::cout << std::endl;

  std::cout << std::endl;

  // show the unordered sets=========================================================
  std::cout << "multiset: ";
  for (auto m : multiset) std::cout << '{' << m << '}';
  std::cout << std::endl;
  
  std::cout << "uniqMap: ";
  for(auto u : uniqSet) std::cout << '{' << u << '}';
  std::cout << std::endl;

  // insert elements
  long long work = 4970719754513;

  multiMap.insert({"grimm", work});
  // will not work, std::multi_map does not have operator [] or at method
  // multiMap["grimm-jaud"]=491601232;

  uniqMap["lp"] = 4;
  uniqMap.insert({"sshd", 71});

  std::map<std::string, int> myMap{{"ftp", 40}, {"rainer", 999}};
  uniqMap.insert(myMap.begin(), myMap.end());

  // insert elements for sets============================================================
  multiset.insert("abcdefg");
  uniqSet.insert("dfghjkl");

  std::set<std::string> mySet{"ftp", "rainer"};
  uniqSet.insert(mySet.begin(), mySet.end());

  // show the unordered maps
  std::cout << "multiMap: ";
  for(auto m : multiMap) std::cout << '{' << m.first << ", " << m.second << '}';

  std::cout << std::endl;

  std::cout << "uniqMap: ";
  for(auto u : uniqMap) std::cout << '{' << u.first << ", " << u.second << '}';
  std::cout << std::endl;

  std::cout << std::endl;

  // show the unordered sets================================================================
  std::cout << "multiset: ";
  for (auto m : multiset) std::cout << '{' << m << '}';
  std::cout << std::endl;
  
  std::cout << "uniqMap: ";
  for(auto u : uniqSet) std::cout << '{' << u << '}';
  std::cout << std::endl;

  // search for elements

  // only grimm
  auto iter = multiMap.equal_range("grimm");
  std::cout << "grimm: ";
  for(auto itVal = iter.first; itVal != iter.second;++itVal){
    std::cout << itVal->second << " ";
  }

  std::cout << std::endl;

  std::cout << "multiMap.count(grimm): " << multiMap.count("grimm") << std::endl;

  auto it= uniqMap.find("root");
  if (it != uniqMap.end()){
    std::cout << "uniqMap.find(root): " << it->second << std::endl;
    std::cout << "uniqMap[root]: " << uniqMap["root"] << std::endl;
  }

  // search for elements, unordered_sets=================================================
  auto mset_iter = multiset.equal_range("grimm");
  std::cout << "grimm in multiset: ";
  for(auto it = mset_iter.first; it != mset_iter.second; it++)
  {
    std::cout << *it << "\n";
  }

  auto uset_iter = uniqSet.find("root");
  if (uset_iter != uniqSet.end()){
    std::cout << "uniqSet.find(root): " << *uset_iter << std::endl;
  }

  // will create a new entry
  std::cout << "uniqMap[notAvailable]: " << uniqMap["notAvailable"] << std::endl;

  std::cout << std::endl;

  // remove
  int numMulti= multiMap.erase("grimm");
  int numUniq= uniqMap.erase("rainer");

  std::cout << "Erased " << numMulti << " times grimm from multiMap." << std::endl;
  std::cout << "Erased " << numUniq << " times rainer from uniqMap." << std::endl;

  // remove sets ======================================================================
  int numMutiSet = multiset.erase("grimm");
  int numUniqSet = uniqSet.erase("rainer");

  std::cout << "Erased " << numMutiSet << " times grimm from multiset." << std::endl;
  std::cout << "Erased " << numUniqSet << " times rainer from uniqSet." << std::endl;

  // all
  multiMap.clear();
  uniqMap.clear();

  std::cout << std::endl;

  std::cout << "multiMap.size(): " << multiMap.size() << std::endl;
  std::cout << "uniqMap.size(): " << uniqMap.size() << std::endl;

  std::cout << std::endl;
}