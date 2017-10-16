//
//  BrowserHistory.cpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include "BrowserHistory.h"


BrowserHistory::BrowserHistory()
    :head_ptr (NULL){
        n       = 0;
        URL     = " ";
        NavSize = 0;
        
    } // TO BE COMPLETED


BrowserHistory::~BrowserHistory() {
    // TO BE COMPLETED
    // use (n + 1)
    delete head_ptr;
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
    
   return NavSize;
}

string BrowserHistory::back() {

    this->NavSize--;
    // TO BE COMPLETED

    return URL;
}

string BrowserHistory::forward() {
    // TO BE COMPLETED
    
    
    //return (head_ptr->element);
    return (URL);
}

void BrowserHistory::readHistory(string fileName) {
    
    ifstream myfile(fileName);
    //cout << "------------seeing if files open--------------- " << endl;
    if (myfile.is_open()) {
        cout << "Successfully opened file " << fileName << endl;
        string newSite;
        string webpageURL;
        int    timeVisited;
        
        while (myfile >> newSite >> webpageURL >> timeVisited ){
            //cout << "" << newSite << " " << webpageURL << " " << timeVisited  << endl;
             Webpage wp =  Webpage(webpageURL, timeVisited);
             BrowserHistory bh = BrowserHistory();
             bh.visitSite(wp);
            
            //cout << "------->"<<URL << NavSize << endl;
        }
        myfile.close(); // TO BE COMPLETED
    }
}

void BrowserHistory::printBackSites(){
    
//    StringNode *current;
//    current = head_ptr;
//    while (current == nullptr) {
//        cout << current->data;
//    }
        // TO BE COMPLETED
}//how to do forward and back?

void BrowserHistory::printForwardSites() {
    
    // TO BE COMPLETED
    
    //how do you print it??
}//until the node is empty? can we do a stack?? and how???// do i need to use recursion

void BrowserHistory::printFullHistory() {
    // TO BE COMPLETED
}
