//
// Created by devinchang on 2019/12/11.
//

#ifndef LEETCODE_UTIL_H
#define LEETCODE_UTIL_H

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

void trimLeftTrailingSpaces(string &input){
    input.erase(input.begin(), find_if(input.begin(), input.end(),
            [](int ch){ return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input){
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch){ return !isspace(ch); }). base(), input.end());
}


TreeNode *stringToTreeNode(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);

    input = input.substr(1, input.length() - 2);
    if(!input.size())
        return nullptr;

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while(true){
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if(!getline(ss, item, ',')){
            break;
        }

        trimLeftTrailingSpaces(item);
        if(item != "null"){
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if(!getline(ss, item, ',')){
            break;
        }

        trimLeftTrailingSpaces(item);
        if(item != "null"){
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}


string treeNodeToString(TreeNode *root){
    if(root == nullptr)
        return "[]";

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(node == nullptr){
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length()-2) + "]";
}


string boolToString(bool input){
    return input ? "True" : "False";
}

vector<int> stringToIntegerVector(string input){
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length()-2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while(getline(ss, item, delim)){
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input){
    vector<int> list = stringToIntegerVector(input);
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for(int item : list){
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string stringToString(string input){
    assert(input.length() >= 2);
    string result;
    for(int i = 1; i < input.length()-1; i++){
        char currentChar = input[i];
        if(input[i] == '\\'){
            char nextChar = input[i];
            switch (nextChar){
                case '\"' : result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\' : result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        }
        else{
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input){
    return stoi(input);
}

#endif //LEETCODE_UTIL_H
