// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFeatureTypes.h"
#include "GameFeaturesSubsystem.h"
#include "GameFeatureUtilFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class UGameFeatureUtilFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

#if 0
		/** Returns all the active plugins GameFeatureDatas */
		UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void GetGameFeatureDataForActivePlugins(TArray<const UGameFeatureData*>& OutActivePluginFeatureDatas);
#endif

	/** Returns the game feature data for an active plugin specified by PluginURL */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static const UGameFeatureData* GetGameFeatureDataForActivePluginByURL(const FString& PluginURL);

	/** Returns the game feature data for a registered plugin specified by PluginURL */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static const UGameFeatureData* GetGameFeatureDataForRegisteredPluginByURL(const FString& PluginURL, bool bCheckForRegistering = false);

	/** Determines if a plugin is in the Installed state (or beyond) */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static bool IsGameFeaturePluginInstalled(const FString& PluginURL);

	/** Determines if a plugin is in the Registered state (or beyond) */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static bool IsGameFeaturePluginRegistered(const FString& PluginURL, bool bCheckForRegistering = false);

	/** Determines if a plugin is in the Loaded state (or beyond) */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static bool IsGameFeaturePluginLoaded(const FString& PluginURL);

	/** Gets the Install_Percent for single game feature plugin if it is active. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static bool GetGameFeaturePluginInstallPercent(const FString& PluginURL, float& Install_Percent);

	/** Determines if a plugin is in the Active state.*/
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static bool IsGameFeaturePluginActive(const FString& PluginURL, bool bCheckForActivating = false);

	/**
	 * If the specified plugin is known by the game feature system, returns the URL used to identify it
	 * @return true if the plugin exists, false if it was not found
	 */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static bool GetPluginURLByName(const FString& PluginName, FString& OutPluginURL);

#if 0
	/** If the specified plugin is a built-in plugin, return the URL used to identify it. Returns true if the plugin exists, false if it was not found */
	UE_DEPRECATED(5.1, "Use GetPluginURLByName instead")
		static bool GetPluginURLForBuiltInPluginByName(const FString& PluginName, FString& OutPluginURL);
#endif

	/** Get the plugin path from the plugin URL */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static FString GetPluginFilenameFromPluginURL(const FString& PluginURL);

	/** Fixes a package path/directory to either be relative to plugin root or not. Paths relative to different roots will not be modified */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void FixPluginPackagePath(FString& PathToFix, const FString& PluginRootPath, bool bMakeRelativeToPluginRoot);
#if 0
	/** Loads a built-in game feature plugin if it passes the specified filter */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void LoadBuiltInGameFeaturePlugin(const TSharedRef<IPlugin>& Plugin, UGameFeaturesSubsystem::FBuiltInPluginAdditionalFilters AdditionalFilter);

	/** Loads all built-in game feature plugins that pass the specified filters */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void LoadBuiltInGameFeaturePlugins(UGameFeaturesSubsystem::FBuiltInPluginAdditionalFilters AdditionalFilter);
#endif
	/** Returns the list of plugin filenames that have progressed beyond installed. Used in cooking to determine which will be cooked. */
	//@TODO: GameFeaturePluginEnginePush: Might not be general enough for engine level, TBD
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void GetLoadedGameFeaturePluginFilenamesForCooking(TArray<FString>& OutLoadedPluginFilenames);
#if 0
	/** Removes assets that are in plugins we know to be inactive.  Order is not maintained. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void FilterInactivePluginAssets(TArray<FAssetIdentifier>& AssetsToFilter);

	/** Removes assets that are in plugins we know to be inactive.  Order is not maintained. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static void FilterInactivePluginAssets(TArray<FAssetData>& AssetsToFilter);

	/** Returns the current state of the state machine for the specified plugin URL */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil")
		static GameFeaturePluginStatePrivate::EGameFeaturePluginState GetPluginState(const FString& PluginURL);
#endif

};
