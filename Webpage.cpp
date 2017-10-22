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
    webURL = "";
    timeVisit = time(NULL);
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    
    this->webURL  = webpageURL;
    this->timeVisit = timeVisited;
    
    
    // TO BE COMPLETED
}

string Webpage::getURL() {
    return webURL;
    // TO BE COMPLETED
}

time_t Webpage::getTime() {
    return timeVisit;
    // TO BE COMPLETED
}
