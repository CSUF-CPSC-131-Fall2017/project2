//
//  BrowserHistory.cpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include "BrowserHistory.h"


BrowserHistory::BrowserHistory()
    :head (NULL){} // TO BE COMPLETED


BrowserHistory::~BrowserHistory() {
    // TO BE COMPLETED
    delete head;
}

void BrowserHistory::visitSite(Webpage newSite) {
    
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
    // TO BE COMPLETED

    return URL;
}

string BrowserHistory::forward() {

    // TO BE COMPLETED
    return URL;
}

void BrowserHistory::readHistory(string fileName) {
    
    ifstream myfile(fileName);
    //cout << "------------seeing if files open--------------- " << endl;
    if (myfile.is_open()) {
        cout << "Successfully opened file " << fileName << endl;
        string newSite;
        string webAdress;
        int    WebNumber;
        while (myfile >> newSite >> webAdress >> WebNumber){
        cout << "" << newSite << " " << webAdress << " " << WebNumber << endl;
    
            }
                myfile.close(); // TO BE COMPLETED
                    }
                        }

void BrowserHistory::printBackSites() {

    // TO BE COMPLETED
}

void BrowserHistory::printForwardSites() {
    // TO BE COMPLETED
}

void BrowserHistory::printFullHistory() {
    // TO BE COMPLETED
}
