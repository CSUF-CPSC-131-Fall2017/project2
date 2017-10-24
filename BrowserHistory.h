//
//  BrowserHistory.cpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include "BrowserHistory.h"
#include <iostream>

BrowserHistory::BrowserHistory(){
    // TO BE COMPLETED

        head_ptr = new Webpage;
        tail_ptr = new Webpage;
        head_ptr ->next_ptr = tail_ptr;
        tail_ptr ->prev_ptr = head_ptr;
        cursor = head_ptr;
        n       = 0;
        NavSize = 0;
        
    }// TO BE COMPLETED


BrowserHistory::~BrowserHistory() {
    delete head_ptr;
    // TO BE COMPLETED
}

void BrowserHistory::visitSite(Webpage newSite) {
    // TO BE COMPLETED
    Webpage* temp = new Webpage(newSite.webURL, newSite.timeVisit);
    
    temp->next_ptr = tail_ptr;
    temp->prev_ptr = cursor;
    cursor->next_ptr = temp;
    cursor= temp;
    NavSize++;
}

string BrowserHistory::getURL() {
    // TO BE COMPLETED
    //cout << "in get URL" << cursor->webURL << endl;
    return cursor->webURL;
}


size_t BrowserHistory::getNavSize(){
    // TO BE COMPLETED
    if(head_ptr->next_ptr == tail_ptr){
        return 0;
    }
    int count = 0;
    Webpage* temp = head_ptr->next_ptr;
    while(temp != tail_ptr){
    temp = temp->next_ptr;
        count++;
    }

  return count;
//return NavSize;
}

string BrowserHistory::back() {
    // TO BE COMPLETED
//
    try{
    if (cursor != head_ptr)
        cursor = cursor->prev_ptr;
    else throw invalid_argument("Back on a non existing webpage");
    }
    catch (const invalid_argument &e) {
        cerr << e.what();
    };

    return cursor->webURL;

}

string BrowserHistory::forward() {
    // TO BE COMPLETED
    try {
    if (cursor == tail_ptr)
        cursor = cursor->next_ptr;

        else throw invalid_argument("Back on a non existing webpage");
    }
    catch (const invalid_argument &e) {
        cerr << e.what();
    };
    return cursor->webURL;

}

void BrowserHistory::readHistory(string fileName) {
    
    ifstream myfile(fileName);
    string line;
    BrowserHistory bh = BrowserHistory();

    if(myfile.is_open()){
        cout << "Successfully opened file " << fileName << endl;
        string key;
        string webPageUrl;
        int timeVisted;
        
        while(myfile >> key ){
            if(key == "new"){
                myfile >> webPageUrl >> timeVisted;
                Webpage wp = Webpage(webPageUrl, timeVisted);
                //cout << key << " " << webPageUrl << " " << timeVisted  << endl;
                bh.visitSite(wp);
            }
            else if(key == "back"){
               back();
            }
            else if(key == "forward"){
forward();
            }
        }
    }
}
//    ifstream myfile(fileName);
//    BrowserHistory bh = BrowserHistory();
//    
//    if (myfile.is_open()) {
//        cout << "Successfully opened file " << fileName << endl;
//        string newSite;
//        string webpageURL;
//        int    timeVisited;
//        
//        while (myfile >> newSite >> webpageURL >> timeVisited ){
//            if(((newSite != "back" || newSite != "front") && (webpageURL != "back" || webpageURL != "front")) || (timeVisited > 0 ))
//            {
//             Webpage wp = Webpage(webpageURL, timeVisited);
//             bh.visitSite(wp);
//            }
//            
//        }
//        myfile.close(); // TO BE COMPLETED
//    }
//}

void BrowserHistory::printBackSites(){
//    
//    {
//        Webpage* temp = head_ptr;
//        
//        cout << temp->prev_ptr << endl;
//    }
     //TO BE COMPLETED
}

void BrowserHistory::printForwardSites() {
    
//    Webpage* temp = head_ptr;
//    
//    cout << temp->data << endl;
//    // TO BE COMPLETED
}

void BrowserHistory::printFullHistory() {
    
//    Webpage* temp = head_ptr;
//    head_ptr ->next_ptr = tail_ptr;
//    tail_ptr ->prev_ptr = head_ptr;
//    cout << temp->next_ptr << endl;
//
//    // TO BE COMPLETED
}
