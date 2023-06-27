project "Canny"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "**.h",
        "**.cpp"
    }

    includedirs
    {
        "%{IncludeDirs.OpenCV}",
    }

    libdirs
    {
        "%{LinkDirs.OpenCV}",
    }
    
	filter "configurations:Debug"
        systemversion "latest"
		runtime "Debug"
        symbols "on"
        staticruntime "off"
        links
        {
            "opencv_world470d.lib"
        }

	filter "configurations:Release"
        systemversion "latest"
		runtime "Release"
        optimize "on"
        staticruntime "On"
        links
        {
            "opencv_world470.lib"
        }
