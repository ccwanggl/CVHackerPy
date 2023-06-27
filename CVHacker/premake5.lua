project "CVHacker"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"


    targetdir ("..bin/" .. outputdir .. "/%{prj.name}")
    objdir ("..bin-int/" .. outputdir .. "/%{prj.name}")

-- not use precompiled header

    pchheader "cvpch.h"
    pchsource "%{wks.location}/CVHacker/src/cvpch.cpp"

    files
    {
        "%{wks.location}/CVHacker/src/CVHacker/**.h",
        "%{wks.location}/CVHacker/src/CVHacker/**.cpp",
        "%{wks.location}/CVHacker/src/cv.h",
        "%{wks.location}/CVHacker/src/cvpch.h",
        "%{wks.location}/CVHacker/src/cvpch.cpp",
    }


    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "CV_DEBUG"
        runtime "Debug"
        symbols "on"
        staticruntime "off"

    filter "configurations:Release"
        defines "CV_RELEASE"
        runtime "Release"
        optimize "on"
        staticruntime "on"

    filter "configurations:Dist"
        defines "CV_DIST"
        runtime "Release"
        optimize "on"
        staticruntime "on"
