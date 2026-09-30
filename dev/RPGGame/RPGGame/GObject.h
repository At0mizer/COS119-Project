#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Helper.h"

class GObject
{
public:
	GObject();
	virtual ~GObject() = default;

	virtual void BeginPlay() {};

};

