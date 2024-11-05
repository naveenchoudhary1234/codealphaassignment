#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
  
  //creation
  unordered_map<string,int> mapping;

  ///insertion
  pair<string, int> p = make_pair("love", 25);

  pair<string,int> q("dipansh",24);

  pair<string,int> r;
  q.first = "arun";
  q.second = 21;
  //insertion 
  mapping.insert(p);
  mapping.insert(q);
  mapping.insert(r);
  //insert
  mapping["babbar"] = 51;

  cout << "Size of map: " << mapping.size() << endl; 
  //ACCESS 
  cout << mapping.at("love") << endl;
  cout << mapping["love"] << endl;

  //searching
  cout << mapping.count("lover") << endl;
  cout << "Size of map: " << mapping.size() << endl; 

  if(mapping.find("babbar") != mapping.end() ) {
    cout << "Found" << endl;
  }
  else {
    cout << "Not Found" << endl;
  }
   cout << "Size of map: " << mapping.size() << endl; 
   cout << mapping["kumar"] << endl;
   cout << "Size of map: " << mapping.size() << endl;
  return 0;
}
#include <iostream>
#include<unordered_map>
using namespace std;

void countCharacters(unordered_map<char,int> &mapping, string str) {
  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    mapping[ch]++;
  }
}

int main() {
  string str = "lovebbabbar";
  unordered_map<char,int> mapping;
  countCharacters(mapping,str);

  for(auto i: mapping) {
    cout << i.first << " -> " <<i.second << endl;
  }

  return 0;
}