project "VideoCapture"
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
        "%{IncludeDirs.OPENCV}",
    }

    libdirs
    {
        "%{LinkDirs.OPENCV}",
    }

	filter "configurations:Debug"
        systemversion "latest"
		runtime "Debug"
        symbols "on"
        staticruntime "off"
        links
        {
            "opencv_world460d.lib"
        }

	filter "configurations:Release"
        systemversion "latest"
		runtime "Release"
        optimize "on"
        staticruntime "On"
        links
        {
            "opencv_world460.lib"
        }
