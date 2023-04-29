// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureUtilAsyncAction.h"


void UGameFeatureUtilAsyncAction::OnGameFeatureCompleted(UE::GameFeatures::FResult const& Result)
{
    Completed.Broadcast();
    SetReadyToDestroy();
}

void UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.LoadGameFeaturePlugin(PluginName, FGameFeaturePluginLoadComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin* UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin::GameFeatureAsyncAction_LoadGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_LoadGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.LoadAndActivateGameFeaturePlugin(PluginName, FGameFeaturePluginLoadComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin* UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin::GameFeatureAsyncAction_LoadAndActivateGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_LoadAndActivateGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.ChangeGameFeatureTargetState(PluginName, TargetState, FGameFeaturePluginChangeStateComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState* UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState::GameFeatureAsyncAction_ChangeGameFeatureTargetState(UObject* WorldContextObject, const FString& PluginName, EGameFeatureTargetState TargetState)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_ChangeGameFeatureTargetState>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;
    Action->TargetState = TargetState;

    return Action;
}

void UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.UpdateGameFeaturePluginURL(PluginName, FGameFeaturePluginUpdateURLComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL* UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL::GameFeatureAsyncAction_UpdateGameFeaturePluginURL(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_UpdateGameFeaturePluginURL>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.DeactivateGameFeaturePlugin(PluginName, FGameFeaturePluginDeactivateComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin* UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin::GameFeatureAsyncAction_DeactivateGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_DeactivateGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.UnloadGameFeaturePlugin(PluginName, FGameFeaturePluginUnloadComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted), bKeepRegistered);
}

UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin* UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin::GameFeatureAsyncAction_UnloadGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName, bool bKeepRegistered)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_UnloadGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;
    Action->bKeepRegistered = bKeepRegistered;

    return Action;
}

void UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.ReleaseGameFeaturePlugin(PluginName, FGameFeaturePluginReleaseComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin* UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin::GameFeatureAsyncAction_ReleaseGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_ReleaseGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.UninstallGameFeaturePlugin(PluginName, FGameFeaturePluginUninstallComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin* UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin::GameFeatureAsyncAction_UninstallGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_UninstallGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.LoadGameFeaturePlugin(PluginName, FGameFeaturePluginTerminateComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin* UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin::GameFeatureAsyncAction_TerminateGameFeaturePlugin(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_TerminateGameFeaturePlugin>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}

void UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange::Activate()
{
    auto& Subsystem = UGameFeaturesSubsystem::Get();
    Subsystem.CancelGameFeatureStateChange(PluginName, FGameFeaturePluginChangeStateComplete::CreateUObject(this, &ThisClass::OnGameFeatureCompleted));
}

UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange* UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange::GameFeatureAsyncAction_CancelGameFeatureStateChange(UObject* WorldContextObject, const FString& PluginName)
{
    auto* Action = NewObject<UGameFeatureUtilAsyncAction_CancelGameFeatureStateChange>(WorldContextObject);
    Action->RegisterWithGameInstance(WorldContextObject);
    Action->PluginName = PluginName;

    return Action;
}
