// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureUtilFunctionLibrary.h"


FString UGameFeatureUtilFunctionLibrary::GetPluginURL_FileProtocol(const FString& PluginDescriptorPath)
{
	return UGameFeaturesSubsystem::GetPluginURL_FileProtocol(PluginDescriptorPath);
}

FString UGameFeatureUtilFunctionLibrary::GetPluginURL_InstallBundleProtocolByStringArray(const FString& PluginName, const TArray<FString>& BundleNames)
{
	return UGameFeaturesSubsystem::GetPluginURL_InstallBundleProtocol(PluginName, BundleNames);
}

FString UGameFeatureUtilFunctionLibrary::GetPluginURL_InstallBundleProtocolByString(const FString& PluginName, const FString& BundleName)
{
	return UGameFeaturesSubsystem::GetPluginURL_InstallBundleProtocol(PluginName, BundleName);
}

FString UGameFeatureUtilFunctionLibrary::GetPluginURL_InstallBundleProtocolByNameArray(const FString& PluginName, const TArray<FName>& BundleNames)
{
	return UGameFeaturesSubsystem::GetPluginURL_InstallBundleProtocol(PluginName, BundleNames);
}

FString UGameFeatureUtilFunctionLibrary::GetPluginURL_InstallBundleProtocolByName(const FString& PluginName, const FName& BundleName)
{
	return UGameFeaturesSubsystem::GetPluginURL_InstallBundleProtocol(PluginName, BundleName);
}

#if 0
FString UGameFeatureUtilFunctionLibrary::GetPluginURL_InstallBundleProtocol(const FString& PluginName, const FInstallBundlePluginProtocolMetaData& ProtocolMetadata)
{
	return UGameFeaturesSubsystem::GetPluginURL_InstallBundleProtocol(PluginName, ProtocolMetadata);
}

EGameFeaturePluginProtocol UGameFeatureUtilFunctionLibrary::GetPluginURLProtocol(const FString& PluginURL)
{
	return UGameFeaturesSubsystem::GetPluginURLProtocol(PluginURL);
}

bool UGameFeatureUtilFunctionLibrary::IsPluginURLProtocol(const FString& PluginURL, EGameFeaturePluginProtocol PluginProtocol)
{
	return UGameFeaturesSubsystem::IsPluginURLProtocol(PluginURL, PluginProtocol);
}

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
