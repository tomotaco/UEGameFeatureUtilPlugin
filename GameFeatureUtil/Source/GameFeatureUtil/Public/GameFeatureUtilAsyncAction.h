// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameFeaturesSubsystem.h"
#include "GameFeatureUtilAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAsyncCompletedFunction);

/**
 *
 */
UCLASS()
class UGameFeatureUtilAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction(FObjectInitializer const& ObjectInitializer) : Super(ObjectInitializer) {}

	UPROPERTY(BlueprintAssignable)
		FAsyncCompletedFunction Completed;

	FGameFeaturePluginChangeStateComplete GameFeatureCompleted;

protected:
	void OnGameFeatureCompleted(UE::GameFeatures::FResult const& Result);

	FString PluginName;
};

UCLASS()
class UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Loads a single game feature plugin. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "LoadGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin* GameFeatureAsyncAction_LoadGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName);
};

UCLASS()
class UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Loads a single game feature plugin and activates it. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "LoadAndActivateGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin* GameFeatureAsyncAction_LoadAndActivateGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginURL);
};

UCLASS()
class UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Changes the target state of a game feature plugin */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "ChangeGameFeatureTargetState", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState* GameFeatureAsyncAction_ChangeGameFeatureTargetState(UObject* WorldContextObject, const FString& PluginURL, EGameFeatureTargetState TargetState);

protected:
	EGameFeatureTargetState TargetState;
};

UCLASS()
class UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Changes the URL data of a game feature plugin. Useful to change any options data that is parsed from the URL such as settings flags */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "UpdateGameFeaturePluginURL", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL* GameFeatureAsyncAction_UpdateGameFeaturePluginURL(UObject* WorldContextObject, const FString& NewPluginURL);
};

UCLASS()
class UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Deactivates the specified plugin */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "DeactivateGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin* GameFeatureAsyncAction_DeactivateGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginURL);
};

UCLASS()
class UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Unloads the specified game feature plugin. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "UnloadGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin* GameFeatureAsyncAction_UnloadGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginURL, bool bKeepRegistered = false);

protected:
	bool bKeepRegistered = false;
};

UCLASS()
class UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Releases any game data stored for this GameFeaturePlugin. Does not uninstall data and it will remain on disk. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "ReleaseGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin* GameFeatureAsyncAction_ReleaseGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginURL);
};

UCLASS()
class UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Uninstalls any game data stored for this GameFeaturePlugin and terminates the GameFeaturePlugin.
		If the given PluginURL is not found this will create a GameFeaturePlugin first and attempt to run it through the uninstall flow.
		This allows for the uninstalling of data that was installed on previous runs of the application where we haven't yet requested the
		GameFeaturePlugin that we would like to uninstall data for on this run. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "UninstallGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin* GameFeatureAsyncAction_UninstallGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginURL);
};

UCLASS()
class UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Terminate the GameFeaturePlugin and remove all associated plugin tracking data. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "TerminateGameFeaturePlugin", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin* GameFeatureAsyncAction_TerminateGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginURL);
};

UCLASS()
class UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange : public UGameFeatureUtilAsyncAction
{
	GENERATED_BODY()

public:
	UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	virtual void Activate() override;

	/** Attempt to cancel any state change. Calls back when cancelation is complete. Any other pending callbacks will be called with a canceled error. */
	UFUNCTION(BlueprintCallable, Category = "GameFeatureUtil", meta = (DisplayName = "CancelGameFeatureStateChange", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "true"))
		static UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange* GameFeatureAsyncAction_CancelGameFeatureStateChange(UObject* WorldContextObject, const FString& PluginURL);
};
