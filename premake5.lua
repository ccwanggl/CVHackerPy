include "./vendor/premake_customization/solution_items.lua"

workspace "CVHacker"
    architecture "x64"
    --startproject "CGHackerTest"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
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
IncludeDir = {}
IncludeDir["OPENCV"] = os.getenv("OpenCV_DIR") .. "/include"

LinkDir = {}
LinkDir["OPENCV"] = os.getenv("OpenCV_DIR") .. "/x64/vc15/lib"

-- projects
group "Dependencies"
    include "vendor"
group ""

include "CVHacker"
include "premakes/learn_opencv.lua"
