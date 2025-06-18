workspace "AbsurdLog"
configurations { "Debug", "Release" }
language "C"
location "build"

output_dir = "%{cfg.buildcfg}"

-- Static Library
project "AbsurdLogStatic"
kind "StaticLib"
targetdir "build/output/%{cfg.buildcfg}"
objdir "build/obj/AbsurdLogStatic/%{cfg.buildcfg}"

files { "src/**.c", "src/**.h" }
includedirs { "src" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "NDEBUG" }
optimize "On"

-- Shared Library
project "AbsurdLogShared"
kind "SharedLib"
targetdir "build/output/%{cfg.buildcfg}"
objdir "build/obj/AbsurdLogShared/%{cfg.buildcfg}"

files { "src/**.c", "src/**.h" }
includedirs { "src" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "NDEBUG" }
optimize "On"

-- Example Application
project "AbsurdLogExample"
kind "ConsoleApp"
targetdir "build/bin/%{cfg.buildcfg}"
objdir "build/obj/AbsurdLogExample/%{cfg.buildcfg}"

files { "example/**.c" }
includedirs { "src" }

links { "AbsurdLogStatic" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "NDEBUG" }
optimize "On"