#include "ResourceBuilding.h"

ResourceBuilding::ResourceBuilding()
{

}
int ResourceBuilding::getStoredNResource()
{
	return this->stored_Resources;
}

int ResourceBuilding::getMaximunStorage()
{
	return this->max_stored_res;
}

int ResourceBuilding::getMaxlvl()
{
	return this->max_lvl;
}

int ResourceBuilding::getProdRate()
{
	return this->produciont_rate;
}

Resources ResourceBuilding::getProductedRes()
{
	return this->resource_producted;
}
