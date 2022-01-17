// // { Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

//  // } Driver Code Ends
// // User function Template for C++

// class Solution{
// public:
//     struct TrieNode{
//     	unordered_map<char,TrieNode*> child;
//     	bool isLast;
//     	TrieNode(){
//     		for (char i = 'a'; i <= 'z'; i++)
//     			child[i] = NULL;
//     		isLast = false;
//     	}
//     };
//     TrieNode *root = NULL;
    
//     void insert(string s){
//     	int len = s.length();
//     	TrieNode *itr = root;
//     	for (int i = 0; i < len; i++){
//     		TrieNode *nextNode = itr->child[s[i]];
//     		if (nextNode == NULL){
//     			nextNode = new TrieNode();
//     			itr->child[s[i]] = nextNode;
//     		}
//     		itr = nextNode;
//     		if (i == len - 1)
//     			itr->isLast = true;
//     	}
//     }
    
//     void insertIntoTrie(string s[],int n){
//     	root = new TrieNode();
//     	for (int i = 0; i < n; i++)
//     		insert(s[i]);
//     }
    
//     void displayContactsUtil(TrieNode *curNode, string prefix, 
//                             vector<string> &vec){
//     	if (curNode->isLast)
//     		    vec.push_back(prefix);
//     	for (char i = 'a'; i <= 'z'; i++){
//     		TrieNode *nextNode = curNode->child[i];
//     		if (nextNode != NULL)
//     			displayContactsUtil(nextNode, prefix + (char)i, vec);
//     	}
//     }
    
//     vector<vector<string>> displayContacts(int n, string contact[], string s)
//     {
//     	insertIntoTrie(contact, n);
//     	TrieNode *prevNode = root;
//         vector<vector<string>> res;
//     	string prefix = "";
//     	int len = s.length();
//     	int i;
//     	for (i = 0; i < len; i++){
//     		vector<string> v;
//     		prefix += (char)s[i];
//     		char lastChar = prefix[i];
//     		TrieNode *curNode = prevNode->child[lastChar];
//     		if (curNode == NULL){
//     			v.push_back("0");
//     			res.push_back(v);
//     			i++;
//     			break;
//     		}
//     		displayContactsUtil(curNode, prefix, v);
//     		prevNode = curNode;
//     		res.push_back(v);
//     	}
//     	for (; i<len; i++){
//     	    vector<string> v;
//     	    v.push_back("0");
//     	    res.push_back(v);
//     	}
//     	return res;
//     }
// };

// // { Driver Code Starts.

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string contact[n], s;
//         for(int i = 0;i < n;i++)
//             cin>>contact[i];
//         cin>>s;
        
//         Solution ob;
//         vector<vector<string>> ans = ob.displayContacts(n, contact, s);
//         for(int i = 0;i < s.size();i++){
//             for(auto u: ans[i])
//                 cout<<u<<" ";
//             cout<<"\n";
//         }
//     }
//     return 0;
// }  // } Driver Code Ends


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans;
        string cur;
        for(auto &i:s){
            cur+=i;
            set<string>st;
            for(int j=0;j<n;j++){
                //return the index
                if(!contact[j].find(cur))st.insert(contact[j]);//if index is 0 then add to set
            }
            if(!st.empty()){
                vector<string>v(st.begin(),st.end());//set->vector
                ans.push_back(v);
            }else{
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends