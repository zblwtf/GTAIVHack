# GTAIVHack

---

## 项目介绍
GTAIVHack是一个使用代理DLL与ScriptHook进行开发且 只支持**Grand Theft Auto IV The Complete Edition**的项目。由于没有**ScriptHook.lib**文件，代码无法直接使用ScriptHook，因此通过生成一个ScriptHook的代理DLL来实现调用ScriptHook的功能。因此，该项目依赖一个代理DLL和ScriptHook.dll，因此需要使用Loader DLL来先加载代理DLL，再加载项目的DLL。
## 实现的模块
1. Skeleton ESP
2. TraceLine
3. 3DBox

## 项目结构
- GTAIVHack.dll：项目的核心DLL文件，通过Loader DLL加载。
- Loader.dll：用于先加载代理DLL，然后再加载项目的DLL。
- ProxyScriptHook.dll：ScriptHook的代理DLL，用于与ScriptHook进行交互。

## 依赖
-  [ScriptHook](https://www.lcpdfr.com/downloads/gta4mods/g17media/26726-compatibility-patch-for-gta-iv-complete-edition/)   [download](https://fileservice.gtainside.com/downloads/ftpl/1614788383_GTA%20IV%20Complete%20Edition%20ASI%20Loader%20plus%20ScriptHook.zip)

## 使用方法
1. 使用Loader项目编译得到Loader.dll。
2. 将ProxyScriptHook.dll和Loader.dll放置在与GTAIVHack.dll同一目录下。
3. 使用[PowerSploit](https://github.com/PowerShellMafia/PowerSploit/blob/master/CodeExecution/Invoke-DllInjection.ps1) 的Invoke-DllInject 加载 Loader.dll 在这之前确保ScriptHook.dll已经被正确加载。
4. 项目的DLL文件GTAIVHack.dll现在可以正常运行。

注意：由于代理DLL与普通的PE文件不同，无法使用PE加载技术。因此，需要通过调用Kernel32.dll的LoadLibrary函数来手动加载ScriptHook.dll的代理DLL。为了保证代码的正常工作，建议使用Loader.dll来先加载代理DLL，然后再加载项目的DLL。

## 许可证
该项目基于 MIT 许可证。详情请参阅 [LICENSE](LICENSE) 文件。

---


