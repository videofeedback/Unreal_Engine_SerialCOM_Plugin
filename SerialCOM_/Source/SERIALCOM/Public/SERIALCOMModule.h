#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_CLASS(SERIALCOMLog, Log, All);

class SERIALCOMModule : public IModuleInterface
{
private:

public:
	SERIALCOMModule();
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};