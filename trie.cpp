#include <bits/stdc++.h>

using namespace std;

struct node {
    bool isWord;
    node *next[26+1];
    node()
    {
        isWord = false;
        for(int i=0; i<27; i++) {
            next[i] = NULL;
        }
    }
} *root;

int getId(char ch)
{
    return (int)(ch-'a');
}

bool searchInTrie(string str)
{
    node *curr = root;
    int n = str.size();
    for(int i=0; i<n; i++) {
        int id = getId(str[i]);

        if(curr->next[id]==NULL) {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->isWord; // in case of finding exact word, prefix won't be allowed as YES!!!
    //return true; // in case of finding prefix
}

void insertInTrie(string str)
{
    node *curr = root;
    int n = str.size();
    for(int i=0; i<n; i++) {
        int id = getId(str[i]);

        if(curr->next[id]==NULL) {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->isWord = true;
}

int main()
{
    root = new node();
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        insertInTrie(str);
    }
    cin >> n;
    cin.ignore();
    while(n--) {
        string str;
        cin >> str;
        //cout << str << "\n";
        cout << searchInTrie(str) << "\n";
    }
    return 0;
}
