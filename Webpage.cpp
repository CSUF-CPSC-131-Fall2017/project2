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
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    
    this->webpageURL = webpageURL;
    this->timeVisited = timeVisited;
    
    
    // TO BE COMPLETED
}

string Webpage::getURL() {
    return webpageURL;
    // TO BE COMPLETED
}

time_t Webpage::getTime() {
    return timeVisited;
    // TO BE COMPLETED
}
