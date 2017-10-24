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
    delete head_ptr;                        //destructor to free memory
    // TO BE COMPLETED
}

void BrowserHistory::visitSite(Webpage newSite) {
    // TO BE COMPLETED
    Webpage* temp = new Webpage(newSite.webURL, newSite.timeVisit);//overloading parameters from filename //copy constructor
    Webpage* temp2 = tail_ptr->prev_ptr;    //creating temp2 for navsize navigation
    while(cursor->next_ptr != tail_ptr){    //while to direct cursor to next and cannot reach tail
        temp2 = temp2->prev_ptr;            //setting temp equal to prev temp
        delete temp2->next_ptr;             //delete temp so we can reload later
        temp2->next_ptr = tail_ptr;         //load temp with next weburl and go till you reach tail
        NavSize--;                          //decrement navsize
    }
    
    temp->next_ptr = tail_ptr;              //point temp to next node and reach tail of node
    tail_ptr->prev_ptr = temp;              //from the tail we go back to previous temp
    temp->prev_ptr = cursor;                //then from current cursor location we go next to cursor
    cursor->next_ptr = temp;                //then from cursor we go next to temp
    cursor= temp;                           //cursor will now equal temp, fillind nodes
    NavSize++;                              //increment through web sites
    
    Webpage *temp3 = new Webpage(newSite.webURL, newSite.timeVisit);//copy constructor
    temp3->prev_ptr = history;              //used to point to previous history and setting equal to history
    history->next_ptr = temp3;              //next history goes to next and fills temp3
    history = history->next_ptr;            //lastly history will equal history to the next pointer (like going through).
    
}

string BrowserHistory::getURL() {
    // TO BE COMPLETED
    return cursor->webURL;                  //return current wed URL (getter function).
}


size_t BrowserHistory::getNavSize(){
    // TO BE COMPLETED
    if(head_ptr->next_ptr == tail_ptr){     //if the head next equals tail then return 0
        return 0;
    }
    int count = 0;                          //initialize count to 0 for later iteration
    Webpage* temp = head_ptr->next_ptr;     //using user defined function to set head to next pointer
    while(temp != tail_ptr){                //while temp does not reach tail
    temp = temp->next_ptr;                  //then set temp equal to temp pointing to next
        count++;                            //iterate through naveSize
    }

  return count;                             //return count
}

string BrowserHistory::back() {
    // TO BE COMPLETED
//
    try{                                    //try and catch an exception
    if (cursor != head_ptr)                 //if current position = current previous webpage then ->
        cursor = cursor->prev_ptr;          //current position equals current previous page
    else throw invalid_argument("Back on a non existing webpage "); //checking for invalid_argument
    }
    catch (const invalid_argument &e) {     //checking for invalid_argument
        cerr << e.what();                   //checking for invalid_argument
    };

    return cursor->webURL;                  //return current webURL

}

string BrowserHistory::forward() {
    // TO BE COMPLETED
    try {                                   //try and catch an exception
    if (cursor != tail_ptr)                 //if current position = tail of nodes then ->
        cursor = cursor->next_ptr;          //current position equals current previous page

        else throw invalid_argument("Back on a non existing webpage "); //checking for invalid_argument
    }
    catch (const invalid_argument &e) {     //checking for invalid_argument
        cerr << e.what();                   //checking for invalid_argument
    };
    return cursor->webURL;                  //return current webURL

}

void BrowserHistory::readHistory(string fileName) {
    
    ifstream myfile(fileName);              //open txt files here
    string line;                            //declare string line for later use in file operations
    if(myfile.is_open()){                   //checking to make sure file is open bool etc..
        cout << "Successfully opened file " << fileName << endl;
        string key;                         //declaring key
        string webPageUrl;                  //declaring webpageURL
        int timeVisted;                     //declaring timeVisited
        
        while(myfile >> key ){              //while in file load key
            if(key.compare("new") == 0){    //compare to new in txt file
                myfile >> webPageUrl >> timeVisted; //load data into webpageURL and timevisited
                Webpage wp(webPageUrl, timeVisted); //loading the parameter with data
                visitSite(wp);              //user loading visite
            }
            else if(key.compare("back") == 0){
                back();                     //checking back in file
            }
            else if(key.compare("forward")==0){
                forward();                  //checking back in file
            }
        }
    }
}

void BrowserHistory::printBackSites(){

    int count=0;                    //initialize count at zero
    while(cursor->prev_ptr != head_ptr){//while current cursor go back (previous) you cann reach head
        cout << back() << endl;     //print out back sites
        count++;                    //iterate through back sites to print them all
    }
    for(int i=0; i < count; i++){   //for loop to increment through web pages
        forward();                  //gathering pages
    }
     //TO BE COMPLETED
}

void BrowserHistory::printForwardSites() {

    // TO BE COMPLETED
    int count=0;                    //initialize count at 0
    cout << getURL() << endl;       //cout URL's
    while(cursor->next_ptr != tail_ptr){ //while loop to go from next to but not reach tail
        cout << forward() << endl;  //cout forward sites
        count++;                    //iterate through foward web sites
    }
    for(int i=0; i < count; i++){   //iterate through forward history
        back();                     //go back function to get all back data
    }
}

void BrowserHistory::printFullHistory() {
    
    for(Webpage* temp=history_head; temp != history; temp = temp->next_ptr){ //using temp history and temp history head to print history
        cout << temp->getURL() << endl;                                      // cout temp histroy from history_head to full history
    }
    
   // TO BE COMPLETED
}
