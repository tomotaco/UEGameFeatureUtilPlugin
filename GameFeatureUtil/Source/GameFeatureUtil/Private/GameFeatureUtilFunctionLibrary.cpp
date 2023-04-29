// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureUtilFunctionLibrary.h"

#if 0
void UGameFeatureUtilFunctionLibrary::GetGameFeatureDataForActivePlugins(TArray<const UGameFeatureData*>& OutActivePluginFeatureDatas)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.GetGameFeatureDataForActivePlugins(OutActivePluginFeatureDatas);
}
#endif

const UGameFeatureData* UGameFeatureUtilFunctionLibrary::GetGameFeatureDataForActivePluginByURL(const FString& PluginURL)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.GetGameFeatureDataForActivePluginByURL(PluginURL);
}

const UGameFeatureData* UGameFeatureUtilFunctionLibrary::GetGameFeatureDataForRegisteredPluginByURL(const FString& PluginURL, bool bCheckForRegistering)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.GetGameFeatureDataForRegisteredPluginByURL(PluginURL, bCheckForRegistering);
}

bool UGameFeatureUtilFunctionLibrary::IsGameFeaturePluginInstalled(const FString& PluginURL)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.IsGameFeaturePluginInstalled(PluginURL);
}

bool UGameFeatureUtilFunctionLibrary::IsGameFeaturePluginRegistered(const FString& PluginURL, bool bCheckForRegistering)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.IsGameFeaturePluginRegistered(PluginURL, bCheckForRegistering);
}

bool UGameFeatureUtilFunctionLibrary::IsGameFeaturePluginLoaded(const FString& PluginURL)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.IsGameFeaturePluginLoaded(PluginURL);
}

bool UGameFeatureUtilFunctionLibrary::GetGameFeaturePluginInstallPercent(const FString& PluginURL, float& Install_Percent)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.GetGameFeaturePluginInstallPercent(PluginURL, Install_Percent);
}

bool UGameFeatureUtilFunctionLibrary::IsGameFeaturePluginActive(const FString& PluginURL, bool bCheckForActivating)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.IsGameFeaturePluginActive(PluginURL, bCheckForActivating);
}

bool UGameFeatureUtilFunctionLibrary::GetPluginURLByName(const FString& PluginName, FString& OutPluginURL)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.GetPluginURLByName(PluginName, OutPluginURL);
}

FString UGameFeatureUtilFunctionLibrary::GetPluginFilenameFromPluginURL(const FString& PluginURL)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.GetPluginFilenameFromPluginURL(PluginURL);
}

void UGameFeatureUtilFunctionLibrary::FixPluginPackagePath(FString& PathToFix, const FString& PluginRootPath, bool bMakeRelativeToPluginRoot)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.FixPluginPackagePath(PathToFix, PluginRootPath, bMakeRelativeToPluginRoot);
}

#if 0
void UGameFeatureUtilFunctionLibrary::LoadBuiltInGameFeaturePlugin(const TSharedRef<IPlugin>& Plugin, FBuiltInPluginAdditionalFilters AdditionalFilter)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.LoadBuiltInGameFeaturePlugin(Plugin, AdditionalFilter);
}

void UGameFeatureUtilFunctionLibrary::LoadBuiltInGameFeaturePlugins(FBuiltInPluginAdditionalFilters AdditionalFilter)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.LoadBuiltInGameFeaturePlugins(PluginURL, AdditionalFilter);
}
#endif
void UGameFeatureUtilFunctionLibrary::GetLoadedGameFeaturePluginFilenamesForCooking(TArray<FString>& OutLoadedPluginFilenames)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.GetLoadedGameFeaturePluginFilenamesForCooking(OutLoadedPluginFilenames);
}
#if 0
void UGameFeatureUtilFunctionLibrary::FilterInactivePluginAssets(TArray<FAssetIdentifier>& AssetsToFilter)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.FilterInactivePluginAssets(AssetsToFilter);
}

void UGameFeatureUtilFunctionLibrary::FilterInactivePluginAssets(TArray<FAssetData>& AssetsToFilter)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	Subsystem.FilterInactivePluginAssets(AssetsToFilter);
}

EGameFeaturePluginState UGameFeatureUtilFunctionLibrary::GetPluginState(const FString& PluginURL)
{
	auto& Subsystem = UGameFeaturesSubsystem::Get();
	return Subsystem.GetPluginState(PluginURL);
}
#endif
