project "001_imread"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "001_imread.cpp"
    }
    includedirs
    {
        "%{IncludeDirs.OpenCV}",
    }

    libdirs
    {
        "%{LinkDirs.OpenCV}",
    }

    debugenvs
    {
      "path=" .. os.getenv("path") .. ";" .. "%{dllDirs.OpenCV}"
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

project "002_filters"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "002_filters.cpp"
    }

    includedirs
    {
        "%{IncludeDirs.OpenCV}",
    }

    libdirs
    {
        "%{LinkDirs.OpenCV}",
    }

    debugenvs
    {
      "path=" .. os.getenv("path") .. ";" .. "%{dllDirs.OpenCV}"
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
