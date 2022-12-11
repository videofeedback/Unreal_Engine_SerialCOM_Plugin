#include "SERIALCOMModule.h"

IMPLEMENT_MODULE(SERIALCOMModule, SERIALCOM);

#define LOCTEXT_NAMESPACE "SERIALCOM"

SERIALCOMModule::SERIALCOMModule()
{
}

void SERIALCOMModule::StartupModule()
{
	// Startup LOG MSG
	UE_LOG(SERIALCOMLog, Warning, TEXT("SERIALCOM: Log Started"));
}

void SERIALCOMModule::ShutdownModule()
{
	// Shutdown LOG MSG
	UE_LOG(SERIALCOMLog, Warning, TEXT("SERIALCOM: Log Ended"));
}