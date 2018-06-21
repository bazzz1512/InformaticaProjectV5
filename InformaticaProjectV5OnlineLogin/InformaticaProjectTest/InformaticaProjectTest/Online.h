#pragma once

#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include "md5.h"

class Online {
	public:
		std::string GetOutputServer(std::string Username, std::string Password);

};

extern Online COnline;
