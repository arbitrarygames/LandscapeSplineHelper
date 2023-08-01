// Copyright 2023 Arbitrary Games. All rights reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FLandscapeSplineHelperPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
