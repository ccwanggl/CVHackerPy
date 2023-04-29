include "./vendor/premake_customization/solution_items.lua"

workspace "CVHacker"
    architecture "x64"
    --startproject "CGHackerTest"

    configurations
    {
        "Debug",
        "Release",
    }

    solution_items
    {
        ".editorconfig"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDirs = {}
IncludeDirs["OPENCV"] = os.getenv("OpenCV_DIR") .. "/include"

LinkDirs = {}
LinkDirs["OPENCV"] = os.getenv("OpenCV_DIR") .. "/x64/vc15/lib"

-- projects
group "Dependencies"
    include "vendor"
group ""

include "CVHacker"
include "premakes/learn_opencv.lua"
