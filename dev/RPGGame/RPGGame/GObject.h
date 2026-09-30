#pragma once
#include <iostream>
#include <string>
#include <vector>

class GObject
{
public:
	GObject();
	virtual ~GObject() = default;

	virtual void BeginPlay() {};

};

