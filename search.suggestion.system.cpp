#include<iostream> 
#include<vector>
#include<algorithm> 
#include<string> 

using namespace std; 

class TrieNode{
public: 
     TrieNode* children[26]={nullptr}; 
     vector<string> suggestions; 
};
class Solution{
private: 
    TrieNode* root; 
    void insert(string word){
      TrieNode* node = root; 
      for(char c:word){
        int i = c-'a'; 
        if(!node->children[i]) node->children[i]= new TrieNode(); 
        node = node->children[i]; 
        if(node->suggestions.size()<3) node->suggestions.push_back(word); 
      }   
    } 
public: 
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      root = new TrieNode(); 
      sort(products.begin(),products.end()); 
      for(string& word:products){
        insert(word); 
      }
      vector<vector<string>> res; 
      TrieNode* node = root; 
      for(char c:searchWord){
        if(node) node = node->children[c-'a']; 
        if(node) res.push_back(node->suggestions); 
        else res.push_back({}); 
      }
      return res; 
      
    }
};
int main(){
  vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
  string searchWord = "mouse"; 
  Solution sol; 
  vector<vector<string>> res = sol.suggestedProducts(products, searchWord); 
  for(auto vec:res){
    cout << "[" ; 
    for(string& word:vec){
      cout << word << "," ; 
    }
    cout << "]" <<endl; 
  }
  return 0; 
}
