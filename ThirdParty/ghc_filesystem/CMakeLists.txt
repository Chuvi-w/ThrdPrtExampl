add_library(FSHeader STATIC 
							FSHeader.cpp 
							FSHeader.h
							ghc/filesystem.hpp
							ghc/fs_fwd.hpp
							ghc/fs_impl.hpp
							ghc/fs_std.hpp
							ghc/fs_std_fwd.hpp
							ghc/fs_std_impl.hpp
			)
target_include_directories(FSHeader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})