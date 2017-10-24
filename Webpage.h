//
//
//  Webpage.hpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#pragma once

#include <string>
using namespace std;

class Webpage {
public:
    Webpage();
    Webpage(const string& webpageURL, const time_t& timeVisited);
    string getURL();
    time_t getTime();
    
private:
    
    string webURL;    //webpage URL
    time_t timeVisit; //time visited
    Webpage *next_ptr;//used to point to next pointer webpage
    Webpage *prev_ptr;//used to point to previous pointer on webpage
    friend class BrowserHistory;
    // Add private member variables for your class along with any
    // other variables required to implement the public member functions
    // TO BE COMPLETED
};
