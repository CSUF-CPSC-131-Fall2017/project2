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

        head_ptr = new Webpage;             //allocating memory blocks for webpage head pointer
        tail_ptr = new Webpage;             //allocating memory blocks for webpage tail pointer
        head_ptr ->next_ptr = tail_ptr;     //linking head to tail pointers
        tail_ptr ->prev_ptr = head_ptr;     //linking head to tail pointers
        cursor = head_ptr;                  //setting cursor equal to head
        history = new Webpage;              //allocating memory block for webpage history
        history_head = history;             //setting head of history to history
        NavSize = 0;                        //setting defualt to 0 on navsize
        
    }// TO BE COMPLETED


BrowserHistory::~BrowserHistory() {
    delete head_ptr;//destructor
    // TO BE COMPLETED
}

void BrowserHistory::visitSite(Webpage newSite) {
    // TO BE COMPLETED
    Webpage* temp = new Webpage(newSite.webURL, newSite.timeVisit);//overloading parameters from filename
    Webpage* temp2 = tail_ptr->prev_ptr;    //creating temp2 for navsize navigation
    while(cursor->next_ptr != tail_ptr){    //while to direct cursor to next and cannot reach tail
        temp2 = temp2->prev_ptr;            //setting temp equal to prev temp
        delete temp2->next_ptr;             //delete temp so we can reload later
        temp2->next_ptr = tail_ptr;         //load temp with next weburl and go till you reach tail
        NavSize--;                          //decrement navsize
    }
    
    temp->next_ptr = tail_ptr;
    tail_ptr->prev_ptr = temp;
    temp->prev_ptr = cursor;
    cursor->next_ptr = temp;
    cursor= temp;
    NavSize++;
    
    Webpage *temp3 = new Webpage(newSite.webURL, newSite.timeVisit);
    temp3->prev_ptr = history;
    history->next_ptr = temp3;
    history = history->next_ptr;
    
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
    else throw invalid_argument("Back on a non existing webpage ");
    }
    catch (const invalid_argument &e) {
        cerr << e.what();
    };

    return cursor->webURL;

}

string BrowserHistory::forward() {
    // TO BE COMPLETED
    try {
    if (cursor != tail_ptr)
        cursor = cursor->next_ptr;

        else throw invalid_argument("Back on a non existing webpage ");
    }
    catch (const invalid_argument &e) {
        cerr << e.what();
    };
    return cursor->webURL;

}

void BrowserHistory::readHistory(string fileName) {
    
    ifstream myfile(fileName);
    string line;
    if(myfile.is_open()){
        cout << "Successfully opened file " << fileName << endl;
        string key;
        string webPageUrl;
        int timeVisted;
        
        while(myfile >> key ){
            if(key.compare("new") == 0){
                myfile >> webPageUrl >> timeVisted;
                Webpage wp(webPageUrl, timeVisted);
                visitSite(wp);
            }
            else if(key.compare("back") == 0){
                back();
            }
            else if(key.compare("forward")==0){
                forward();
            }
        }
    }
}

void BrowserHistory::printBackSites(){

    int count=0;
    while(cursor->prev_ptr != head_ptr){
        cout << back() << endl;
        count++;
    }
    for(int i=0; i < count; i++){
        forward();
    }
     //TO BE COMPLETED
}

void BrowserHistory::printForwardSites() {

    // TO BE COMPLETED
    int count=0;
    cout << getURL() << endl;
    while(cursor->next_ptr != tail_ptr){
        cout << forward() << endl;
        count++;
    }
    for(int i=0; i < count; i++){
        back();
    }
}

void BrowserHistory::printFullHistory() {
    
    for(Webpage* temp=history_head; temp != history; temp = temp->next_ptr){
        cout << temp->getURL() << endl;
    }
    
   // TO BE COMPLETED
}
