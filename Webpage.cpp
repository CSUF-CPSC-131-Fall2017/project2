////
//  Webpage.cpp
//  Project II - C++ -CPSC131
//
//  Created by Jeremy Escobar on 10/10/17.
//  Copyright © 2017 Jeremy Escobar. All rights reserved.
//

#include "Webpage.h"

Webpage::Webpage() {
    // TO BE COMPLETED
    webURL = " "; //setting default string to blank
    timeVisit = time(NULL); //setting time to null
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    
    this->webURL    = webpageURL;  //seting web URL to webpageURL to use in other classes
    this->timeVisit = timeVisited; //seting timeVisit to timevisited to use in other classes
    
    // TO BE COMPLETED
}

string Webpage::getURL() {
    return webURL; //return webURL for getter function
    // TO BE COMPLETED
}

time_t Webpage::getTime() {
    return timeVisit; //return timeVisit for getter function
    // TO BE COMPLETED
}
