# UEGameFeatureUtilPlugin

This is an experimental implementation of wrapper plugin for Game Feature Subsystem in Unreal Engine 5.1.1.
It contains 10 Latent nodes and 11 Blueprint Function Library nodes

Latent nodes:

- LoadGameFeaturePlugin
- LoadAndActivateGameFeaturePlugin
- ChangeGameFeatureTargetState
- UpdateGameFeaturePluginURL
- DeactivateGameFeaturePlugin
- UnloadGameFeaturePlugin
- ReleaseGameFeaturePlugin
- UninstallGameFeaturePlugin
- TerminateGameFeaturePlugin
- CancelGameFeatureStateChange

Blueprint Function Library nodes:

- GetPluginURL_FileProtocol
- GetPluginURL_InstallBundleProtocolByStringArray
- GetPluginURL_InstallBundleProtocolByString
- GetPluginURL_InstallBundleProtocolByNameArray
- GetPluginURL_InstallBundleProtocolByName
- GetGameFeatureDataForActivePluginByURL
- GetGameFeatureDataForRegisteredPluginByURL
- IsGameFeaturePluginInstalled
- IsGameFeaturePluginRegistered
- IsGameFeaturePluginLoaded
- GetGameFeaturePluginInstallPercent
- IsGameFeaturePluginActive
- GetPluginURLByName
- GetPluginFilenameFromPluginURL
- FixPluginPackagePath
- GetLoadedGameFeaturePluginFilenamesForCooking

![Blueprint nodes](images/blueprint-nodes.png)
![Blueprint nodes](images/blueprint-nodes2.png)
