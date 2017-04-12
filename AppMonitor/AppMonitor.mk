##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Win_x64_Release
ProjectName            :=AppMonitor
ConfigurationName      :=Win_x64_Release
WorkspacePath          :=D:/skola/diplomka/codelite
ProjectPath            :=D:/skola/diplomka/codelite/AppMonitor
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=zuzy
Date                   :=28/03/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/AppMonitor.dll
Preprocessors          :=$(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)WXUSINGDLL $(PreprocessorSwitch)WXUSINGDLL_WXSQLITE3 $(PreprocessorSwitch)WXUSINGDLL_SDK $(PreprocessorSwitch)WXUSINGDLL_CL $(PreprocessorSwitch)YY_NEVER_INTERACTIVE=1 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="AppMonitor.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  -O2 $(shell wx-config --debug=no --libs std,stc --unicode=yes) -s -lnetapi32
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../Interfaces $(IncludeSwitch)../CodeLite $(IncludeSwitch)../Plugin $(IncludeSwitch)../sdk/wxsqlite3/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)plugin_sdku $(LibrarySwitch)codeliteu $(LibrarySwitch)wxsqlite3u 
ArLibs                 :=  "libplugin_sdku.dll" "libcodeliteu.dll" "libwxsqlite3u.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib/gcc_lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  $(shell wx-config --cxxflags --debug=no --unicode=yes)  -O2 $(Preprocessors)
CFLAGS   :=  $(shell wx-config --cxxflags --debug=no --unicode=yes)   -O2 -fgnu89-inline $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
WXCFG:=gcc_dll\mswu
WXWIN:=c:\wxWidgets
WXWIN:=D:\src\wxWidgets
WXCFG:=gcc_dll\mswu
Objects0=$(IntermediateDirectory)/appmonitor.cpp$(ObjectSuffix) $(IntermediateDirectory)/sigarmanager.cpp$(ObjectSuffix) $(IntermediateDirectory)/visualizer.cpp$(ObjectSuffix) $(IntermediateDirectory)/appmonitorsettings.cpp$(ObjectSuffix) $(IntermediateDirectory)/childpidchecker.cpp$(ObjectSuffix) $(IntermediateDirectory)/sigar.c$(ObjectSuffix) $(IntermediateDirectory)/sigar_cache.c$(ObjectSuffix) $(IntermediateDirectory)/sigar_fileinfo.c$(ObjectSuffix) $(IntermediateDirectory)/sigar_format.c$(ObjectSuffix) $(IntermediateDirectory)/sigar_getline.c$(ObjectSuffix) \
	$(IntermediateDirectory)/sigar_ptql.c$(ObjectSuffix) $(IntermediateDirectory)/sigar_signal.c$(ObjectSuffix) $(IntermediateDirectory)/sigar_util.c$(ObjectSuffix) $(IntermediateDirectory)/sigarclass.cpp$(ObjectSuffix) $(IntermediateDirectory)/peb.c$(ObjectSuffix) $(IntermediateDirectory)/win32_sigar.c$(ObjectSuffix) $(IntermediateDirectory)/wmi.cpp$(ObjectSuffix) $(IntermediateDirectory)/appmonitoroutputview.cpp$(ObjectSuffix) $(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/appmonitorui.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/axis.cpp$(ObjectSuffix) $(IntermediateDirectory)/ringdataset.cpp$(ObjectSuffix) $(IntermediateDirectory)/displayableringdataset.cpp$(ObjectSuffix) $(IntermediateDirectory)/basedynamicchart.cpp$(ObjectSuffix) $(IntermediateDirectory)/simpledynamicchart.cpp$(ObjectSuffix) $(IntermediateDirectory)/multipledynamicchart.cpp$(ObjectSuffix) $(IntermediateDirectory)/chartlegend.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "D:\skola\diplomka\codelite/.build-win_x64_release"
	@echo rebuilt > "D:\skola\diplomka\codelite/.build-win_x64_release/AppMonitor"

PostBuild:
	@echo Executing Post Build commands ...
	copy "Win_x64_Release\AppMonitor.dll" ..\Runtime\plugins
	@echo Done

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/appmonitor.cpp$(ObjectSuffix): appmonitor.cpp $(IntermediateDirectory)/appmonitor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/appmonitor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/appmonitor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/appmonitor.cpp$(DependSuffix): appmonitor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/appmonitor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/appmonitor.cpp$(DependSuffix) -MM appmonitor.cpp

$(IntermediateDirectory)/appmonitor.cpp$(PreprocessSuffix): appmonitor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/appmonitor.cpp$(PreprocessSuffix) appmonitor.cpp

$(IntermediateDirectory)/sigarmanager.cpp$(ObjectSuffix): sigarmanager.cpp $(IntermediateDirectory)/sigarmanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigarmanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigarmanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigarmanager.cpp$(DependSuffix): sigarmanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigarmanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sigarmanager.cpp$(DependSuffix) -MM sigarmanager.cpp

$(IntermediateDirectory)/sigarmanager.cpp$(PreprocessSuffix): sigarmanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigarmanager.cpp$(PreprocessSuffix) sigarmanager.cpp

$(IntermediateDirectory)/visualizer.cpp$(ObjectSuffix): visualizer.cpp $(IntermediateDirectory)/visualizer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/visualizer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/visualizer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/visualizer.cpp$(DependSuffix): visualizer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/visualizer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/visualizer.cpp$(DependSuffix) -MM visualizer.cpp

$(IntermediateDirectory)/visualizer.cpp$(PreprocessSuffix): visualizer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/visualizer.cpp$(PreprocessSuffix) visualizer.cpp

$(IntermediateDirectory)/appmonitorsettings.cpp$(ObjectSuffix): appmonitorsettings.cpp $(IntermediateDirectory)/appmonitorsettings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/appmonitorsettings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/appmonitorsettings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/appmonitorsettings.cpp$(DependSuffix): appmonitorsettings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/appmonitorsettings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/appmonitorsettings.cpp$(DependSuffix) -MM appmonitorsettings.cpp

$(IntermediateDirectory)/appmonitorsettings.cpp$(PreprocessSuffix): appmonitorsettings.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/appmonitorsettings.cpp$(PreprocessSuffix) appmonitorsettings.cpp

$(IntermediateDirectory)/childpidchecker.cpp$(ObjectSuffix): childpidchecker.cpp $(IntermediateDirectory)/childpidchecker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/childpidchecker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/childpidchecker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/childpidchecker.cpp$(DependSuffix): childpidchecker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/childpidchecker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/childpidchecker.cpp$(DependSuffix) -MM childpidchecker.cpp

$(IntermediateDirectory)/childpidchecker.cpp$(PreprocessSuffix): childpidchecker.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/childpidchecker.cpp$(PreprocessSuffix) childpidchecker.cpp

$(IntermediateDirectory)/sigar.c$(ObjectSuffix): sigar.c $(IntermediateDirectory)/sigar.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar.c$(DependSuffix): sigar.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar.c$(DependSuffix) -MM sigar.c

$(IntermediateDirectory)/sigar.c$(PreprocessSuffix): sigar.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar.c$(PreprocessSuffix) sigar.c

$(IntermediateDirectory)/sigar_cache.c$(ObjectSuffix): sigar_cache.c $(IntermediateDirectory)/sigar_cache.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_cache.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_cache.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_cache.c$(DependSuffix): sigar_cache.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_cache.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_cache.c$(DependSuffix) -MM sigar_cache.c

$(IntermediateDirectory)/sigar_cache.c$(PreprocessSuffix): sigar_cache.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_cache.c$(PreprocessSuffix) sigar_cache.c

$(IntermediateDirectory)/sigar_fileinfo.c$(ObjectSuffix): sigar_fileinfo.c $(IntermediateDirectory)/sigar_fileinfo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_fileinfo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_fileinfo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_fileinfo.c$(DependSuffix): sigar_fileinfo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_fileinfo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_fileinfo.c$(DependSuffix) -MM sigar_fileinfo.c

$(IntermediateDirectory)/sigar_fileinfo.c$(PreprocessSuffix): sigar_fileinfo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_fileinfo.c$(PreprocessSuffix) sigar_fileinfo.c

$(IntermediateDirectory)/sigar_format.c$(ObjectSuffix): sigar_format.c $(IntermediateDirectory)/sigar_format.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_format.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_format.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_format.c$(DependSuffix): sigar_format.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_format.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_format.c$(DependSuffix) -MM sigar_format.c

$(IntermediateDirectory)/sigar_format.c$(PreprocessSuffix): sigar_format.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_format.c$(PreprocessSuffix) sigar_format.c

$(IntermediateDirectory)/sigar_getline.c$(ObjectSuffix): sigar_getline.c $(IntermediateDirectory)/sigar_getline.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_getline.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_getline.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_getline.c$(DependSuffix): sigar_getline.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_getline.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_getline.c$(DependSuffix) -MM sigar_getline.c

$(IntermediateDirectory)/sigar_getline.c$(PreprocessSuffix): sigar_getline.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_getline.c$(PreprocessSuffix) sigar_getline.c

$(IntermediateDirectory)/sigar_ptql.c$(ObjectSuffix): sigar_ptql.c $(IntermediateDirectory)/sigar_ptql.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_ptql.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_ptql.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_ptql.c$(DependSuffix): sigar_ptql.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_ptql.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_ptql.c$(DependSuffix) -MM sigar_ptql.c

$(IntermediateDirectory)/sigar_ptql.c$(PreprocessSuffix): sigar_ptql.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_ptql.c$(PreprocessSuffix) sigar_ptql.c

$(IntermediateDirectory)/sigar_signal.c$(ObjectSuffix): sigar_signal.c $(IntermediateDirectory)/sigar_signal.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_signal.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_signal.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_signal.c$(DependSuffix): sigar_signal.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_signal.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_signal.c$(DependSuffix) -MM sigar_signal.c

$(IntermediateDirectory)/sigar_signal.c$(PreprocessSuffix): sigar_signal.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_signal.c$(PreprocessSuffix) sigar_signal.c

$(IntermediateDirectory)/sigar_util.c$(ObjectSuffix): sigar_util.c $(IntermediateDirectory)/sigar_util.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigar_util.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigar_util.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigar_util.c$(DependSuffix): sigar_util.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigar_util.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sigar_util.c$(DependSuffix) -MM sigar_util.c

$(IntermediateDirectory)/sigar_util.c$(PreprocessSuffix): sigar_util.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigar_util.c$(PreprocessSuffix) sigar_util.c

$(IntermediateDirectory)/sigarclass.cpp$(ObjectSuffix): sigarclass.cpp $(IntermediateDirectory)/sigarclass.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/sigarclass.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sigarclass.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sigarclass.cpp$(DependSuffix): sigarclass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sigarclass.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sigarclass.cpp$(DependSuffix) -MM sigarclass.cpp

$(IntermediateDirectory)/sigarclass.cpp$(PreprocessSuffix): sigarclass.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sigarclass.cpp$(PreprocessSuffix) sigarclass.cpp

$(IntermediateDirectory)/peb.c$(ObjectSuffix): peb.c $(IntermediateDirectory)/peb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/peb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/peb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/peb.c$(DependSuffix): peb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/peb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/peb.c$(DependSuffix) -MM peb.c

$(IntermediateDirectory)/peb.c$(PreprocessSuffix): peb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/peb.c$(PreprocessSuffix) peb.c

$(IntermediateDirectory)/win32_sigar.c$(ObjectSuffix): win32_sigar.c $(IntermediateDirectory)/win32_sigar.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/win32_sigar.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/win32_sigar.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/win32_sigar.c$(DependSuffix): win32_sigar.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/win32_sigar.c$(ObjectSuffix) -MF$(IntermediateDirectory)/win32_sigar.c$(DependSuffix) -MM win32_sigar.c

$(IntermediateDirectory)/win32_sigar.c$(PreprocessSuffix): win32_sigar.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/win32_sigar.c$(PreprocessSuffix) win32_sigar.c

$(IntermediateDirectory)/wmi.cpp$(ObjectSuffix): wmi.cpp $(IntermediateDirectory)/wmi.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/wmi.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wmi.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wmi.cpp$(DependSuffix): wmi.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wmi.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wmi.cpp$(DependSuffix) -MM wmi.cpp

$(IntermediateDirectory)/wmi.cpp$(PreprocessSuffix): wmi.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wmi.cpp$(PreprocessSuffix) wmi.cpp

$(IntermediateDirectory)/appmonitoroutputview.cpp$(ObjectSuffix): appmonitoroutputview.cpp $(IntermediateDirectory)/appmonitoroutputview.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/appmonitoroutputview.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/appmonitoroutputview.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/appmonitoroutputview.cpp$(DependSuffix): appmonitoroutputview.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/appmonitoroutputview.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/appmonitoroutputview.cpp$(DependSuffix) -MM appmonitoroutputview.cpp

$(IntermediateDirectory)/appmonitoroutputview.cpp$(PreprocessSuffix): appmonitoroutputview.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/appmonitoroutputview.cpp$(PreprocessSuffix) appmonitoroutputview.cpp

$(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(ObjectSuffix): appmonitorsettingsdialog.cpp $(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/appmonitorsettingsdialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(DependSuffix): appmonitorsettingsdialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(DependSuffix) -MM appmonitorsettingsdialog.cpp

$(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(PreprocessSuffix): appmonitorsettingsdialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/appmonitorsettingsdialog.cpp$(PreprocessSuffix) appmonitorsettingsdialog.cpp

$(IntermediateDirectory)/appmonitorui.cpp$(ObjectSuffix): appmonitorui.cpp $(IntermediateDirectory)/appmonitorui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/appmonitorui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/appmonitorui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/appmonitorui.cpp$(DependSuffix): appmonitorui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/appmonitorui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/appmonitorui.cpp$(DependSuffix) -MM appmonitorui.cpp

$(IntermediateDirectory)/appmonitorui.cpp$(PreprocessSuffix): appmonitorui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/appmonitorui.cpp$(PreprocessSuffix) appmonitorui.cpp

$(IntermediateDirectory)/axis.cpp$(ObjectSuffix): axis.cpp $(IntermediateDirectory)/axis.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/axis.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/axis.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/axis.cpp$(DependSuffix): axis.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/axis.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/axis.cpp$(DependSuffix) -MM axis.cpp

$(IntermediateDirectory)/axis.cpp$(PreprocessSuffix): axis.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/axis.cpp$(PreprocessSuffix) axis.cpp

$(IntermediateDirectory)/ringdataset.cpp$(ObjectSuffix): ringdataset.cpp $(IntermediateDirectory)/ringdataset.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/ringdataset.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ringdataset.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ringdataset.cpp$(DependSuffix): ringdataset.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ringdataset.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ringdataset.cpp$(DependSuffix) -MM ringdataset.cpp

$(IntermediateDirectory)/ringdataset.cpp$(PreprocessSuffix): ringdataset.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ringdataset.cpp$(PreprocessSuffix) ringdataset.cpp

$(IntermediateDirectory)/displayableringdataset.cpp$(ObjectSuffix): displayableringdataset.cpp $(IntermediateDirectory)/displayableringdataset.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/displayableringdataset.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/displayableringdataset.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/displayableringdataset.cpp$(DependSuffix): displayableringdataset.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/displayableringdataset.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/displayableringdataset.cpp$(DependSuffix) -MM displayableringdataset.cpp

$(IntermediateDirectory)/displayableringdataset.cpp$(PreprocessSuffix): displayableringdataset.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/displayableringdataset.cpp$(PreprocessSuffix) displayableringdataset.cpp

$(IntermediateDirectory)/basedynamicchart.cpp$(ObjectSuffix): basedynamicchart.cpp $(IntermediateDirectory)/basedynamicchart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/basedynamicchart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/basedynamicchart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/basedynamicchart.cpp$(DependSuffix): basedynamicchart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/basedynamicchart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/basedynamicchart.cpp$(DependSuffix) -MM basedynamicchart.cpp

$(IntermediateDirectory)/basedynamicchart.cpp$(PreprocessSuffix): basedynamicchart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/basedynamicchart.cpp$(PreprocessSuffix) basedynamicchart.cpp

$(IntermediateDirectory)/simpledynamicchart.cpp$(ObjectSuffix): simpledynamicchart.cpp $(IntermediateDirectory)/simpledynamicchart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/simpledynamicchart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/simpledynamicchart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/simpledynamicchart.cpp$(DependSuffix): simpledynamicchart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/simpledynamicchart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/simpledynamicchart.cpp$(DependSuffix) -MM simpledynamicchart.cpp

$(IntermediateDirectory)/simpledynamicchart.cpp$(PreprocessSuffix): simpledynamicchart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/simpledynamicchart.cpp$(PreprocessSuffix) simpledynamicchart.cpp

$(IntermediateDirectory)/multipledynamicchart.cpp$(ObjectSuffix): multipledynamicchart.cpp $(IntermediateDirectory)/multipledynamicchart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/multipledynamicchart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/multipledynamicchart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/multipledynamicchart.cpp$(DependSuffix): multipledynamicchart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/multipledynamicchart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/multipledynamicchart.cpp$(DependSuffix) -MM multipledynamicchart.cpp

$(IntermediateDirectory)/multipledynamicchart.cpp$(PreprocessSuffix): multipledynamicchart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/multipledynamicchart.cpp$(PreprocessSuffix) multipledynamicchart.cpp

$(IntermediateDirectory)/chartlegend.cpp$(ObjectSuffix): chartlegend.cpp $(IntermediateDirectory)/chartlegend.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/skola/diplomka/codelite/AppMonitor/chartlegend.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/chartlegend.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/chartlegend.cpp$(DependSuffix): chartlegend.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/chartlegend.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/chartlegend.cpp$(DependSuffix) -MM chartlegend.cpp

$(IntermediateDirectory)/chartlegend.cpp$(PreprocessSuffix): chartlegend.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/chartlegend.cpp$(PreprocessSuffix) chartlegend.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


