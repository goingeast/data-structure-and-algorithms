#include<iostream>
#include<string>

using namespace std;


string strCompress(string str){
  int size = str.size();
  if( size == 0 )
    return "";
  int fast = 0;
  int slow = -1;
  int i = 0;
  while(i < size){
    while(fast < size && (str[fast] == str[i])){
      ++fast;
    }
    int count = fast - i;
    if(count == 1){
      str[++slow] = str[i];
      ++i;
      continue;
    }else{
      string countstr =std::to_string(count);
      str[++slow] = str[i];
      for(int j=0; j <countstr.size();++j){
        str[++slow] = countstr[j];
      }
    }
    i = fast;
  }
  str.resize(slow+1);
  return str;
}

int main(){

  cout << strCompress("a") << endl;
  cout << strCompress("aa") << endl;
  cout << strCompress("aaa") << endl;
  cout << strCompress("aaab") << endl;
  cout << strCompress("aaaaaaaaaaaaabbsszzzzddddd") << endl;

}
