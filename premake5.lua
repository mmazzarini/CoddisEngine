-- Premake file LUA
workspace "CoddisEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CoddisEngine"
	location "CoddisEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"
		defines
		{
			"CODDIS_PLATFORM_WINDOWS",
			"CODDIS_BUILD_DLL"
			-- "_DEBUG;_CONSOLE",
		}
		-- IF EXIST ..\bin\Debug-windows-x86_64\CoddisEngine\CoddisEngine.dll\ (xcopy /Q /E /Y /I ..\bin\Debug-windows-x86_64\CoddisEngine\CoddisEngine.dll ..\bin\Debug-windows-x86_64\Sandbox > nul) ELSE (xcopy /Q /Y /I ..\bin\Debug-windows-x86_64\CoddisEngine\CoddisEngine.dll ..\bin\Debug-windows-x86_64\Sandbox > nul)

	filter "configurations:Debug"
		defines "CODDIS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CODDIS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CODDIS_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CoddisEngine/vendor/spdlog/include",
		"CoddisEngine/src"
	}

	links
	{
		"CoddisEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"
		defines
		{
			"CODDIS_PLATFORM_WINDOWS",
			-- "_DEBUG;_CONSOLE",

		}

		postbuildcommands
		{
			"{COPY} ../bin/" .. outputdir .. "/CoddisEngine/*.dll ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "CODDIS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CODDIS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CODDIS_DIST"
		optimize "On"
