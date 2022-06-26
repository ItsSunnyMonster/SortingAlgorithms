workspace "SortingAlgorithms"
    configurations { "Debug", "Release" }
    targetdir "bin/%{cfg.platform}-%{cfg.buildcfg}/%{prj.name}"
    objdir "bin-int/%{cfg.platform}-%{cfg.buildcfg}/%{prj.name}"

    include "SortingAlgorithms"