//
//  eval.cpp
//  HW2
//
//  Created by WangSiwen on 15-4-24.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;
bool checkvalidity(string infix)
{
    if (infix.length()==0) {
        return 0;
    }
    char prev='!',cur;
    int num=0;
    for (int i=0; i<infix.length(); i++) {
        cur=infix[i];
        switch (cur) {
            case ' ':
            break;
            
            case 'F':case 'T':case '!':
            if (prev==')' || prev=='F' || prev=='T') {
                return 0;
            }
            prev=cur;
            break;
            
            case '&':case '|':
            if (prev=='|' || prev=='&' || prev=='(' || prev=='!') {
                return 0;
            }
            prev=cur;
            break;
            
            case '(':
            if (prev==')' || prev=='F' || prev=='T') {
                return 0;
            }
            prev=cur;
            num++;
            break;
            
            case ')':
            if (prev=='|' || prev=='&' || prev=='(' || prev=='!') {
                return 0;
            }
            prev=cur;
            num--;
            break;
            
            default: return 0;
            break;
        }
    }
    if (prev=='|' || prev=='&' || prev=='(' || prev=='!') {
        return 0;
    }
    if (num) {
        return 0;
    }
    return 1;
}
int evaluate(string infix, string& postfix, bool& result)
{

    stack<char> opstack;
    postfix="";
    if (!checkvalidity(infix)) {
        return 1;
    }
    int i=0;
    for (i=0; i<infix.length(); i++) {//for the infix to postfix conversion step
       
        switch (infix[i]) {
            case 'F':case 'T':
            postfix+=infix[i];
            //pfstack.push(infix[i]);
            break;
            
            case '(':
            opstack.push('(');
            //postfix+=infix[i];
            //pfstack.push(infix[i]);
            break;
            
            case ')':
            while (!opstack.empty() && opstack.top()!='(') {
                postfix+=opstack.top();
                //pfstack.push(opstack.top());
                opstack.pop();
            }
            opstack.pop();
            break;
            
            case '!':
            while (!opstack.empty() && opstack.top()=='!') {
                postfix+=opstack.top();
                //pfstack.push(opstack.top());
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
            
            case '&':
            while (!opstack.empty() && opstack.top()!='(' && !(opstack.top()=='&' || opstack.top()=='|')) {
                postfix+=opstack.top();
                //pfstack.push(opstack.top());
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
                   
            case '|':
            while (!opstack.empty() && opstack.top()!='(' ) {
                postfix+=opstack.top();
                //pfstack.push(opstack.top());
                opstack.pop();
            }
            opstack.push(infix[i]);
            break;
            
            default:
            break;
        }
    }
    while (!opstack.empty()) {
        postfix+=opstack.top();
        //pfstack.push(opstack.top());
        opstack.pop();
    }
    
    stack<bool> res;
    bool tmp;
    for (i=0; i<postfix.length(); i++) {////the evaluation of the postfix expression
        switch (postfix[i]) {
            case 'F':
            res.push(0);
            break;
            
            case 'T':
            res.push(1);
            break;
            
            case '!':
            if (res.empty()) {
                return 1;
            }
            res.top()=!res.top();
            break;
            
            case '&':
            if (res.empty()) {
                return 1;
            }
            tmp=res.top();
            res.pop();
            if (res.empty()) {
                return 1;
            }
            res.top()=res.top()&tmp;
            break;
            
            case '|':
            if (res.empty()) {
                return 1;
            }
            tmp=res.top();
            res.pop();
            if (res.empty()) {
                return 1;
            }
            res.top()=res.top()|tmp;
            break;
            
            default:
            break;
        }
        
    }
    if (res.empty()) {
        return 1;
    }
    result=res.top();
    res.pop();
    if (!res.empty()) {
        return 1;
    }
    return 0;
}
int main()
{
    string pf;
    bool answer;
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0 &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    cout << "Passed all tests" << endl;
}
