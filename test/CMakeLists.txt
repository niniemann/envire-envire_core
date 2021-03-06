find_package(Boost COMPONENTS unit_test_framework system filesystem serialization thread)

if(ENABLE_PLUGINS)
    rock_library(envire_vector_plugin
        SOURCES vector_plugin.cpp
        DEPS envire_core
        DEPS_PKGCONFIG class_loader)

    rock_library(envire_string_plugin
        SOURCES string_plugin.cpp
        DEPS envire_core
        DEPS_PKGCONFIG class_loader)
    
    rock_testsuite(test_plugins suite.cpp
        test_plugins.cpp
        test_serialization.cpp
        DEPS envire_core
        DEPS_PKGCONFIG class_loader boost_serialization
	DEPS_PLAIN
	   Boost_THREAD
	   Boost_UNIT_TEST_FRAMEWORK
)
    
endif()

rock_testsuite(test_suite suite.cpp
    test_transform_graph.cpp
    test_boundary.cpp
    test_graph.cpp
    test_transform.cpp
    test_envire_graph.cpp
    test_filter.cpp
    DEPS envire_core
	DEPS_PLAIN
	   Boost_THREAD
	   Boost_UNIT_TEST_FRAMEWORK
)


#rock_testsuite(timing suite.cpp
#    graph_performance_test.cpp
#    DEPS_CMAKE Boost
#    DEPS envire_core)
#target_link_libraries(timing ${Boost_LIBRARIES})
    


#only enable the performance comparision when the old envire is installed
pkg_check_modules(OLD_ENVIRE envire)
if(OLD_ENVIRE_FOUND)
    rock_executable(performance_comapare compare_old_new_performance.cpp
        DEPS envire_core
        DEPS_PKGCONFIG envire
	DEPS_PLAIN
	   Boost_THREAD
	   Boost_UNIT_TEST_FRAMEWORK
)
else()
    message(STATUS "old envire not found ... NOT building the performance comparision test")
endif()
	
	
	
