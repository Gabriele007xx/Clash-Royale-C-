#include "Building.h"

Building::Building()
{
}

Resources Building::getResCosto()
{
	return this->res_c;
}

int Building::getCost()
{
	return cost;
}
