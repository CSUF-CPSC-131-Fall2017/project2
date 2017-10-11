////
//  BrowserHistory.hpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class StringNode {
    
private:
    string element;
    StringNode *next;
    
    friend class BrowserHistory;
};

class BrowserHistory {
public:
    BrowserHistory();
    ~BrowserHistory();
    
    void visitSite(Webpage newSite);
    
    string back();
    string forward();
    
    void readHistory(string fileName);
    
    bool empty() const;
    
    string getURL();
    size_t getNavSize();
    
    void printBackSites();
    void printForwardSites();
    void printFullHistory();
    
private:
    int n;
    string URL;
    size_t NavSize;
    StringNode *head;
    
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions
    // TO BE COMPLETED
};
