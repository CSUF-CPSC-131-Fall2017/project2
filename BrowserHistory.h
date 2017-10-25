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

class BrowserHistory {
    
public:
    
    BrowserHistory();
    ~BrowserHistory();
    
    void visitSite(Webpage newSite);
    string back();
    string forward();
    
    void readHistory(string fileName);
    
    string getURL();
    size_t getNavSize();
    
    void printBackSites();
    void printForwardSites();
    void printFullHistory();

    
private:
    size_t NavSize;    //used for incrementing navsize in browserhistory.cpp
    Webpage *head_ptr; //a pointer that points to the head
    Webpage *tail_ptr; //used for tail of browser history
    Webpage *cursor;   //used for current website
    Webpage *history;  //used to create history to store total browser history
    Webpage *history_head;//used to create head for full browser history
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions
    // TO BE COMPLETED
};
