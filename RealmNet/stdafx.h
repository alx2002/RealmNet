#pragma once

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <thread>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long uint64;
typedef unsigned short ushort;

#pragma comment(lib, "user32.lib")