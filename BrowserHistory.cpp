//
//  BrowserHistory.cpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include "BrowserHistory.h"


BrowserHistory::BrowserHistory()
    {
        head_ptr = new StringNode;
        tail_ptr = new StringNode;
        head_ptr ->next_ptr = tail_ptr;
        tail_ptr ->prev_ptr = head_ptr;
        // link head to the tail
        cursor = head_ptr;
        n       = 0;
        URL     = " ";
        NavSize = 0;
        
    } // TO BE COMPLETED


BrowserHistory::~BrowserHistory() {
    // TO BE COMPLETED
    // use (n + 1)
   // delete head_ptr;
}

void BrowserHistory::visitSite(Webpage newSite) {
    
    this->URL = newSite.getURL();
    this->NavSize++;
    
    // TO BE COMPLETED
}

string BrowserHistory::getURL() {
    // TO BE COMPLETED
    return URL;
    }


size_t BrowserHistory::getNavSize(){
    // TO BE COMPLETED
   return NavSize;
}

string BrowserHistory::back() {
    
    StringNode* old = head_ptr;
    head_ptr = old->next_ptr;
    delete old;
    this->NavSize--;
    // TO BE COMPLETED
    return URL;
//cursor iterator linked linked
}

string BrowserHistory::forward() {
    // TO BE COMPLETED
    StringNode* v = new StringNode;
    v->data = n;
    v->next_ptr = head_ptr;
    head_ptr = v;

    return this->URL;

}

void BrowserHistory::readHistory(string fileName) {
    
    ifstream myfile(fileName);
    
    if (myfile.is_open()) {
        cout << "Successfully opened file " << fileName << endl;
        string newSite;
        string webpageURL;
        int    timeVisited;
        
        while (myfile >> newSite >> webpageURL >> timeVisited ){
            if(((newSite != "back" || newSite != "front") && (webpageURL != "back" || webpageURL != "front")) || (timeVisited > 0 ))
            {
             Webpage wp = Webpage(webpageURL, timeVisited);
             BrowserHistory bh = BrowserHistory();
             bh.visitSite(wp);
            }
            
        }
        myfile.close(); // TO BE COMPLETED
    }
}

void BrowserHistory::printBackSites(){

    // TO BE COMPLETED
}

void BrowserHistory::printForwardSites() {
    
    // TO BE COMPLETED
}

void BrowserHistory::printFullHistory() {
    // TO BE COMPLETED
}
