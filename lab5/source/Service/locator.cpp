#include "../../include/Service/locator.h"


static VisualEffcets* service;
VisualEffcets* Locator::getVFX()
{
	return service;
}

void Locator::provide(VisualEffcets* serv)
{
	service = serv;
}




