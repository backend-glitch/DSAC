/*
logic:
0. take two pointers: i => count ans index => character.
1. count condn for duplicates
2. print condn for count = 1
3. print condn for count > 1 
4.to_string used.
5. return index value => answer

*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;


int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;

        for(int i= 0;i<n;i++){
            char ch = chars[i];
            int count  = 0;

            while(i < n && chars[i] == ch){// to count for duplicates
                count++;
                i++;
            }
            if(count == 1){ // if count  == 1 , then  no printing of count, 
                chars[index] = ch;
                index++;
            }else{
                chars[index++] = ch; // if count > 1 ,then first print character, then you have to print "1","0".
                string str = to_string(count);//to store count.
                for(char dig : str){
                    chars[index++] = dig;
                }
            }
           i--; // to compensate for one extra increment by forloop
        }
        chars.resize(index); //to remove thr further indices
return index;  // to return index

    }

    int main(){

       vector<char> chars1 = {'a','a','b','b','c','c','c'};

       int ans = compress(chars1);
       cout<<"the compressed version:"<<ans;
    }